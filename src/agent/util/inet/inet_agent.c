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


#include "util/inet/inet_agent.h"
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
unsigned long readInAddrT(TAInputStream* stream)
{
    char data;
    size_t i, size;
    unsigned long res=0;

    verifyType_TAInputStream(stream,"inaddrt");

    size = readSize(stream);

    for( i = 0; i < size; i++ )
    {
        data = readChar(stream);
        res=(res<<8)+(unsigned char)data;
    }

    return res;
}
static TACommandVerdict inet_addr_cmd(TAThread thread,TAInputStream stream)
{
    char* in_val;
    unsigned long res;
    int i;
    char out_val[5];

    // Prepare

    in_val= readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute

    res = ntohl(inet_addr(in_val));

    END_TARGET_OPERATION(thread);

    // Response

    for(i=0;i<4;i++)
    {
        out_val[3-i]=(res&255);
        res>>=8;
    }
    out_val[i]='\0';

    writeByteArray(thread, out_val, 4);


    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict inet_ntoa_cmd(TAThread thread,TAInputStream stream)
{
    int i;
    char* res;
    struct in_addr param;

    // Prepare

    param.s_addr=readInAddrT(&stream);


    START_TARGET_OPERATION(thread);

    // Execute

    res = inet_ntoa(param);

    END_TARGET_OPERATION(thread);

    // Response

    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inet_ntop_cmd(TAThread thread,TAInputStream stream)
{
    int af, size;
    char *dst;
    const char *res;
    void* src;
    // Prepare

    af=readInt(&stream);
    src=(void*)readPointer(&stream);
    dst=(char*)readPointer(&stream);
    size=readInt(&stream);


    START_TARGET_OPERATION(thread);

    // Execute
    errno=0;
    res = inet_ntop(af, src, dst, size);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, (char*)res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict inet_pton_cmd(TAThread thread,TAInputStream stream)
{
    int af, size;
    char *dst;
    void* src;
    int res;
    // Prepare

    af=readInt(&stream);
    src=(char*)readPointer(&stream);
    dst=(void*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno=0;
    res = inet_pton(af, src, dst);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_inet_commands(void)
{
    ta_register_command("inet_addr",inet_addr_cmd);
    ta_register_command("inet_ntoa",inet_ntoa_cmd);
    ta_register_command("inet_ntop",inet_ntop_cmd);
    ta_register_command("inet_pton",inet_pton_cmd);
}

