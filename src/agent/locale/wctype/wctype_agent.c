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


#include "locale/wctype/wctype_agent.h"
#include <wchar.h>
#include <wctype.h>

static wint_t readWInt(TAInputStream* stream)
{
    return readUInt(stream);
}

static wctype_t readWCType(TAInputStream* stream)
{
    return readULong(stream);
}

static void writeWCType(TAThread thread, wctype_t value)
{
    return writeULong(thread, value);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict iswalnum_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswalnum(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswalpha_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswalpha(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswblank_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswblank(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswcntrl_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswcntrl(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswctype_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    wctype_t charclass;
    int res;

    // Prepare
    wc = readWInt(&stream);
    charclass = readWCType(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswctype(wc, charclass);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswdigit_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswdigit(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswgraph_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswgraph(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswlower_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswlower(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswprint_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswprint(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswpunct_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswpunct(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswspace_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswspace(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswupper_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswupper(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict iswxdigit_cmd(TAThread thread, TAInputStream stream)
{
    wint_t wc;
    int res;

    // Prepare
    wc = readWInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = iswxdigit(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wctype_cmd(TAThread thread, TAInputStream stream)
{
    const char *property;
    wctype_t res;

    // Prepare
    property = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = wctype(property);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeWCType(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcwidth_cmd(TAThread thread, TAInputStream stream)
{
    wchar_t wc;
    int res;

    // Prepare
    wc = readWChar(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = wcwidth(wc);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcswidth_cmd(TAThread thread, TAInputStream stream)
{
    const size_t MAX_SIZE = 1024;
    wchar_t pwcs[MAX_SIZE];
    size_t sz;
    size_t n;
    int res;

    // Prepare
    readWCharArray(&stream, pwcs, &sz);
    n = readSize(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = wcswidth(pwcs, n);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_wctype_commands(void)
{
    ta_register_command("iswalnum", iswalnum_cmd);
    ta_register_command("iswalpha", iswalpha_cmd);
    ta_register_command("iswblank", iswblank_cmd);
    ta_register_command("iswcntrl", iswcntrl_cmd);
    ta_register_command("iswctype", iswctype_cmd);
    ta_register_command("iswdigit", iswdigit_cmd);
    ta_register_command("iswgraph", iswgraph_cmd);
    ta_register_command("iswlower", iswlower_cmd);
    ta_register_command("iswprint", iswprint_cmd);
    ta_register_command("iswpunct", iswpunct_cmd);
    ta_register_command("iswspace", iswspace_cmd);
    ta_register_command("iswupper", iswupper_cmd);
    ta_register_command("iswxdigit", iswxdigit_cmd);
    ta_register_command("wctype", wctype_cmd);
    ta_register_command("wcwidth", wcwidth_cmd);
    ta_register_command("wcswidth", wcswidth_cmd);
}
