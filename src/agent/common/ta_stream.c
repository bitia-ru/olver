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


#include "common/ta_stream.h"
#include "common/agent.h"
#include "common/ta_assertion.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>


/********************************************************************/
/**                     Test Agent Input Stream                    **/
/********************************************************************/
TAInputStream createTAInputStream( char* buffer,int size )
{
TAInputStream res;

  res.buffer = buffer;
  res.size = size;
  res.cursor = 0;
  return res;
}

void printTAInputStream( TAInputStream* stream )
{
int i;

  for(i=0;i<stream->size;i++)
   {if (i == stream->cursor)
      ta_debug_printf("^");
    ta_debug_printf("%c",stream->buffer[i]);
   }
  ta_debug_printf("\n");
}

void shift_TAInputStream(TAInputStream* stream,int delta)
{
  stream->cursor = stream->cursor + delta;
}

char* pointer_TAInputStream(TAInputStream* stream)
{
  return &(stream->buffer[stream->cursor]);
}

static void verifyLength_TAInputStream(TAInputStream* stream,int length)
{
  if (is_ta_verbose() && (stream->cursor + length > stream->size) )
    printTAInputStream(stream);
  assertion( stream->cursor + length <= stream->size,"verifyLength_TAInputStream failed");
}


void verifyType_TAInputStream(TAInputStream* stream,const char* type)

{
int len = strlen(type);

  verifyLength_TAInputStream( stream, len + 1 );
  assertion(pointer_TAInputStream(stream)[0],"verifyType_TAInputStream failed: unexpected NULL in stream");
  assertion(memcmp(pointer_TAInputStream(stream),type,len) == 0,"verifyType_TAInputStream failed: %s expected, %s found", type, pointer_TAInputStream(stream) );
  shift_TAInputStream(stream,len);
  assertion(pointer_TAInputStream(stream)[0] == ':',"verifyType_TAInputStream failed: ':' expected");
  shift_TAInputStream(stream,1);
}


size_t readInt32(TAInputStream* stream)

{
size_t res;

  memcpy(&res,pointer_TAInputStream(stream),4);
  shift_TAInputStream(stream,4);
#if (__powerpc64__ || __s390x__)
	res=res>>32;
#endif	  
  return ntohl(res);
}


/********************************************************************/
/**                     Test Agent Output Stream                   **/
/********************************************************************/
static int AllocateBy = 512;

TAOuputStream* createTAOuputStream(void)
{
    TAOuputStream* stream;

    stream = (TAOuputStream*)ta_alloc_memory(sizeof(TAOuputStream));
    assertion(stream != 0, "createTAOuputStream: not enought memory");

    stream->buffer = (char*)ta_alloc_memory(AllocateBy);
    assertion(stream->buffer != 0, "createTAOuputStream: not enought memory");

    stream->size = AllocateBy;
    stream->cursor = 0;

    return stream;
}

void destroyTAInputStream(TAOuputStream* stream)
{
  if (stream == NULL)
    return;
  ta_dealloc_memory(stream->buffer);
  ta_dealloc_memory(stream);
}

void insertCharArray_TAOuputStream(TAOuputStream* stream, const char* data, int length)
{
    if(length <= 0) return;

    if(stream->cursor + length >= stream->size)
    {
        int size = (length > AllocateBy) ? length : AllocateBy;
        stream->buffer = (char*)ta_realloc_memory(stream->buffer, stream->size + size);
        stream->size = stream->size + size;
    }

    memmove(stream->buffer + length, stream->buffer, stream->cursor);
    memcpy(stream->buffer, data, length);
    stream->cursor = stream->cursor + length;
}


/********************************************************************/
/**                       Additional Types                         **/
/********************************************************************/
#define MILLIARD 1000000000

struct timespec addTimeUnit( struct timespec time, TimeUnit delta )
{
struct timespec res;
time_t overflow = 0;

  if (delta > 0)
   {
    res.tv_nsec = time.tv_nsec + (delta%MILLIARD);
    if (res.tv_nsec >= MILLIARD)
     {
      overflow = 1;
      res.tv_nsec = res.tv_nsec - MILLIARD;
     }
    res.tv_sec = time.tv_sec + (delta/MILLIARD) + overflow;
    return res;
   }
  if (delta < 0)
   {
    delta = -delta;
    res.tv_nsec = time.tv_nsec - (delta%MILLIARD);
    if (res.tv_nsec < 0)
     {
      overflow = 1;
      res.tv_nsec = res.tv_nsec + MILLIARD;
     }
    res.tv_sec = time.tv_sec - (delta/MILLIARD) - overflow;
    return res;
   }
  return time;
}


/********************************************************************/
/**                      Test Agent Readers                        **/
/********************************************************************/
int startsWith_TAInputStream(TAInputStream* stream,const char* str)
{
int length;

  length = strlen(str);
  if (stream->cursor + length > stream->size)
    return 0;
  return memcmp(pointer_TAInputStream(stream),str,length) == 0;
}

void align_TAInputStream( TAInputStream * stream ) {
    //int shift = stream->cursor % sizeof( long );
    //if ( shift != 0 ) { shift = sizeof( long ) - shift; }
    // ! skip all 7 !
    int shift = 0;
    while ( * ( (char *)pointer_TAInputStream( stream ) + shift ) == (char)7 ) { shift++; }
    //while ( ( (unsigned long)pointer_TAInputStream( stream ) + shift ) % sizeof( long ) != 0 ) { shift++; }
    //ta_debug_printf( "align_TAInputStream : shift is [%i]\n", shift );
    verifyLength_TAInputStream( stream, shift );
    shift_TAInputStream( stream, shift );
}

void readByteArray(TAInputStream* stream,char** data,size_t* size)
{
  verifyType_TAInputStream(stream,"ba");
  *size = readInt32(stream);
  *data = pointer_TAInputStream(stream);
  shift_TAInputStream(stream,*size);
}

void readWCharArray(TAInputStream* stream,wchar_t* data,size_t* size)
{
size_t i;

  verifyType_TAInputStream(stream,"wchararray");
  *size = readInt32(stream);
  for( i = 0; i < *size; i++ )
   {
    sscanf(pointer_TAInputStream(stream),"%d",data+i);
    shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
   }
}

//!returns unaligned string!
wchar_t * readWString(TAInputStream* stream)
{
    wchar_t* res;

    if (startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return NULL;
    }
    if ( 0 ) {
        int i;
        ta_debug_printf( "readWString : stream->size   is [%i]\n", stream->size   );
        ta_debug_printf( "readWString : stream->cursor is [%i]\n", stream->cursor );
        ta_debug_printf( "readWString : stream->buffer is [%p]\n", stream->buffer );
        for ( i = 0; i < stream->size; i++ ) {
            unsigned char c = stream->buffer[ i ];
            ta_debug_printf( "[%3hhu|%c]", c, c < 32 || 127 < c ? '?' : c );
            if ( ( i + 1 ) % 10 == 0 ) { verbose( "\n" ); }
        }
        if ( stream->size % 10 != 0 ) { verbose( "\n" ); }
    }
    verifyType_TAInputStream(stream, "wstr");
    //alignment checking is delegated to the target interface wrapper
    //align_TAInputStream( stream );
    res = (wchar_t*)pointer_TAInputStream(stream);
    //ta_debug_printf( "readWString : res is [%p]\n", res );
    shift_TAInputStream(stream, (ta_wcslen(res) + 1) * sizeof(wchar_t));
    return res;
}

char* readString(TAInputStream* stream)
{
char* res;

  if (startsWith_TAInputStream(stream,"null:"))
   {verifyType_TAInputStream(stream,"null");
    return NULL;
   }
  verifyType_TAInputStream(stream,"str");
  res = pointer_TAInputStream(stream);
  shift_TAInputStream(stream,strlen(res)+1);
  return res;
}

/* Standard Integer Types */
char readChar(TAInputStream* stream)
{
char res;

  verifyType_TAInputStream(stream,"char");
  res = pointer_TAInputStream(stream)[0];
  shift_TAInputStream(stream,1);
  return res;
}

signed char readSChar(TAInputStream* stream)
{
signed char res;

  verifyType_TAInputStream(stream,"schar");
  res = (signed char)pointer_TAInputStream(stream)[0];
  shift_TAInputStream(stream,1);
  return res;
}

unsigned char readUChar(TAInputStream* stream)
{
unsigned char res;

  verifyType_TAInputStream(stream,"uchar");
  res = (unsigned char)pointer_TAInputStream(stream)[0];
  shift_TAInputStream(stream,1);
  return res;
}

short readShort(TAInputStream* stream)
{
short res;

  verifyType_TAInputStream(stream,"short");
  sscanf(pointer_TAInputStream(stream),"%hd",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

unsigned short readUShort(TAInputStream* stream)
{
unsigned short res;

  verifyType_TAInputStream(stream,"ushort");
  sscanf(pointer_TAInputStream(stream),"%hu",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

int readInt(TAInputStream* stream)
{
int res;

  verifyType_TAInputStream(stream,"int");
  sscanf(pointer_TAInputStream(stream),"%d",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

uint16_t readUInt16(TAInputStream* stream)
{
uint16_t res;

  verifyType_TAInputStream(stream,"uint16");
  sscanf(pointer_TAInputStream(stream),"%hu",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

unsigned int readUInt(TAInputStream* stream)
{
unsigned int res;

  verifyType_TAInputStream(stream,"uint");
  sscanf(pointer_TAInputStream(stream),"%u",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

uint32_t readUInt32(TAInputStream* stream)
{
unsigned long res;

  verifyType_TAInputStream(stream,"uint32");
  sscanf(pointer_TAInputStream(stream),"%lu",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return (uint32_t)res;
}

long readLong(TAInputStream* stream)
{
  long res;
  verifyType_TAInputStream(stream,"long");
  sscanf(pointer_TAInputStream(stream),"%ld",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

unsigned long readULong(TAInputStream* stream)
{
unsigned long res;

  verifyType_TAInputStream(stream,"ulong");
  sscanf(pointer_TAInputStream(stream),"%lu",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

long long readLLong(TAInputStream* stream)
{
    long long res;

  verifyType_TAInputStream(stream,"llong");
  sscanf(pointer_TAInputStream(stream),"%lld",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

unsigned long long readULLong(TAInputStream* stream)
{
    unsigned long long res;

  verifyType_TAInputStream(stream,"ullong");
  sscanf(pointer_TAInputStream(stream),"%llu",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

wchar_t readWChar(TAInputStream* stream)
{
wchar_t res;

  verifyType_TAInputStream(stream,"wchar");
  sscanf(pointer_TAInputStream(stream),"%d",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

size_t readSize(TAInputStream* stream)
{
size_t res;

  verifyType_TAInputStream(stream,"size");
  sscanf(pointer_TAInputStream(stream),"%zu",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

ssize_t readSSize(TAInputStream* stream)
{
ssize_t res;

  verifyType_TAInputStream(stream,"ssize");
  sscanf(pointer_TAInputStream(stream),"%zd",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

intmax_t readIntMax(TAInputStream* stream)
{
intmax_t res;

  verifyType_TAInputStream(stream,"intmax");
  sscanf(pointer_TAInputStream(stream),"%lld",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}

/* Real Floating Types */
float readFloat(TAInputStream* stream)
{
    float res[2];
    long *buf = (long*)res;

    int size = (sizeof(float) - 4) / sizeof(long) + 1;
    int i;

    verifyType_TAInputStream(stream, "unifloat");

    readInt(stream);

    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
        for(i = 0; i < size; i++)
            buf[size - 1 - i] = readLong(stream);
    }
    else
    {
        for(i = 0; i < size; i++)
            buf[i] = readLong(stream);
        
        if(sizeof(long) == 8)
            buf[0] <<= 32;
    }

    shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);

    return res[0];
}

double readDouble(TAInputStream* stream)
{
    double res;
    long *buf = (long*)&res;

    int size = (sizeof(double) - 4)/sizeof(long) + 1;
    int i;

    verifyType_TAInputStream(stream, "unifloat");

    readInt(stream);

    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
        for(i = 0; i < size; i++)
            buf[size - 1 - i] = readLong(stream);
    }
    else
    {
        for(i = 0; i < size; i++)
            buf[i] = readLong(stream);
    }

    shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);

    return res;
}

long double readLongDouble(TAInputStream* stream)
{
    long double res;
    long *buf = (long*)&res;

    int size = (sizeof(long double) - 4)/sizeof(long) + 1;
    int i;

    verifyType_TAInputStream(stream, "unifloat");

    readInt(stream);

    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
        for(i = 0; i < size; i++)
            buf[size - 1 - i] = readLong(stream);
    }
    else
    {
        for(i = 0; i < size; i++)
            buf[i] = readLong(stream);
    }

    shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);

    return res;
}

/* Pointers */
void* readPointer(TAInputStream* stream)
{
  unsigned long address;

  verifyType_TAInputStream(stream,"ptr");
  sscanf(pointer_TAInputStream(stream),"%lu",&address);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return (void*)address;
}

/* Additional Types */
TimeUnit readTimeUnit(TAInputStream* stream)
{
TimeUnit res;

  verifyType_TAInputStream(stream,"timeunit");
  sscanf(pointer_TAInputStream(stream),"%lld",&res);
  shift_TAInputStream(stream,strlen(pointer_TAInputStream(stream))+1);
  return res;
}


/********************************************************************/
/**                      Test Agent Writers                        **/
/********************************************************************/
static char* pointer_TAStream(TAThread thread)
{
  return &(thread->stream->buffer[thread->stream->cursor]);
}

static void shift_TAStream(TAThread thread,int delta)
{
  thread->stream->cursor = thread->stream->cursor + delta;
}

void write_TAStream(TAThread thread,const char* buffer,int length)
{
  if (length <= 0)
    return;
  if (thread->stream->cursor + length >= thread->stream->size)
   {int size = (length > AllocateBy) ? length : AllocateBy;
    thread->stream->buffer = (char*)ta_realloc_memory( thread->stream->buffer, thread->stream->size + size );
    thread->stream->size = thread->stream->size + size;
   }
  memcpy( pointer_TAStream(thread), buffer, length );
  shift_TAStream( thread, length );
}

static void writeString_TAStream(TAThread thread, const char* str)
{
    if(str == NULL)
    {
        writeType_TAStream(thread,"null");
        return;
    }

    write_TAStream(thread, str, strlen(str));
}

void writeChar_TAStream(TAThread thread,char c)
{
  write_TAStream(thread,&c,1);
}

static void writeInt32_TAStream(TAThread thread,int value)
{
int netint;

  netint = htonl(value);
  write_TAStream(thread,(char*)&netint,4);
}

void writeType_TAStream(TAThread thread,const char* type)
{
  writeString_TAStream(thread,type);
  writeChar_TAStream(thread,':');
}

// Temporary: It is not thread-safe
static char buff[64];

void writeByteArray(TAThread thread,char* buffer,size_t length)
{
  writeType_TAStream(thread,"ba");
  writeInt32_TAStream(thread,length);
  write_TAStream(thread,buffer,length);
}

void writeWCharArray(TAThread thread,wchar_t* buffer,size_t length)
{
size_t i;

  writeType_TAStream(thread,"wchararray");
  writeInt32_TAStream(thread,length);
  for( i = 0; i < length; i++ )
   {
    sprintf(buff,"%d",(int)buffer[i]);
    writeString_TAStream(thread,buff);
    writeChar_TAStream(thread,'\0');
   }
}

void writeString(TAThread thread,const char* str)
{
  if (str == NULL)
   {
    writeType_TAStream(thread,"null");
    return;
   }
  writeType_TAStream(thread,"str");
  writeString_TAStream(thread,str);
  writeChar_TAStream(thread,'\0');
}

void writeLimitedString(TAThread thread,const char* str,size_t size)
{
size_t i;

  if (str == NULL)
   {
    writeType_TAStream(thread,"null");
    return;
   }
  for( i = 0; i < size; i++ )
   {
    if (str[i] == 0)
      break;
   }
  if (i < size)
   {
    writeString(thread,str);
   }
  else
   {
    writeType_TAStream(thread,"str");
    write_TAStream(thread,str,size);
    writeChar_TAStream(thread,'\0');
   }
}

void writeWString(TAThread thread,const wchar_t* wstr)
{
size_t i,length;

  if (wstr == NULL)
   {
    writeType_TAStream(thread,"null");
    return;
   }
  writeType_TAStream(thread,"wstr");
  for( i = 0; wstr[i] != 0; i++ );
  length = i;
  writeInt32_TAStream(thread,length);
  for( i = 0; i < length; i++ )
   {
    sprintf(buff,"%d",(int)wstr[i]);
    writeString_TAStream(thread,buff);
    writeChar_TAStream(thread,'\0');
   }
}

void writeLimitedWString(TAThread thread,const wchar_t* wstr,size_t size)
{
size_t i,length;

  if (wstr == NULL)
   {
    writeType_TAStream(thread,"null");
    return;
   }
  writeType_TAStream(thread,"wstr");
  for( i = 0; (wstr[i] != 0) && (i < size); i++ );
  length = i;
  writeInt32_TAStream(thread,length);
  for( i = 0; i < length; i++ )
   {
    sprintf(buff,"%d",(int)wstr[i]);
    writeString_TAStream(thread,buff);
    writeChar_TAStream(thread,'\0');
   }
}

/* Standard Integer Types */
void writeChar(TAThread thread,char value)
{
  writeType_TAStream(thread,"char");
  writeChar_TAStream(thread,value);
}

void writeSChar(TAThread thread,signed char value)
{
  writeType_TAStream(thread,"schar");
  writeChar_TAStream(thread,(char)value);
}

void writeUChar(TAThread thread,unsigned char value)
{
  writeType_TAStream(thread,"uchar");
  writeChar_TAStream(thread,(char)value);
}

void writeShort(TAThread thread,short value)
{
  writeType_TAStream(thread,"short");
  sprintf(buff,"%d",(int)value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeUShort(TAThread thread,unsigned short value)
{
  writeType_TAStream(thread,"ushort");
  sprintf(buff,"%u",(unsigned)value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeInt(TAThread thread,int value)
{
  writeType_TAStream(thread,"int");
  sprintf(buff,"%d",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeUInt16(TAThread thread,uint16_t value)
{
  writeType_TAStream(thread,"uint16");
  sprintf(buff,"%lu",(unsigned long)value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeUInt(TAThread thread,unsigned int value)
{
  writeType_TAStream(thread,"uint");
  sprintf(buff,"%u",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeUInt32(TAThread thread,uint32_t value)
{
  writeType_TAStream(thread,"uint32");
  sprintf(buff,"%lu",(unsigned long)value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeLong(TAThread thread,long value)
{
  writeType_TAStream(thread,"long");
  sprintf(buff,"%ld",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeULong(TAThread thread,unsigned long value)
{
  writeType_TAStream(thread,"ulong");
  sprintf(buff,"%lu",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeLLong(TAThread thread,long long value)
{
  writeType_TAStream(thread,"llong");
  sprintf(buff,"%lld",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeULLong(TAThread thread,unsigned long long value)
{
  writeType_TAStream(thread,"ullong");
  sprintf(buff,"%llu",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeWChar(TAThread thread,wchar_t value)
{
  writeType_TAStream(thread,"wchar");
  sprintf(buff,"%d",(int)value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeSize(TAThread thread,size_t value)
{
  writeType_TAStream(thread,"size");
  sprintf(buff,"%zu",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeSSize(TAThread thread,ssize_t value)
{
  writeType_TAStream(thread,"ssize");
  sprintf(buff,"%zd",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

void writeIntMax(TAThread thread,intmax_t value)
{
  writeType_TAStream(thread,"intmax");
  sprintf(buff,"%lld",value);
  write_TAStream(thread,buff,strlen(buff));
  write_TAStream(thread,"\0",1);
}

/* Real Floating Types */
void writeFloat(TAThread thread,float value)
{
    float v[2] = {value, 0.0};
    long *buf = (long*)&v;

    int size = (sizeof(float) - 4)/sizeof(long) + 1;
    int i;

    writeType_TAStream(thread, "unifloat");

    writeInt(thread,0);

    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
    	for(i = 0; i < size; i++)
            writeLong(thread,buf[i]);
    }
    else
    {
    	if(sizeof(long) == 8)
    	    buf[0] >>= 32;
    	
    	for(i = 0; i < size; i++)
            writeLong(thread,buf[size - 1 - i]);
    }

    writeChar(thread,'\0');
}

void writeDouble(TAThread thread,double value)
{
    long *buf = (long*)&value;

    int size = (sizeof(double) - 4)/sizeof(long) + 1;
    int i;

    writeType_TAStream(thread, "unifloat");

    writeInt(thread,1);

    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
    	for(i = 0; i < size; i++)
            writeLong(thread,buf[i]);
    }
    else
    {
    	for(i = 0; i < size; i++)
            writeLong(thread,buf[size - 1 - i]);
    }

    writeChar(thread,'\0');
}

void writeLongDouble(TAThread thread,long double value)
{
    long *buf = (long*)&value;

    int size = (sizeof(long double) - 4)/sizeof(long) + 1;
    int i;

    writeType_TAStream(thread, "unifloat");

    writeInt(thread,2);

    if(__BYTE_ORDER == __LITTLE_ENDIAN)
    {
    	for(i = 0; i < size; i++)
            writeLong(thread,buf[i]);
    }
    else
    {
    	for(i = 0; i < size; i++)
            writeLong(thread,buf[size - 1 - i]);
    }

    writeChar(thread,'\0');
}

/* Pointers */
void writePointer(TAThread thread,void* ptr)
{
  writeType_TAStream(thread,"ptr");
  sprintf(buff,"%lu",(unsigned long)ptr);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

/* Additional Types */
void writeTimeUnit(TAThread thread,TimeUnit value)
{
  writeType_TAStream(thread,"timeunit");
  sprintf(buff,"%lld",value);
  writeString_TAStream(thread,buff);
  writeChar_TAStream(thread,'\0');
}

/* Deferred Reaction Header */
void writeDeferredReaction(TAThread thread,const char* drname)
{
  writeType_TAStream(thread,"$dr");
  writeString(thread,drname);
}
