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


#include "util/dl/dl_agent.h"

#include <dlfcn.h>
#include <stdio.h>
    
/********************************************************************/
/**                       Specification Types                      **/
/********************************************************************/

static void readDLInfo(TAInputStream* stream, Dl_info* dli)
{
    dli->dli_fname = readPointer(stream);
    dli->dli_fbase = readPointer(stream);
    dli->dli_sname = readPointer(stream);
    dli->dli_saddr = readPointer(stream);
}

static void writeDLInfo(TAThread thread, Dl_info* dli)
{
    writeString(thread, dli->dli_fname);
    writePointer(thread, dli->dli_fbase);
    writeString(thread, dli->dli_sname);
    writePointer(thread, dli->dli_saddr);
}

/********************************************************************/
/**                        Test Data Transfer                      **/
/********************************************************************/

static TACommandVerdict dlget_stdsyms_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    FILE* file;
    char line[512], ch;
    int i = 0;
    
    // Execute
    if(file = fopen("../testdata/util.dl/stdsyms.txt", "r"))
    {
        while(fread(&ch, 1, 1, file))
        {
            if(ch == '\n')
            {
                line[i] = '\0', i = 0;
                writeString(thread, line);
                continue;
            }

            line[i++] = ch;
        }

        fclose(file);
    }

    // Response
    writeString(thread, "!");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict dladdr_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    Dl_info dli;
    void* addr;
    
    addr = readPointer(&stream);
    readDLInfo(&stream, &dli);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = dladdr(addr, &dli);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeDLInfo(thread, &dli);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dlclose_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    void* handle = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = dlclose(handle);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dlerror_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char* res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = dlerror();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dlopen_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    void* res;
    const char* file = readString(&stream);
    int mode = readInt(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = dlopen(file, mode);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dlsym_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    void* res;
    void* handle = readPointer(&stream);
    const char* name = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = dlsym(handle, name);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_dl_commands(void)
{
    ta_register_command("dladdr", dladdr_cmd);
    ta_register_command("dlclose", dlclose_cmd);
    ta_register_command("dlerror", dlerror_cmd);
    ta_register_command("dlopen", dlopen_cmd);
    ta_register_command("dlsym", dlsym_cmd);
    ta_register_command("dlget_stdsyms", dlget_stdsyms_cmd);
}

