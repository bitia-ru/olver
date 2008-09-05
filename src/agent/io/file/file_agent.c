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
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/file.h>
#include <sys/uio.h>


/********************************************************************/
/**                        Format Functions                        **/
/********************************************************************/

/* AccessMode */
int readAccessMode(TAInputStream* stream)
{
char* value = readString(stream);

    if (strcmp(value,"O_RDONLY") == 0)
        return O_RDONLY;
    if (strcmp(value,"O_WRONLY") == 0)
        return O_WRONLY;
    if (strcmp(value,"O_RDWR") == 0)
        return O_RDWR;
    assertion( 0, "Invalid access mode: %s", value );
    return -1;
}


void writeAccessMode(TAThread thread, int mode)
{

    if (mode==O_RDONLY)
    {
        writeInt(thread, 0);
    }
    else if (mode==O_WRONLY)
    {
        writeInt(thread, 1);
    }
    else if (mode==O_RDWR)
    {
        writeInt(thread, 2);
    }
    else
    {
        assertion( 0, "Invalid access mode: %d", mode );
    }
}


/* BlockMode */
int readBlockMode(TAInputStream* stream)
{
char* value = readString(stream);

    if (strcmp(value,"O_BLOCK") == 0)
        return 0;
    if (strcmp(value,"O_NONBLOCK") == 0)
        return O_NONBLOCK;
    assertion( 0, "Invalid block mode: %s", value );
    return -1;
}



/* OpenFlags */
int readOpenFlags(TAInputStream* stream)
{
int res;

    verifyType_TAInputStream(stream,"openflags");
    res = readAccessMode(stream);
    res = res | readBlockMode(stream);
    res = res | (readInt(stream) ? O_APPEND : 0);
    res = res | (readInt(stream) ? O_CREAT : 0);
    res = res | (readInt(stream) ? O_TRUNC : 0);
    res = res | (readInt(stream) ? O_NOCTTY : 0);

    res = res | (readInt(stream) ? O_LARGEFILE : 0);
    return res;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict close_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res;

    fildes=readInt(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res =  close(fildes);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict creat_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int mode;
    int res;

    // Prepare
    path = readString(&stream);
    mode = readFilePermissions(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    res = creat(path, mode);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict creat64_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int mode;
    int res;

    // Prepare
    path = readString(&stream);
    mode = readFilePermissions(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    res = creat64(path, mode);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dup_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res;

    // Prepare
    fildes = readInt(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    res = dup(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict dup2_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, fildes2;
    int res;

    // Prepare
    fildes = readInt(&stream);
    fildes2 = readInt(&stream);

    errno = 0;
  
    START_TARGET_OPERATION(thread);

    res = dup2(fildes, fildes2);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fcntl_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, cmd;
    int isInt;
    int intArg;
    struct flock lock;
    int res;

    // Prepare
    fildes = readInt(&stream);
    cmd = readInt(&stream);
    isInt = readInt(&stream);
    
    errno = 0;

    if (isInt)
    {
        intArg = readInt(&stream);

        START_TARGET_OPERATION(thread);
        res = fcntl(fildes, cmd, intArg);
        END_TARGET_OPERATION(thread);
    }
    else
    {
        lock.l_type = readInt(&stream);
        lock.l_whence = readInt(&stream);
        lock.l_start = readLLong(&stream);
        lock.l_len = readLLong(&stream);
        lock.l_pid = readInt(&stream);

        START_TARGET_OPERATION(thread);
        res = fcntl(fildes, cmd, &lock);
        END_TARGET_OPERATION(thread);
    }


    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict fcntl_F_GETFL_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    
    errno = 0;
        
    START_TARGET_OPERATION(thread);
        res = fcntl(fildes, F_GETFL);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeAccessMode(thread, res & O_ACCMODE);
    writeInt(thread, res&O_NONBLOCK);
    writeInt(thread, res&O_APPEND);
    
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict fcntl_F_SETFL_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, block_mode, append_flag;
    int flags_to_set=0;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    block_mode = readInt(&stream);
    append_flag = readInt(&stream);
    
    errno = 0;
    
    if (block_mode)
    {
        flags_to_set= flags_to_set|O_NONBLOCK;
    }

    if (append_flag)
    {
        flags_to_set= flags_to_set|O_APPEND;
    }

    START_TARGET_OPERATION(thread);
    res = fcntl(fildes, F_SETFL, flags_to_set);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict fcntl_F_GETLCK_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, cmd;
    int isInt;
    int intArg;
    struct flock lock;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    lock.l_type = readInt(&stream);
    lock.l_whence = readInt(&stream);
    lock.l_start = readLLong(&stream);
    lock.l_len = readLLong(&stream);
    lock.l_pid = readInt(&stream);
      
    errno = 0;
            
    START_TARGET_OPERATION(thread);
    res = fcntl(fildes, F_GETLK, &lock);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeInt(thread, res);

    writeInt(thread, lock.l_type);
    writeInt(thread, lock.l_whence);
    writeLLong(thread, lock.l_start);
    writeLLong(thread, lock.l_len);
    writeInt(thread, lock.l_pid);
   
    
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict fcntl_F_SETLKW_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, cmd;
    int isInt;
    int intArg;
    struct flock lock;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    lock.l_type = readInt(&stream);
    lock.l_whence = readInt(&stream);
    lock.l_start = readLLong(&stream);
    lock.l_len = readLLong(&stream);
    lock.l_pid = readInt(&stream);
    

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    
    writeString(thread,"Ok");
    sendResponse(thread);

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = fcntl(fildes, F_SETLKW, &lock);
    END_TARGET_OPERATION(thread);
    
    
    writeDeferredReaction(thread, "fcntl_F_SETLKW_return");

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict fdatasync_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res;

    // Prepare
    fildes = readInt(&stream);

    errno = 0;
   
    START_TARGET_OPERATION(thread);

    res = fdatasync(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict flock_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, operation, block;
    int res;

    // Prepare
    fildes = readInt(&stream);
    operation = readInt(&stream);
    block = readInt(&stream);

    if (block==0)
    {
        operation=operation|LOCK_NB;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    
    writeString(thread,"Ok");
    sendResponse(thread);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = flock(fildes, operation);
    END_TARGET_OPERATION(thread);

    writeDeferredReaction(thread, "flock_return");

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fsync_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res;

    // Prepare
    fildes = readInt(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    res = fsync(fildes);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftruncate_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    off_t length;
    int res;

    // Prepare
    fildes = readInt(&stream);
    length = readLLong(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = ftruncate(fildes, length);
    END_TARGET_OPERATION(thread);


    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ftruncate64_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    off_t length;
    int res;

    // Prepare
    fildes = readInt(&stream);
    length = readLLong(&stream);

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = ftruncate64(fildes, length);
    END_TARGET_OPERATION(thread);


    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lockf_lock_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, func;
    off_t size;
    int res;

    // Prepare
    fildes = readInt(&stream);
    size = readLLong(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    
    writeString(thread,"Ok");
    sendResponse(thread);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = lockf(fildes, F_LOCK, size);
    END_TARGET_OPERATION(thread);


    writeDeferredReaction(thread, "lockf_F_LOCK_return");
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lockf64_lock_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, func;
    off_t size;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    size = readLLong(&stream);
    
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    
    writeString(thread,"Ok");
    sendResponse(thread);
    
    errno = 0;    
    
    START_TARGET_OPERATION(thread);
    res = lockf64(fildes, F_LOCK, size);
    END_TARGET_OPERATION(thread);
    
    
    writeDeferredReaction(thread, "lockf_F_LOCK_return");
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}




static TACommandVerdict lockf_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, func;
    off_t size;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    func = readInt(&stream);
    size = readLLong(&stream);
   
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = lockf(fildes, func, size);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lockf64_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, func;
    off_t size;
    int res;
    
    // Prepare
    fildes = readInt(&stream);
    func = readInt(&stream);
    size = readLLong(&stream);
 
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = lockf64(fildes, func, size);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict lseek_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, whence;
    off_t offset;
    off_t res;

    // Prepare
    fildes = readInt(&stream);
    offset = readLLong(&stream);
    whence = readInt(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = lseek(fildes, offset, whence);
    END_TARGET_OPERATION(thread);


    // Response
    writeLLong(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lseek64_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, whence;
    off_t offset;
    off_t res;

    // Prepare
    fildes = readInt(&stream);
    offset = readLLong(&stream);
    whence = readInt(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = lseek64(fildes, offset, whence);
    END_TARGET_OPERATION(thread);


    // Response
    writeLLong(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict open_cmd(TAThread thread,TAInputStream stream)
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
     
    errno = 0;

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

    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict open64_cmd(TAThread thread,TAInputStream stream)
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

    errno = 0;

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

    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pread_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;
    off_t offset;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);
    offset=readLLong(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = pread(fildes, buf, nbyte, offset);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pread64_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;
    off_t offset;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);
    offset=readLLong(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = pread64(fildes, buf, nbyte, offset);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pwrite_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;
    off_t offset;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);
    offset=readLLong(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = pwrite(fildes, buf, nbyte, offset);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pwrite64_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;
    off_t offset;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);
    offset=readLLong(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = pwrite64(fildes, buf, nbyte, offset);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict read_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = read(fildes, buf, nbyte);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict readv_cmd(TAThread thread,TAInputStream stream)
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

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = readv(fildes, iov, size);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(iov);

    return taDefaultVerdict;
}

static TACommandVerdict sync_cmd(TAThread thread,TAInputStream stream)
{
    // Execute
    START_TARGET_OPERATION(thread);
    sync();
    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict truncate_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    off_t length;
    int res;

    // Prepare
    path=readString(&stream);
    length=readLLong(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = truncate(path, length);

    END_TARGET_OPERATION(thread);


    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict truncate64_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    off_t length;
    int res;

    // Prepare
    path=readString(&stream);
    length=readLLong(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = truncate64(path, length);

    END_TARGET_OPERATION(thread);


    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict write_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    void* buf;
    size_t nbyte;

    ssize_t res;

    // Prepare
    fildes = readInt(&stream);
    buf=readPointer(&stream);
    nbyte=readSize(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = write(fildes, buf, nbyte);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict writev_cmd(TAThread thread,TAInputStream stream)
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

    errno = 0;

    START_TARGET_OPERATION(thread);
    res = writev(fildes, iov, size);
    END_TARGET_OPERATION(thread);


    // Response
    writeSSize(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);

    ta_dealloc_memory(iov);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_io_file_commands(void)
{
    ta_register_command("close",close_cmd);
    ta_register_command("creat",creat_cmd);
    ta_register_command("creat64",creat64_cmd);
    ta_register_command("dup",dup_cmd);
    ta_register_command("dup2",dup2_cmd);
    ta_register_command("fcntl",fcntl_cmd);
    ta_register_command("fdatasync",fdatasync_cmd);
    ta_register_command("flock",flock_cmd);
    ta_register_command("fsync",fsync_cmd);
    ta_register_command("ftruncate",ftruncate_cmd);
    ta_register_command("ftruncate64",ftruncate64_cmd);
    ta_register_command("lockf",lockf_cmd);
    ta_register_command("lockf64",lockf64_cmd);

    ta_register_command("lockf_lock",lockf_lock_cmd);
    ta_register_command("lockf64_lock",lockf64_lock_cmd);

    ta_register_command("lseek",lseek_cmd);
    ta_register_command("lseek64",lseek64_cmd);
    ta_register_command("open",open_cmd);
    ta_register_command("open64",open64_cmd);
    ta_register_command("pread",pread_cmd);
    ta_register_command("pread64",pread64_cmd);
    ta_register_command("pwrite",pwrite_cmd);
    ta_register_command("pwrite64",pwrite64_cmd);
    ta_register_command("read",read_cmd);
    ta_register_command("readv",readv_cmd);
    ta_register_command("sync",sync_cmd);
    ta_register_command("truncate",truncate_cmd);
    ta_register_command("truncate64",truncate64_cmd);
    ta_register_command("write",write_cmd);
    ta_register_command("writev",writev_cmd);

    ta_register_command("fcntl_GETFL", fcntl_F_GETFL_cmd);
    ta_register_command("fcntl_SETFL", fcntl_F_SETFL_cmd);
    ta_register_command("fcntl_GETLCK",  fcntl_F_GETLCK_cmd);
    ta_register_command("fcntl_SETLKW", fcntl_F_SETLKW_cmd);
}

