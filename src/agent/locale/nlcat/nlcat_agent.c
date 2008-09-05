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


#include "locale/nlcat/nlcat_agent.h"
#include <nl_types.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict catclose_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    nl_catd catd = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    errno = 0;
    res = catclose(catd);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict catgets_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char* res;
    nl_catd catd = readPointer(&stream);
    int set_id = readInt(&stream);
    int msg_id = readInt(&stream);
    const char* s = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    errno = 0;
    res = catgets(catd, set_id, msg_id, s);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, res);
    writeInt(thread, res == s);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict catopen_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    nl_catd res;
    const char* name;
    int oflag;
    
    name = readString(&stream);
    oflag = readInt(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    errno = 0;
    res = catopen(name, oflag);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_nlcat_commands(void)
{
    ta_register_command("catclose", catclose_cmd);
    ta_register_command("catgets", catgets_cmd);
    ta_register_command("catopen", catopen_cmd);
}

