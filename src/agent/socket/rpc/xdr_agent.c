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


#include "socket/rpc/xdr_agent.h"
#include <rpc/rpc.h>
#include <string.h>

/*
 * These functions are present in the LSB standard, but are not defined in its headers.
 */
bool_t xdr_accepted_reply(XDR *xdrs, struct accepted_reply *ar);
bool_t xdr_rejected_reply(XDR *xdrs, struct rejected_reply *rr);
bool_t xdr_callmsg(XDR *xdrs, struct rpc_msg *cmsg);
bool_t xdr_replymsg(XDR *xdrs, struct rpc_msg *rmsg);
#define xdr_destroy(xdrs)                       \
    do {                                        \
        if ((xdrs)->x_ops->x_destroy)           \
            (*(xdrs)->x_ops->x_destroy)(xdrs);  \
    } while (0)

#define XDRREC_EXTENDED         0

#ifdef XDRREC_EXTENDED
/*
 * These functions are not present in the LSB standard, but are necessary for the testing.
 */
bool_t xdrrec_endofrecord(XDR *xdrs, bool_t sendnow);
bool_t xdrrec_skiprecord(XDR *xdrs);
#endif

/********************************************************************/
/**                       Service functions                        **/
/********************************************************************/
int readfp(FILE* fp, char* buf, unsigned int n)
{
    int nrd;
    nrd = fread(buf, 1, n, fp);
    if (nrd == 0)
        nrd = -1;
    return nrd;
}

int writefp(FILE* fp, char* buf, unsigned int n)
{
    int nwr;
    nwr = fwrite(buf, 1, n, fp);
    if (nwr == 0)
        nwr = -1;
    return nwr;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict xdr_accepted_reply_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    struct accepted_reply* ar;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    ar = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_accepted_reply(xdrs, ar);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_array_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    caddr_t arrp;
    u_int sizep;
    u_int maxsize;
    u_int elsize;
    xdrproc_t elproc;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    arrp = readPointer(&stream);
    sizep = readUInt(&stream);
    maxsize = readUInt(&stream);
    elsize = readUInt(&stream);
    elproc = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_array(xdrs, &arrp, &sizep, maxsize, elsize, elproc);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, arrp);
    writeUInt(thread, sizep);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_bool_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    bool_t bp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    bp = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_bool(xdrs, &bp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, bp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_bytes_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char* sp;
    u_int sizep;
    u_int maxsize;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    sp = readPointer(&stream);
    sizep = readUInt(&stream);
    maxsize = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_bytes(xdrs, &sp, &sizep, maxsize);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, sp);
    writeUInt(thread, sizep);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_callhdr_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    struct rpc_msg* chdr;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    chdr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_callhdr(xdrs, chdr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_callmsg_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    struct rpc_msg* cmsg;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    cmsg = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_callmsg(xdrs, cmsg);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_char_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char cp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    cp = readChar(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_char(xdrs, &cp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeChar(thread, cp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_double_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    double dp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    dp = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_double(xdrs, &dp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeDouble(thread, dp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_enum_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    enum_t ep;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    ep = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_enum(xdrs, &ep);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, ep);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_float_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    float fp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    fp = readFloat(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_float(xdrs, &fp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeFloat(thread, fp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_free_cmd(TAThread thread, TAInputStream stream)
{
    xdrproc_t proc;
    char* objp;

    // Prepare
    proc = readPointer(&stream);
    objp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    xdr_free(proc, (char*)&objp);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, objp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_int_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    int ip;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    ip = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_int(xdrs, &ip);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, ip);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_long_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    long lp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    lp = readLong(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_long(xdrs, &lp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeLong(thread, lp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_opaque_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    caddr_t cp;
    u_int cnt;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    cp = readPointer(&stream);
    cnt = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_opaque(xdrs, cp, cnt);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_opaque_auth_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    struct opaque_auth* ap;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    ap = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_opaque_auth(xdrs, ap);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_pointer_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char* objpp;
    u_int objsize;
    xdrproc_t xdrobj;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    objpp = readPointer(&stream);
    objsize = readUInt(&stream);
    xdrobj = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_pointer(xdrs, &objpp, objsize, xdrobj);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, objpp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_reference_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char* pp;
    u_int size;
    xdrproc_t proc;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    pp = readPointer(&stream);
    size = readUInt(&stream);
    proc = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_reference(xdrs, &pp, size, proc);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, pp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_rejected_reply_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    struct rejected_reply* rr;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    rr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_rejected_reply(xdrs, rr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_replymsg_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    struct rpc_msg* rmsg;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    rmsg = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_replymsg(xdrs, rmsg);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_short_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    short sp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    sp = readShort(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_short(xdrs, &sp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeShort(thread, sp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_string_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char* sp;
    u_int maxsize;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    sp = readPointer(&stream);
    maxsize = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_string(xdrs, &sp, maxsize);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, sp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_u_char_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    u_char ucp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    ucp = readUChar(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_u_char(xdrs, &ucp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeUChar(thread, ucp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_u_int_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    u_int up;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    up = readUInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_u_int(xdrs, &up);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeUInt(thread, up);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_u_long_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    u_long ulp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    ulp = readULong(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_u_long(xdrs, &ulp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeULong(thread, ulp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_u_short_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    u_short usp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    usp = readUShort(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_u_short(xdrs, &usp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeUShort(thread, usp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_union_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    enum_t dscmp;
    char* unp;
    struct xdr_discrim* choices;
    xdrproc_t defaultarm;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    dscmp = readInt(&stream);
    unp = readPointer(&stream);
    choices = readPointer(&stream);
    defaultarm = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_union(xdrs, &dscmp, unp, choices, defaultarm);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, dscmp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_vector_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char* arrp;
    u_int size;
    u_int elsize;
    xdrproc_t elproc;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    arrp = readPointer(&stream);
    size = readUInt(&stream);
    elsize = readUInt(&stream);
    elproc = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_vector(xdrs, arrp, size, elsize, elproc);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_void_cmd(TAThread thread, TAInputStream stream)
{
    bool_t res;

    // Prepare

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_void();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_wrapstring_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    char* sp;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);
    sp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdr_wrapstring(xdrs, &sp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writePointer(thread, sp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdrmem_create_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    caddr_t addr;
    u_int size;
    enum xdr_op op;

    // Prepare
    xdrs = readPointer(&stream);
    addr = readPointer(&stream);
    size = readUInt(&stream);
    op = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    xdrmem_create(xdrs, addr, size, op);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdrrec_create_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    u_int sendsz;
    u_int recvsz;
    caddr_t handle;
    enum xdr_op op;

    /* Function declarations from SVID.4 */
    // const int (*readit)(const void *, char *, const int);
    // const int (*writeit)(const void *, const char *, const int);

    /* Function declarations from LSB */
    int (*readit)(char*, char*, int);
    int (*writeit)(char*, char*, int);

    // Prepare
    xdrs = readPointer(&stream);
    sendsz = readUInt(&stream);
    recvsz = readUInt(&stream);
    handle = readPointer(&stream);
    readit = readPointer(&stream);
    writeit = readPointer(&stream);
    op = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    xdrrec_create(xdrs, sendsz, recvsz, handle, readit, writeit);
    xdrs->x_op = op;

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdrrec_eof_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;
    bool_t res;

    // Prepare
    xdrs = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = xdrrec_eof(xdrs);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdr_destroy_cmd(TAThread thread, TAInputStream stream)
{
    XDR* xdrs;

    // Prepare
    xdrs = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    xdr_destroy(xdrs);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict xdrrec_endofrecord_cmd(TAThread thread, TAInputStream stream)
{
    #if XDRRECORD_EXTENDED<=0
        sendException(thread, "Function <i>xdrrec_endofrecord</i>() is not supported. See XDRRECORD_EXTENDED configuration param");
        return taDefaultVerdict;
    #else
        XDR* xdrs;
        int sendnow;
        bool_t res;

        // Prepare
        xdrs = readPointer(&stream);
        sendnow = readInt(&stream);

        START_TARGET_OPERATION(thread);

        // Execute
        res = xdrrec_endofrecord(xdrs, sendnow);

        END_TARGET_OPERATION(thread);

        // Response
        writeInt(thread, res);
        sendResponse(thread);

        return taDefaultVerdict;
    #endif
}

static TACommandVerdict xdrrec_skiprecord_cmd(TAThread thread, TAInputStream stream)
{
    #if XDRRECORD_EXTENDED<=0
        sendException(thread, "Function <i>xdrrec_skiprecord</i>() is not supported. See XDRRECORD_EXTENDED configuration param");
        return taDefaultVerdict;
    #else
        XDR* xdrs;
        bool_t res;

        // Prepare
        xdrs = readPointer(&stream);

        START_TARGET_OPERATION(thread);

        // Execute
        res = xdrrec_skiprecord(xdrs);

        END_TARGET_OPERATION(thread);

        // Response
        writeInt(thread, res);
        sendResponse(thread);

        return taDefaultVerdict;
    #endif
}


/********************************************************************/
/**                       Service functions                        **/
/********************************************************************/

static void* get_func_addr_socket_rpc_xdr(char* func_name)
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
    ADD_FUNC(readfp);
    ADD_FUNC(writefp);
    ADD_FUNC(xdr_accepted_reply);
    ADD_FUNC(xdr_array);
    ADD_FUNC(xdr_bool);
    ADD_FUNC(xdr_bytes);
    ADD_FUNC(xdr_callhdr);
    ADD_FUNC(xdr_callmsg);
    ADD_FUNC(xdr_char);
    ADD_FUNC(xdr_double);
    ADD_FUNC(xdr_enum);
    ADD_FUNC(xdr_float);
    ADD_FUNC(xdr_int);
    ADD_FUNC(xdr_long);
    ADD_FUNC(xdr_opaque);
    ADD_FUNC(xdr_opaque_auth);
    ADD_FUNC(xdr_pointer);
    ADD_FUNC(xdr_reference);
    ADD_FUNC(xdr_rejected_reply);
    ADD_FUNC(xdr_replymsg);
    ADD_FUNC(xdr_short);
    ADD_FUNC(xdr_string);
    ADD_FUNC(xdr_u_char);
    ADD_FUNC(xdr_u_int);
    ADD_FUNC(xdr_u_long);
    ADD_FUNC(xdr_u_short);
    ADD_FUNC(xdr_union);
    ADD_FUNC(xdr_vector);
    ADD_FUNC(xdr_void);
    ADD_FUNC(xdr_wrapstring);
    END_CHECK();

    return res;
}

static TACommandVerdict get_func_addr_socket_rpc_xdr_cmd(TAThread thread, TAInputStream stream)
{
    void* res;

    START_TARGET_OPERATION(thread);

    res = get_func_addr_socket_rpc_xdr(readString(&stream));

    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_xdr_discrim_cmd(TAThread thread, TAInputStream stream)
{
    struct xdr_discrim* xdr_discrim_ptr;
    int value;
    char* proc_name;
    xdrproc_t proc;
    int discrims_ex_num;

    xdr_discrim_ptr = (struct xdr_discrim*)readPointer(&stream);
    value = readInt(&stream);
    proc_name = readString(&stream);
    discrims_ex_num = readInt(&stream);
    proc = (xdrproc_t)get_func_addr_socket_rpc_xdr(proc_name);

    START_TARGET_OPERATION(thread);

    xdr_discrim_ptr[discrims_ex_num].value = value;
    xdr_discrim_ptr[discrims_ex_num].proc = proc;

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_null_accepted_reply_cmd(TAThread thread, TAInputStream stream)
{
    struct accepted_reply* ar;
    int minimal;

    ar = (struct accepted_reply*)readPointer(&stream);
    minimal = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if (!minimal)
    {
        memset(ar, 0, sizeof(struct accepted_reply));
        ar->ar_results.where = NULL;
    }
    ar->ar_results.proc = (xdrproc_t) xdr_void;

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_null_rejected_reply_cmd(TAThread thread, TAInputStream stream)
{
    struct rejected_reply* rr;

    rr = (struct rejected_reply*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    memset(rr, 0, sizeof(struct rejected_reply));

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_null_opaque_auth_cmd(TAThread thread, TAInputStream stream)
{
    struct opaque_auth* ap;

    ap = (struct opaque_auth*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    memset(ap, 0, sizeof(struct opaque_auth));

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_call_rpc_msg_cmd(TAThread thread, TAInputStream stream)
{
    struct rpc_msg* msg;

    msg = (struct rpc_msg*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    memset(msg, 0, sizeof(struct rpc_msg));
    msg->rm_direction = CALL;
    msg->rm_call.cb_rpcvers = 2;
    msg->rm_call.cb_prog = 0;
    msg->rm_call.cb_vers = 0;

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict init_reply_rpc_msg_cmd(TAThread thread, TAInputStream stream)
{
    struct rpc_msg* msg;

    msg = (struct rpc_msg*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    memset(msg, 0, sizeof(struct rpc_msg));
    msg->rm_direction = REPLY;
    msg->rm_reply.rp_stat = MSG_DENIED;
    msg->rm_reply.rp_rjct.rj_stat = AUTH_ERROR;
    msg->rm_reply.rp_rjct.rj_why = AUTH_FAILED;

    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_rpc_xdr_commands(void)
{
    ta_register_command("xdr_accepted_reply", xdr_accepted_reply_cmd);
    ta_register_command("xdr_array", xdr_array_cmd);
    ta_register_command("xdr_bool", xdr_bool_cmd);
    ta_register_command("xdr_bytes", xdr_bytes_cmd);
    ta_register_command("xdr_callhdr", xdr_callhdr_cmd);
    ta_register_command("xdr_callmsg", xdr_callmsg_cmd);
    ta_register_command("xdr_char", xdr_char_cmd);
    ta_register_command("xdr_double", xdr_double_cmd);
    ta_register_command("xdr_enum", xdr_enum_cmd);
    ta_register_command("xdr_float", xdr_float_cmd);
    ta_register_command("xdr_free", xdr_free_cmd);
    ta_register_command("xdr_int", xdr_int_cmd);
    ta_register_command("xdr_long", xdr_long_cmd);
    ta_register_command("xdr_opaque", xdr_opaque_cmd);
    ta_register_command("xdr_opaque_auth", xdr_opaque_auth_cmd);
    ta_register_command("xdr_pointer", xdr_pointer_cmd);
    ta_register_command("xdr_reference", xdr_reference_cmd);
    ta_register_command("xdr_rejected_reply", xdr_rejected_reply_cmd);
    ta_register_command("xdr_replymsg", xdr_replymsg_cmd);
    ta_register_command("xdr_short", xdr_short_cmd);
    ta_register_command("xdr_string", xdr_string_cmd);
    ta_register_command("xdr_u_char", xdr_u_char_cmd);
    ta_register_command("xdr_u_int", xdr_u_int_cmd);
    ta_register_command("xdr_u_long", xdr_u_long_cmd);
    ta_register_command("xdr_u_short", xdr_u_short_cmd);
    ta_register_command("xdr_union", xdr_union_cmd);
    ta_register_command("xdr_vector", xdr_vector_cmd);
    ta_register_command("xdr_void", xdr_void_cmd);
    ta_register_command("xdr_wrapstring", xdr_wrapstring_cmd);
    ta_register_command("xdrmem_create", xdrmem_create_cmd);
    ta_register_command("xdrrec_create", xdrrec_create_cmd);
    ta_register_command("xdrrec_eof", xdrrec_eof_cmd);
    ta_register_command("xdr_destroy", xdr_destroy_cmd);
    ta_register_command("xdrrec_endofrecord", xdrrec_endofrecord_cmd);
    ta_register_command("xdrrec_skiprecord", xdrrec_skiprecord_cmd);

    ta_register_command("func_addr_socket_rpc_xdr", get_func_addr_socket_rpc_xdr_cmd);
    ta_register_command("init_xdr_discrim", init_xdr_discrim_cmd);
    ta_register_command("init_null_accepted_reply", init_null_accepted_reply_cmd);
    ta_register_command("init_null_rejected_reply", init_null_rejected_reply_cmd);
    ta_register_command("init_null_opaque_auth", init_null_opaque_auth_cmd);
    ta_register_command("init_call_rpc_msg", init_call_rpc_msg_cmd);
    ta_register_command("init_reply_rpc_msg", init_reply_rpc_msg_cmd);
}
