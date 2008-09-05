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


#include "socket/rpc/svc_agent.h"
#include <rpc/rpc.h>
#include <string.h>


/********************************************************************/
/**                       Service functions                        **/
/********************************************************************/
enum {
    PROC_NULL,
    PROC_ADD_NUM,
    PROC_REPLACE_STR,
    PROC_ERR_AUTH,
    PROC_ERR_DECODE,
    PROC_ERR_NOPROC,
    PROC_ERR_NOPROG,
    PROC_ERR_PROGVERS,
    PROC_ERR_SYSTEMERR,
    PROC_ERR_WEAKAUTH
};

typedef struct progvers {
    rpcvers_t low_vers;
    rpcvers_t high_vers;
} progvers;

bool_t xdr_progvers(XDR* xdrs, void* inbuf)
{
    progvers* buf = (progvers*)inbuf;
    return xdr_u_long(xdrs, &(buf->low_vers)) && xdr_u_long(xdrs, &(buf->high_vers));
}

int test_svc_proc(struct svc_req* request, SVCXPRT* xprt)
{
    int in, out;
    char* in_str;
    enum auth_stat a_stat;
    progvers vers;
    int res;

    switch (request->rq_proc)
    {
        case PROC_NULL:
            // Mark that we actually call svc_sendreply
            ta_debug_printf("search for svc_sendreply (%u)...\n", (unsigned long)pthread_self());
            res = svc_sendreply(xprt, (xdrproc_t)xdr_void, (char*)NULL);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_NULL sendreply failed!\n");
                // Mark that we actually call svcerr_systemerr
                ta_debug_printf("search for svcerr_systemerr (%u)...\n", (unsigned long)pthread_self());
                svcerr_systemerr(xprt);
                return -1;
            }
            break;
        case PROC_ADD_NUM:
            res = svc_getargs(xprt, (xdrproc_t)xdr_int, (char*)&in);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_ADD_NUM getargs failed!\n");
                // Mark that we actually call svcerr_decode
                ta_debug_printf("search for svcerr_decode (%u)...\n", (unsigned long)pthread_self());
                svcerr_decode(xprt);
                return -1;
            }
            out = in + 123;
            // Mark that we actually call svc_sendreply
            ta_debug_printf("search for svc_sendreply (%u)...\n", (unsigned long)pthread_self());
            res = svc_sendreply(xprt, (xdrproc_t)xdr_int, (char*)&out);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_ADD_NUM sendreply failed!\n");
                // Mark that we actually call svcerr_systemerr
                ta_debug_printf("search for svcerr_systemerr (%u)...\n", (unsigned long)pthread_self());
                svcerr_systemerr(xprt);
                return -1;
            }
            break;
        case PROC_REPLACE_STR:
            in_str = NULL;
            res = svc_getargs(xprt, (xdrproc_t)xdr_wrapstring, (char*)&in_str);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_REPLACE_STR getargs failed!\n");
                // Mark that we actually call svcerr_decode
                ta_debug_printf("search for svcerr_decode (%u)...\n", (unsigned long)pthread_self());
                svcerr_decode(xprt);
                return -1;
            }
            in = strlen(in_str);
            if (in >= 3)
            {
                in_str[in - 1] = 'z';
                in_str[in - 2] = 'y';
                in_str[in - 3] = 'x';
            }
            // Mark that we actually call svc_sendreply
            ta_debug_printf("search for svc_sendreply (%u)...\n", (unsigned long)pthread_self());
            res = svc_sendreply(xprt, (xdrproc_t)xdr_wrapstring, (char*)&in_str);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_REPLACE_STR sendreply failed!\n");
                // Mark that we actually call svcerr_systemerr
                ta_debug_printf("search for svcerr_systemerr (%u)...\n", (unsigned long)pthread_self());
                svcerr_systemerr(xprt);
                return -1;
            }
            res = svc_freeargs(xprt, (xdrproc_t)xdr_wrapstring, (char*)&in_str);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_REPLACE_STR freeargs failed!\n");
                return -1;
            }
            break;
        case PROC_ERR_AUTH:
            res = svc_getargs(xprt, (xdrproc_t)xdr_int, (char*)&a_stat);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_ERR_AUTH getargs failed!\n");
                // Mark that we actually call svcerr_decode
                ta_debug_printf("search for svcerr_decode (%u)...\n", (unsigned long)pthread_self());
                svcerr_decode(xprt);
                return -1;
            }
            // Mark that we actually call svcerr_auth
            ta_debug_printf("search for svcerr_auth (%u)...\n", (unsigned long)pthread_self());
            svcerr_auth(xprt, a_stat);
            break;
        case PROC_ERR_DECODE:
            // Mark that we actually call svcerr_decode
            ta_debug_printf("search for svcerr_decode (%u)...\n", (unsigned long)pthread_self());
            svcerr_decode(xprt);
            break;
        case PROC_ERR_NOPROC:
            // Mark that we actually call svcerr_noproc
            ta_debug_printf("search for svcerr_noproc (%u)...\n", (unsigned long)pthread_self());
            svcerr_noproc(xprt);
            break;
        case PROC_ERR_NOPROG:
            // Mark that we actually call svcerr_noprog
            ta_debug_printf("search for svcerr_noprog (%u)...\n", (unsigned long)pthread_self());
            svcerr_noprog(xprt);
            break;
        case PROC_ERR_PROGVERS:
            res = svc_getargs(xprt, (xdrproc_t)xdr_progvers, (char*)&vers);
            if (!res)
            {
                ta_debug_printf("socket.prc.svc: PROC_ERR_PROGVERS getargs failed!\n");
                // Mark that we actually call svcerr_decode
                ta_debug_printf("search for svcerr_decode (%u)...\n", (unsigned long)pthread_self());
                svcerr_decode(xprt);
                return -1;
            }
            // Mark that we actually call svcerr_progvers
            ta_debug_printf("search for svcerr_progvers (%u)...\n", (unsigned long)pthread_self());
            svcerr_progvers(xprt, vers.low_vers, vers.high_vers);
            break;
        case PROC_ERR_SYSTEMERR:
            // Mark that we actually call svcerr_systemerr
            ta_debug_printf("search for svcerr_systemerr (%u)...\n", (unsigned long)pthread_self());
            svcerr_systemerr(xprt);
            break;
        case PROC_ERR_WEAKAUTH:
            // Mark that we actually call svcerr_weakauth
            ta_debug_printf("search for svcerr_weakauth (%u)...\n", (unsigned long)pthread_self());
            svcerr_weakauth(xprt);
            break;
        default:
            ta_debug_printf("socket.prc.svc: Unsupported command received!\n");
            // Mark that we actually call svcerr_noproc
            ta_debug_printf("search for svcerr_noproc (%u)...\n", (unsigned long)pthread_self());
            svcerr_noproc(xprt);
    }
    return 0;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict svc_getreqset_cmd(TAThread thread, TAInputStream stream)
{
    fd_set* rdfds;

    // Prepare
    rdfds = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svc_getreqset(rdfds);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_auth_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;
    enum auth_stat why;

    // Prepare
    xprt = readPointer(&stream);
    why = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_auth(xprt, why);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_decode_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;

    // Prepare
    xprt = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_decode(xprt);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_noproc_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;

    // Prepare
    xprt = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_noproc(xprt);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_noprog_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;

    // Prepare
    xprt = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_noprog(xprt);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_progvers_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;
    rpcvers_t low_vers;
    rpcvers_t high_vers;

    // Prepare
    xprt = readPointer(&stream);
    low_vers = readULong(&stream);
    high_vers = readULong(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_progvers(xprt, low_vers, high_vers);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_systemerr_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;

    // Prepare
    xprt = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_systemerr(xprt);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcerr_weakauth_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;

    // Prepare
    xprt = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    svcerr_weakauth(xprt);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svc_freeargs_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;
    xdrproc_t inproc;
    char* in;
    bool_t res;

    // Prepare
    xprt = readPointer(&stream);
    inproc = readPointer(&stream);
    in = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = svc_freeargs(xprt, inproc, in);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svc_getargs_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;
    xdrproc_t inproc;
    char* in;
    bool_t res;

    // Prepare
    xprt = readPointer(&stream);
    inproc = readPointer(&stream);
    in = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = svc_getargs(xprt, inproc, in);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svc_register_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;
    rpcprog_t prog;
    rpcvers_t vers;
    __dispatch_fn_t dispatch;
    rpcprot_t protocol;
    bool_t res;

    // Prepare
    xprt = readPointer(&stream);
    prog = readULong(&stream);
    vers = readULong(&stream);
    dispatch = readPointer(&stream);
    protocol = readULong(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = svc_register(xprt, prog, vers, dispatch, protocol);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svc_run_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);

    // Execute
    svc_run();

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "svc_run_return");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svc_sendreply_cmd(TAThread thread, TAInputStream stream)
{
    SVCXPRT* xprt;
    xdrproc_t outproc;
    caddr_t out;
    bool_t res;

    // Prepare
    xprt = readPointer(&stream);
    outproc = readPointer(&stream);
    out = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = svc_sendreply(xprt, outproc, out);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svctcp_create_cmd(TAThread thread, TAInputStream stream)
{
    int sock;
    u_int sendsize;
    u_int recvsize;
    SVCXPRT* res;

    // Prepare
    sock = readInt(&stream);
    sendsize = readUInt(&stream);
    recvsize = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = svctcp_create(sock, sendsize, recvsize);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict svcudp_create_cmd(TAThread thread, TAInputStream stream)
{
    int sock;
    SVCXPRT* res;

    // Prepare
    sock = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = svcudp_create(sock);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                       Service functions                        **/
/********************************************************************/

static void* get_func_addr_socket_rpc_svc_clnt(char* func_name)
{
    void* res;

#define BEGIN_CHECK()                                   \
    if ((func_name == NULL) || (func_name[0] == '\0'))  \
        res = NULL

#define ADD_FUNC(func)                                  \
    else if (!strcmp(func_name, #func))                 \
        res = func

#define END_CHECK()                                     \
    else                                                \
        res = NULL

    BEGIN_CHECK();
        ADD_FUNC(test_svc_proc);
        ADD_FUNC(xdr_progvers);
        ADD_FUNC(xdr_void);
        ADD_FUNC(xdr_int);
        ADD_FUNC(xdr_wrapstring);
    END_CHECK();

    return res;
}

static TACommandVerdict get_func_addr_socket_rpc_svc_clnt_cmd(TAThread thread, TAInputStream stream)
{
    void* res;

    START_TARGET_OPERATION(thread);

    res = get_func_addr_socket_rpc_svc_clnt(readString(&stream));

    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict get_sizeof_progvers_cmd(TAThread thread, TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    writeSize(thread, sizeof(progvers));
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_progvers_cmd(TAThread thread, TAInputStream stream)
{
    progvers* buf;
    rpcvers_t low_vers;
    rpcvers_t high_vers;

    buf = readPointer(&stream);
    low_vers = readULong(&stream);
    high_vers = readULong(&stream);

    START_TARGET_OPERATION(thread);

    buf->low_vers = low_vers;
    buf->high_vers = high_vers;

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_rpc_svc_commands(void)
{
    ta_register_command("svc_getreqset", svc_getreqset_cmd);
    ta_register_command("svcerr_auth", svcerr_auth_cmd);
    ta_register_command("svcerr_decode", svcerr_decode_cmd);
    ta_register_command("svcerr_noproc", svcerr_noproc_cmd);
    ta_register_command("svcerr_noprog", svcerr_noprog_cmd);
    ta_register_command("svcerr_progvers", svcerr_progvers_cmd);
    ta_register_command("svcerr_systemerr", svcerr_systemerr_cmd);
    ta_register_command("svcerr_weakauth", svcerr_weakauth_cmd);

    ta_register_command("svc_register", svc_register_cmd);
    ta_register_command("svc_run", svc_run_cmd);
    ta_register_command("svc_sendreply", svc_sendreply_cmd);
    ta_register_command("svctcp_create", svctcp_create_cmd);
    ta_register_command("svcudp_create", svcudp_create_cmd);

    ta_register_command("func_addr_socket_rpc_svc_clnt", get_func_addr_socket_rpc_svc_clnt_cmd);
    ta_register_command("get_sizeof_progvers", get_sizeof_progvers_cmd);
    ta_register_command("init_progvers", init_progvers_cmd);
}
