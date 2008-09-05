#include <stdarg.h>
#include <unistd.h>

#define TA_DEF_TOSTR_FUNC(type_name, func_type) \
unsigned int ta_tostr_##type_name(char* buf, func_type i) \
{ \
    char buf2[32]; \
    char *p2 = buf2, *p = buf; \
    \
    func_type q, s = 0, dec = 10; \
    func_type sign = 0; \
    \
    if(i < 0) sign = 1; \
    \
    if((sign ? -i : i) < 10) \
        *p2 = (sign ? -i : i) + '0'; \
    else while(i - s != 0) \
    { \
        func_type x; \
        \
        q = (i%dec - s)/(dec/10); \
        *p2 = sign ? '0'-q : '0'+q, p2++; \
        s += q*(dec/10); \
        \
        x = sign ? -(i-s)/dec : (i-s)/dec; \
        if(x < 10) { \
            *p2 = '0' + x; \
            break; \
        } \
        \
        dec *= 10; \
    } \
    \
    if(sign == 1) *++p2 = '-'; \
    \
    while(p2-buf2+3) *p++ = *p2--; \
    \
    return p-buf-2; \
}

#define TA_DEF_STRTO_FUNC(type_name, func_type) \
const char* ta_str_to##type_name(const char* buf, func_type* pi) \
{ \
    int dec = 1, sign = 0; \
    const char* p = buf; \
    const char* res; \
    \
    *pi = 0; \
    \
    if(*buf == '-') sign = 1, buf++, p++; \
    \
    while(*buf != '\0' && *buf != ' ' && *buf != '\t') buf++; \
    res = buf; \
    while(*res == ' ' || *res == '\t') res++; \
    \
    buf--; \
    \
    while(buf+1 != p) \
    { \
        *pi += sign ? -(*buf - '0')*dec : (*buf - '0')*dec; \
        dec *= 10; \
        \
        buf--; \
    } \
    \
    return res; \
}

TA_DEF_TOSTR_FUNC(sint, int)
TA_DEF_TOSTR_FUNC(uint, unsigned int)
TA_DEF_TOSTR_FUNC(slong, long)
TA_DEF_TOSTR_FUNC(ulong, unsigned long)
TA_DEF_TOSTR_FUNC(sllong, long long)
TA_DEF_TOSTR_FUNC(ullong, unsigned long long)
TA_DEF_TOSTR_FUNC(size, size_t)
TA_DEF_TOSTR_FUNC(ssize, ssize_t)

TA_DEF_STRTO_FUNC(sint, int)
TA_DEF_STRTO_FUNC(uint, unsigned int)
TA_DEF_STRTO_FUNC(slong, long)
TA_DEF_STRTO_FUNC(ulong, unsigned long)
TA_DEF_STRTO_FUNC(sllong, long long)
TA_DEF_STRTO_FUNC(ullong, unsigned long long)
TA_DEF_STRTO_FUNC(size, size_t)
TA_DEF_STRTO_FUNC(ssize, ssize_t)

char* ta_vsprintf(char* buf, const char* format, va_list list)
{
    char* p = buf;

    while(*format)
    {
        if(format[0] == '%')
        {
            if(format[1] == '\0')
            {
                *p++ = *format;
                break;
            }

            switch(format[1])
            {
            case 'i':
                p += ta_tostr_sint(p, va_arg(list, int));
                format += 2;
                break;
            
            case 'z':
                if(format[2] == 'u')
                    p += ta_tostr_size(p, va_arg(list, size_t));
                else p += ta_tostr_ssize(p, va_arg(list, ssize_t));

                format += 2;
                break;
            
            case 'l':
                if(format[2] == 'l')
                    p += ta_tostr_sllong(p, va_arg(list, long long)), format++;
                else p += ta_tostr_slong(p, va_arg(list, long));
                format += 2;
                break;
                
            case 'u':
                if(format[2] == 'l')
                {
                    format++;
                    if(format[3] == 'l')
                        p += ta_tostr_ullong(p, va_arg(list, unsigned long long)), format++;
                    else p += ta_tostr_ulong(p, va_arg(list, unsigned long));
                } else p += ta_tostr_uint(p, va_arg(list, unsigned int));

                format += 2;
                break;
            
            case 'c':
                *p++ = (char)va_arg(list, int);
                format += 2;
                break;

            case 's': {
                char* s = va_arg(list, char*);
                while(*s) *p++ = *s++;
                format += 2;
                break;
                }
            
            default:
                *p++ = format[1];
                format += 2;
            }
        }
        else *p++ = *format++;
    }
    
    *p = '\0';
    
    return buf;
}

char* ta_sprintf(char* buf, const char* format, ...)
{
    char* res;
    va_list list;

    va_start(list, format);

    res = ta_vsprintf(buf, format, list);

    va_end(list);
}

void ta_vsscanf(const char* buf, const char* format, va_list list)
{
    void* p;

    while(format[0])
    {
        if(format[0] == '%')
        {
            if(format[1] == '\0') break;
        
            switch(format[1])
            {
            case 'i':
                p = va_arg(list, void*);
                buf = ta_str_tosint(buf, ((int*)p));

                format += 2;
                break;
                
            case 'z':
                p = va_arg(list, void*);

                if(format[2] == 'u')
                    buf = ta_str_tosize(buf, ((size_t*)p));
                else buf = ta_str_tossize(buf, ((ssize_t*)p));

                format += 2;
                break;
                
            case 'l':
                p = va_arg(list, void*);
                
                if(format[2] == 'l')
                    buf = ta_str_tosllong(buf, ((long long*)p)), format++;
                buf = ta_str_toslong(buf, ((long*)p));

                format += 2;
                break;
            
            case 'u':
                p = va_arg(list, void*);
                if(format[2] == 'l')
                {
                    format++;
                    if(format[3] == 'l')
                        buf = ta_str_toullong(buf, ((unsigned long long*)p)), format++;
                    buf = ta_str_toulong(buf, ((unsigned long*)p));
                } else buf = ta_str_touint(buf, ((unsigned int*)p));

                format += 2;
                break;

            default:
                format++;
            }
        }
        else format++;
    }
}

void ta_sscanf(const char* buf, const char* format, ...)
{
    va_list list;

    va_start(list, format);

    ta_vsscanf(buf, format, list);

    va_end(list);
}
