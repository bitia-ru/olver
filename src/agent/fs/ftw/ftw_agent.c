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

#include <errno.h>
#include <ftw.h>

#include "fs/ftw/ftw_agent.h"
#include "fs/meta/meta_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                            Writers                             **/
/********************************************************************/
void writeFTWFunctionFlag(TAThread thread, int flag)
{
    switch(flag)
    {
    case FTW_F:
        writeInt(thread, 0);
        return;
    case FTW_D:
        writeInt(thread, 1);
        return;
    case FTW_DNR:
        writeInt(thread, 2);
        return;
    case FTW_DP:
        writeInt(thread, 3);
        return;
    case FTW_NS:
        writeInt(thread, 4);
        return;
    case FTW_SL:
        writeInt(thread, 5);
        return;
    case FTW_SLN:
        writeInt(thread, 6);
        return;
    default:
        writeInt(thread, -1);
        return;
    }
}

void writeFTWStructure(TAThread thread, const struct FTW *ftw_struct)
{
    if(ftw_struct == NULL)
    {
        writeType_TAStream(thread, "null");
        return;
    }

    writeType_TAStream(thread, "ftw");

    writeInt(thread, ftw_struct->base);
    writeInt(thread, ftw_struct->level);
}

void writeFTWFunctionCall
(
    TAThread thread,
    const char *path,
    const struct stat *file_stat,
    int flag,
    const struct FTW *ftw_struct,
    const char *cwd,
    int result
)
{
    writeType_TAStream(thread, "ftwcall");

    writeString(thread, path);
    writeFileStatus(thread, file_stat);
    writeFTWFunctionFlag(thread, flag);
    writeFTWStructure(thread, ftw_struct);
    writeString(thread, cwd);
    writeInt(thread, result);
}

void writeFTW64FunctionCall
(
    TAThread thread,
    const char *path,
    const struct stat64 *file_stat,
    int flag,
    const struct FTW *ftw_struct,
    const char *cwd,
    int result
)
{
    writeType_TAStream(thread, "ftwcall");

    writeString(thread, path);
    writeFileStatus64(thread, file_stat);
    writeFTWFunctionFlag(thread, flag);
    writeFTWStructure(thread, ftw_struct);
    writeString(thread, cwd);
    writeInt(thread, result);
}

/********************************************************************/
/**       Functions for ftw(), ftw64(), nftw(), and nftw64()       **/
/********************************************************************/
volatile static int ftw_function_type = 0;
volatile static int ftw_function_param = 0;
volatile static int ftw_function_result = 0;

static int ftw_function(const char *path, const struct stat *file_stat, int flags)
{
    char buffer[1024];
    int result = ftw_function_result;
    TAThread thread = ta_current_thread();

    if(ftw_function_type == 1 && ftw_function_param > 0)
    {
        result = 0;
        ftw_function_param--;
    }

    writeFTWFunctionCall(thread, path, file_stat, flags, NULL, getcwd(buffer, 1024), result);

    return result;
}

static int ftw64_function(const char *path, const struct stat64 *file_stat, int flags)
{
    char buffer[1024];
    int result = ftw_function_result;
    TAThread thread = ta_current_thread();

    if(ftw_function_type == 1 && ftw_function_param > 0)
    {
        result = 0;
        ftw_function_param--;
    }

    writeFTW64FunctionCall(thread, path, file_stat, flags, NULL, getcwd(buffer, 1024), result);

    return result;
}

static int nftw_function(const char *path, const struct stat *file_stat, int flags, struct FTW *ftw_struct)
{
    char buffer[1024];
    int result = ftw_function_result;
    TAThread thread = ta_current_thread();

    if(ftw_function_type == 1 && ftw_function_param > 0)
    {
        result = 0;
        ftw_function_param--;
    }

    writeFTWFunctionCall(thread, path, file_stat, flags, ftw_struct, getcwd(buffer, 1024), result);

    return result;
}

static int nftw64_function(const char *path, const struct stat64 *file_stat, int flags, struct FTW *ftw_struct)
{
    char buffer[1024];
    int result = ftw_function_result;
    TAThread thread = ta_current_thread();

    if(ftw_function_type == 1 && ftw_function_param > 0)
    {
        result = 0;
        ftw_function_param--;
    }

    writeFTW64FunctionCall(thread, path, file_stat, flags, ftw_struct, getcwd(buffer, 1024), result);

    return result;
}

/********************************************************************/
/**                            Readers                             **/
/********************************************************************/
static int readNFTWFlags(TAInputStream *stream)
{
    int res = 0;

    // TODO: Bug in LSB 3.1 environment
    int FTW_PHYS  = 1;
    int FTW_MOUNT = 2;
    int FTW_DEPTH = 8;
    int FTW_CHDIR = 4;

    verifyType_TAInputStream(stream, "nftwflags");

    res = (readChar(stream) != '\x00' ? res | FTW_PHYS  : res);
    res = (readChar(stream) != '\x00' ? res | FTW_MOUNT : res);
    res = (readChar(stream) != '\x00' ? res | FTW_DEPTH : res);
    res = (readChar(stream) != '\x00' ? res | FTW_CHDIR : res);

    return res;
}

static int (*readFTWFunction(TAInputStream *stream))(const char *, const struct stat *, int)
{
    if(startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return NULL;
    }

    verifyType_TAInputStream(stream, "ftwfunc");

    ftw_function_type = readInt(stream);
    ftw_function_param = readInt(stream);
    ftw_function_result = readInt(stream);

    return ftw_function;
}

static int (*readFTW64Function(TAInputStream *stream))(const char *, const struct stat64 *, int)
{
    if(startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return NULL;
    }

    verifyType_TAInputStream(stream, "ftwfunc");

    ftw_function_type = readInt(stream);
    ftw_function_param = readInt(stream);
    ftw_function_result = readInt(stream);

    return ftw64_function;
}

static int (*readNFTWFunction(TAInputStream *stream))(const char *, const struct stat *, int, struct FTW *)
{
    if(startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return NULL;
    }

    verifyType_TAInputStream(stream, "ftwfunc");

    ftw_function_type = readInt(stream);
    ftw_function_param = readInt(stream);
    ftw_function_result = readInt(stream);

    return nftw_function;
}

static int (*readNFTW64Function(TAInputStream *stream))(const char *, const struct stat64 *, int, struct FTW *)
{
    if(startsWith_TAInputStream(stream, "null:"))
    {
        verifyType_TAInputStream(stream, "null");
        return NULL;
    }

    verifyType_TAInputStream(stream, "ftwfunc");

    ftw_function_type = readInt(stream);
    ftw_function_param = readInt(stream);
    ftw_function_result = readInt(stream);

    return nftw64_function;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict ftw_cmd(TAThread thread, TAInputStream stream)
{
    char *path;
    int (*fn)(const char *, const struct stat *, int);
    int ndirs, res;

    // Prepare
    path = readString(&stream);
    fn = readFTWFunction(&stream);
    ndirs = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = ftw(path, fn, ndirs);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, NULL);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftw64_cmd(TAThread thread, TAInputStream stream)
{
    char *path;
    int (*fn)(const char *, const struct stat64 *, int);
    int ndirs, res;

    // Prepare
    path = readString(&stream);
    fn = readFTW64Function(&stream);
    ndirs = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = ftw64(path, fn, ndirs);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, NULL);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nftw_cmd(TAThread thread, TAInputStream stream)
{
    char *path;
    int (*fn)(const char *, const struct stat *, int, struct FTW *);
    int fd_limit, flags, res;

    // Prepare
    path = readString(&stream);
    fn = readNFTWFunction(&stream);
    fd_limit = readInt(&stream);
    flags = readNFTWFlags(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = nftw(path, fn, fd_limit, flags);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, NULL);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict nftw64_cmd(TAThread thread, TAInputStream stream)
{
    char *path;
    int (*fn)(const char *, const struct stat64 *, int, struct FTW *);
    int fd_limit, flags, res;

    // Prepare
    path = readString(&stream);
    fn = readNFTW64Function(&stream);
    fd_limit = readInt(&stream);
    flags = readNFTWFlags(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = nftw64(path, fn, fd_limit, flags);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, NULL);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_ftw_commands(void)
{
    ta_register_command("ftw", ftw_cmd);
    ta_register_command("ftw64", ftw64_cmd);
    ta_register_command("nftw", nftw_cmd);
    ta_register_command("nftw64", nftw64_cmd);

    ta_register_command( "appendIfFileExists", appendIfFileExists_cmd );
}
