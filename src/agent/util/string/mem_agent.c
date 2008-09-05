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


#include "util/string/mem_agent.h"

#include <string.h>
#include <strings.h>
#include <unistd.h>

/*
 * The 'ptr_t' type is used in binary interface definition of
 *   Linux Standard Base Core Specification 3.1
 *   Copyright (c) 2004, 2005 Free Standards Group
 *
 *   See section 'Interface Definitions for libc'.
 *
 *   But there is no definition of the type in the standard.
 *   The problem is registered as defect 7.
 */

typedef void* ptr_t;


/*
 * These function declarations represents binary interface definition of
 *   Linux Standard Base Core Specification 3.1
 *   Copyright (c) 2004, 2005 Free Standards Group
 *
 *   See section 'Interface Definitions for libc'.
 */
ptr_t __rawmemchr(const ptr_t s, int c);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __mempcpy_cmd(TAThread thread,TAInputStream stream)
{
    ptr_t s1;
    ptr_t s2;
    size_t n;
    ptr_t res;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = __mempcpy( s1, s2, n );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __rawmemchr_cmd(TAThread thread,TAInputStream stream)
{
    ptr_t s;
    int c;
    size_t n;
    ptr_t res;

    // Prepare
    s = readPointer(&stream);
    c = readInt(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = __rawmemchr( s, c);
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict bcmp_cmd(TAThread thread,TAInputStream stream)
{
    void* s1;
    void* s2;
    size_t n;
    int res;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = bcmp( s1, s2, n );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict bcopy_cmd(TAThread thread,TAInputStream stream)
{
    void* s1;
    void* s2;
    size_t n;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    bcopy( s1, s2, n );
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict bzero_cmd(TAThread thread,TAInputStream stream)
{
    void* s;
    size_t n;

    // Prepare
    s = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    bzero( s,n );
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict memccpy_cmd(TAThread thread,TAInputStream stream)
{
    void* s1;
    void* s2;
    int c;
    size_t n;
    void* res;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    c = readInt(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memccpy( s1, s2, c, n);
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memchr_cmd(TAThread thread,TAInputStream stream)
{
    void* s;
    int c;
    size_t n;
    void* res;

    // Prepare
    s = readPointer(&stream);
    c = readInt(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memchr( s, c, n );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memcmp_cmd(TAThread thread,TAInputStream stream)
{
    void* s1;
    void* s2;
    size_t n;
    int res;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memcmp( s1, s2, n );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memcpy_cmd(TAThread thread,TAInputStream stream)
{
    void* s1;
    void* s2;
    size_t n;
    void* res;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memcpy( s1, s2, n );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memmem_cmd(TAThread thread,TAInputStream stream)
{
    void* haystack;
    void* needle;
    size_t haystacklen;
    size_t needlelen;
    void* res;

    // Prepare
    haystack = readPointer(&stream);
    haystacklen = readSize(&stream);
    needle = readPointer(&stream);
    needlelen = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memmem( haystack, haystacklen, needle, needlelen );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memmove_cmd(TAThread thread,TAInputStream stream)
{
    void* s1;
    void* s2;
    size_t n;
    void* res;

    // Prepare
    s1 = readPointer(&stream);
    s2 = readPointer(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memmove( s1, s2, n );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memrchr_cmd(TAThread thread,TAInputStream stream)
{
    void* s;
    int c;
    size_t n;
    void* res;

    // Prepare
    s = readPointer(&stream);
    c = readInt(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memrchr( s, c, n );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict memset_cmd(TAThread thread,TAInputStream stream)
{
    void* s;
    int c;
    size_t n;
    void* res;

    // Prepare
    s = readPointer(&stream);
    c = readInt(&stream);
    n = readSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    res = memset( s, c, n );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict swab_cmd(TAThread thread,TAInputStream stream)
{
    void* src;
    void* dest;
    ssize_t n;

    // Prepare
    src = readPointer(&stream);
    dest = readPointer(&stream);
    n = readSSize(&stream);

    // Execute
    START_TARGET_OPERATION(thread);
    swab( src, dest, n );
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_string_mem_commands(void)
{
    ta_register_command("__mempcpy",__mempcpy_cmd);
    ta_register_command("__rawmemchr",__rawmemchr_cmd);
    ta_register_command("bcmp",bcmp_cmd);
    ta_register_command("bcopy",bcopy_cmd);
    ta_register_command("bzero",bzero_cmd);
    ta_register_command("memccpy",memccpy_cmd);
    ta_register_command("memchr",memchr_cmd);
    ta_register_command("memcmp",memcmp_cmd);
    ta_register_command("memcpy",memcpy_cmd);
    ta_register_command("memmem",memmem_cmd);
    ta_register_command("memmove",memmove_cmd);
    ta_register_command("memrchr",memrchr_cmd);
    ta_register_command("memset",memset_cmd);
    ta_register_command("swab",swab_cmd);
}

