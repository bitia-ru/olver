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


#include "locale/ctype/ctype_agent.h"
#include <ctype.h>
#include <stdlib.h>

const unsigned short int** __ctype_b_loc(void);

void writeLocspec(TAThread thread, const unsigned short int** array)
{
    int i;
    writeType_TAStream(thread, "locspec");
    writeInt(thread, 384);
    for (i=-128; i<=256; ++i)
        writeUShort(thread, (*array)[i]);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __ctype_b_loc_cmd(TAThread thread, TAInputStream stream)
{
    const unsigned short int** res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = __ctype_b_loc();

    END_TARGET_OPERATION(thread);

    // Response
    writeLocspec(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __ctype_get_mb_cur_max_cmd(TAThread thread, TAInputStream stream)
{
    size_t res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = __ctype_get_mb_cur_max();

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isalnum_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isalnum(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isalpha_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isalpha(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isascii_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isascii(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isblank_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isblank(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict iscntrl_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = iscntrl(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isdigit_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isdigit(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isgraph_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isgraph(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict islower_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = islower(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isprint_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isprint(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ispunct_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = ispunct(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isspace_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isspace(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isupper_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isupper(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict isxdigit_cmd(TAThread thread, TAInputStream stream)
{
    int c;
    int res;

    // Prepare
    c = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = isxdigit(c);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_ctype_commands(void)
{
    ta_register_command("__ctype_b_loc", __ctype_b_loc_cmd);
    ta_register_command("__ctype_get_mb_cur_max", __ctype_get_mb_cur_max_cmd);
    ta_register_command("isalnum", isalnum_cmd);
    ta_register_command("isalpha", isalpha_cmd);
    ta_register_command("isascii", isascii_cmd);
    ta_register_command("isblank", isblank_cmd);
    ta_register_command("iscntrl", iscntrl_cmd);
    ta_register_command("isdigit", isdigit_cmd);
    ta_register_command("isgraph", isgraph_cmd);
    ta_register_command("islower", islower_cmd);
    ta_register_command("isprint", isprint_cmd);
    ta_register_command("ispunct", ispunct_cmd);
    ta_register_command("isspace", isspace_cmd);
    ta_register_command("isupper", isupper_cmd);
    ta_register_command("isxdigit", isxdigit_cmd);
}
