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

#include "fs/meta/statvfs_agent.h"
#include <sys/statvfs.h>
#include <errno.h>

void writeMountPointStatus(TAThread thread, struct statvfs* buff)
{
    writeULong(thread, buff->f_bsize);
    writeULong(thread, buff->f_frsize);

    writeULLong(thread, buff->f_blocks);
    writeULLong(thread, buff->f_bfree);
    writeULLong(thread, buff->f_bavail);
    writeULLong(thread, buff->f_files);
    writeULLong(thread, buff->f_ffree);
    writeULLong(thread, buff->f_favail);

    writeULong(thread, buff->f_fsid);
//    writeInt(thread, (buff->f_flag & ST_RDONLY ? 1 : 0));
//    writeInt(thread, (buff->f_flag & ST_NOSUID ? 1 : 0));
    writeInt(thread, 0);
    writeInt(thread, 0);
    writeULong(thread, buff->f_namemax);
}
void writeMountPointStatus64(TAThread thread, struct statvfs64* buff)
{
    writeULong(thread, buff->f_bsize);
    writeULong(thread, buff->f_frsize);

    writeULLong(thread, buff->f_blocks);
    writeULLong(thread, buff->f_bfree);
    writeULLong(thread, buff->f_bavail);
    writeULLong(thread, buff->f_files);
    writeULLong(thread, buff->f_ffree);
    writeULLong(thread, buff->f_favail);

    writeULong(thread, buff->f_fsid);
//    writeInt(thread, (buff->f_flag & ST_RDONLY ? 1 : 0));
//    writeInt(thread, (buff->f_flag & ST_NOSUID ? 1 : 0));
    writeInt(thread, 0);
    writeInt(thread, 0);
    writeULong(thread, buff->f_namemax);
}
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict fstatvfs_cmd(TAThread thread, TAInputStream stream)
{
    struct statvfs buffer;
    int res;
    int fildes;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = fstatvfs(fildes, &buffer);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeMountPointStatus(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fstatvfs64_cmd(TAThread thread, TAInputStream stream)
{
    struct statvfs64 buffer;
    int res;
    int fildes;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = fstatvfs64(fildes, &buffer);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeMountPointStatus64(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict statvfs_cmd(TAThread thread,TAInputStream stream)
{
    struct statvfs buffer;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = statvfs(path, &buffer);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeMountPointStatus(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict statvfs64_cmd(TAThread thread,TAInputStream stream)
{
    struct statvfs64 buffer;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = statvfs64(path, &buffer);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeMountPointStatus64(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_meta_statvfs_commands(void)
{
    ta_register_command("fstatvfs",fstatvfs_cmd);
    ta_register_command("fstatvfs64",fstatvfs64_cmd);
    ta_register_command("statvfs",statvfs_cmd);
    ta_register_command("statvfs64",statvfs64_cmd);
}

