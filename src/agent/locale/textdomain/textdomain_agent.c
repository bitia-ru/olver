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


#include "locale/textdomain/textdomain_agent.h"
#include <libintl.h>
#include <locale.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict bind_textdomain_codeset_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    char* codeset;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);
    codeset = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = bind_textdomain_codeset(domainname, codeset);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict bindtextdomain_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    char* dirname;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);
    dirname = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;    
    res = bindtextdomain(domainname, dirname);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dcgettext_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    char* msgid;
    int category;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);
    msgid = readString(&stream);
    category = readInt(&stream);
    errno_save = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = errno_save;
    res = dcgettext(domainname, msgid, category);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dcngettext_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    char* msgid1;
    char* msgid2;
    unsigned long int n;
    int category;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);
    msgid1 = readString(&stream);
    msgid2 = readString(&stream);
    n = readULong(&stream);
    category = readInt(&stream);
    errno_save = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = errno_save;
    res = dcngettext(domainname, msgid1, msgid2, n, category);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dgettext_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    char* msgid;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);
    msgid = readString(&stream);
    errno_save = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = errno_save;
    res = dgettext(domainname, msgid);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dngettext_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    char* msgid1;
    char* msgid2;
    unsigned long int n;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);
    msgid1 = readString(&stream);
    msgid2 = readString(&stream);
    n = readULong(&stream);
    errno_save = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = errno_save;
    res = dngettext(domainname, msgid1, msgid2, n);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gettext_cmd(TAThread thread, TAInputStream stream)
{
    char* msgid;
    int errno_save;
    char* res;

    // Prepare
    msgid = readString(&stream);
    errno_save = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = errno_save;
    res = gettext(msgid);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ngettext_cmd(TAThread thread, TAInputStream stream)
{
    char* msgid1;
    char* msgid2;
    unsigned long int n;
    int errno_save;
    char* res;

    // Prepare
    msgid1 = readString(&stream);
    msgid2 = readString(&stream);
    n = readULong(&stream);
    errno_save = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = errno_save;
    res = ngettext(msgid1, msgid2, n);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict textdomain_cmd(TAThread thread, TAInputStream stream)
{
    char* domainname;
    int errno_save;
    char* res;

    // Prepare
    domainname = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;    
    res = textdomain(domainname);
    errno_save = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno_save);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_textdomain_commands(void)
{
    ta_register_command("bind_textdomain_codeset", bind_textdomain_codeset_cmd);
    ta_register_command("bindtextdomain", bindtextdomain_cmd);
    ta_register_command("dcgettext", dcgettext_cmd);
    ta_register_command("dcngettext", dcngettext_cmd);
    ta_register_command("dgettext", dgettext_cmd);
    ta_register_command("dngettext", dngettext_cmd);
    ta_register_command("gettext", gettext_cmd);
    ta_register_command("ngettext", ngettext_cmd);
    ta_register_command("textdomain", textdomain_cmd);
}
