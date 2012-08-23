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


#include "util/string/wcasecmp_agent.h"
#include <wchar.h> 


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict wcscasecmp_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    wchar_t *s1;
    wchar_t *s2;
    
    // Prepare
    
    s1 = ta_wcsalign(readWString(&stream)); //align on copy
    s2 = ta_wcsalign(readWString(&stream)); //align on copy
    
    START_TARGET_OPERATION(thread);
    res =  wcscasecmp(s1, s2);

    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeInt(thread,res);
    sendResponse(thread);
    
    ta_dealloc_memory(s1);
    ta_dealloc_memory(s2);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcsncasecmp_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    wchar_t *s1;
    wchar_t *s2;
    size_t n;
    
    // Prepare

    s1 = ta_wcsalign(readWString(&stream)); //align on copy
    s2 = ta_wcsalign(readWString(&stream)); //align on copy    
    n = readSize(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wcsncasecmp(s1, s2, n); 
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeInt(thread,res);
    sendResponse(thread);
    
    ta_dealloc_memory(s1);
    ta_dealloc_memory(s2);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_string_wcasecmp_commands(void)
{
    ta_register_command("wcscasecmp",wcscasecmp_cmd);
    ta_register_command("wcsncasecmp",wcsncasecmp_cmd);
}

