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


#include "locale/wcollate/wcollate_agent.h"
#include "common/ta_stream.h"
#include <wchar.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict wcscoll_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    int res;
    int save_errno;

    // Prepare
    ws1 = readWString(&stream);
    ws2 = readWString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = wcscoll(ws1, ws2);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

#define BUFFER_TAIL 4

static TACommandVerdict wcsxfrm_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t* ws1;
    wchar_t* ws2;
    wchar_t* xxx = L"";
    size_t n;
    size_t res;
    int save_errno;
    int overflow = 0;
    int i;

    // Prepare
    ws2 = readWString(&stream);
    n = readSize(&stream);
    ws1 = ta_alloc_memory((n + BUFFER_TAIL) * sizeof(wchar_t));
    for (i=0; i<BUFFER_TAIL; ++i)
        ws1[n + i] = (wchar_t)0xDDDDDDDD;

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = wcsxfrm(ws1, ws2, n);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    for (i=0; i<BUFFER_TAIL; ++i)
        overflow |= (ws1[n + i] != (wchar_t)0xDDDDDDDD);

    if (overflow)
    {
        sendException(thread, "wcsxfrm.02 failed: writing outside of buffer limits occured!");
        return taDefaultVerdict;
    }

    // Response
    if (res >= n)
        writeWString(thread, xxx);
    else
        writeWString(thread, ws1);
    writeSize(thread, res);
    writeInt(thread, save_errno);

    sendResponse(thread);

    ta_dealloc_memory(ws1);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_wcollate_commands(void)
{
    ta_register_command("wcscoll", wcscoll_cmd);
    ta_register_command("wcsxfrm", wcsxfrm_cmd);
}
