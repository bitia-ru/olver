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


#include "util/regex/regex_agent.h"
#include <regex.h>
#include <fnmatch.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict fnmatch_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char *pattern;
    char *string;
    int flags;

    // Prepare
    pattern = readString(&stream);
    string = readString(&stream);
    flags = readInt(&stream);

    
    START_TARGET_OPERATION(thread);
    res =  fnmatch(pattern, string, flags);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict regcomp_cmd(TAThread thread,TAInputStream stream)
{
    int      res;
    char*    pattern;
    int      cflags;
    regex_t* preg = ta_alloc_memory(sizeof(regex_t));

    // Prepare
    pattern = readString(&stream);
    cflags = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  regcomp(preg, pattern, cflags);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writePointer(thread, preg);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict regerror_cmd(TAThread thread,TAInputStream stream)
{
    size_t      res;
    int errcode;
    regex_t * preg;
    char * errbuf = NULL;
    size_t errbuf_size;

    // Prepare
    errcode = readInt(&stream);
    preg = readPointer(&stream);
    errbuf_size = readSize(&stream);
    if (errbuf_size!=0)
    {
        errbuf = ta_alloc_memory(errbuf_size);
    }
    
    START_TARGET_OPERATION(thread);
    res =  regerror(errcode, preg, errbuf, errbuf_size);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeSize(thread,res);
    if (errbuf_size!=0)
    {
        writeString(thread, errbuf);
        ta_dealloc_memory(errbuf);
    }
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict regexec_cmd(TAThread thread,TAInputStream stream)
{
    int      res;
    regex_t *preg;
    char* string;
    size_t nmatch;
    regmatch_t* pmatch;
    int eflags;
    size_t i;

    // Prepare

    preg = readPointer(&stream);
    string = readString(&stream);
    nmatch = readSize(&stream);
    eflags = readInt(&stream);

    pmatch = ta_alloc_memory(sizeof(regmatch_t)*nmatch+5);
    
    START_TARGET_OPERATION(thread);
    res = regexec(preg, string, nmatch, pmatch, eflags);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    
    for (i=0;i<nmatch;i++)
    {
        writeInt(thread, pmatch[i].rm_so);
        writeInt(thread, pmatch[i].rm_eo);
    }

    sendResponse(thread);
    
    ta_dealloc_memory(pmatch);

    return taDefaultVerdict;
}

static TACommandVerdict regfree_cmd(TAThread thread,TAInputStream stream)
{
    regex_t* preg;

    // Prepare
    preg = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    regfree(preg);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_regex_commands(void)
{
    ta_register_command("fnmatch",fnmatch_cmd);
    ta_register_command("regcomp",regcomp_cmd);
    ta_register_command("regerror",regerror_cmd);
    ta_register_command("regexec",regexec_cmd);
    ta_register_command("regfree",regfree_cmd);
}

