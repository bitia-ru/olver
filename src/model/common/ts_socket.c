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


#include "common/ts_socket.h"

#include "ts/version.hh"
#if CTESK_VERSION >= 25247
	#include "c_tracer/c_tracer.h"
#else
	#include "tracer/c_tracer.h"
#endif // CTESK_VERSION >= 25247
#include "common/coveragesTypes.h"

#include "utils/assertion.h"
#include "utils/boolean.h"
#include <string.h>
#include "config/test_system_config.h"

#ifndef _WIN32
  #include <errno.h>
  #include <fcntl.h>
  #include <unistd.h>
  #include <time.h>
#else
  #include <winsock2.h>
#endif

/********************************************************************/
/**                      Trace System Error                        **/
/********************************************************************/
#ifdef _WIN32

#include <windows.h>

void traceSystemError(const char* name)
{
    DWORD errCode,msgLen;
    char* error = NULL;
    char* message = NULL;

    errCode = GetLastError();
    if (errCode == ERROR_SUCCESS)
        errCode = WSAGetLastError();
    if (errCode == ERROR_SUCCESS)
    {
        message = (char*)malloc( strlen(name) + 16 );
        sprintf( message, "%s: No error", name );
        traceUserInfo( message );
        free(message);
        return;
    }

    /* get the text description for that error number from the system */
    msgLen = FormatMessage( FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
        0,
        errCode,
        0,
        (LPTSTR)&error,
        512,
        0);
    if (msgLen == 0)
    {
        message = (char*)malloc( strlen(name) + 32 );
        sprintf( message, "%s: error %d", name, errCode );
        traceUserInfo( message );
        free(message);
        return;
    }
    message = (char*)malloc( strlen(name) + strlen(error) + 6 );
    sprintf( message, "%s: %s", name, error );
    traceUserInfo( message );
    free(message);
    LocalFree(error);
}

#else

void traceSystemError(const char* name)
{
    char* message;
    char* error;

    error = strerror( errno );
    if (error != NULL)
    {
        message = (char*)malloc( strlen(name) + strlen(error) + 6 );
        if (message != NULL)
        {
            sprintf( message, "%s: %s", name, error );
            traceUserInfo( message );
            free(message);
        }
        else
        {
            traceUserInfo( name );
            traceUserInfo( "Not enough memory to print out error message" );
        }
    }
    else
    {
        message = (char*)malloc( strlen(name) + 16 );
        sprintf( message, "%s failed", name );
        traceUserInfo( message );
        free(message);
    }
}

#endif


/********************************************************************/
/**                       Test System Buffer                       **/
/********************************************************************/
void shift_TSBuffer( TSBuffer* buffer, int delta )
{
    if (delta >= buffer->length)
    {
        buffer->length = 0;
        return;
    }
    memmove( buffer->data, buffer->data + delta, buffer->length - delta );
    buffer->length = buffer->length - delta;
}

void destroy_TSBuffer( TSBuffer* buffer )
{
    if (buffer->data != NULL)
        free(buffer->data);
}


/********************************************************************/
/**                       Test System Stream                       **/
/********************************************************************/
// !!! Separate InStream and OutStream
void initTSStream( TSStream* stream, TSBuffer* buffer )
{
    stream->buffer.data = buffer->data;
    stream->buffer.length = buffer->length;
    stream->buffer.memory_available = buffer->memory_available;
    stream->cursor = 0;
}

static int AllocateBy = 1024;

/**
void allocateTSStream( TSStream* stream, TSBuffer* buffer )
{
  buffer->data = malloc(AllocateBy);
  buffer->length = 0;
  buffer->memory_available = AllocateBy;
  stream->buffer = buffer;
  stream->cursor = 0;
}
**/

char* pointer_TSStream(TSStream* stream)
{
    return &(stream->buffer.data[stream->cursor]);
}

void shift_TSInputStream(TSStream* stream,int delta)
{
    stream->cursor = stream->cursor + delta;
}

void shift_TSOutputStream(TSStream* stream,int delta)
{
    stream->cursor = stream->cursor + delta;
    stream->buffer.length = stream->buffer.length + delta;
}

void print_TSInputStream(TSStream* stream)
{
    int i;

    for(i=0;i<stream->buffer.length;i++)
    {
        if (i == stream->cursor)
            printf("^");
        printf("%c",stream->buffer.data[i]);
    }
    printf("\n");
}


/********************************************************************/
/**                    TSStream Low Level Writers                  **/
/********************************************************************/


void alignTSStream( TSStream * stream ) {
    int s_LongT;
	int prefixLen;

  if(TARGET_DATA_TYPES_ARCH == LSB_ARCH_IA32 || TARGET_DATA_TYPES_ARCH == LSB_ARCH_S390 || TARGET_DATA_TYPES_ARCH == LSB_ARCH_PPC32)
  {
	s_LongT=4;
  }
  else
  {
	s_LongT=8;
  }

    // "1234functionName:afterPrefix"
    prefixLen = 1;
    //while ( stream->buffer.data[ prefixLen - 1 ] != ':' ) { prefixLen++; }
    // ! only "1234" !
    prefixLen = 4;
    // align afterPrefix
    //verbose( "alignTSStream : ( stream->cursor - prefixLen ) %% sizeof_LongT is [%i]\n",
    //         ( stream->cursor - prefixLen ) % sizeof_LongT
    //       );
    while ( ( stream->cursor - prefixLen ) % s_LongT != 0 ) {
	writeCharTSStream( stream, (char)7 );
    }
}

void writeTSStream( TSStream* stream, const char* buffer,int length)
{
    if (length <= 0)
        return;
    if (stream->cursor + length >= stream->buffer.memory_available)
    {
        int size = (length > AllocateBy) ? length : AllocateBy;
        stream->buffer.data = realloc( stream->buffer.data, stream->buffer.memory_available + size );
        stream->buffer.memory_available = stream->buffer.memory_available + size;
    }
    memcpy( pointer_TSStream(stream), buffer, length );
    shift_TSOutputStream( stream, length );
}

void writeCharTSStream( TSStream* stream, char ch )
{
    if (stream->cursor + 1 >= stream->buffer.memory_available)
    {
        stream->buffer.data = realloc( stream->buffer.data, stream->buffer.memory_available + AllocateBy );
        stream->buffer.memory_available = stream->buffer.memory_available + AllocateBy;
    }
    pointer_TSStream(stream)[0] = ch;
    shift_TSOutputStream( stream, 1 );
}

void writeStringTSStream( TSStream* stream, const char* buffer)
{
//    verbose("%d\n", strlen(buffer));
    writeTSStream( stream, buffer, strlen(buffer) );
}

void writeInt32TSStream( TSStream* stream, TSInt32 value )
{
    TSInt32 netint;

    netint = htonl(value);
    writeTSStream( stream, (const char*)&netint, 4 );
}

void writeTypeHeaderTSStream( TSStream* stream, const char* type )
{
    writeTSStream( stream, type, strlen(type) );
    writeCharTSStream( stream, ':' );
}

#define FORMAT_CSTRING_LEN (1024)
/* When format_cstring overflows increase it by
 * 100/FORMAT_CSTRING_DIV per cent
 * */
#define FORMAT_CSTRING_DIV (5)
#ifdef WIN32
#define VSNPRINTF _vsnprintf
#else
#define VSNPRINTF vsnprintf
#endif

void formatStringTSStream( TSStream* stream, const char * format, ... )
{
    va_list args;
    void * p;
    static char * format_cstring;
    static size_t format_cstring_len = FORMAT_CSTRING_LEN;

    if (format_cstring==NULL) {
        format_cstring=malloc(format_cstring_len);
        assertion(format_cstring!=NULL,
            FORMAT("format_String: Failed to allocate %d bytes"),
            format_cstring_len);
    }
    va_start(args, format);
    while (VSNPRINTF(format_cstring, format_cstring_len, format, args)<0) {
        format_cstring_len += (format_cstring_len/FORMAT_CSTRING_DIV);
        p = realloc(format_cstring, format_cstring_len);
        assertion(p!=NULL,
            FORMAT("format_String: Failed to allocate %d bytes"),
            format_cstring_len);
        format_cstring = (char *)p;
    }
    va_end(args);
    //
    writeStringTSStream( stream, format_cstring );
}


/********************************************************************/
/**                    TSStream Low Level Readers                  **/
/********************************************************************/
void verifyLength_TSStream(TSStream* stream,int length)
{
    assertion( stream->cursor + length <= stream->buffer.length,"verifyLength_TSStream failed");
}

void verifyType_TSStream(TSStream* stream,const char* type)
{
    int len = strlen(type);

    verifyLength_TSStream( stream, len + 1 );
    if(
        !(memcmp(pointer_TSStream(stream),type,len) == 0)
        )
        assertion(memcmp(pointer_TSStream(stream),type,len) == 0,"verifyType_TSStream failed for %s", type);
    shift_TSInputStream(stream,len);
    assertion(pointer_TSStream(stream)[0] == ':',"verifyType_TSStream failed for %s", type);
    shift_TSInputStream(stream,1);
}

TSInt32 readTSInt32_TSStream(TSStream* stream)
{
    TSInt32 res;

    verifyLength_TSStream(stream,4);
    memcpy((char*)&res,pointer_TSStream(stream),4);
    shift_TSInputStream(stream,4);
    return ntohl(res);
}

bool startsWith_TSStream(TSStream* stream,const char* str)
{
    int length;

    length = strlen(str);
    if (stream->cursor + length > stream->buffer.length)
        return false;
    return memcmp(pointer_TSStream(stream),str,length) == 0;
}


/********************************************************************/
/**                       Test System Command                      **/
/********************************************************************/
TSCommand create_TSCommand(void)
{
    TSCommand res;

    // The first 4 bytes of the command are reserved for command length
    res.command.buffer.data = malloc(AllocateBy);
    res.command.buffer.length = TSCOMMAND_HEADER_SIZE;
    res.command.buffer.memory_available = AllocateBy;
    res.command.cursor = TSCOMMAND_HEADER_SIZE;
    res.response.buffer.data = NULL;
    res.response.buffer.length = 0;
    res.response.buffer.memory_available = 0;
    res.response.cursor = 0;
    res.meta.timestamp = overallTimeInterval;
    return res;
}

void destroy_TSCommand(TSCommand* command)
{
    destroy_TSBuffer( &command->command.buffer );
    destroy_TSBuffer( &command->response.buffer );
}


// Low level writers
void write_TSCommand( TSCommand* command, const char* buffer, int length )
{
    writeTSStream( &command->command, buffer, length );
}

void writeChar_TSCommand( TSCommand* command, char ch )
{
    writeCharTSStream( &command->command, ch );
}

void writeNTString_TSCommand( TSCommand* command, const char* buffer )
{
    writeStringTSStream( &command->command, buffer );
}

void writeTypeHeader_TSCommand( TSCommand* command, const char* type )
{
    writeTypeHeaderTSStream( &command->command, type );
}


/********************************************************************/
/**                       Test System Buffer                       **/
/********************************************************************/
typedef void Object;
typedef void (*TSFormatterFuncType)(TSStream* stream,Object* obj);
TSFormatterFuncType findTSFormatter(const char* name);


static char formatter_buffer[2048];

void format_TSCommand( TSCommand* command, const char * format, ... )
{
    int i,j,len;
    void* obj;
    va_list args;

    va_start(args, format);
    //
    len = strlen(format);
    //format_TSBuffer( stream, "pthread_mutex_init:$(mu):$(muattr)", mutex, attributes );
    j = 0;
    for(i=0;i<len;i++)
    {
        if (format[i] == '$')
        {
            writeTSStream( &command->command, format+j, i-j );
            i++;
            assertion( format[i] == '(', "format_TSBuffer: '(' is expected after '$'" );
            for(j=i+1;j<len;j++)
                if (format[j] == ')')
                    break;
                assertion( j < len, "format_TSBuffer: ')' not found" );
                assertion( j-i-1 < 2048, "format_TSBuffer: name too long" );
                memcpy( formatter_buffer, format+i+1, j-i-1 );
                formatter_buffer[j-i-1] = 0;
                {
                    TSFormatterFuncType formatter = findTSFormatter(formatter_buffer);
                    obj = va_arg( args, void*);
                    formatter( &command->command, obj );
                    // Cannot be in SEC file
                    // destroy(obj); is in formatter
                    i = j;
                    j++;
                }
        }
    }
    writeTSStream( &command->command, format+j, i-j );
    //
    va_end(args);
}


/********************************************************************/
/**                       Test System Sockets                      **/
/********************************************************************/
bool parseHostAndPort(const char* address,char** host,int* port)
{
    int i,deg;

    if (address == NULL)
        return false;
    *host = NULL;
    *port = 0;
    deg = 1;
    for(i=strlen(address)-1;i>=0;i--)
    {
        if (address[i] == ':')
        {
            if ((i == 0) || (address[i+1] == 0))
                return false;
            *host = malloc(i+1);
            assertion(*host != NULL, "parseHostAndPort: not enought memory");
            memcpy(*host,address,i);
            (*host)[i] = 0;
            return true;
        }
        if (('0' <= address[i]) && (address[i] <= '9'))
        {
            *port = *port + deg*(address[i]-'0');
            deg = deg*10;
            continue;
        }
        *port = 0;
        return false;
    }
    return false;
}


#ifdef _WIN32

static bool wasInitialized = false;

static void initSocketSubsystem(void)
{
    WORD wVersionRequested;
    WSADATA wsaData;

    if (wasInitialized)
        return;
    wVersionRequested = MAKEWORD( 2, 2 );
    if (WSAStartup(wVersionRequested,&wsaData) != 0)
    {assertion(false,"Can not start up windows sockets");
    return;
    }
    wasInitialized = true;
}

TSSocket WrongTSSocket = -1;

TSSocket createTSSocket(const char* address)
{
    char* host;
    int port;
    struct sockaddr_in addr;
    struct hostent* hp;
    TSSocket result;

    initSocketSubsystem();

    // Parse hostname and portname
    if (!parseHostAndPort(address,&host,&port))
    {
        traceFormattedUserInfo("createTSSocket: invalid address '%s'",address);
        return WrongTSSocket;
    }

    // Create socket
    result = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,0,0);
    if (result == -1)
    {
        traceSystemError("createTSSocket");
        free(host);
        return WrongTSSocket;
    }

    addr.sin_family = AF_INET;
    hp = gethostbyname(host);
    if (hp == NULL)
    {
        traceFormattedUserInfo("createTSSocket: host '%s' not found",host);
        free(host);
        closeTSSocket(result);
        return WrongTSSocket;
    }
    free(host);
    memcpy((char*)&addr.sin_addr,(char*)hp->h_addr,hp->h_length);
    addr.sin_port = htons((unsigned short)port);

    // !!!!!!!!!! Nonblocking
    if (connect(result,(struct sockaddr*) &addr,sizeof(addr)) == -1)
    {
        closeTSSocket(result);
        return WrongTSSocket;
    }
    return result;
}

TSSocket createWellKnownTSSocket(int port)
{
    TSSocket result;
    struct sockaddr_in addr;
    char msg[512];

    initSocketSubsystem();
    //
    result = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP,NULL,0,0);
    if (result == -1)
    {
        assertion( false, "Can not create socket: %d", WSAGetLastError() );
        return WrongTSSocket;
    }

    // Set reuse address option
    {
        int optval = 1;
        setsockopt(result,SOL_SOCKET,SO_REUSEADDR,(const char*)&optval,sizeof(int));
    }

    // Bind
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons((u_short)port);
    if (bind(result,(struct sockaddr*) &addr,sizeof(addr)) == -1)
    {
        closesocket(result);
        _snprintf(msg,sizeof(msg),"Can not bind socket: error %s\n",strerror(errno));
        assertion(false,msg);
        return WrongTSSocket;
    }
    if (listen(result,10) == -1)
    {
        closesocket(result);
        assertion(false,"Can not listen socket");
        return WrongTSSocket;
    }
    return result;
}

TSSocket acceptTSSocket(TSSocket socket)
{
    struct sockaddr_in addr;
    int length;
    TSSocket new_sockid;

    if (socket == WrongTSSocket)
        return WrongTSSocket;
    length = sizeof(addr);
    new_sockid = accept(socket,(struct sockaddr *) &addr, &length);
    if (new_sockid == -1)
    {
        if (WSAGetLastError() == WSAEWOULDBLOCK)
            return WrongTSSocket;
        assertion(false,"Cannot accept connection");
        return false;
    }
    // Save sockaddr somewhere
    return new_sockid;
}

void closeTSSocket(TSSocket socket)
{
  //printf("Shutting down socket\n");
  shutdown(socket,2);
  closesocket(socket);
}

/*
 * sendTSMessage assumes that the buffer starts with the 4 bytes
 * reserved for TS Message header
 */
bool sendTSMessage(TSSocket socket,const char* buffer,int length)
{
    TSInt32 netint;

    netint = htonl(length-TSMESSAGE_HEADER_SIZE);
    *((TSInt32*)buffer) = netint;
    /*
    printf("Sending stream:");
    fwrite(buffer, length, 1, stdout);
    printf("\n$$$\n");
    */
    if (send(socket,buffer,length,0) != length)
    {
        traceSystemError( "send" );
        return false;
    }
    return true;
}

int ts_recv(TSSocket socket, char* buffer, int length, int flags)
{
    int was_received,to_be_received,res2;

    was_received = 0;
    to_be_received = length;
    for(;;)
    {
        res2 = recv( socket, buffer+was_received, to_be_received, 0 );
        if (res2 == SOCKET_ERROR)
            return res2;
        if (res2 == 0)
            return was_received;
        if (res2 == to_be_received)
            return length;
        was_received = was_received + res2;
        to_be_received = to_be_received - res2;
    }
}

ConnectionStatus receiveTSMessage(TSSocket socket,TSBuffer* buffer)
{
    int res2,length;

    assertion(buffer!=NULL,"receiveTSMessage: buffer is NULL");

    res2 = ts_recv(socket,(char*)&length,sizeof(length),0);
    if (res2 != sizeof(length))
    {
        if (res2 == SOCKET_ERROR)
            traceSystemError("ts_recv");
        buffer->data = NULL;
        buffer->length = 0;
        buffer->memory_available = 0;
        return (res2 == 0) ? Closed_ConnectionStatus : Error_ConnectionStatus;
    }
    length = ntohl(length);

    buffer->length = length;
    buffer->memory_available = length;
    buffer->data = (char*)malloc(length);
    res2 = ts_recv(socket,buffer->data,length,0);


    //traceFormattedUserInfo("message=%s", buffer->data);
    {
        //static int nc = 0;
        //printf("GOT MESSAGE %d:\n", nc++);
        //fwrite(buffer->data, length, 1, stdout);
        //printf("\n\n");
    }


    if (res2 != length)
    {
        if (res2 == SOCKET_ERROR)
            traceSystemError("ts_recv");
        free(buffer->data);
        buffer->data = NULL;
        return (res2 == 0) ? Closed_ConnectionStatus : Error_ConnectionStatus;
    }
    return Available_ConnectionStatus;
}

bool setNoDelayMode(TSSocket socket,bool nodelay_mode)
{
    BOOL flag;
    int res;

    flag = nodelay_mode ? 1 : 0;
    res = setsockopt(socket,IPPROTO_TCP,TCP_NODELAY,(const char*)&flag,sizeof(int));
    return  (res != 0);
}

bool setNonblockingMode(TSSocket socket,bool nonblocking_mode)
{
    unsigned long nonblocking;
    int res2;

    if (nonblocking_mode)
        nonblocking = 1;
    else
        nonblocking = 0;

    res2 = ioctlsocket(socket,FIONBIO,&nonblocking) ;
    return (res2 == 0);
}

bool isTSMessageAvailable(TSSocket socket)
{
    bool res2;
    int length,res;

    res2 = setNonblockingMode(socket,true);
    assertion(res2,"Set up asynchronous mode failed");

    res = recv(socket,(char*)&length,sizeof(length),MSG_PEEK);

    res2 = setNonblockingMode(socket,false);
    assertion(res2,"Set up synchronous mode failed");

    return (res != SOCKET_ERROR);
}

ConnectionStatus getConnectionStatus(TSSocket socket)
{
    bool res2;
    int length,res,error;

    res2 = setNonblockingMode(socket,true);
    assertion(res2,"Set up asynchronous mode failed");

    res = recv(socket,(char*)&length,sizeof(length),MSG_PEEK);
    error = WSAGetLastError();

    res2 = setNonblockingMode(socket,false);
    assertion(res2,"Set up synchronous mode failed");

    if (res == 0)
        return Closed_ConnectionStatus;
    if (res != SOCKET_ERROR)
        return Available_ConnectionStatus;
    if (error == WSAEWOULDBLOCK)
        return Empty_ConnectionStatus;
    return Error_ConnectionStatus;
}

#else
////////////////////////////////////////////////////////

#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <stdio.h>

TSSocket WrongTSSocket = -1;

TSSocket createTSSocket(const char* address)
{
    char* host;
    int port;
    struct sockaddr_in addr;
    struct hostent* hp;
    TSSocket result;

    // Parse hostname and portname
    if (!parseHostAndPort(address,&host,&port))
    {
        traceFormattedUserInfo("createTSSocket: invalid address '%s'",address);
        return WrongTSSocket;
    }

    // Create socket
    result = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (result == -1)
    {
        traceSystemError("createTSSocket");
        free(host);
        return WrongTSSocket;
    }

    addr.sin_family = AF_INET;
    hp = gethostbyname(host);
    if (hp == NULL)
    {
        traceFormattedUserInfo("createTSSocket: host '%s' not found",host);
        free(host);
        closeTSSocket(result);
        return false;
    }
    free(host);
    memcpy((char*)&addr.sin_addr,(char*)hp->h_addr_list,hp->h_length);
    addr.sin_port = htons(port);

    if (connect(result,(struct sockaddr*) &addr,sizeof(addr)) == -1)
    {
        closeTSSocket(result);
        return false;
    }
    return true;
}

TSSocket createWellKnownTSSocket(int port)
{
    TSSocket result;
    struct sockaddr_in addr;
    char msg[512];
    //
    result = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (result == -1)
    {
        traceSystemError("socket");
        assertion( false, "Can not create socket");
        return false;
    }

    // Set reuse address option
    {
        int optval = 1;
        setsockopt(result,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int));
    }

    // Bind
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(result,(struct sockaddr*) &addr,sizeof(addr)) == -1)
    {
        traceSystemError("bind");
        close(result);
        snprintf(msg,sizeof(msg),"Can not bind socket: error %s\n",strerror(errno));
        assertion(false,msg);
        return false;
    }
    if (listen(result,10) == -1)
    {
        traceSystemError("listen");
        close(result);
        assertion(false,"Can not listen socket");
        return false;
    }
    return result;
}

TSSocket acceptTSSocket(TSSocket socket)
{
    struct sockaddr_in addr;
    socklen_t length;
    TSSocket new_sockid;

    if (socket == WrongTSSocket)
        return WrongTSSocket;
    length = sizeof(addr);
    new_sockid = accept(socket,(struct sockaddr *) &addr, &length);
    if (new_sockid == -1)
    {
        if (errno == EAGAIN)
            return WrongTSSocket;
        traceSystemError("accept");
        assertion(false,"Can not accept connection");
        return false;
    }
    // Save sockaddr somewhere
    return new_sockid;
}

void closeTSSocket(TSSocket socket)
{
    //printf("Close socket\n");
    shutdown(socket,2);
    close(socket);
}

/*
 * sendTSMessage assumes that the buffer starts with the 4 bytes
 * reserved for TS Message header
 */
bool sendTSMessage(TSSocket socket,const char* buffer,int length)
{
    TSInt32 netint;

    netint = htonl(length-TSMESSAGE_HEADER_SIZE);
    *((TSInt32*)buffer) = netint;
    if (send(socket,buffer,length,0) != length)
    {
        traceSystemError("send");
        return false;
    }
    return true;
}

ConnectionStatus receiveTSMessage(TSSocket socket,TSBuffer* buffer)
{
    int res2,length;

    assertion(buffer!=NULL,"receiveTSMessage: buffer is NULL");

    res2 = recv(socket,(char*)&length,sizeof(length),MSG_WAITALL);
    if (res2 != sizeof(length))
    {
        if (res2 == -1)
            traceSystemError("recv");
        buffer->data = NULL;
        buffer->length = 0;
        buffer->memory_available = 0;
        {
            char buff[200];
            sprintf(buff,"[%d]1:errno=%d,res2=%d",socket,errno,res2);
            traceUserInfo(buff);
        }
        return (res2 == -1) && (errno != ECONNRESET) ? Error_ConnectionStatus : Closed_ConnectionStatus;
    }
    length = ntohl(length);

    buffer->length = length;
    buffer->memory_available = length;
    buffer->data = (char*)malloc(length);
    res2 = recv(socket,buffer->data,length,MSG_WAITALL);
    if (res2 != length)
    {
        if (res2 == -1)
            traceSystemError("recv");
        free(buffer->data);
        buffer->data = NULL;
        {
            char buff[200];
            sprintf(buff,"[%d]2:errno=%d,res2=%d",socket,errno,res2);
            traceUserInfo(buff);
        }
        return (res2 == -1) && (errno != ECONNRESET) ? Error_ConnectionStatus : Closed_ConnectionStatus;
    }
    return Available_ConnectionStatus;
}

#include <netinet/tcp.h>

bool setNoDelayMode(TSSocket socket,bool nodelay_mode)
{
    int flag,res;

    flag = nodelay_mode ? 1 : 0;
    res = setsockopt(socket,IPPROTO_TCP,TCP_NODELAY,(const char*)&flag,sizeof(int));
    return  (res != 0);
}

bool setNonblockingMode(TSSocket socket,bool nonblocking_mode)
{
    unsigned long nonblocking;
    int res2;

    if (nonblocking_mode)
        res2 = fcntl(socket,F_SETFL,O_NONBLOCK);
    else
        res2 = fcntl(socket,F_SETFL,0);
    return (res2 != -1);
}

bool isTSMessageAvailable(TSSocket socket)
{
    bool res2;
    int length,res;

    res2 = setNonblockingMode(socket,true);
    assertion(res2,"Set up asynchronous mode failed");

    res = recv(socket,(char*)&length,sizeof(length),MSG_PEEK);

    res2 = setNonblockingMode(socket,false);
    assertion(res2,"Set up synchronous mode failed");

    return (res != -1);
}

ConnectionStatus getConnectionStatus(TSSocket socket)
{
    bool res2;
    int length,res,error;

    res2 = setNonblockingMode(socket,true);
    assertion(res2,"Set up asynchronous mode failed");

    res = recv(socket,(char*)&length,sizeof(length),MSG_PEEK);
    error = errno;

    res2 = setNonblockingMode(socket,false);
    assertion(res2,"Set up synchronous mode failed");

    if (res != -1)
        return Available_ConnectionStatus;
    if (error == EAGAIN)
        return Empty_ConnectionStatus;
    {
        char buff[200];
        sprintf(buff,"[%d]3:errno=%d,res=%d",socket,errno,res);
        traceUserInfo(buff);
    }
    return Closed_ConnectionStatus;
}

#endif


/********************************************************************/
/**                   Auxiliary System Functions                   **/
/********************************************************************/

#ifdef WIN32

#include <windows.h>

void ts_sleep_msec(long msecs)
{
    Sleep(msecs);
}

void setEnvironmentVariable(const char* name,const char* value)
{
    SetEnvironmentVariable( name, value );
}

#else

#include <sys/time.h>

void ts_sleep_msec(long msecs)
{
    struct timespec tx;

    tx.tv_sec = msecs/1000;
    tx.tv_nsec = (msecs%1000)*1000000;
    nanosleep(&tx,NULL);
}

void setEnvironmentVariable(const char* name,const char* value)
{
    setenv(name,value,1);
}

#endif
