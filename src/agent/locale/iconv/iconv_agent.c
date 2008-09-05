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


#include "locale/iconv/iconv_agent.h"
#include <iconv.h>
#include <errno.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict iconv_cmd(TAThread thread, TAInputStream stream)
{
    iconv_t cd;
    char* inbuf;
    char* outbuf;
    size_t inbytesleft;
    size_t outbytesleft;
    size_t res;
    int save_errno;

    // Prepare
    cd = (iconv_t)readPointer(&stream);
    inbuf = (char*)readPointer(&stream);
    inbytesleft = readSize(&stream);
    outbuf = (char*)readPointer(&stream);
    outbytesleft = readSize(&stream);

	errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute
    res = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeSize(thread, res);
    writePointer(thread, inbuf);
    writeSize(thread, inbytesleft);
    writePointer(thread, outbuf);
    writeSize(thread, outbytesleft);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict iconv_close_cmd(TAThread thread, TAInputStream stream)
{
    iconv_t cd;
    int res;
    int save_errno;

    // Prepare
    cd = (iconv_t)readPointer(&stream);

	errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute
    res = iconv_close(cd);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict iconv_open_cmd(TAThread thread, TAInputStream stream)
{
    char* tocode;
    char* fromcode;
    iconv_t res;
    int save_errno;

    // Prepare
    tocode = readString(&stream);
    fromcode = readString(&stream);

	errno = 0;
	
    START_TARGET_OPERATION(thread);

    // Execute
    res = iconv_open(tocode, fromcode);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_iconv_commands(void)
{
    ta_register_command("iconv", iconv_cmd);
    ta_register_command("iconv_close", iconv_close_cmd);
    ta_register_command("iconv_open", iconv_open_cmd);
}
