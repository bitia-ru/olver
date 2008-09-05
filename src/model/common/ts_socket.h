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


#ifndef COMMON_TS_SOCKET_H
#define COMMON_TS_SOCKET_H


#include "utils/boolean.h"
#include "ts/timemark.h"


// Tmp
extern const TimeInterval overallTimeInterval;


/********************************************************************/
/**                         Auxiliary Types                        **/
/********************************************************************/
#ifdef _WIN32

typedef __int32 TSInt32;

#else

#include <stdint.h>

typedef int32_t TSInt32;

#endif


/********************************************************************/
/**               Endianness of the Model Platform                 **/
/********************************************************************/
#ifdef _WIN32

#define __LITTLE_ENDIAN  1234
#define __BIG_ENDIAN     4321
#define __PDP_ENDIAN     3412

#define __BYTE_ORDER __LITTLE_ENDIAN

#else

#include <endian.h>

#endif


/********************************************************************/
/**                       Test System Buffer                       **/
/********************************************************************/
typedef struct TSBuffer
{
  char* data;
  int   length;
  int   memory_available;
} TSBuffer;

void shift_TSBuffer( TSBuffer* buffer, int delta );
void destroy_TSBuffer( TSBuffer* buffer );


/********************************************************************/
/**                       Test System Stream                       **/
/********************************************************************/
typedef struct TSStream
{
  TSBuffer buffer;
  int      cursor;
} TSStream;

void initTSStream( TSStream* stream, TSBuffer* buffer );
//void allocateTSStream( TSStream* stream, TSBuffer* buffer );

char* pointer_TSStream(TSStream* stream);
void shift_TSInputStream(TSStream* stream,int delta);
void shift_TSOutputStream(TSStream* stream,int delta);

// Debug functions
void print_TSInputStream(TSStream* stream);

// Low level writers
void alignTSStream( TSStream * stream );
void writeTSStream( TSStream* stream, const char* buffer, int length );
void writeCharTSStream( TSStream* stream, char ch );
void writeStringTSStream( TSStream* stream, const char* buffer );
void writeInt32TSStream( TSStream* stream, TSInt32 value );
void writeTypeHeaderTSStream( TSStream* stream, const char* type );
void formatStringTSStream( TSStream* stream, const char * format, ... );

// Low level readers
void verifyLength_TSStream(TSStream* stream,int length);
void verifyType_TSStream(TSStream* stream,const char* type);
TSInt32 readTSInt32_TSStream(TSStream* stream);
bool startsWith_TSStream(TSStream* stream,const char* str);


/********************************************************************/
/**                     TS Message Meta Data                       **/
/********************************************************************/
typedef struct TSMetaData
{
  TimeInterval timestamp;
} TSMetaData;


/********************************************************************/
/**                       Test System Command                      **/
/********************************************************************/
#define TSMESSAGE_HEADER_SIZE    4
#define TSCOMMAND_HEADER_SIZE    TSMESSAGE_HEADER_SIZE

typedef struct TSCommand
{
  TSStream   command;
  TSStream   response;
  TSMetaData meta;
} TSCommand;

TSCommand create_TSCommand(void);
void destroy_TSCommand(TSCommand* command);

// Low level writers
void format_TSCommand( TSCommand* command, const char * format, ... );


/********************************************************************/
/**                       Test System Sockets                      **/
/********************************************************************/
#ifdef _WIN32
//#include <winsock2.h>
//typedef SOCKET TSSocket;

// Compilation optimization
typedef unsigned TSSocket;

#else
#include <arpa/inet.h>

typedef int TSSocket;

#endif


extern TSSocket WrongTSSocket;

TSSocket createTSSocket(const char* address);
TSSocket createWellKnownTSSocket(int port);
TSSocket acceptTSSocket(TSSocket socket);
void closeTSSocket(TSSocket socket);

typedef enum ConnectionStatus
{
  Empty_ConnectionStatus,
  Available_ConnectionStatus,
  Closed_ConnectionStatus,
  Error_ConnectionStatus
} ConnectionStatus;

/*
 * sendTSMessage assumes that the buffer starts with the 4 bytes
 * reserved for TS Message header
 */
bool sendTSMessage(TSSocket socket,const char* buffer,int length);

ConnectionStatus receiveTSMessage(TSSocket socket,TSBuffer* buffer);
bool setNoDelayMode(TSSocket socket,bool nodelay_mode);
bool setNonblockingMode(TSSocket socket,bool nonblocking_mode);
bool isTSMessageAvailable(TSSocket socket);

ConnectionStatus getConnectionStatus(TSSocket socket);


/********************************************************************/
/**                   Auxiliary System Functions                   **/
/********************************************************************/
void ts_sleep_msec(long msecs);
void setEnvironmentVariable(const char* name,const char* value);


#endif

