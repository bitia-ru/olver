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

#include "io/fstream/buffer_agent.h"
# include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "fs/fs/fs_agent.h"
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/uio.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict setbuf_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;
    char* buf;

    file=(FILE*)readPointer(&stream);
    buf=(char*)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    setbuf(file, buf);
    END_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setbuffer_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;
    char*  buf;
    size_t size;

    file=(FILE*)readPointer(&stream);
    buf=(char*)readPointer(&stream);
    size=readSize(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    setbuffer(file, buf, size);
    END_TARGET_OPERATION(thread);

    writeInt( thread, errno );
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setvbuf_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;
    char*  buf;
    int    type;
    size_t size;
    int res;

    file=(FILE*)readPointer(&stream);
    buf=(char*)readPointer(&stream);
    type=readInt(&stream);
    size=readSize(&stream);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = setvbuf(file, buf, type, size);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_io_fstream_buffer_commands(void)
{
    ta_register_command("setbuf",setbuf_cmd);
    ta_register_command("setbuffer",setbuffer_cmd);
    ta_register_command("setvbuf",setvbuf_cmd);
}
