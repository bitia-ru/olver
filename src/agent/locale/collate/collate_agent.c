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


#include "locale/collate/collate_agent.h"
#include <string.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict strcoll_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    int res;
    int save_errno;

    // Prepare
    s1 = readString(&stream);
    s2 = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = strcoll(s1, s2);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

#define BUFFER_TAIL 4

static TACommandVerdict strxfrm_cmd(TAThread thread, TAInputStream stream)
{
    char* s1;
    char* s2;
    size_t n;
    size_t res;
    int save_errno;
    int overflow = 0;
    int i;

    // Prepare
    s2 = readString(&stream);
    n = readSize(&stream);
    s1 = ta_alloc_memory(n + BUFFER_TAIL);
    for (i=0; i<BUFFER_TAIL; ++i)
        s1[n + i] = '\xDD';

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = strxfrm(s1, s2, n);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    for (i=0; i<BUFFER_TAIL; ++i)
        overflow |= (s1[n + i] != '\xDD');

    if (overflow)
    {
        sendException(thread, "strxfrm.02 failed: writing outside of buffer limits occured!");
        return taDefaultVerdict;
    }

    // Response
    if (res >= n)
        writeString(thread, "");
    else
        writeString(thread, s1);
    writeSize(thread, res);
    writeInt(thread, save_errno);

    sendResponse(thread);

    ta_dealloc_memory(s1);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_collate_commands(void)
{
    ta_register_command("strcoll", strcoll_cmd);
    ta_register_command("strxfrm", strxfrm_cmd);
}
