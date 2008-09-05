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

#include <arpa/inet.h>
#include "socket/netdata/netdata_agent.h"
#include "common/ta_stream.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict htonl_cmd(TAThread thread,TAInputStream stream)
{
    uint32_t hostlong, res;
    char* tmp;
   
    // Prepare
    hostlong=readUInt32(&stream);

    START_TARGET_OPERATION(thread);
    res=htonl(hostlong);
    END_TARGET_OPERATION(thread);
    
    tmp=&res;
    // Response
    writeChar(thread, tmp[0]);
    writeChar(thread, tmp[1]);
    writeChar(thread, tmp[2]);
    writeChar(thread, tmp[3]);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict htons_cmd(TAThread thread,TAInputStream stream)
{
    uint16_t hostshort, res;
    char* tmp;
   
    // Prepare
    hostshort=readUInt16(&stream);
    
    START_TARGET_OPERATION(thread);
    res=htons(hostshort);
    END_TARGET_OPERATION(thread);
    
    // Response
    tmp=&res;
    writeChar(thread, tmp[0]);
    writeChar(thread, tmp[1]);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ntohl_cmd(TAThread thread,TAInputStream stream)
{
    uint32_t netlong, res;
    char arr[4];
   
    // Prepare
    arr[0]=readChar(&stream);
    arr[1]=readChar(&stream);
    arr[2]=readChar(&stream);
    arr[3]=readChar(&stream);

    netlong=*((uint32_t*)arr);
    //netlong=readUInt32(&stream);

    START_TARGET_OPERATION(thread);
    res=ntohl(netlong);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeUInt32(thread, res);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ntohs_cmd(TAThread thread,TAInputStream stream)
{
    uint16_t netshort, res;
    char arr[4];
   
    // Prepare
    arr[0]=readChar(&stream);
    arr[1]=readChar(&stream);

    netshort=*((uint16_t*)arr);   
    // Prepare
    //netshort=readUInt16(&stream);

    START_TARGET_OPERATION(thread);
    res=ntohs(netshort);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeUInt16(thread, res);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_netdata_commands(void)
{
    ta_register_command("htonl",htonl_cmd);
    ta_register_command("htons",htons_cmd);
    ta_register_command("ntohl",ntohl_cmd);
    ta_register_command("ntohs",ntohs_cmd);
}

