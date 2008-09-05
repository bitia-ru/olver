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


#include "socket/netdb/netdb_agent.h"
#include "socket/socket/socket_agent.h"
#include <netdb.h>
#include <string.h>
#include <errno.h>

/********************************************************************/
/**                        Readers & Writers                       **/
/********************************************************************/

void writeServent(TAThread thread, struct servent * se)
{
    if(se != NULL)
    {
        writeInt(thread, 0); // is_null flag
        writeString(thread, se->s_name);
        writePointer(thread, se->s_aliases);
        writeInt(thread, se->s_port);
        writeString(thread, se->s_proto);
    }
    else
    {
        writeInt(thread, 1); // is_null flag
    }
}

void writeProtoent(TAThread thread, struct protoent * pe)
{
    if(pe != NULL)
    {
        writeInt(thread, 0); // is_null flag
        writeString(thread, pe->p_name);
        writePointer(thread, pe->p_aliases);
        writeInt(thread, pe->p_proto);
    }
    else
    {
        writeInt(thread, 1); // is_null flag
    }
}

void writeHostent(TAThread thread, struct hostent * he)
{
    if(he != NULL)
    {
        writeInt(thread, 0); // is_null flag
        writeString(thread, he->h_name); // is_null flag
        writePointer(thread, he->h_aliases);
        writeInt(thread, he->h_addrtype);
        writeInt(thread, he->h_length);
        writePointer(thread, he->h_addr_list);
    }
    else
    {
        writeInt(thread, 1); // is_null flag
    }
}

void writeAddrinfo(TAThread thread, struct addrinfo * ai)
{
    writePointer(thread, ai);
    if(ai != NULL)
    {
        writeInt(thread, ai->ai_flags);
        writeInt(thread, ai->ai_family);
        writeInt(thread, ai->ai_socktype);
        writeInt(thread, ai->ai_protocol);
        writeUInt(thread, ai->ai_addrlen);
        writeSockaddr(thread, ai->ai_addr);
        writeString(thread, ai->ai_canonname);
        writePointer(thread, ai->ai_next);
    }
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict endservent_cmd(TAThread thread,TAInputStream stream)
{
    
    START_TARGET_OPERATION(thread);
    
    endservent();
    
    END_TARGET_OPERATION(thread);
    
    /* Void */
    sendResponse(thread); 
        
    return taDefaultVerdict;
}

static TACommandVerdict getservbyname_cmd(TAThread thread,TAInputStream stream)
{
    char * name;
    char * proto;
    struct servent * res;
    
    name = readString(&stream);
    proto = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = getservbyname(name, proto);
    
    END_TARGET_OPERATION(thread);
    
    writeServent(thread, res);
    sendResponse(thread); 
    
    return taDefaultVerdict;
}

static TACommandVerdict getservbyport_cmd(TAThread thread,TAInputStream stream)
{
    int port;
    char * proto;
    struct servent * res;
    
    port = readInt(&stream);
    proto = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = getservbyport(port, proto);
    
    END_TARGET_OPERATION(thread);
    
    writeServent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getservent_cmd(TAThread thread,TAInputStream stream)
{
    struct servent * res;
    
    START_TARGET_OPERATION(thread);
    
    res = getservent();
    
    END_TARGET_OPERATION(thread);
    
    writeServent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict setservent_cmd(TAThread thread,TAInputStream stream)
{
    int stayopen;
    
    stayopen = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    setservent(stayopen);
    
    END_TARGET_OPERATION(thread);
    
    /* Void */
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/*******/

static TACommandVerdict endprotoent_cmd(TAThread thread,TAInputStream stream)
{
    
    START_TARGET_OPERATION(thread);
    
    endprotoent();
    
    END_TARGET_OPERATION(thread);
    
    /* Void */
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getprotobyname_cmd(TAThread thread,TAInputStream stream)
{
    char * name;
    struct protoent * res;
    
    name = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = getprotobyname(name);
    
    END_TARGET_OPERATION(thread);
    
    writeProtoent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getprotobynumber_cmd(TAThread thread,TAInputStream stream)
{
    int proto;
    struct protoent * res;
    
    proto = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = getprotobynumber(proto);
    
    END_TARGET_OPERATION(thread);
    
    writeProtoent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getprotoent_cmd(TAThread thread,TAInputStream stream)
{
    struct protoent * res;
    
    START_TARGET_OPERATION(thread);
    
    res = getprotoent();
    
    END_TARGET_OPERATION(thread);
    
    writeProtoent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



static TACommandVerdict setprotoent_cmd(TAThread thread,TAInputStream stream)
{
    int stayopen;
    
    START_TARGET_OPERATION(thread);
    
    setprotoent(stayopen);
    
    END_TARGET_OPERATION(thread);
    
    /* Void */
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/*******/


static TACommandVerdict freeaddrinfo_cmd(TAThread thread,TAInputStream stream)
{
    struct addrinfo * ai;
    
    ai = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    freeaddrinfo(ai);
    
    END_TARGET_OPERATION(thread);
    
    /* Void */
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getaddrinfo_cmd(TAThread thread,TAInputStream stream)
{
    char *nodename;
    char *servname;
    struct addrinfo * hints;
    struct addrinfo * resptr;
    struct addrinfo ** res = &resptr;
    int is_null;
    int result;
    
    nodename = readString(&stream);
    servname = readString(&stream);
    hints = readPointer(&stream);
    is_null = readInt(&stream);
    if(!is_null)
        resptr = readPointer(&stream);
    else
        res = NULL;
    
    START_TARGET_OPERATION(thread);
    
    result = getaddrinfo(nodename, servname, hints, res);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, result);
    if(!is_null)
        writePointer(thread, resptr);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/*******/

static TACommandVerdict getnameinfo_cmd(TAThread thread,TAInputStream stream)
{
    struct sockaddr *sa;
    socklen_t salen;
    char * buf;
    int buf_len;
    char *node = NULL;
    socklen_t nodelen;
    char *service = NULL;
    socklen_t servicelen;
    int flags;
    int res;
    
    sa = readSockaddr(&stream, &salen);
    
    node = readString(&stream);
    nodelen = readUInt(&stream);
    if(node)
    {
        if(nodelen>0)
            buf_len = nodelen;
        else
            buf_len = strlen(node)+1;
        buf = (char*)ta_alloc_memory(buf_len);
        strncpy(buf, node, buf_len);
        node = buf;
    }
    
    service = readString(&stream);
    servicelen = readUInt(&stream);
    if(service)
    {
        if(servicelen>0)
            buf_len = servicelen;
        else
            buf_len = strlen(service)+1;
        buf = (char*)ta_alloc_memory(buf_len);
        strncpy(buf, service, buf_len);
        service = buf;
    }
    
    flags = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    //ta_debug_printf("0x%x %d", sa, salen);
    h_errno = 0;
    res = getnameinfo(sa, salen, node, nodelen, service, servicelen, flags);
    
    ta_debug_printf("  res:%i[%s]; node:%s; service:%s; h_errno:%i\n", res, (res==0?"Ok":gai_strerror(res)),node, service, h_errno);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, node);
    writeString(thread, service);
    sendResponse(thread);
    
    if(sa)
        ta_dealloc_memory(sa);
    if(node)
        ta_dealloc_memory(node);
    if(service)
        ta_dealloc_memory(service);
    
    return taDefaultVerdict;
}


/*******/


static TACommandVerdict gethostbyaddr_cmd(TAThread thread,TAInputStream stream)
{
    void *addr;
    socklen_t len;
    int type;
    struct hostent * res;    
    
    addr = readPointer(&stream);
    len = readUInt(&stream);
    type = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = gethostbyaddr(addr, len, type);
    
    END_TARGET_OPERATION(thread);
    
    writeHostent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict gethostbyname_cmd(TAThread thread,TAInputStream stream)
{
    char * name;
    struct hostent * res;
    
    name = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = gethostbyname(name);
    
    END_TARGET_OPERATION(thread);
    
    writeHostent(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/*******/


static TACommandVerdict gai_strerror_cmd(TAThread thread,TAInputStream stream)
{
    int ecode;
    char * res;
    
    ecode = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = gai_strerror(ecode);
    
    END_TARGET_OPERATION(thread);
    
    writeString(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict __h_errno_location_cmd(TAThread thread,TAInputStream stream)
{
    int * res;
    
    START_TARGET_OPERATION(thread);
    
    res = __h_errno_location();
    
    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict read_addrinfo_cmd(TAThread thread,TAInputStream stream)
{
    struct addrinfo * ai;
    
    ai = readPointer(&stream);
    
    writeInt(thread, ai->ai_flags);
    writeInt(thread, ai->ai_family);
    writeInt(thread, ai->ai_socktype);
    writeInt(thread, ai->ai_protocol);
    writeUInt(thread, ai->ai_addrlen);
    writeSockaddr(thread, ai->ai_addr);
    writeString(thread, ai->ai_canonname);
    writePointer(thread, ai->ai_next);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict create_addrinfo_cmd(TAThread thread,TAInputStream stream)
{
    struct addrinfo * ai;
    
    ai = (struct addrinfo *)ta_alloc_memory(sizeof(struct addrinfo));
    ai->ai_flags = readInt(&stream);
    ai->ai_family = readInt(&stream);
    ai->ai_socktype = readInt(&stream);
    ai->ai_protocol = readInt(&stream);
    ai->ai_addr = readSockaddr(&stream, &(ai->ai_addrlen));

    ai->ai_canonname = readString(&stream);
    ai->ai_next = readPointer(&stream);
    
    writePointer(thread, ai);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict write_addrinfo_cmd(TAThread thread,TAInputStream stream)
{
    struct addrinfo * ai;
    
    ai = (struct addrinfo *)readPointer(&stream);
    ai->ai_flags = readInt(&stream);
    ai->ai_family = readInt(&stream);
    ai->ai_socktype = readInt(&stream);
    ai->ai_protocol = readInt(&stream);
    ai->ai_addr = readSockaddr(&stream, &(ai->ai_addrlen));
    ai->ai_canonname = readString(&stream);
    ai->ai_next = readPointer(&stream); 
    
    writeString(thread,"Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_netdb_commands(void)
{
    ta_register_command("endservent",endservent_cmd);
    ta_register_command("getservbyname",getservbyname_cmd);
    ta_register_command("getservbyport",getservbyport_cmd);
    ta_register_command("getservent",getservent_cmd);
    ta_register_command("setservent",setservent_cmd);

    ta_register_command("endprotoent",endprotoent_cmd);
    ta_register_command("getprotobyname",getprotobyname_cmd);
    ta_register_command("getprotobynumber",getprotobynumber_cmd);
    ta_register_command("getprotoent",getprotoent_cmd);
    ta_register_command("setprotoent",setprotoent_cmd);

    ta_register_command("freeaddrinfo",freeaddrinfo_cmd);
    ta_register_command("getaddrinfo",getaddrinfo_cmd);

    ta_register_command("getnameinfo",getnameinfo_cmd);

    ta_register_command("gethostbyaddr",gethostbyaddr_cmd);
    ta_register_command("gethostbyname",gethostbyname_cmd);

    ta_register_command("gai_strerror",gai_strerror_cmd);
    ta_register_command("__h_errno_location",__h_errno_location_cmd);
    
    /**/
    ta_register_command("read_addrinfo",read_addrinfo_cmd);    
    ta_register_command("create_addrinfo",create_addrinfo_cmd);
    ta_register_command("write_addrinfo",write_addrinfo_cmd);
}

