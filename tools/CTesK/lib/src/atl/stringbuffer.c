/*
 * File: stringbuffer.c
 * Description:
 *       This file defines the specification type representing
 *       string buffers.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2006 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <atl/object.h>
#include <utils/assertion.h>
#include <utils/boolean.h>

#include <atl/stringbuffer.h>
#include <ctype.h>
#include <string.h>

#define DEFAULT_ALLOCATE_SIZE   256

struct StringBuffer
{
  int   size;
  int   capacity;
  int   allocateBy;
  char* buffer;
};

static void init_StringBuffer( StringBuffer* strbuf, va_list *arg_list )
{
  strbuf->size = 0;
  strbuf->allocateBy = va_arg( *arg_list, int );
  strbuf->capacity = strbuf->allocateBy;

  assertion( strbuf->allocateBy > 0,
             FORMAT( "init_StringBuffer: allocateBy should be greater zero" )
           );

  strbuf->buffer = malloc( strbuf->allocateBy );

  assertion( strbuf->buffer != NULL, FORMAT( "init_StringBuffer: Not enough memory" ) );
}

static void copy_StringBuffer( StringBuffer* src, StringBuffer* dst )
{
  dst->size = src->size;
  dst->capacity = src->capacity;
  dst->allocateBy = src->allocateBy;
  dst->buffer = malloc( dst->capacity );

  assertion( dst->buffer != NULL, FORMAT( "copy_StringBuffer: Not enough memory" ) );

  memcpy( dst->buffer, src->buffer, dst->size );
}

static int compare_StringBuffer( StringBuffer* left, StringBuffer* right )
{
  if (left->size != right->size)
    return left->size - right->size;
  return memcmp( left->buffer, right->buffer, left->size );
}

static String* to_string_StringBuffer( StringBuffer* strbuf )
{
char* cstr;
String* res;

  res = create( &type_String, NULL, strbuf->size  );
  cstr = (char*)toCharArray_String( r(res) );
  memcpy( cstr, strbuf->buffer, strbuf->size );
  cstr[strbuf->size] = '\0';
  return res;
}

static String* to_XML_StringBuffer( StringBuffer* strbuf )
{
	return to_XML_spec("StringBuffer", to_string_StringBuffer(strbuf));
}

static void destroy_StringBuffer( StringBuffer* strbuf )
{
  free( strbuf->buffer );
}

const Type type_StringBuffer
    = { "StringBuffer"
      , sizeof(StringBuffer)
      , &type_Object
      , (Init)init_StringBuffer
      , (Copy)copy_StringBuffer
      , (Compare)compare_StringBuffer
      , (ToString)to_string_StringBuffer
      , (ToXML)to_XML_StringBuffer
      , (CheckInvariant)check_invariant_Default
      , (Enumerate)enumerate_Default
      , (Destroy)destroy_StringBuffer
      };

/*
 * Expand the string buffer for at least min bytes.
 */
static void expand_StringBuffer( StringBuffer* self, int min )
{
int extra;

  if (min < self->allocateBy)
    extra = self->allocateBy;
  else
    extra = ((min / self->allocateBy) + 1) * self->allocateBy;

  self->buffer = realloc( self->buffer, self->capacity + extra );
  assertion( self->buffer != NULL, FORMAT( "expand_StringBuffer: Not enough memory" ) );

  self->capacity = self->capacity + extra;

  destroy( self );
}


/*
 * Create empty StringBuffer.
 */
StringBuffer* create_StringBuffer(void)
{
  return create( &type_StringBuffer, DEFAULT_ALLOCATE_SIZE );
}

/*
 * Create empty StringBuffer with the given allocateBy.
 */
StringBuffer* createCustomized_StringBuffer( int allocateBy )
{
  return create( &type_StringBuffer, allocateBy );
}

/*
 * Returns the current size of the string buffer.
 */
int size_StringBuffer( StringBuffer* self )
{
int res;

  CHECK_TYPE_COMPATIBLE( size_StringBuffer, &type_StringBuffer, self );

  res = self->size;

  destroy( self );

  return res;
}

/*
 * Returns the character at the specified index.
 */
char charAt_StringBuffer( StringBuffer* self, int index )
{
char res;

  CHECK_TYPE_COMPATIBLE( charAt_StringBuffer, &type_StringBuffer, self );

  assertion( 0 <= index && index < self->size
           , FORMAT( "charAt_StringBuffer: char index %d is out of bounds [0, %d[" )
           , index
           , self->size
           );

  res = self->buffer[index];

  destroy( self );

  return res;
}

/*
 * Appends the specified char to the end of the string buffer.
 */
void appendChar_StringBuffer( StringBuffer* self, char ch )
{
  CHECK_TYPE_COMPATIBLE( appendChar_StringBuffer, &type_StringBuffer, self );

  if (self->size == self->capacity)
   {
    expand_StringBuffer( r(self), 1 );
   }

  self->buffer[self->size] = ch;
  self->size++;

  destroy( self );
}

/*
 * Appends the specified null-terminating string
 * to the end of the string buffer.
 */
void append_StringBuffer( StringBuffer* self, const char* str )
{
int length;

  CHECK_TYPE_COMPATIBLE( append_StringBuffer, &type_StringBuffer, self );

  length = strlen( str );

  if (self->size + length > self->capacity)
   {
    expand_StringBuffer( r(self), self->size + length - self->capacity );
   }

  memcpy( &(self->buffer[self->size]), str, length );
  self->size = self->size + length;

  destroy( self );
}

/*
 * Appends the specified char array to the end of the string buffer.
 */
void appendCharArray_StringBuffer( StringBuffer* self, const char* arr, int size )
{
  CHECK_TYPE_COMPATIBLE( appendCharArray_StringBuffer, &type_StringBuffer, self );

  if (self->size + size > self->capacity)
   {
    expand_StringBuffer( r(self), self->size + size - self->capacity );
   }

  memcpy( &(self->buffer[self->size]), arr, size );
  self->size = self->size + size;

  destroy( self );
}

/*
 * Appends the specified string to the end of the string buffer.
 */
void appendString_StringBuffer( StringBuffer* self, String* str )
{
int length;

  CHECK_TYPE_COMPATIBLE( appendString_StringBuffer, &type_StringBuffer, self );
  CHECK_TYPE_COMPATIBLE( appendString_StringBuffer, &type_String, str );

  length = length_String( r(str) );

  if (self->size + length > self->capacity)
   {
    expand_StringBuffer( r(self), self->size + length - self->capacity );
   }

  memcpy( &(self->buffer[self->size]), toCharArray_String( r(str) ), length );
  self->size = self->size + length;

  destroy( self );
  destroy( str );
}

/*
 * Appends the specified string buffer to the end of the string buffer.
 */
void appendStringBuffer_StringBuffer( StringBuffer* self, StringBuffer* strbuf )
{
  CHECK_TYPE_COMPATIBLE( appendStringBuffer_StringBuffer, &type_StringBuffer, self );
  CHECK_TYPE_COMPATIBLE( appendStringBuffer_StringBuffer, &type_StringBuffer, strbuf );

  if (self->size + strbuf->size > self->capacity)
   {
    expand_StringBuffer( r(self), self->size + strbuf->size - self->capacity );
   }

  memcpy( &(self->buffer[self->size]), strbuf->buffer, strbuf->size );
  self->size = self->size + strbuf->size;

  destroy( self );
  destroy( strbuf );
}


/*
 * Appends the string with formatted data like sprintf
 * to the end of the string buffer.
 */
void appendFormat_StringBuffer( StringBuffer* self, const char* format, ... )
{
va_list args;

    va_start( args, format );
    vappendFormat_StringBuffer( r(self), format, args );
    va_end( args );
    destroy( self );
}

#ifdef WIN32

/*
 * Appends the string with formatted data like sprintf
 * to the end of the string buffer.
 */
void vappendFormat_StringBuffer( StringBuffer* self, const char* format, va_list args )
{
int i;
int res_vsnprintf;

  CHECK_TYPE_COMPATIBLE( appendFormat_StringBuffer, &type_StringBuffer, self );

  for( i = 1; ; i++ )
   {
    res_vsnprintf = _vsnprintf( self->buffer + self->size, self->capacity - self->size, format, args );

    if ( res_vsnprintf >= 0 ) { break; }
    expand_StringBuffer( r(self), i*self->allocateBy );
   }
  self->size = self->size + res_vsnprintf;

  destroy( self );
}

#else

/*
 * Appends the string with formatted data like sprintf
 * to the end of the string buffer.
 */
void vappendFormat_StringBuffer( StringBuffer* self, const char* format, va_list args )
{
int added_len;
va_list args_copy;

  CHECK_TYPE_COMPATIBLE( appendFormat_StringBuffer, &type_StringBuffer, self );

  va_copy( args_copy, args );

  added_len = vsnprintf( self->buffer + self->size, self->capacity - self->size, format, args );
  va_end(args);

  if ( self->size + added_len + 1 > self->capacity )
   {
    expand_StringBuffer( r(self), self->size + added_len + 1 - self->capacity );
    added_len = vsnprintf( self->buffer + self->size, self->capacity - self->size, format, args );
   }
  self->size = self->size + added_len;

  va_end( args_copy );
  destroy( self );
}
#endif


/*
 * Tests if this string buffer ends with the specified suffix.
 */
bool endsWith_StringBuffer( StringBuffer* self, String* suffix )
{
const char *suffix_cstr;
int suffix_len;
bool res;

  CHECK_TYPE_COMPATIBLE( endsWith_StringBuffer, &type_StringBuffer, self   );
  CHECK_TYPE_COMPATIBLE( endsWith_StringBuffer, &type_String, suffix );

  suffix_cstr = toCharArray_String( r( suffix ) );
  suffix_len  = length_String( r( suffix ) );

  if( self->size >= suffix_len )
   {
    res = memcmp( self->buffer + self->size - suffix_len, suffix_cstr, suffix_len )
              ?   false
                : true;
   }
  else
   {
    res = false;
   }

  destroy( self );
  destroy( suffix );

  return res;
}

/*
 * Returns the index within this string buffer of the first occurrence
 * of the specified character.
 */
int indexOfChar_StringBuffer( StringBuffer* self, int ch )
{
  return indexOfCharFrom_StringBuffer( self, ch, 0 );
}

/*
 * Returns the index within this string buffer of the first occurrence
 * of the specified character, starting the search at the specified index.
 */
int indexOfCharFrom_StringBuffer( StringBuffer* self, int ch, int fromIndex )
{
int res = - 1;

  CHECK_TYPE_COMPATIBLE( indexOfCharFrom_StringBuffer, &type_StringBuffer, self );

  if ( fromIndex < 0 ) fromIndex = 0;

  if ( ch != 0 && fromIndex < self->size )
   {
    const char* pos = memchr( self->buffer + fromIndex, ch, self->size - fromIndex );

    if (pos != NULL)
     {
      res = pos - self->buffer;
     }
   }

  destroy( self );

  return res;
}

/*
 * Returns the index within this string buffer of the first occurrence
 * of the specified substring.
 */
int indexOfString_StringBuffer( StringBuffer* self, String* str )
{
  return indexOfStringFrom_StringBuffer( self, str, 0 );
}

/*
 * Returns the index within this string buffer of the first occurrence
 * of the specified substring, starting at the specified index.
 */
int indexOfStringFrom_StringBuffer( StringBuffer* self, String* str, int fromIndex )
{
int i,str_length;
int res = -1;

  CHECK_TYPE_COMPATIBLE( indexOfStringFrom_StringBuffer, &type_StringBuffer, self );
  CHECK_TYPE_COMPATIBLE( indexOfStringFrom_StringBuffer, &type_String, str  );

  if ( fromIndex < 0 ) fromIndex = 0;

  str_length = length_String( r(str) );

  if ( fromIndex <= self->size - str_length )
   {
    const char* str_cstr = toCharArray_String( r( str  ) );

    for( i = fromIndex; i <= self->size - str_length; i++ )
     {
      if (memcmp( self->buffer + i, str_cstr, str_length ) == 0)
       {
        res = i;
        break;
       }
     }
   }

  destroy( self );
  destroy( str );

  return res;
}

/*
 * Returns the index within this string buffer of the last occurrence
 * of the specified character.
 */
int lastIndexOfChar_StringBuffer( StringBuffer* self, int ch )
{
  CHECK_TYPE_COMPATIBLE( lastIndexOfChar_StringBuffer, &type_StringBuffer, self );

  return lastIndexOfCharFrom_StringBuffer( self, ch, self->size );
}

/*
 * Returns the index within this string buffer of the last occurrence
 * of the specified character, searching backward starting
 * at the specified index.
 */
int lastIndexOfCharFrom_StringBuffer( StringBuffer* self, int ch, int fromIndex )
{
int res = - 1;

  CHECK_TYPE_COMPATIBLE( lastIndexOfCharFrom_StringBuffer, &type_StringBuffer, self );

  if ( ch != 0 && 0 <= fromIndex )
   {
    int i;

    if ( fromIndex >= self->size ) fromIndex = self->size - 1;

    for( i = fromIndex; 0 <= i; i-- )
     {
      if (self->buffer[i] == ch)
       {
        res = i;
        break;
       }
     }
   }

  destroy( self );

  return res;
}

/*
 * Returns the index within this string buffer of the rightmost occurrence
 * of the specified substring.
 */
int lastIndexOfString_StringBuffer( StringBuffer* self, String* str )
{
  CHECK_TYPE_COMPATIBLE( lastIndexOfString_StringBuffer, &type_StringBuffer, self );

  return lastIndexOfStringFrom_StringBuffer( self, str, self->size );
}

/*
 * Returns the index within this string buffer of the last occurrence
 * of the specified substring.
 */
int lastIndexOfStringFrom_StringBuffer( StringBuffer* self, String* str, int fromIndex )
{
int res = -1;
int i;

  CHECK_TYPE_COMPATIBLE( lastIndexOfStringFrom_StringBuffer, &type_StringBuffer, self );
  CHECK_TYPE_COMPATIBLE( lastIndexOfStringFrom_StringBuffer, &type_String, str  );

  if ( fromIndex > self->size ) fromIndex = self->size - length_String( r(str) );

  for( i = fromIndex; 0 <= i; i-- )
   {
    if ( startsWithOffset_StringBuffer( r(self), r(str), i ) )
     {
      res = i;
      break;
     }
   }

  destroy( self );
  destroy( str );

  return res;
}

/*
 * Replaces all occurrences of oldChar in the string buffer with newChar.
 */
void replace_StringBuffer( StringBuffer* self, char oldChar, char newChar )
{
int i;

  CHECK_TYPE_COMPATIBLE( replace_StringBuffer, &type_StringBuffer, self );

  for( i = 0; i < self->size; i++ )
   {
    if (self->buffer[i] == oldChar)
      self->buffer[i] = newChar;
   }

  destroy( self );
}

/*
 * Tests if this string buffer starts with the specified prefix.
 */
bool startsWith_StringBuffer( StringBuffer* self, String* prefix )
{
    return startsWithOffset_StringBuffer( self, prefix, 0 );
}

/*
 * Tests if this string buffer starts with the specified prefix beginning
 * a specified index.
 */
bool startsWithOffset_StringBuffer( StringBuffer* self, String* prefix, int toffset )
{
int length;
bool res = false;

  CHECK_TYPE_COMPATIBLE( startsWithOffset_StringBuffer, &type_StringBuffer, self   );
  CHECK_TYPE_COMPATIBLE( startsWithOffset_StringBuffer, &type_String, prefix );

  length = length_String( r( prefix ) );

  if ( 0 <= toffset && toffset <= self->size - length )
   {
    const char* prefix_cstr = toCharArray_String( r( prefix ) );

    res = memcmp( self->buffer + toffset
                 , prefix_cstr
                 , length
                 )
          ?   false
            : true;
   }

  destroy( self );
  destroy( prefix );

  return res;
}

/*
 * Returns a new string that is a substring of the string buffer.
 */
String* substringFrom_StringBuffer( StringBuffer* self, int beginIndex )
{
String* res;
char* cstr;

  CHECK_TYPE_COMPATIBLE( substringFrom_StringBuffer, &type_StringBuffer, self );

  assertion( 0 <= beginIndex && beginIndex <= self->size
             , FORMAT( "substringFrom_StringBuffer: beginIndex %d is out of bounds [0,%d]" )
             , beginIndex
             , self->size
             );

  res = create( &type_String, NULL, self->size - beginIndex );
  cstr = (char*)toCharArray_String( r(res) );
  memcpy( cstr, self->buffer + beginIndex, self->size - beginIndex );
  cstr[self->size - beginIndex] = '\0';

  destroy( self );

  return res;
}

/*
 * Returns a new string that is a substring of the string buffer.
 */
String* substring_StringBuffer( StringBuffer* self, int beginIndex, int endIndex )
{
String* res;
char* cstr;

  CHECK_TYPE_COMPATIBLE( substring_StringBuffer, &type_StringBuffer, self );

  assertion(    0 <= beginIndex
             && beginIndex <= endIndex
             && endIndex <= self->size
           , FORMAT( "substring_String: beginIndex %d or endIndex %d are out of bounds [0,%d]"
                     " or endIndex < beginIndex"
                   )
           , beginIndex
           , endIndex
           , self->size
           );

  res = create( &type_String, NULL, endIndex - beginIndex );
  cstr = (char*)toCharArray_String( r(res) );
  memcpy( cstr, self->buffer + beginIndex, endIndex - beginIndex );
  cstr[endIndex - beginIndex] = '\0';

  destroy( self );

  return res;
}


