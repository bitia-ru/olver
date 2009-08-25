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

#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include "fs/dir/dir_agent.h"
#include "fs/fs/fs_agent.h"
#include <string.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static void remove_dir(char* sz_dir)
{
    char subname[4096];
    DIR *pdir = NULL;
    struct dirent *pdirent = NULL;
    int status;
    char* strer;

    VERBOSE("destroying folder: %s\n", sz_dir);

    status = setuid(0);
    status = setgid(0);

    errno=0;
    pdir = opendir(sz_dir);
    if (pdir) {
        while ((pdirent = readdir(pdir)) != NULL) {
            struct stat buffer;
            sprintf(subname, "%s/%s", sz_dir, pdirent->d_name);
            status = lstat(subname, &buffer);

            if (S_ISDIR(buffer.st_mode)
                && strcmp(pdirent->d_name, ".") != 0
                && strcmp(pdirent->d_name, "..") != 0) {
                sprintf(subname, "%s/%s", sz_dir, pdirent->d_name);
                VERBOSE("cleaning dir: %s\n", subname);
                remove_dir(subname);
            } else /*sock, reg, lnk, fifo, chr, blk*/ {
                status = remove(subname);
                VERBOSE("removing file: %s\n", subname);
            }
        }
        closedir(pdir);
        VERBOSE("removing dir: %s\n", sz_dir);
        remove(sz_dir);
    }
    else {
        strer = strerror(errno);

        VERBOSE("Error in reading %s : %s\n", sz_dir, strer);
    }
}

static TACommandVerdict remove_dir_recursive_cmd(TAThread thread, TAInputStream stream)
{

    // Prepare
    char *path;

    path = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    remove_dir(path);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict closedir_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    DIR *dirp = readPointer(&stream);
    int res;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Execute
    errno = 0;
    res = closedir(dirp);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict mkdir_cmd(TAThread thread, TAInputStream stream)
{

    int res;
    // Prepare
    const char *path;
    mode_t mode;

    path = readString(&stream);
    mode = readFilePermissions(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = mkdir(path, mode);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict opendir_cmd(TAThread thread, TAInputStream stream)
{

    // Prepare
    const char *path = readString(&stream);
    DIR *dirp = NULL;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Execute
    errno = 0;
    dirp = opendir( path );

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Response
    writePointer(thread, dirp);
    writeInt(thread, errno);
    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict readdir_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    DIR *dirp = readPointer(&stream);

    struct dirent *dirent;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Execute
    errno = 0;
    dirent = readdir(dirp);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Response
    writePointer(thread, dirent);
    if(NULL!=dirent)
    {
        writeULLong(thread, dirent->d_ino);
        writeString(thread, dirent->d_name);
    }
    writeInt(thread, errno);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict readdir64_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    DIR *dirp = readPointer(&stream);

    struct dirent64 *dirent;

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    dirent = readdir64(dirp);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, dirent);
    if(NULL!=dirent)
    {
        writeULLong(thread, dirent->d_ino);
        writeString(thread, dirent->d_name);
    }
    writeInt(thread, errno);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict readdir_r_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    DIR *dirp = readPointer(&stream);

    struct dirent dirent, *direntp;
    int retval;

    int name_max;

/* readdir_r.02
* The storage pointed to by entry shall be large enough for a dirent with an
* array of char d_name members containing at least {NAME_MAX}+1 elements.
*/

/* According to limits.36, Minimum Acceptable Value for NAME_MAX is
    _POSIX_NAME_MAX

   TODO: It seems that more correct way is to get real NAME_MAX here.
*/


    /*name_max = _POSIX_NAME_MAX;
    if(sizeof(dirent.d_name)<name_max+1)
    {
        sendException(thread, "readdir_r_cmd: sizeof(dirent.d_name)<NAME_MAX+1");
        return taDefaultVerdict;
    }*/


    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Execute
    retval = readdir_r(dirp, &dirent, &direntp);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Response
    writePointer(thread, direntp);
    writePointer(thread, &dirent);
    if(NULL!=direntp)
    {
        writeLong(thread, direntp->d_ino);
        writeString(thread, direntp->d_name);
    }
    writeInt(thread, retval);
    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict rewinddir_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare

    DIR* dirp = readPointer(&stream);

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Execute
    errno = 0;
    rewinddir(dirp);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict rmdir_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    int res;
    const char *path = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = rmdir(path);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict seekdir_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare

    DIR *dirp = readPointer(&stream);
    long loc = readLong(&stream);

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Execute
    errno = 0;
    seekdir(dirp, loc);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict telldir_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    DIR *dirp = readPointer(&stream);
    long retval;

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    retval = telldir(dirp);

    END_TARGET_OPERATION(thread);

    // Response
    writeLong(thread, retval);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_dir_commands(void)
{
    ta_register_command("closedir",closedir_cmd);
    ta_register_command("mkdir",mkdir_cmd);
    ta_register_command("opendir",opendir_cmd);
    ta_register_command("readdir",readdir_cmd);
    ta_register_command("readdir64",readdir64_cmd);
    ta_register_command("readdir_r",readdir_r_cmd);
    ta_register_command("rewinddir",rewinddir_cmd);
    ta_register_command("rmdir",rmdir_cmd);
    ta_register_command("seekdir",seekdir_cmd);
    ta_register_command("telldir",telldir_cmd);
    ta_register_command("remove_dir_recursive", remove_dir_recursive_cmd);
}

