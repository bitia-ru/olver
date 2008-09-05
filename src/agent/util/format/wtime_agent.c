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


#include "util/format/wtime_agent.h"
#include <wchar.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict wcsftime_cmd(TAThread thread,TAInputStream stream)
{
    size_t res;
    
    wchar_t *wcs;
    size_t maxsize;
    wchar_t * format;
    struct tm times;
    
    // Prepare
    wcs = (wchar_t*)readPointer(&stream);
    maxsize = readSize(&stream);
    format = (wchar_t*)readPointer(&stream);
    readTimeTm(&stream, &times);
    
    START_TARGET_OPERATION(thread);
    res = wcsftime(wcs, maxsize, format, &times);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeSize(thread, res);

    sendResponse(thread);
   
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_format_wtime_commands(void)
{
    ta_register_command("wcsftime",wcsftime_cmd);
}

