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


#include "locale/wctrans/wctrans_agent.h"
#include <wctype.h>
#include <errno.h>

static wint_t readWInt(TAInputStream* stream)
{
    return readUInt(stream);
}

static void writeWInt(TAThread thread, wint_t value)
{
    return writeUInt(thread, value);
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict towctrans_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    wctrans_t desc;
    wint_t res;
    int save_errno;

    // Prepare
    wc = readWInt(&stream);
    desc = (wctrans_t)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = towctrans(wc, desc);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeWInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict towlower_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    wint_t res;

    // Prepare
    wc = readWInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = towlower(wc);

    END_TARGET_OPERATION(thread);

    // Response
    writeWInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict towupper_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    wint_t res;

    // Prepare
    wc = readWInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = towupper(wc);

    END_TARGET_OPERATION(thread);

    // Response
    writeWInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wctrans_cmd(TAThread thread, TAInputStream stream)
{
    const char* charclass;
    wctrans_t res;
    int save_errno;

    // Prepare
    charclass = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wctrans(charclass);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, (void*)res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_wctrans_commands(void)
{
    ta_register_command("towctrans", towctrans_cmd);
    ta_register_command("towlower", towlower_cmd);
    ta_register_command("towupper", towupper_cmd);
    ta_register_command("wctrans", wctrans_cmd);
}
