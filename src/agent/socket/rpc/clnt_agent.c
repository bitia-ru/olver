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


#include "socket/rpc/clnt_agent.h"
#include <rpc/rpc.h>

void readTimeVal(TAInputStream* stream, struct timeval* value);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict authnone_create_cmd(TAThread thread, TAInputStream stream)
{
    AUTH* res;

    // Prepare

    START_TARGET_OPERATION(thread);

    // Execute
    res = authnone_create();

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_create_cmd(TAThread thread, TAInputStream stream)
{
    char* host;
    u_long prognum;
    u_long versnum;
    char* nettype;
    CLIENT* res;

    // Prepare
    host = readString(&stream);
    prognum = readULong(&stream);
    versnum = readULong(&stream);
    nettype = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_create(host, prognum, versnum, nettype);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_pcreateerror_cmd(TAThread thread, TAInputStream stream)
{
    char* s;

    // Prepare
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    clnt_pcreateerror(s);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_perrno_cmd(TAThread thread, TAInputStream stream)
{
    enum clnt_stat stat;
    
    // Prepare
    stat = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    clnt_perrno(stat);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_perror_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;
    char* s;

    // Prepare
    clnt = readPointer(&stream);
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    clnt_perror(clnt, s);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_spcreateerror_cmd(TAThread thread, TAInputStream stream)
{
    char* s;
    char* res;

    // Prepare
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_spcreateerror(s);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_sperrno_cmd(TAThread thread, TAInputStream stream)
{
    enum clnt_stat stat;
    char* res;

    // Prepare
    stat = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_sperrno(stat);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_sperror_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;
    char* s;
    char* res;

    // Prepare
    clnt = readPointer(&stream);
    s = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_sperror(clnt, s);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_control_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;
    u_int req;
    char* info;
    bool_t res;

    // Prepare
    clnt = readPointer(&stream);
    req = readUInt(&stream);
    info = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_control(clnt, req, info);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_destroy_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;

    // Prepare
    clnt = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    clnt_destroy(clnt);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_freeres_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;
    xdrproc_t outproc;
    caddr_t out;
    bool_t res;

    // Prepare
    clnt = readPointer(&stream);
    outproc = readPointer(&stream);
    out = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_freeres(clnt, outproc, out);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_geterr_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;
    struct rpc_err* errp;

    // Prepare
    clnt = readPointer(&stream);
    errp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    clnt_geterr(clnt, errp);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict clnt_call_cmd(TAThread thread, TAInputStream stream)
{
    CLIENT* clnt;
    u_long procnum;
    xdrproc_t inproc;
    caddr_t in;
    xdrproc_t outproc;
    caddr_t out;
    struct timeval tout;
    enum clnt_stat res;

    // Prepare
    clnt = readPointer(&stream);
    procnum = readULong(&stream);
    inproc = readPointer(&stream);
    in = readPointer(&stream);
    outproc = readPointer(&stream);
    out = readPointer(&stream);
    readTimeVal(&stream, &tout);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clnt_call(clnt, procnum, inproc, in, outproc, out, tout);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_rpc_clnt_commands(void)
{
    ta_register_command("authnone_create", authnone_create_cmd);
    ta_register_command("clnt_create", clnt_create_cmd);
    ta_register_command("clnt_pcreateerror", clnt_pcreateerror_cmd);
    ta_register_command("clnt_perrno", clnt_perrno_cmd);
    ta_register_command("clnt_perror", clnt_perror_cmd);
    ta_register_command("clnt_spcreateerror", clnt_spcreateerror_cmd);
    ta_register_command("clnt_sperrno", clnt_sperrno_cmd);
    ta_register_command("clnt_sperror", clnt_sperror_cmd);
    ta_register_command("clnt_control", clnt_control_cmd);
//    ta_register_command("clnt_abort", clnt_abort_cmd);
    ta_register_command("clnt_destroy", clnt_destroy_cmd);
    ta_register_command("clnt_freeres", clnt_freeres_cmd);
    ta_register_command("clnt_geterr", clnt_geterr_cmd);
    ta_register_command("clnt_call", clnt_call_cmd);
}
