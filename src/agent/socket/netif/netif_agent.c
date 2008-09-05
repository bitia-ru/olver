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


#include "socket/netif/netif_agent.h"
#include <net/if.h>
#include <errno.h>
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict if_freenameindex_cmd(TAThread thread,TAInputStream stream)
{
    struct if_nameindex * ptr;
    
    ptr = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    if_freenameindex(ptr);
    
    END_TARGET_OPERATION(thread);
    
    writeString(thread,"Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict if_indextoname_cmd(TAThread thread,TAInputStream stream)
{
    unsigned int ifindex;
    char * ptr;
    char * res;
    
    ifindex = readUInt(&stream);
    ptr = readPointer(&stream);
    errno = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = if_indextoname(ifindex, ptr);
    
    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict if_nameindex_cmd(TAThread thread,TAInputStream stream)
{
    struct if_nameindex * res;
    
    errno = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = if_nameindex();
    
    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict if_nametoindex_cmd(TAThread thread,TAInputStream stream)
{
    char * ifname;
    unsigned int res;
    
    ifname = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = if_nametoindex(ifname);
    
    END_TARGET_OPERATION(thread);
    
    writeUInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict read_ifnameindex_cmd(TAThread thread,TAInputStream stream)
{
    struct if_nameindex * ptr;
    unsigned int if_index;
    char *if_name;
    
    ptr = (struct if_nameindex *)readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    if_index = ptr->if_index;
    if_name = ptr->if_name;
    
    END_TARGET_OPERATION(thread);
    
    writeUInt(thread, if_index);
    writeString(thread, if_name);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_netif_commands(void)
{
    ta_register_command("if_freenameindex",if_freenameindex_cmd);
    ta_register_command("if_indextoname",if_indextoname_cmd);
    ta_register_command("if_nameindex",if_nameindex_cmd);
    ta_register_command("if_nametoindex",if_nametoindex_cmd);
    
    ta_register_command("read_ifnameindex",read_ifnameindex_cmd);
}

