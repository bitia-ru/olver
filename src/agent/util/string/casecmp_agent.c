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


#include "util/string/casecmp_agent.h"
#include <strings.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict strcasecmp_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char *s1;
    char *s2;

    // Prepare

    s1 = readString(&stream);
    s2 = readString(&stream);

    START_TARGET_OPERATION(thread);
    res = strcasecmp(s1, s2);
    END_TARGET_OPERATION(thread);
    
    // Response

    writeInt(thread,res);
    sendResponse(thread);
    

    return taDefaultVerdict;
}

static TACommandVerdict strncasecmp_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char *s1;
    char *s2;
    size_t n;
    
    // Prepare
    
    s1 = readString(&stream);
    s2 = readString(&stream);
    n = readSize(&stream);
    
    START_TARGET_OPERATION(thread);
    res = strncasecmp(s1, s2, n); 
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeInt(thread,res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict strcasestr_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char *s1;
    char *s2;
    char* strres;
    
    // Prepare
    
    s1 = readString(&stream);
    s2 = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    strres = strcasestr(s1, s2);
    END_TARGET_OPERATION(thread);
    
    // Response

    if (strres==NULL)
    {
        writeInt(thread, -1);
    }
    else
    {
        res = (int)(strres - s1);
        writeInt(thread, res);
    }

    sendResponse(thread);
    
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_string_casecmp_commands(void)
{
    ta_register_command("strcasecmp",strcasecmp_cmd);
    ta_register_command("strcasestr",strcasestr_cmd);
    ta_register_command("strncasecmp",strncasecmp_cmd);
}

