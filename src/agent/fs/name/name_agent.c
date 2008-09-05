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


#include "fs/name/name_agent.h"
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict basename_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    char* res;
    // Prepare

    ta_debug_printf("bef_read\n");
    path = readString(&stream);

    ta_debug_printf("aft_read: path==%s\n", path);
    START_TARGET_OPERATION(thread);    
    // Execute
    res = basename(path); 
    END_TARGET_OPERATION(thread);
    ta_debug_printf("path==%s, agent_str==%s\n", path, res);
    // Response
    writeString(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dirname_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    char* res;

    path = readString(&stream);


    START_TARGET_OPERATION(thread);
    res = dirname(path);
    END_TARGET_OPERATION(thread);

    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict realpath_cmd(TAThread thread,TAInputStream stream)
{
    char* file_name, *resolved_name, *res;



    file_name = readString(&stream);

    resolved_name = (char*)readPointer(&stream);



    START_TARGET_OPERATION(thread);

    errno = 0;

    res = realpath(file_name, resolved_name);

    END_TARGET_OPERATION(thread);



    writeInt(thread, errno);

    writeString(thread, res);

    sendResponse(thread);



    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_name_commands(void)
{    
    ta_register_command("basename",basename_cmd);    
    ta_register_command("dirname",dirname_cmd);
    ta_register_command("realpath",realpath_cmd);
}

