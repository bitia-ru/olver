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


#include "socket/rpc/pmap_agent.h"
#include "socket/socket/socket_agent.h"
#include <stdlib.h>
#include <rpc/pmap_clnt.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pmap_getport_cmd(TAThread thread,TAInputStream stream)
{
    u_short res;
    struct sockaddr_in * addr;
    u_long prognum, versnum, protocol;
    socklen_t length;
    
    addr = readSockaddr(&stream, &length);
    prognum  = readULong(&stream);
    versnum  = readULong(&stream);
    protocol = readULong(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = pmap_getport(addr, prognum, versnum, protocol);
    
    END_TARGET_OPERATION(thread);
    
    writeUShort(thread, res);
    sendResponse(thread);
    
    if(addr)
        ta_dealloc_memory(addr);
    
    return taDefaultVerdict;
}

static TACommandVerdict pmap_set_cmd(TAThread thread,TAInputStream stream)
{
    bool_t res;
    u_long program, version;
    int protocol;
    u_short port;
    
    program  = readULong(&stream);
    version  = readULong(&stream);
    protocol = readInt(&stream);
    port = readUShort(&stream);
    
    START_TARGET_OPERATION(thread);
    
    ta_debug_printf("program:%d; version:%d; protocol:%d; port:%d;\n",program, version, protocol, port);
    res = pmap_set(program, version, protocol, port);
    system("/usr/sbin/rpcinfo -p localhost");
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict pmap_unset_cmd(TAThread thread,TAInputStream stream)
{
    bool_t res;
    u_long prognum, versnum;
    
    prognum  = readULong(&stream);
    versnum  = readULong(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = pmap_unset(prognum, versnum);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_rpc_pmap_commands(void)
{
    ta_register_command("pmap_getport",pmap_getport_cmd);
    ta_register_command("pmap_set",pmap_set_cmd);
    ta_register_command("pmap_unset",pmap_unset_cmd);
}

