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


#include <wordexp.h>

#include "util/wordexp/wordexp_agent.h"

extern int wordexp(const char *, wordexp_t *, int);

extern void wordfree(wordexp_t *);

/********************************************************************/
/**                           Readers                             **/
/********************************************************************/
static int readWordExpFlags(TAInputStream *stream)
{
    int res = 0;

    verifyType_TAInputStream(stream, "weflags");

    res = readChar(stream) != '\x00' ? res | WRDE_APPEND  : res;
    res = readChar(stream) != '\x00' ? res | WRDE_DOOFFS   : res;
    res = readChar(stream) != '\x00' ? res | WRDE_NOCMD   : res;
    res = readChar(stream) != '\x00' ? res | WRDE_REUSE   : res;
    res = readChar(stream) != '\x00' ? res | WRDE_SHOWERR : res;
    res = readChar(stream) != '\x00' ? res | WRDE_UNDEF   : res;

    return res;
}

/********************************************************************/
/**                           Writers                              **/
/********************************************************************/
static void writeWordExpT(TAThread thread, wordexp_t *pwordexp)
{
    size_t i;

    writeSize(thread, pwordexp->we_wordc);
    writeSize(thread, pwordexp->we_offs);

    for(i = 0; i < pwordexp->we_wordc; i++)
    {
        writeString(thread, pwordexp->we_wordv[i]);
    }
}

static void writeWordExpErrorCode(TAThread thread, int error_code)
{
    switch(error_code)
    {
    case 0:
        writeInt(thread, 0);
        break;
    case WRDE_BADCHAR:
        writeInt(thread, 1);
        break;
    case WRDE_BADVAL:
        writeInt(thread, 2);
        break;
    case WRDE_CMDSUB:
        writeInt(thread, 3);
        break;
    case WRDE_NOSPACE:
        writeInt(thread, 4);
        break;
    case WRDE_SYNTAX:
        writeInt(thread, 5);
        break;
    default:
        writeInt(thread, -1);
        break;
    }
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getwordexp_cmd(TAThread thread, TAInputStream stream)
{
    wordexp_t *pwordexp;

    // Prepare
    pwordexp = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    // Response
    writeWordExpT(thread, pwordexp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setwordexp_cmd(TAThread thread, TAInputStream stream)
{
    wordexp_t *pwordexp;

    // Prepare
    pwordexp = readPointer(&stream);
    pwordexp->we_offs = readSize(&stream);

    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wordexp_cmd(TAThread thread, TAInputStream stream)
{
    char *words;
    wordexp_t *pwordexp;
    int flags, res;

    // Prepare
    words = readString(&stream);
    pwordexp = readPointer(&stream);
    flags = readWordExpFlags(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = wordexp(words, pwordexp, flags);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeWordExpErrorCode(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wordfree_cmd(TAThread thread, TAInputStream stream)
{
    wordexp_t *pwordexp;

    // Prepare
    pwordexp = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    wordfree(pwordexp);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
 
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_wordexp_commands(void)
{
    ta_register_command("getwordexp", getwordexp_cmd);
    ta_register_command("setwordexp", setwordexp_cmd);
    ta_register_command("wordexp", wordexp_cmd);
    ta_register_command("wordfree", wordfree_cmd);
}

