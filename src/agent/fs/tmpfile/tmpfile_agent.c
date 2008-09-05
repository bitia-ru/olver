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

#include <errno.h>
#include <stdlib.h>
#include "fs/tmpfile/tmpfile_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict mkstemp_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* templ;

    // Prepare
    templ = readString(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = mkstemp(templ);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt   ( thread, res   );
    writeString( thread, templ );

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mkstemp64_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* templ;

    // Prepare
    templ = readString(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = mkstemp64(templ);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt   ( thread, res   );
    writeString( thread, templ );

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mktemp_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    char* templ;

    // Prepare
    templ = readString(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = mktemp(templ);

    END_TARGET_OPERATION(thread);

    // Response
    if (res!=NULL)
    {
        writeInt(thread, 0);
        writeString( thread, res   );
        writeString( thread, templ );
    }
    else
    {
        writeInt(thread, 1);
    }

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tempnam_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    char *dir = NULL;
    int isDirNull;
    char *pfx = NULL;
    int isPfxNull;

    // Prepare
    isDirNull = readInt(&stream);
    isPfxNull = readInt(&stream);

    if (!isDirNull)
    {
        dir = readString(&stream);
    }

    if (!isPfxNull)
    {
        pfx = readString(&stream);
    }

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = tempnam(dir, pfx);
    END_TARGET_OPERATION(thread);

    // Response
    if (res!=NULL)
    {
        writeInt(thread, 0);
        writeString(thread, res);
    }
    else
    {
        writeInt(thread, 1);
    }

    writeInt(thread, errno);

    sendResponse(thread);

    if ( res != NULL ) { free( res ); }

    return taDefaultVerdict;
}

static TACommandVerdict tmpfile_cmd(TAThread thread,TAInputStream stream)
{
    FILE * res;
    char* templ;

    // Prepare

    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  tmpfile();
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tmpfile64_cmd(TAThread thread,TAInputStream stream)
{
    FILE * res;
    char* templ;

    // Prepare

    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  tmpfile64();
    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tmpnam_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    char* s = NULL;
    int   sz;

    // Prepare
    sz = readInt(&stream);

    if (sz!=-1)
    {
        s = ta_alloc_memory(sz);
    }

    START_TARGET_OPERATION(thread);
    res = tmpnam(s);
    END_TARGET_OPERATION(thread);

    // Response
    if (res!=NULL)
    {
        writeInt(thread, 0);
        writeString(thread, res);
    }
    else
    {
        writeInt(thread, 1);
    }

    if (sz!=-1)
    {
        ta_dealloc_memory(s);
    }

    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_tmpfile_commands(void)
{
    ta_register_command("mkstemp",mkstemp_cmd);
    ta_register_command("mkstemp64",mkstemp64_cmd);
    ta_register_command("mktemp",mktemp_cmd);
    ta_register_command("tempnam",tempnam_cmd);
    ta_register_command("tmpfile",tmpfile_cmd);
    ta_register_command("tmpfile64",tmpfile64_cmd);
    ta_register_command("tmpnam",tmpnam_cmd);
}

