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


#include <fcntl.h>
#include <string.h>
#include "io/file/file_agent.h"
#include "fs/fs/fs_agent.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/uio.h>
#include "fs/fifo/fifo_agent.h"


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict mkfifo_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int mode;
    int res;

    // Prepare
    path = readString(&stream);
    mode = readFilePermissions(&stream);


    START_TARGET_OPERATION(thread);

    res = mkfifo(path, mode);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict write_fifo_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    res = write(fildes, buf, nbyte);
    END_TARGET_OPERATION(thread);


    writeDeferredReaction(thread, "write_fifo_return");

    // Response
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}



static TACommandVerdict read_fifo_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf    = readPointer(&stream);
    nbyte  = readSize(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    res = read(fildes, buf, nbyte);
    END_TARGET_OPERATION(thread);


    writeDeferredReaction(thread, "read_fifo_return");

    // Response
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict writev_fifo_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int size;
    int i=0;
    void* curPointer;
    size_t curSize;
    struct iovec *iov;
    ssize_t res;


    // Prepare
    fildes = readInt(&stream);
    size = readInt(&stream);

    iov=(struct iovec *)ta_alloc_memory(size*sizeof(struct iovec));

    for (i=0;i<size;i++)
    {
        curPointer=readPointer(&stream);
        curSize=readSize(&stream);
        iov[i].iov_base=curPointer;
        iov[i].iov_len=curSize;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    res = writev(fildes, iov, size);
    END_TARGET_OPERATION(thread);


    writeDeferredReaction(thread, "writev_fifo_return");

    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(iov);

    return taDefaultVerdict;
}


static TACommandVerdict readv_fifo_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int size;
    int i=0;
    void* curPointer;
    size_t curSize;
    struct iovec *iov;
    ssize_t res;


    // Prepare
    fildes = readInt(&stream);
    size = readInt(&stream);

    iov=(struct iovec *)ta_alloc_memory(size*sizeof(struct iovec));

    for (i=0;i<size;i++)
    {
        curPointer=readPointer(&stream);
        curSize=readSize(&stream);
        iov[i].iov_base=curPointer;
        iov[i].iov_len=curSize;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    res = readv(fildes, iov, size);
    END_TARGET_OPERATION(thread);

    writeDeferredReaction(thread, "readv_fifo_return");

    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(iov);

    return taDefaultVerdict;
}


static TACommandVerdict open_fifo_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int oflag;
    int is_not_null;
    int mode;
    int res;

    // Prepare
    path = readString(&stream);
    oflag = readOpenFlags(&stream);
    if (startsWith_TAInputStream(&stream,"null:"))
     {
      is_not_null = 0;
      verifyType_TAInputStream(&stream,"null");
     }
    else
     {
      is_not_null = 1;
      mode = readFilePermissions(&stream);
     }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);

    // Execute
    if (is_not_null)
     {
      res = open(path,oflag,mode);
     }
    else
     {
      res = open(path,oflag);
     }

    END_TARGET_OPERATION(thread);


    writeDeferredReaction(thread, "open_fifo_return");

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict open64_fifo_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int oflag;
    int is_not_null;
    int mode;
    int res;

    // Prepare
    path = readString(&stream);
    oflag = readOpenFlags(&stream);
    if (startsWith_TAInputStream(&stream,"null:"))
    {
        is_not_null = 0;
        verifyType_TAInputStream(&stream,"null");
    }
    else
    {
        is_not_null = 1;
        mode = readFilePermissions(&stream);
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    if (is_not_null)
    {
        res = open64(path,oflag,mode);
    }
    else
    {
        res = open64(path,oflag);
    }

    END_TARGET_OPERATION(thread);


    writeDeferredReaction(thread, "open_fifo_return");


    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_fifo_commands(void)
{
    ta_register_command("mkfifo",mkfifo_cmd);
    ta_register_command("write_fifo", write_fifo_cmd);
    ta_register_command("read_fifo", read_fifo_cmd);
    ta_register_command("writev_fifo", writev_fifo_cmd);
    ta_register_command("readv_fifo", readv_fifo_cmd);
    ta_register_command("open_fifo", open_fifo_cmd);
    ta_register_command("open64_fifo", open64_fifo_cmd);
}

