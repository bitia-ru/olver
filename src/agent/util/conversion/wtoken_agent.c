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


#include "util/conversion/wtoken_agent.h"
#include <wchar.h>

#include <stdio.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict wcstok_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* stringp, *buff, *delim, *res;

/*
    freopen(NULL, "a+", stdout);
    orient=fwide(stdout, 0);
    wprintf(L"Before wcstok(wprintf): mode==%ls\n", orient>0?L"Wide": orient<0?L"Byte":L"Non oriented");
    wprintf(L"Test==%ls\n", test);
    ta_debug_printf("Before wcstok(printf): mode==%s\n", orient>0?"Wide": orient<0?"Byte":"Non oriented");
*/    

    // Prepare       
    stringp=(wchar_t*)readPointer(&stream);
    delim=(wchar_t*)readPointer(&stream);
    buff=(wchar_t*)readPointer(&stream);    

    // Execute    
    START_TARGET_OPERATION(thread);
    res = wcstok(stringp, delim, &buff);
    END_TARGET_OPERATION(thread);

    // Response    
    writePointer(thread, res);
    writePointer(thread, buff);

    sendResponse(thread);

    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_wtoken_commands(void)
{
    ta_register_command("wcstok",wcstok_cmd);
}

