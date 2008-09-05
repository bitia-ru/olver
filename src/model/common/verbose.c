/*
 * Copyright (c) 2005-2006 Institute for System Programming
 * Russian Academy of Sciences
 * All rights reserved. 
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at 
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "utils/assertion.h"
#include "atl/string.h"

#include "common/verbose.h"

/*
 *  Redirect output to this file
 */
FILE* verbose_output = NULL;

/*
 * Verbose control flag
 */
int verbose_enabled = 1;

/*
 * Verbose function implementation
 */
int verbose(const char *format, ...)
{
    if (verbose_enabled == 1 && verbose_output != NULL)
    {
        va_list args;
        va_start(args, format);
        vfprintf(verbose_output, format, args);
        va_end(args);       
    }
    return 0;
}

/*
 * Dump function implementation  
 */
static char formatter_buffer[2048];
static char string_buffer[2048];


int dumpv(const char * format, va_list args)
{
    String* s = NULL;

    int i;      // start of current $(obj), points to '$'
    int j;      //   end of current $(obj), points to ')'
    int k;      // position of a char next to the last $(obj), equals to previous j + 1
    int len;

    void* obj;

    if (verbose_enabled == 1 && verbose_output != NULL)
    {
        len = strlen(format);
        
        j = 0;
        k = 0;

        for(i = 0; i < len; i++)
        {
            if (format[i] == '$')
            {
                i++;
                
                assertion(format[i] == '(', "dump: '(' is expected after '$'");
                
                for(j = i + 1; j < len; j++)
                {
                    if (format[j] == ')')
                    {
                        break;
                    }
                }

                assertion(j < len, "dump: ')' not found");
                assertion(j - i - 1 < 2048, "dump: name too long");

                memcpy(string_buffer, format + k, i - k - 1);
                string_buffer[i - k - 1] = 0;

                memcpy(formatter_buffer, format + i + 1, j - i - 1);
                formatter_buffer[j - i - 1] = 0;

                assertion(strcmp(formatter_buffer, "obj") == 0, "dump: only $(obj) format is supported");
                
                // print forestall string
                fprintf(verbose_output, string_buffer);

                // print object
                obj = va_arg(args, void*);

                s = toString(r(obj));
                fprintf(verbose_output, "%s", toCharArray_String(r(s)));
                destroy(s);
                destroy(obj);

                i = j;
                j++;
                k = j;
            }
        }

        // print trailing string
        if (k < len)
        {
            memcpy(string_buffer, format + k, len - k);
            string_buffer[len - k] = 0;
            vfprintf(verbose_output, string_buffer, args);
        }

    }

    return 0;
}

int dump(const char *format, ...)
{
    va_list args;
    int res;
    va_start(args, format);
    res = dumpv(format, args);
    va_end(args);
    return res;
}

int dump_req(const char *format,...)
{
    va_list args;
    int res;
    va_start(args, format);
    res = dumpv(format, args);
    va_end(args);
    return res;
}


// temporary
struct  _string
{
    char * data;
    int  length;
};
typedef struct  _string CString;

CString* create_CString(char * str);


CString *format_CStringV(const char * format, va_list args)
{
    String* s = NULL;
    CString *retval;

    int i;      // start of current $(obj), points to '$'
    int j;      //   end of current $(obj), points to ')'
    int k;      // position of a char next to the last $(obj), equals to previous j + 1
    int len;

    void* obj;
    int outbuf_len = 65536;

    char *outbuf = malloc(outbuf_len);
    const char *ch;

    *outbuf = 0;

    len = strlen(format);
    
    
    
    j = 0;
    k = 0;
    
    for(i = 0; i < len; i++)
    {
        if (format[i] == '$')
        {
            i++;
            
            assertion(format[i] == '(', "dump: '(' is expected after '$'");
            
            for(j = i + 1; j < len; j++)
            {
                if (format[j] == ')')
                {
                    break;
                }
            }
            
            assertion(j < len, "format_CString: ')' not found");
            assertion(j - i - 1 < 2048, "format_CString: name too long");
            
            memcpy(string_buffer, format + k, i - k - 1);
            string_buffer[i - k - 1] = 0;
            
            memcpy(formatter_buffer, format + i + 1, j - i - 1);
            formatter_buffer[j - i - 1] = 0;
            
            assertion(strcmp(formatter_buffer, "obj") == 0, "format_CString: only $(obj) format is supported");
            
            // print forestall string
            if((outbuf_len-=strlen(string_buffer))>0)
                strcat(outbuf,string_buffer);
            
            // print object
            obj = va_arg(args, void*);
            
            s = toString(r(obj));
            if((outbuf_len-=strlen(ch=toCharArray_String(r(s))))>0)
                strcat(outbuf, ch);
            destroy(s);
            destroy(obj);
            
            i = j;
            j++;
            k = j;
        }
    }
    
    // print trailing string
    if (k < len)
    {
        memcpy(string_buffer, format + k, len - k);
        string_buffer[len - k] = 0;
        vsprintf(outbuf+strlen(outbuf), string_buffer, args);
    }

    retval = create_CString(outbuf);
    free(outbuf);
    return retval;
}

CString *format_CString(const char *format, ...)
{
    va_list ap;
    CString *retval;
    
    va_start(ap, format);
    retval = format_CStringV(format, ap);
    va_end(ap);
    return retval;
}

/********************************************************************/
/**                          Debug Functions                       **/
/********************************************************************/

static AssertionExit system_assertion_handler;

void myAssertionExit(const char * format, va_list  arg_list)
{
    system_assertion_handler(format, arg_list);
}

void set_assertion_exit_callback(void)
{
    system_assertion_handler = atAssertion(myAssertionExit);
}


void breakHere()
{
    static int breakCnt = 0;
    printf("break here: %d \n", ++breakCnt);
}
