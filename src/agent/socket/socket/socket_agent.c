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


#include "socket/socket/socket_agent.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/uio.h>
#include <net/if.h>

#define MAX_SOCKADDR_SIZE 1000

/********************************************************************/
/**                         Socket Types Readers And Writers       **/
/********************************************************************/

struct sockaddr* readSockaddr(TAInputStream * stream, socklen_t * size)
{
    int family;
    struct sockaddr_in* sockin;
    struct sockaddr_in sockin_addr;
    struct sockaddr_in6* sockin6;
    struct sockaddr_in6 sockin6_addr;
    struct sockaddr* sockunix;
    struct sockaddr sockinunix_addr;

    int in6size, i;
    char* name;

    verifyType_TAInputStream(stream, "sockaddr");

    family = readInt(stream);

    if (family == -1)
    {
        if(size)
            *size = 0;
        return NULL;
    }

    if (family==AF_INET)
    {
        sockin = ta_alloc_memory(sizeof(sockin_addr));

        memset(sockin, 0, sizeof(sockin_addr));

        sockin->sin_family=AF_INET;
        sockin->sin_port = readUShort(stream);
        sockin->sin_addr.s_addr= readUInt32(stream);

        *size = sizeof(sockin_addr);

        return (struct sockaddr*)sockin;
    }
    else if (family==AF_INET6)
    {
        sockin6 = ta_alloc_memory(sizeof(sockin6_addr));

        memset(sockin6, 0, sizeof(sockin6_addr));

        sockin6->sin6_family=AF_INET6;
        sockin6->sin6_port=readUInt16(stream);
        sockin6->sin6_flowinfo=readUInt32(stream);

        in6size=readInt(stream);

        for (i=0;i<in6size;i++)
        {
            sockin6->sin6_addr.in6_u.u6_addr8[i] = readUInt16(stream);
        }

        sockin6->sin6_scope_id=readUInt32(stream);

        *size = sizeof(sockin6_addr);

        return (struct sockaddr*)sockin6;
    }
    else if (family==AF_UNIX)
    {
        sockunix = ta_alloc_memory(sizeof(sockinunix_addr));

        memset(sockunix, 0, sizeof(sockinunix_addr));


        sockunix->sa_family=AF_UNIX;
        name =readString(stream);

        for (i=0;i<=strlen(name);i++)
        {
            sockunix->sa_data[i]=name[i];
        }

        *size = sizeof(sockinunix_addr);

        return sockunix;

    }
    else
    {
        sockunix = ta_alloc_memory(sizeof(sockinunix_addr));

        memset(sockunix, 0, sizeof(sockinunix_addr));

        sockunix->sa_family=AF_UNSPEC;

        *size = sizeof(sockinunix_addr);

        return sockunix;

    }
    return NULL;
}

void * readSocketOptionValue(TAInputStream * stream, socklen_t * option_len)
{
    int type;
    int* intRetVal;
    struct linger * lingerRetVal;
    struct timeval* timeValRetVal;

    verifyType_TAInputStream(stream, "sockoptionval");

    type = readInt(stream);
    if (type==0)
    {
        intRetVal=ta_alloc_memory(sizeof(int));
        *intRetVal=readInt(stream);
        *option_len=sizeof(int);
        return intRetVal;
    }
    else if (type==1)
    {
        lingerRetVal=ta_alloc_memory(sizeof(struct linger));
        lingerRetVal->l_onoff=readInt(stream);
        lingerRetVal->l_linger= readInt(stream);
        *option_len=sizeof(struct linger);
        return lingerRetVal;
    }
    else
    {
        timeValRetVal=ta_alloc_memory(sizeof(struct timeval));
        timeValRetVal->tv_sec=readLong(stream);
        timeValRetVal->tv_usec=readLong(stream);
        *option_len=sizeof(struct timeval);
        return timeValRetVal;
    }
}


struct msghdr * readSocketMsgHeader(TAInputStream * stream)
{
    struct msghdr * result = ta_alloc_memory(sizeof(struct msghdr));
    socklen_t length;
    void* buf;
    size_t buflen;
    int i;

    size_t cmsg_len;
    int cmsg_level;
    int cmsg_type;
    struct cmsghdr *hdr;


    verifyType_TAInputStream(stream, "socketmsg");

    result->msg_name=readSockaddr(stream, &length);
    result->msg_namelen=length;
    result->msg_iovlen=readInt(stream);
    result->msg_iov=ta_alloc_memory(result->msg_iovlen*sizeof(struct iovec));

    for (i=0;i<result->msg_iovlen;i++)
    {
            result->msg_iov[i].iov_base=readPointer(stream);
            result->msg_iov[i].iov_len=readSize(stream);
    }

    cmsg_level = readInt(stream);
    cmsg_type =  readInt(stream);
    readByteArray(stream, (char**)&(buf), &(buflen));

    hdr=ta_alloc_memory(sizeof(struct cmsghdr)+buflen);
    hdr->cmsg_len = sizeof(struct cmsghdr)+buflen;
    hdr->cmsg_level = cmsg_level;
    hdr->cmsg_type = cmsg_type;
    memcpy(CMSG_DATA(hdr), buf, buflen);

    result->msg_control = hdr;
    result->msg_controllen = sizeof(struct cmsghdr)+buflen;

    result->msg_flags = readUInt(stream);

    return result;
}

void writeSocketMsgHeader(TAThread thread,  struct msghdr * message)
{
    int i=0;
    struct iovec cur_iov;
    struct cmsghdr *hdr = (struct cmsghdr *)message->msg_control;

    writeSockaddr(thread, message->msg_name);
    writeSize(thread, message->msg_iovlen);
    for (i=0;i<message->msg_iovlen;i++)
    {
        cur_iov = message->msg_iov[i];
        writePointer(thread, cur_iov.iov_base);
        writeSize(thread, cur_iov.iov_len);
    }

    writeInt(thread, hdr->cmsg_level);
    writeInt(thread, hdr->cmsg_type);

    writeByteArray(thread, CMSG_DATA(hdr), hdr->cmsg_len - sizeof(struct cmsghdr));

    writeUInt(thread, message->msg_flags);
}


void writeSockaddr(TAThread  thread, struct sockaddr* address)
{
    struct sockaddr_in* sockin;
    struct sockaddr_in6* sockin6;
    int i=0;

    if(address == NULL)
    {
        writeInt(thread, -1);
    }
    else
    {
        writeInt(thread, address->sa_family);

        if (address->sa_family==AF_INET)
        {
            sockin = (struct sockaddr_in*) address;
            writeUShort(thread, sockin->sin_port);
            writeUInt32(thread, sockin->sin_addr.s_addr);
        }
        else if (address->sa_family==AF_INET6)
        {
            sockin6 = (struct sockaddr_in6*) address;

            writeUInt16(thread, sockin6->sin6_port);
            writeUInt32(thread, sockin6->sin6_flowinfo);
            writeUInt32(thread, sockin6->sin6_scope_id);
            for (i=0;i<16;i++)
            {
                writeUInt16(thread, sockin6->sin6_addr.in6_u.u6_addr8[i]);
            }
        }
        else if (address->sa_family==AF_UNIX)
        {
            writeString(thread, address->sa_data);
        }
    }
}


void writeSocketOption(TAThread  thread, void* option_value, int option_name)
{
    struct linger* linger_val = (struct linger*) option_value;
    struct timeval* time_val = (struct timeval*) option_value;
    int*            int_val=(int*) option_value;
    if (option_name==SO_LINGER)
    {
        writeInt(thread, 0);
        writeInt(thread, 1);

        writeInt(thread, linger_val->l_onoff);
        writeInt(thread, linger_val->l_linger);
    }
    else if (option_name == SO_SNDTIMEO || option_name == SO_RCVTIMEO)
    {
        writeInt(thread, 0);
        writeInt(thread, 0);

        writeLong(thread, time_val->tv_sec);
        writeLong(thread, time_val->tv_usec);
    }
    else
    {
        writeInt(thread, 1);
        writeInt(thread, 0);

        writeInt(thread, *int_val);
    }
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict accept_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    struct sockaddr* address=ta_alloc_memory(MAX_SOCKADDR_SIZE);
    socklen_t  address_len = MAX_SOCKADDR_SIZE;


    // Prepare
    socket = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res = accept(socket, address, &address_len);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "accept_return");
    writeSockaddr(thread, address);
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(address);

    return taDefaultVerdict;

}

static TACommandVerdict bind_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    int size=0;
    int notZero;
    struct sockaddr* address;

    // Prepare
    socket = readInt(&stream);
    notZero= readInt(&stream);
    if (notZero)
    {
        address = readSockaddr(&stream, &size);
    }
    else
    {
        address = NULL;
    }


    START_TARGET_OPERATION(thread);

    res = bind(socket, address, size);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    if (notZero)
    {
        ta_dealloc_memory(address);
    }
    return taDefaultVerdict;
}

static TACommandVerdict bindresvport_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    int size=0;
    struct sockaddr* address;

    // Prepare
    socket = readInt(&stream);
    address = readSockaddr(&stream, &size);

    START_TARGET_OPERATION(thread);

    res = bindresvport(socket, (struct sockaddr_in *) address);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(address);

    return taDefaultVerdict;
}



static TACommandVerdict connect_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    int size=0;
    int notZero;
    struct sockaddr* address;
    struct sockaddr* peerAddress=ta_alloc_memory(MAX_SOCKADDR_SIZE);
    socklen_t address_len = MAX_SOCKADDR_SIZE;

    // Prepare
    socket = readInt(&stream);
    notZero= readInt(&stream);
    if (notZero)
    {
        address = readSockaddr(&stream, &size);
    }
    else
    {
        address = NULL;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res = connect(socket, address,  size);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "connect_return");
    writeInt(thread,res);
    writeInt(thread,errno);

    if (res!=-1)
    {
        getpeername(socket, peerAddress, &address_len);

        writeSockaddr(thread, peerAddress);

        ta_dealloc_memory(peerAddress);
    }

    sendResponse(thread);

    if (notZero)
    {
        ta_dealloc_memory(address);
    }

    return taDefaultVerdict;

}

static TACommandVerdict getpeername_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    struct sockaddr* address=ta_alloc_memory(MAX_SOCKADDR_SIZE);
    socklen_t  address_len = MAX_SOCKADDR_SIZE;

    // Prepare
    socket = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = getpeername(socket, address, &address_len);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeSockaddr(thread, address);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(address);

    return taDefaultVerdict;
}

static TACommandVerdict getsockname_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    struct sockaddr* address=ta_alloc_memory(MAX_SOCKADDR_SIZE);
    socklen_t  address_len = MAX_SOCKADDR_SIZE;

    // Prepare
    socket = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = getsockname(socket, address, &address_len);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeSockaddr(thread, address);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(address);

    return taDefaultVerdict;
}

static TACommandVerdict getsockopt_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    int level;
    int option_name;

    void * option_value = ta_alloc_memory(100);
    socklen_t option_len=100;

    // Prepare
    socket = readInt(&stream);
    level= readInt(&stream);
    option_name= readInt(&stream);

#if __powerpc__
	if(option_name >=18)
		option_name=option_name-2;
#endif

    START_TARGET_OPERATION(thread);
    res = getsockopt(socket, level, option_name, option_value, &option_len);
    END_TARGET_OPERATION(thread);

    {
        const char * px = (const char *)option_value;
        int i;
        ta_debug_printf( "getsockopt_cmd : returned value is %d\n", res         );
        ta_debug_printf( "                 socket         is %d\n", socket      );
        ta_debug_printf( "                 level          is %d\n", level       );
        ta_debug_printf( "                 option_name    is %d\n", option_name );
        ta_debug_printf( "                 option_value   is" );
        for ( i = 0; i < option_len; i++ ) { printf( " %02hhX", * ( px + i ) ); }
        ta_debug_printf( "\n" );
        ta_debug_printf( "                 option_len     is %d\n", option_len );
    }

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    writeSocketOption(thread, option_value, option_name);
    sendResponse(thread);

    ta_dealloc_memory(option_value);

    return taDefaultVerdict;
}

static TACommandVerdict listen_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    int backlog;

    // Prepare
    socket = readInt(&stream);
    backlog= readInt(&stream);


    START_TARGET_OPERATION(thread);

    res = listen(socket, backlog);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict recv_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    void *buffer;
    size_t length;
    int flag_MSG_PEEK, flag_MSG_OOB, flag_MSG_WAITALL;
    int flags = 0;

    // Prepare
    socket = readInt(&stream);
    length = readSize(&stream);

    buffer = ta_alloc_memory(length+5);

    flag_MSG_PEEK = readInt(&stream);
    flag_MSG_OOB = readInt(&stream);
    flag_MSG_WAITALL = readInt(&stream);

    if (flag_MSG_PEEK)
    {
        flags = flags | MSG_PEEK;
    }

    if (flag_MSG_OOB)
    {
        flags = flags | MSG_OOB;
    }

    if (flag_MSG_WAITALL)
    {
        flags = flags | MSG_WAITALL;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res = recv(socket, buffer, length, flags);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "recv_return");
    writeByteArray(thread, buffer, (res>=0) ? res:length);
    writeSockaddr(thread, NULL);
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict recvfrom_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    void *buffer;
    size_t length;
    int flag_MSG_PEEK, flag_MSG_OOB, flag_MSG_WAITALL;
    int flags = 0;
    struct sockaddr *address=ta_alloc_memory(MAX_SOCKADDR_SIZE);
    socklen_t address_len=MAX_SOCKADDR_SIZE;

    // Prepare
    socket = readInt(&stream);
    length = readSize(&stream);

    buffer = ta_alloc_memory(length+5);

    flag_MSG_PEEK = readInt(&stream);
    flag_MSG_OOB = readInt(&stream);
    flag_MSG_WAITALL = readInt(&stream);

    if (flag_MSG_PEEK)
    {
        flags = flags | MSG_PEEK;
    }

    if (flag_MSG_OOB)
    {
        flags = flags | MSG_OOB;
    }

    if (flag_MSG_WAITALL)
    {
        flags = flags | MSG_WAITALL;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res = recvfrom(socket, buffer, length, flags, address, &address_len);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "recv_return");
    writeByteArray(thread, buffer, (res>=0) ? res:length);
    writeSockaddr(thread, address);
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict recvmsg_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res, resultLength;

    int socket;
    struct msghdr *message;
    int flag_MSG_PEEK, flag_MSG_OOB, flag_MSG_WAITALL;
    int flags = 0;

    // Prepare
    socket = readInt(&stream);

    message = readSocketMsgHeader(&stream);
    flag_MSG_PEEK = readInt(&stream);
    flag_MSG_OOB = readInt(&stream);
    flag_MSG_WAITALL = readInt(&stream);

    if (flag_MSG_PEEK)
    {
        flags = flags | MSG_PEEK;
    }

    if (flag_MSG_OOB)
    {
        flags = flags | MSG_OOB;
    }

    if (flag_MSG_WAITALL)
    {
        flags = flags | MSG_WAITALL;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res = recvmsg(socket, message, flags);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "recvmsg_return");
    writeSSize(thread, res);
    writeInt(thread, errno);

    writeSocketMsgHeader(thread, message);

    resultLength =  res;
    writeSSize(thread, resultLength);


    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict send_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    void *buffer;
    size_t length;
    int flag_MSG_EOR, flag_MSG_OOB;
    int flags = 0;

    // Prepare
    socket = readInt(&stream);
    readByteArray(&stream, (char**)&buffer, &length);
    flag_MSG_EOR = readInt(&stream);
    flag_MSG_OOB = readInt(&stream);

    if (flag_MSG_EOR)
    {
        flags = flags | MSG_EOR;
    }

    if (flag_MSG_OOB)
    {
        flags = flags | MSG_OOB;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res =  send(socket, buffer, length, flags);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "send_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict sendmsg_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    struct msghdr *message;
    size_t length;
    int flag_MSG_EOR, flag_MSG_OOB;
    int flags = 0;

    // Prepare
    socket = readInt(&stream);
    message = readSocketMsgHeader(&stream);
    flag_MSG_EOR = readInt(&stream);
    flag_MSG_OOB = readInt(&stream);

    if (flag_MSG_EOR)
    {
        flags = flags | MSG_EOR;
    }

    if (flag_MSG_OOB)
    {
        flags = flags | MSG_OOB;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res =  sendmsg(socket, message, flags);


    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "sendmsg_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    ta_dealloc_memory(message);

    return taDefaultVerdict;

}

static TACommandVerdict sendto_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    void *buffer;
    size_t length;
    int flag_MSG_EOR, flag_MSG_OOB;
    int flags = 0;
    struct sockaddr *dest_addr;
    socklen_t dest_len;

    // Prepare
    socket = readInt(&stream);
    readByteArray(&stream, (char**)&buffer, &length);
    flag_MSG_EOR = readInt(&stream);
    flag_MSG_OOB = readInt(&stream);
    dest_addr = readSockaddr(&stream, &dest_len);

    if (flag_MSG_EOR)
    {
        flags = flags | MSG_EOR;
    }

    if (flag_MSG_OOB)
    {
        flags = flags | MSG_OOB;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    res = sendto(socket, buffer, length, flags, dest_addr, dest_len);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "send_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict setsockopt_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    int socket;
    int level;
    int option_name;

    void * option_value;
    socklen_t option_len;

    // Prepare
    socket = readInt(&stream);
    level= readInt(&stream);
    option_name= readInt(&stream);
    option_value=readSocketOptionValue(&stream, &option_len);

#if __powerpc__
	if(option_name >=18)
		option_name=option_name-2;
#endif

    START_TARGET_OPERATION(thread);
    res = setsockopt(socket, level, option_name, option_value, option_len);
    END_TARGET_OPERATION(thread);

    {
        const char * px = (const char *)option_value;
        int i;
        ta_debug_printf( "setsockopt_cmd : returned value is %d\n", res         );
        ta_debug_printf( "                 socket         is %d\n", socket      );
        ta_debug_printf( "                 level          is %d\n", level       );
        ta_debug_printf( "                 option_name    is %d\n", option_name );
        ta_debug_printf( "                 option_value   is" );
        for ( i = 0; i < option_len; i++ ) { printf( " %02hhX", * ( px + i ) ); }
        ta_debug_printf( "\n" );
        ta_debug_printf( "                 option_len     is %d\n", option_len );
    }

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(option_value);

    return taDefaultVerdict;
}

static TACommandVerdict shutdown_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int socket;
    int how;

    // Prepare
    socket = readInt(&stream);
    how = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = shutdown(socket, how);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sockatmark_cmd(TAThread thread,TAInputStream stream)
{
    int socket;
    int res;

    // Prepare
    socket = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = sockatmark(socket);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict socket_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int domain;
    int type;
    int protocol;

    // Prepare
    domain = readInt(&stream);
    type = readInt(&stream);
    protocol = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = socket(domain, type, protocol);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict socketpair_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int domain;
    int type;
    int protocol;
    int socket_vector[2];

    // Prepare
    domain = readInt(&stream);
    type = readInt(&stream);
    protocol = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = socketpair(domain, type, protocol, socket_vector);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread, socket_vector[0]);
    writeInt(thread, socket_vector[1]);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict write_socket_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    void *buffer;
    size_t nbyte;

    // Prepare
    socket = readInt(&stream);
    buffer = readPointer(&stream);
    nbyte = readSize(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);
    res = write(socket, buffer, nbyte);
    END_TARGET_OPERATION(thread);


    // Response
    writeDeferredReaction(thread, "write_socket_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);


    return taDefaultVerdict;

}


static TACommandVerdict read_socket_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;

    int socket;
    void *buffer;
    size_t nbyte;

    // Prepare
    socket = readInt(&stream);
    nbyte = readSize(&stream);
    buffer = ta_alloc_memory(nbyte+5);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);
    res = read(socket, buffer, nbyte);
    END_TARGET_OPERATION(thread);


    // Response
    writeDeferredReaction(thread, "read_socket_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    writeByteArray(thread, buffer, (res>=0) ? res:nbyte);
    sendResponse(thread);

    ta_dealloc_memory(buffer);
    return taDefaultVerdict;

}


static TACommandVerdict writev_socket_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;
    struct iovec *iov;
    int socket;
    size_t size;
    int i=0;

    // Prepare
    socket = readInt(&stream);
    size = readSize(&stream);

    iov=(struct iovec *)ta_alloc_memory(size*sizeof(struct iovec));

    for (i=0;i<size;i++)
    {
        iov[i].iov_base=readPointer(&stream);
        iov[i].iov_len=readSize(&stream);
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    res = writev(socket, iov, size);
    END_TARGET_OPERATION(thread);


    // Response
    writeDeferredReaction(thread, "writev_socket_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    ta_dealloc_memory(iov);

    return taDefaultVerdict;

}

static TACommandVerdict readv_socket_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;
    struct iovec *iov;
    int socket;
    size_t size;
    int i=0;

    // Prepare
    socket = readInt(&stream);
    size = readSize(&stream);

    iov=(struct iovec *)ta_alloc_memory(size*sizeof(struct iovec));

    for (i=0;i<size;i++)
    {
        iov[i].iov_base=readPointer(&stream);
        iov[i].iov_len=readSize(&stream);
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    res = readv(socket, iov, size);
    END_TARGET_OPERATION(thread);


    // Response
    writeDeferredReaction(thread, "readv_socket_return");
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    ta_dealloc_memory(iov);

    return taDefaultVerdict;

}

#define FIONREAD 0x541B

static TACommandVerdict ioctl_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int sockfd;
    int request;
    int i=0;
    int numStr;
    void * argp;
    int FIONREADRes;
    struct ifconf ifcnfs;
    size_t sz;

    // Prepare
    sockfd = readInt(&stream);
    request = readInt(&stream);
    numStr = readInt(&stream);

    ifcnfs.ifc_ifcu.ifcu_req = (struct ifreq *) ta_alloc_memory(numStr*sizeof(struct ifreq ));

    for (i=0;i<numStr;i++)
    {
        readByteArray(&stream, &(ifcnfs.ifc_ifcu.ifcu_req[i].ifr_ifrn.ifrn_name), &sz);
    }
    ifcnfs.ifc_len = numStr*sizeof(struct ifreq );

    if (request==FIONREAD)
    {
        argp=&FIONREADRes;
    }
    else
    {
        argp=&ifcnfs;
    }

    errno =0;

    START_TARGET_OPERATION(thread);
    res = ioctl(sockfd, request, argp);
    END_TARGET_OPERATION(thread);


    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    if (request==FIONREAD)
    {
        writeInt(thread, FIONREADRes);
    }
    else
    {
        if (request==SIOCGIFCONF)
        {
            numStr=ifcnfs.ifc_len / (sizeof(struct ifreq));
        }
        else
        {
            numStr=1;
        }

        writeInt(thread, numStr);

        for (i=0;i<numStr;i++)
        {
            writeByteArray(thread, ifcnfs.ifc_ifcu.ifcu_req[i].ifr_ifrn.ifrn_name, IFNAMSIZ);
            writeByteArray(thread, ifcnfs.ifc_ifcu.ifcu_req[i].ifr_ifru.ifru_newname, IFNAMSIZ);
        }
    }
    sendResponse(thread);

    ta_dealloc_memory(ifcnfs.ifc_ifcu.ifcu_req);

    return taDefaultVerdict;

}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_socket_socket_commands(void)
{
    ta_register_command("accept",accept_cmd);
    ta_register_command("bind",bind_cmd);
    ta_register_command("bindresvport",bindresvport_cmd);
    ta_register_command("connect",connect_cmd);
    ta_register_command("getpeername",getpeername_cmd);
    ta_register_command("getsockname",getsockname_cmd);
    ta_register_command("getsockopt",getsockopt_cmd);
    ta_register_command("listen",listen_cmd);
    ta_register_command("recv",recv_cmd);
    ta_register_command("recvfrom",recvfrom_cmd);
    ta_register_command("recvmsg",recvmsg_cmd);
    ta_register_command("send",send_cmd);
    ta_register_command("sendmsg",sendmsg_cmd);
    ta_register_command("sendto",sendto_cmd);
    ta_register_command("setsockopt",setsockopt_cmd);
    ta_register_command("shutdown",shutdown_cmd);
    ta_register_command("sockatmark",sockatmark_cmd);
    ta_register_command("socket",socket_cmd);
    ta_register_command("socketpair",socketpair_cmd);

    ta_register_command("write_socket", write_socket_cmd);
    ta_register_command("read_socket", read_socket_cmd);
    ta_register_command("writev_socket", writev_socket_cmd);
    ta_register_command("readv_socket", readv_socket_cmd);
    ta_register_command("readv_socket", readv_socket_cmd);

    ta_register_command("ioctl", ioctl_cmd);
}
