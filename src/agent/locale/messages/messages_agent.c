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


#include "locale/messages/messages_agent.h"

#include <string.h>
#include <stdio.h>
#include <errno.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict perror_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char buf[4096];
    int buf_size;
    FILE* temp_stderr = stderr;
    char* s = readString(&stream);
    errno = readInt(&stream);

    stderr = fopen(ta_get_test_file_path("stderr.dat"), "wb");

    START_TARGET_OPERATION(thread);

    // Execute
    perror(s);

    END_TARGET_OPERATION(thread);

    fclose(stderr);
    stderr = temp_stderr;

    temp_stderr = fopen(ta_get_test_file_path("stderr.dat"), "rb");

    buf_size = fread(buf, 1, 4096, temp_stderr);

    fclose(temp_stderr);

    // Response
    writeLimitedString(thread, buf, buf_size);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strerror_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char* res;
    int errnum = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = strerror(errnum);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strerror_r_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    char* res;
    int errnum = readInt(&stream);
    char* s = (char*)readPointer(&stream);
    int buflen = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = strerror_r(errnum, s, buflen);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_locale_messages_commands(void)
{
    ta_register_command("perror", perror_cmd);
    ta_register_command("strerror", strerror_cmd);
    ta_register_command("strerror_r", strerror_r_cmd);
}

