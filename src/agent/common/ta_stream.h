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


#ifndef TA_COMMON_STREAM_H
#define TA_COMMON_STREAM_H


#include <wchar.h>
#include <sys/types.h>
#include <sys/time.h>


/********************************************************************/
/**                     Test Agent Input Stream                    **/
/********************************************************************/
typedef struct TAInputStream
{
  char* buffer;
  int cursor;
  int size;
} TAInputStream;

TAInputStream createTAInputStream( char* buffer,int size );


/********************************************************************/
/**                     Test Agent Output Stream                   **/
/********************************************************************/
typedef struct TAOutputStream
{
  char* buffer;
  int cursor;
  int size;
} TAOuputStream;

TAOuputStream* createTAOuputStream(void);
void destroyTAInputStream(TAOuputStream* stream);

void insertCharArray_TAOuputStream(TAOuputStream* stream,const char* data,int length);


/********************************************************************/
/**                       Test Agent Thread                        **/
/********************************************************************/
typedef struct TAThread* TAThread;


/********************************************************************/
/**                       Additional Types                         **/
/********************************************************************/
typedef int64_t TimeUnit;

struct timespec addTimeUnit( struct timespec time, TimeUnit delta );


/********************************************************************/
/**                      Test Agent Readers                        **/
/********************************************************************/
void verifyType_TAInputStream(TAInputStream* stream,const char* type);

int startsWith_TAInputStream(TAInputStream* stream,const char* str);

void align_TAInputStream( TAInputStream * stream );

void readByteArray(TAInputStream* stream,char** data,size_t* size);

void readWCharArray(TAInputStream* stream,wchar_t* data,size_t* size);

wchar_t* readWString(TAInputStream* stream) ;

char* readString(TAInputStream* stream);

/* Standard Integer Types */
char readChar(TAInputStream* stream);

signed char readSChar(TAInputStream* stream);

unsigned char readUChar(TAInputStream* stream);

short readShort(TAInputStream* stream);

unsigned short readUShort(TAInputStream* stream);

int readInt(TAInputStream* stream);

uint16_t readUInt16(TAInputStream* stream);

unsigned int readUInt(TAInputStream* stream);

uint32_t readUInt32(TAInputStream* stream);

long readLong(TAInputStream* stream);

unsigned long readULong(TAInputStream* stream);

long long readLLong(TAInputStream* stream);

unsigned long long readULLong(TAInputStream* stream);

wchar_t readWChar(TAInputStream* stream);

size_t readSize(TAInputStream* stream);

ssize_t readSSize(TAInputStream* stream);

intmax_t readIntMax(TAInputStream* stream);

intptr_t readIntPtr(TAInputStream* stream);

/* Real Floating Types */
float readFloat(TAInputStream* stream);

double readDouble(TAInputStream* stream);

long double readLongDouble(TAInputStream* stream);

/* Pointers */
void* readPointer(TAInputStream* stream);

/* Additional Types */
TimeUnit readTimeUnit(TAInputStream* stream);


/********************************************************************/
/**                      Test Agent Writers                        **/
/********************************************************************/
/* Low Level Writers */
void write_TAStream(TAThread thread,const char* buffer,int length);

void writeChar_TAStream(TAThread thread,char c);

void writeType_TAStream(TAThread thread,const char* type);

/* Array Types */
void writeByteArray(TAThread thread,char* buffer,size_t length);

void writeWCharArray(TAThread thread,wchar_t* buffer,size_t length);

void writeString(TAThread thread,const char* str);

void writeLimitedString(TAThread thread,const char* str,size_t size);

void writeWString(TAThread thread,const wchar_t* wstr);

void writeLimitedWString(TAThread thread,const wchar_t* wstr,size_t size);

/* Standard Integer Types */
void writeChar(TAThread thread,char value);

void writeSChar(TAThread thread,signed char value);

void writeUChar(TAThread thread,unsigned char value);

void writeShort(TAThread thread,short value);

void writeUShort(TAThread thread,unsigned short value);

void writeInt(TAThread thread,int value);

void writeUInt16(TAThread thread,uint16_t value);

void writeUInt(TAThread thread,unsigned int value);

void writeUInt32(TAThread thread,uint32_t value);

void writeLong(TAThread thread,long value);

void writeULong(TAThread thread,unsigned long value);

void writeLLong(TAThread thread,long long value);

void writeULLong(TAThread thread,unsigned long long value);

void writeWChar(TAThread thread,wchar_t value);

void writeSize(TAThread thread,size_t value);

void writeSSize(TAThread thread,ssize_t value);

void writeIntMax(TAThread thread,intmax_t value);

/* Real Floating Types */
void writeFloat(TAThread thread,float value);

void writeDouble(TAThread thread,double value);

void writeLongDouble(TAThread thread,long double value);

/* Pointers */
void writePointer(TAThread thread,void* ptr);

/* Additional Types */
void writeTimeUnit(TAThread thread,TimeUnit value);

/* Deferred Reaction Header */
void writeDeferredReaction(TAThread thread,const char* drname);


#endif

