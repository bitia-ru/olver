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

#include "io/fstream/lock_agent.h"

#include <stddef.h>
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

static TACommandVerdict flockfile_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;

    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    flockfile(file);
    END_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftrylockfile_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;
    int res;

    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res=ftrylockfile(file);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict funlockfile_cmd(TAThread thread,TAInputStream stream)
{
    FILE*  file ;

    file=(FILE*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    funlockfile(file);
    END_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_io_fstream_lock_commands(void)
{
    ta_register_command("flockfile",flockfile_cmd);
    ta_register_command("ftrylockfile",ftrylockfile_cmd);
    ta_register_command("funlockfile",funlockfile_cmd);
}
