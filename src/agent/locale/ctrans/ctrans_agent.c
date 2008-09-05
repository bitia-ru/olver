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


#include "locale/ctrans/ctrans_agent.h"
#include <ctype.h>

void writeLocchars(TAThread thread, const int** array)
{
    int i;
    writeType_TAStream(thread, "locchars");
    writeInt(thread, 384);
    for (i=-128; i<=256; ++i)
        writeInt(thread, (*array)[i]);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __ctype_tolower_loc_cmd(TAThread thread, TAInputStream stream)
{
    const int** res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = __ctype_tolower_loc();

    END_TARGET_OPERATION(thread);

    // Response
    writeLocchars(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __ctype_toupper_loc_cmd(TAThread thread, TAInputStream stream)
{
    const int** res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = __ctype_toupper_loc();

    END_TARGET_OPERATION(thread);

    // Response
    writeLocchars(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict _tolower_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = _tolower(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict _toupper_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = _toupper(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tolower_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tolower(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict toupper_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = toupper(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_ctrans_commands(void)
{
    ta_register_command("__ctype_tolower_loc", __ctype_tolower_loc_cmd);
    ta_register_command("__ctype_toupper_loc", __ctype_toupper_loc_cmd);
    ta_register_command("_tolower", _tolower_cmd);
    ta_register_command("_toupper", _toupper_cmd);
    ta_register_command("tolower", tolower_cmd);
    ta_register_command("toupper", toupper_cmd);
}
