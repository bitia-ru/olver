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


#include "util/string/wmem_agent.h"
#include <wchar.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict wmemchr_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* s;
    wchar_t c;
    size_t n;
    wchar_t* res;
    
    // Prepare
    s = readPointer(&stream);
    c = readWChar(&stream);
    n = readSize(&stream);
    
    // Execute
    START_TARGET_OPERATION(thread);
    res = wmemchr( s, c, n );
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread,res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wmemcmp_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t n;
    int res;
    
    // Prepare
    ws1 = readPointer(&stream);
    ws2 = readPointer(&stream);
    n = readSize(&stream);
    
    // Execute
    START_TARGET_OPERATION(thread);
    res = wmemcmp( ws1, ws2, n );
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wmemcpy_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t n;
    wchar_t* res;
    
    // Prepare
    ws1 = readPointer(&stream);
    ws2 = readPointer(&stream);
    n = readSize(&stream);
    
    // Execute
    START_TARGET_OPERATION(thread);
    res = wmemcpy( ws1, ws2, n);
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wmemmove_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    size_t n;
    wchar_t* res;
    
    // Prepare
    ws1 = readPointer(&stream);
    ws2 = readPointer(&stream);
    n = readSize(&stream);
    
    // Execute
    START_TARGET_OPERATION(thread);
    res = wmemmove( ws1, ws2, n);
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread, res);
    sendResponse(thread);
    
 
    return taDefaultVerdict;
}

static TACommandVerdict wmemset_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* s;
    wchar_t c;
    size_t n;
    wchar_t* res;
    
    // Prepare
    s = readPointer(&stream);
    c = readWChar(&stream);
    n = readSize(&stream);
    
    // Execute
    START_TARGET_OPERATION(thread);
    res = wmemset( s, c, n );
    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread,res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_string_wmem_commands(void)
{
    ta_register_command("wmemchr",wmemchr_cmd);
    ta_register_command("wmemcmp",wmemcmp_cmd);
    ta_register_command("wmemcpy",wmemcpy_cmd);
    ta_register_command("wmemmove",wmemmove_cmd);
    ta_register_command("wmemset",wmemset_cmd);
}

