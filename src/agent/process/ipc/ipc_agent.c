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


#include <sys/ipc.h>
#include <errno.h>
#include "process/ipc/ipc_agent.h"


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict ftok_cmd(TAThread thread,TAInputStream stream)
{
    key_t res;
    
    const char *path;
    int id;

    // Prepare
    path = readString(&stream);
    id= readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = ftok(path, id); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_ipc_ipc_commands(void)
{
    ta_register_command("ftok",ftok_cmd);
}

