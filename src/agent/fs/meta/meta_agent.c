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


#include "fs/meta/meta_agent.h"

void writeFileStatus(TAThread thread, struct stat* buffer)
{
    writeULLong(thread, buffer->st_dev);
    writeULong(thread, buffer->st_ino);

     //Encoding st_mode
    if(S_ISBLK(buffer->st_mode))
        writeInt(thread, 1);
    else
    if(S_ISCHR(buffer->st_mode))
        writeInt(thread, 2);
    else
    if(S_ISFIFO(buffer->st_mode))
        writeInt(thread, 3);
    else
    if(S_ISREG(buffer->st_mode))
        writeInt(thread, 4);
    else
    if(S_ISDIR(buffer->st_mode))
        writeInt(thread, 5);
    else
    if(S_ISLNK(buffer->st_mode))
        writeInt(thread, 6);
    else
    if(S_ISSOCK(buffer->st_mode))
        writeInt(thread, 7);
    else
    if(S_TYPEISMQ(buffer))
        writeInt(thread, 8);
    else
    if(S_TYPEISSEM(buffer))
        writeInt(thread, 9);
    else
    if(S_TYPEISSHM(buffer))
        writeInt(thread, 10);
#ifdef S_TYPEISTMO
    else
    if(S_TYPEISTMO(buffer))
        writeInt(thread, 11);
#endif
    else
        writeInt(thread, 0);

    //Encoding S_IRWXU
    if(buffer->st_mode & S_IRUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IWUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IXUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);

    //Encoding S_IRWXG
    if(buffer->st_mode & S_IRGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IWGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IXGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);

    //Encoding S_IRWXO
    if(buffer->st_mode & S_IROTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IWOTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IXOTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);


    if(buffer->st_mode & S_ISUID)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_ISGID)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_ISVTX)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);

    //End of encoding st_mode

    writeULong(thread, buffer->st_nlink);

    writeUInt(thread, buffer->st_uid);

    writeUInt(thread, buffer->st_gid);

    writeULLong(thread, buffer->st_rdev);

    writeLLong(thread, buffer->st_size);

    writeLong(thread, buffer->st_atime);

    writeLong(thread, buffer->st_mtime);

    writeLong(thread, buffer->st_ctime);

    writeLLong(thread, buffer->st_blksize);

    writeLLong(thread, buffer->st_blocks);

}
void writeFileStatus64(TAThread thread, struct stat64* buffer)
{
    writeULLong(thread, buffer->st_dev);
    writeULong(thread, buffer->st_ino);

     //Encoding st_mode
    if(S_ISBLK(buffer->st_mode))
        writeInt(thread, 1);
    else
    if(S_ISCHR(buffer->st_mode))
        writeInt(thread, 2);
    else
    if(S_ISFIFO(buffer->st_mode))
        writeInt(thread, 3);
    else
    if(S_ISREG(buffer->st_mode))
        writeInt(thread, 4);
    else
    if(S_ISDIR(buffer->st_mode))
        writeInt(thread, 5);
    else
    if(S_ISLNK(buffer->st_mode))
        writeInt(thread, 6);
    else
    if(S_ISSOCK(buffer->st_mode))
        writeInt(thread, 7);
    else
    if(S_TYPEISMQ(buffer))
        writeInt(thread, 8);
    else
    if(S_TYPEISSEM(buffer))
        writeInt(thread, 9);
    else
    if(S_TYPEISSHM(buffer))
        writeInt(thread, 10);
#ifdef S_TYPEISTMO
    else
    if(S_TYPEISTMO(buffer))
        writeInt(thread, 11);
#endif
    else
        writeInt(thread, 0);

    //Encoding S_IRWXU
    if(buffer->st_mode & S_IRUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IWUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IXUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);

    //Encoding S_IRWXG
    if(buffer->st_mode & S_IRGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IWGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IXGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);

    //Encoding S_IRWXO
    if(buffer->st_mode & S_IROTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IWOTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_IXOTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);


    if(buffer->st_mode & S_ISUID)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_ISGID)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(buffer->st_mode & S_ISVTX)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);

    //End of encoding st_mode

    writeULong(thread, buffer->st_nlink);

    writeUInt(thread, buffer->st_uid);

    writeUInt(thread, buffer->st_gid);

    writeULLong(thread, buffer->st_rdev);

    writeLLong(thread, buffer->st_size);

    writeLong(thread, buffer->st_atime);

    writeLong(thread, buffer->st_mtime);

    writeLong(thread, buffer->st_ctime);

    writeLLong(thread, buffer->st_blksize);

    writeLLong(thread, buffer->st_blocks);

}
struct utimbuf readUTimBuf(TAInputStream* stream)
{
    struct utimbuf res;

    verifyType_TAInputStream(stream,"utimbuf");

    res.actime=readLong(stream);
    res.modtime=readLong(stream);

    return res;
}
void readTimeValPair(TAInputStream* stream, struct timeval* times)
{
    verifyType_TAInputStream(stream,"timeval_list");

    times[0].tv_sec=readLong(stream);
    times[0].tv_usec=readLong(stream);
    times[1].tv_sec=readLong(stream);
    times[1].tv_usec=readLong(stream);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __fxstat_cmd(TAThread thread,TAInputStream stream)
{
    struct stat buffer;
    int res;
    int fildes;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
#if ( __i386__  || __powerpc__ || (__s390__ && !__s390x__))
    res = __fxstat(3, fildes, &buffer);
#else
    res = __fxstat(0, fildes, &buffer);
#endif    
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeFileStatus(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __fxstat64_cmd(TAThread thread,TAInputStream stream)
{
    struct stat64 buffer;
    int res;
    int fildes;

    // Prepare
    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
#if ( __i386__  || __powerpc__ || (__s390__ && !__s390x__))  
    res = __fxstat64(3, fildes, &buffer);
#else
    res = __fxstat64(0, fildes, &buffer);
#endif    
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeFileStatus64(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __lxstat_cmd(TAThread thread,TAInputStream stream)
{
    struct stat buffer;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
#if (__i386__ || __powerpc__ || (__s390__ && !__s390x__))  
    res = __lxstat(3, path, &buffer);
#else        
    res = __lxstat(0, path, &buffer);
#endif
    VERBOSE("after lstat atime==%d\n", buffer.st_atime);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeFileStatus(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __lxstat64_cmd(TAThread thread,TAInputStream stream)
{
    struct stat64 buffer;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
#if ( __i386__  || __powerpc__ || (__s390__ && !__s390x__))      
    res = __lxstat64(3, path, &buffer);
#else
    res = __lxstat64(0, path, &buffer);
#endif    
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeFileStatus64(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __xstat_cmd(TAThread thread,TAInputStream stream)
{
    struct stat buffer;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
#if ( __i386__  || __powerpc__ || (__s390__ && !__s390x__))    
    res = __xstat(3, path, &buffer);
#else
    res = __xstat(0, path, &buffer);
#endif    
    VERBOSE("after stat atime==%d\n", buffer.st_atime);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeFileStatus(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __xstat64_cmd(TAThread thread,TAInputStream stream)
{
    struct stat64 buffer;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
#if ( __i386__  || __powerpc__ || (__s390__ && !__s390x__)) 
    res = __xstat64(3, path, &buffer);
#else
    res = __xstat64(0, path, &buffer);
#endif    
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    writeFileStatus64(thread, &buffer);

    sendResponse(thread);

    return taDefaultVerdict;
}
static TACommandVerdict utime_cmd(TAThread thread,TAInputStream stream)
{
    struct utimbuf times;
    int res;
    char* path;

    // Prepare
    path = readString(&stream);
    times= readUTimBuf(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(times.actime!=-1 || times.modtime!=-1)//We passed non-NULL pointer
        res = utime(path, &times);
    else
        res = utime(path, 0);//We passed NULL pointer
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict utimes_cmd(TAThread thread,TAInputStream stream)
{
    struct timeval times[2];
    int res;
    char* path;

    // Prepare
    path = readString(&stream);
    readTimeValPair(&stream, times);

    START_TARGET_OPERATION(thread);
    errno=0;
    if(     times[0].tv_sec!=-1 || times[0].tv_usec!=-1
        ||  times[1].tv_sec!=-1 || times[1].tv_usec!=-1)//We passed non-NULL pointer
        res = utimes(path, times);
    else
        res = utimes(path, 0);//We passed NULL pointer
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_meta_meta_commands(void)
{
      ta_register_command("__fxstat",__fxstat_cmd);
      ta_register_command("__fxstat64",__fxstat64_cmd);
      ta_register_command("__lxstat",__lxstat_cmd);
      ta_register_command("__lxstat64",__lxstat64_cmd);
      ta_register_command("__xstat",__xstat_cmd);
      ta_register_command("__xstat64",__xstat64_cmd);
      ta_register_command("utime",utime_cmd);
      ta_register_command("utimes",utimes_cmd);
}

