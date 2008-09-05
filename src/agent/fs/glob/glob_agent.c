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

#include "fs/glob/glob_agent.h"

#include <glob.h>

extern int glob(const char *, int, int (*__errfunc) (const char *p1, int p2), glob_t *);

extern int glob64(const char *, int, int (*__errfunc) (const char *p1, int p2), glob64_t *);

extern void globfree(glob_t *);

extern void globfree64(glob64_t *);

/********************************************************************/
/**             Error functions for glob() and glob64()            **/
/********************************************************************/
static int glob_error_function_param = 0;

static int zero_glob_error_function(const char *epath, int eerrno)
{
    TAThread thread = ta_current_thread();

    writeString(thread, epath);
    writeInt(thread, eerrno);
    writeInt(thread, 0);

    return 0;
}

static int one_glob_error_function(const char *epath, int eerrno)
{
    TAThread thread = ta_current_thread();

    writeString(thread, epath);
    writeInt(thread, eerrno);
    writeInt(thread, 1);

    return 1;
}

static int zero_one_glob_error_function(const char *epath, int eerrno)
{
    TAThread thread = ta_current_thread();

    writeString(thread, epath);
    writeInt(thread, eerrno);

    if(glob_error_function_param <= 0)
    {
        writeInt(thread, 1); 
        return 1;
    }

    glob_error_function_param--;

    writeInt(thread, 0);
    return 0;
}
/********************************************************************/
/**                           Readers                             **/
/********************************************************************/
static int readGlobFlags(TAInputStream *stream)
{
    int res = 0;

    verifyType_TAInputStream(stream, "globflags");

    res = readChar(stream) != '\x00' ? res | GLOB_ERR         : res;
    res = readChar(stream) != '\x00' ? res | GLOB_MARK        : res;
    res = readChar(stream) != '\x00' ? res | GLOB_NOSORT      : res;
    res = readChar(stream) != '\x00' ? res | GLOB_DOOFFS      : res;
    res = readChar(stream) != '\x00' ? res | GLOB_NOCHECK     : res;
    res = readChar(stream) != '\x00' ? res | GLOB_APPEND      : res;
    res = readChar(stream) != '\x00' ? res | GLOB_NOESCAPE    : res;
    res = readChar(stream) != '\x00' ? res | GLOB_PERIOD      : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_MAGCHAR     : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_ALTDIRFUNC  : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_BRACE       : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_NOMAGIC     : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_TILDE       : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_ONLYDIR     : res;
//    res = readChar(stream) != '\x00' ? res | GLOB_TILDE_CHECK : res;
    return res;
}

static int (*readGlobErrorFunction(TAInputStream *stream))(const char*, int)
{
    int glob_error_function_type;

    if(startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return NULL;
    }

    verifyType_TAInputStream(stream, "globerrfunc");

    glob_error_function_type = readInt(stream);
    glob_error_function_param = readInt(stream);   

    switch(glob_error_function_type)
    {
    case 0:
        return zero_glob_error_function;
    case 1:
        return one_glob_error_function;
    case 2:
        return zero_one_glob_error_function;
    }

    return NULL;
}

/********************************************************************/
/**                           Writers                              **/
/********************************************************************/
static void writeGlobT(TAThread thread, glob_t *pglob, int flags)
{
    size_t i, size;

    writeSize(thread, pglob->gl_pathc);
    writeSize(thread, pglob->gl_offs);

    size = pglob->gl_pathc + (flags & GLOB_DOOFFS ? pglob->gl_offs : 0);

    for(i = 0; i < size; i++)
    {
        writeString(thread, pglob->gl_pathv[i]);
    }
}

static void writeGlob64T(TAThread thread, glob64_t *pglob, int flags)
{
    size_t i, size;

    writeSize(thread, pglob->gl_pathc);
    writeSize(thread, pglob->gl_offs);

    size = pglob->gl_pathc + (flags & GLOB_DOOFFS ? pglob->gl_offs : 0);

    for(i = 0; i < size; i++)
    {
        writeString(thread, pglob->gl_pathv[i]);
    }
}

static void writeGlobErrorCode(TAThread thread, int error_code)
{
    switch(error_code)
    {
    case 0:
        writeInt(thread, 0);
        break;
    case GLOB_NOSPACE:
        writeInt(thread, 1);
        break;
    case GLOB_ABORTED:
        writeInt(thread, 2);
        break;
    case GLOB_NOMATCH:
        writeInt(thread, 3);
        break;
    case GLOB_NOSYS:
        writeInt(thread, 4);
        break;
    default:
        writeInt(thread, -1);
        break;
    }
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict setglob_cmd(TAThread thread, TAInputStream stream)
{
    glob_t *pglob;
    size_t offs;

    // Prepare
    pglob = readPointer(&stream);
    offs = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    pglob->gl_offs = offs;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setglob64_cmd(TAThread thread, TAInputStream stream)
{
    glob64_t *pglob;
    size_t offs;

    // Prepare
    pglob = readPointer(&stream);
    offs = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    pglob->gl_offs = offs;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getglob_cmd(TAThread thread, TAInputStream stream)
{
    glob_t *pglob;
    int flags;

    // Prepare
    pglob = readPointer(&stream);
    flags = readGlobFlags(&stream);

    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    // Response
    writeGlobT(thread, pglob, flags);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getglob64_cmd(TAThread thread, TAInputStream stream)
{
    glob64_t *pglob;
    int flags;

    // Prepare
    pglob = readPointer(&stream);
    flags = readGlobFlags(&stream);

    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    // Response
    writeGlob64T(thread, pglob, flags);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict glob_cmd(TAThread thread, TAInputStream stream)
{
    const char *pattern;
    int flags, res;
    int (*errfunc)(const char*, int);
    glob_t *pglob;
    size_t size;

    // Prepare
    pattern = readString(&stream);
    flags = readGlobFlags(&stream);
    errfunc = readGlobErrorFunction(&stream);
    pglob = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = glob(pattern, flags, errfunc, pglob);
    
    END_TARGET_OPERATION(thread);

    // Response
    size = pglob->gl_pathc + (flags & GLOB_DOOFFS ? pglob->gl_offs : 0);

    if(pglob->gl_pathc != 0 && pglob->gl_pathv[size] != NULL)
    {
        sendException(thread, "glob.04 violation");
    }

    writeString(thread, NULL);

    writeGlobErrorCode(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict glob64_cmd(TAThread thread, TAInputStream stream)
{
    const char *pattern;
    int flags, res;
    int (*errfunc)(const char*, int);
    glob64_t *pglob;
    size_t size;

    // Prepare
    pattern = readString(&stream);
    flags = readGlobFlags(&stream);
    errfunc = readGlobErrorFunction(&stream);   
    pglob = readPointer(&stream);
 
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = glob64(pattern, flags, errfunc, pglob);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    size = pglob->gl_pathc + (flags & GLOB_DOOFFS ? pglob->gl_offs : 0);

    if(pglob->gl_pathc != 0 && pglob->gl_pathv[size] != NULL)
    {
        sendException(thread, "glob64.04 violation");
    }

    writeString(thread, NULL);

    writeGlobErrorCode(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict globfree_cmd(TAThread thread, TAInputStream stream)
{
    glob_t *pglob;

    // Prepare
    pglob = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    globfree(pglob);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict globfree64_cmd(TAThread thread, TAInputStream stream)
{
    glob64_t *pglob;

    // Prepare
    pglob = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    globfree64(pglob);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_glob_commands(void)
{
    ta_register_command("setglob", setglob_cmd);
    ta_register_command("setglob64", setglob64_cmd);
    ta_register_command("getglob", getglob_cmd);
    ta_register_command("getglob64", getglob64_cmd);
    ta_register_command("glob", glob_cmd);
    ta_register_command("glob64", glob64_cmd);
    ta_register_command("globfree", globfree_cmd);
    ta_register_command("globfree64", globfree64_cmd);
}

