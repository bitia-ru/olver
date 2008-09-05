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





#include "memory/mman/mman_agent.h"

#include <fcntl.h>

#include <string.h>

#include <sys/types.h> 

#include <errno.h>







/********************************************************************/

/**                         Agent Commands                         **/

/********************************************************************/



static TACommandVerdict mlock_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    int res;

    errno = 0;

    void* addr;

    size_t len;

    

    addr = readPointer(&stream);

    len = readSize(&stream);



    START_TARGET_OPERATION(thread);

    

    // Execute

    res = mlock(addr, len);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict mlockall_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    int res, temp, flags;

    errno = 0;

    

    temp = readInt(&stream);

    flags = convertMLockallFlagsReprezentationToIntRealization(temp);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = mlockall(flags);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict mmap_cmd(TAThread thread,TAInputStream stream)

{

    void *addr;

    size_t len;

    int prot, flags, fildes;

    off_t off;

    int temp;

    void* res;

    

    // Prepare

    errno = 0;

    addr = readPointer(&stream);

    len = readSize(&stream);

    temp = readInt(&stream);

    prot = convertMmanProtFlagsReprezentationToIntRealization(temp);

    temp = readInt(&stream);

    flags = convertMmapFlagsReprezentationToIntRealization(temp);

    fildes = readInt(&stream);

    off = readLLong(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = mmap(addr, len, prot, flags, fildes, off);

    END_TARGET_OPERATION(thread);

    

    // Response

    writePointer(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict mmap64_cmd(TAThread thread,TAInputStream stream)

{

    void *addr;

    size_t len;

    int prot, flags, fildes;

    off_t off;

    int temp;

    void* res;

    

    // Prepare

    errno = 0;

    addr = readPointer(&stream);

    len = readSize(&stream);

    temp = readInt(&stream);

    prot = convertMmanProtFlagsReprezentationToIntRealization(temp);

    temp = readInt(&stream);

    flags = convertMmapFlagsReprezentationToIntRealization(temp);

    fildes = readInt(&stream);

    off = readLLong(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = mmap64(addr, len, prot, flags, fildes, off);

    END_TARGET_OPERATION(thread);

    

    // Response

    writePointer(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict mprotect_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    void *addr;

    size_t len;

    int prot;

    int temp;

    int res;

    

    errno = 0;

    addr = readPointer(&stream);

    len = readSize(&stream);

    temp = readInt(&stream);

    prot = convertMmanProtFlagsReprezentationToIntRealization(temp);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = mprotect(addr, len, prot);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict msync_cmd(TAThread thread,TAInputStream stream)

{

   // Prepare

    void *addr;

    size_t len;

    int flags;

    int temp;

    int res;

    

    errno = 0;

    addr = readPointer(&stream);

    len = readSize(&stream);

    temp = readInt(&stream);

    flags = convertMsyncFlagsReprezentationToIntRealization(temp);

    

    BEFORE_BLOCKED_TARGET_OPERATION(thread);



    writeString(thread,"Ok");

    sendResponse(thread);





    START_TARGET_OPERATION(thread);

    

    // Execute

    res = msync(addr, len, flags);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeDeferredReaction(thread, "msync_react");

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict munlock_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    int res;

    void* addr;

    size_t len;

    

    errno = 0;

    addr = readPointer(&stream);

    len = readSize(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = munlock(addr, len);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread); 

    

    return taDefaultVerdict;

}



static TACommandVerdict munlockall_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    int res;

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = munlockall();

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, res);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict munmap_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    errno = 0;

    int res;

    void* addr;

    size_t len;

    

    errno = 0;

    addr = readPointer(&stream);

    len = readSize(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = munmap(addr, len);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict shm_open_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    char* path;

    int oflag, temp;

    int mode;

    int res;



    // Prepare

    errno = 0;

    path = readString(&stream);

    temp = readInt(&stream);

    oflag = convertShm_openOflagsReprezentationToIntRealization(temp);

    mode = readFilePermissions(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute


    res = shm_open(path, oflag, mode);

    if((errno == 0) && (oflag & O_RDWR))

    {

        ftruncate(res, 4096 * 20); //when ftruncate_cmd would be realized, this line should be removed

    }

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread,res);

    writeInt(thread,errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict shm_unlink_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    char* path;

    int res;

    

    errno = 0;

    path = readString(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    res = shm_unlink(path);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread,res);

    writeInt(thread,errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict write_mapped_memory_block_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    char* ptr;

    char* data;

    size_t size;



    readByteArray(&stream,&data,&size);

    ptr = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    

    // Execute

    memcpy(ptr,data,size);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict read_mapped_memory_block_cmd(TAThread thread,TAInputStream stream)

{

    // Prepare

    int res;

    char* mb;

    size_t len = 20;



    mb = readPointer(&stream);

    len = readSize(&stream);





    START_TARGET_OPERATION(thread);

    

    // Execute & part of responce

    writeByteArray(thread, mb, len);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeInt(thread,errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}

/*****************************************************************************/

/*                       Flags conversion functions                         */

/*****************************************************************************/

/* MLockallFlags */

int convertMLockallFlagsReprezentationToIntRealization(int value)

{

    int res = 0;

    if(SUT_MCL_CURRENT & value)

    {

        res = res | MCL_CURRENT;

    }

    if(SUT_MCL_FUTURE & value)

    {

        res = res | MCL_FUTURE;

    }

    return res;

}



int convertIntRealizationToMLockallFlagsRepresentation(int value)

{

    int res = 0;

    

    if(MCL_CURRENT & value)

    {

        res = res | SUT_MCL_CURRENT;

    }

    if(MCL_FUTURE & value)

    {

        res = res | SUT_MCL_FUTURE;

    }

    return res;

}



/* MmanProtFlags */

int convertMmanProtFlagsReprezentationToIntRealization(int value)

{

    int res = 0;

    if(SUT_PROT_READ & value)

    {

        res = res | PROT_READ;

    }

    if(SUT_PROT_WRITE & value)

    {

        res = res | PROT_WRITE;

    }

    if(SUT_PROT_EXEC & value)

    {

        res = res | PROT_EXEC;

    }

    if(SUT_PROT_NONE & value)

    {

        res = res | PROT_NONE;

    }

    return res;

}



int convertIntRealizationToMmanProtFlagsRepresentation(int value)

{

    int res = 0;

    

    if(PROT_READ & value)

    {

        res = res | SUT_PROT_READ;

    }

    if(PROT_WRITE & value)

    {

        res = res | SUT_PROT_WRITE;

    }

    if(PROT_EXEC & value)

    {

        res = res | SUT_PROT_EXEC;

    }

    if(PROT_NONE & value)

    {

        res = res | SUT_PROT_NONE;

    }

    

    return res;

}



/* MmapFlags */

int convertMmapFlagsReprezentationToIntRealization(int value)

{

    int res = 0;

    if(SUT_MAP_SHARED & value)

    {

        res = res | MAP_SHARED;

    }

    if(SUT_MAP_PRIVATE & value)

    {

        res = res | MAP_PRIVATE;

    }

    if(SUT_MAP_FIXED & value)

    {

        res = res | MAP_FIXED;

    }

    

    return res;

}



int convertIntRealizationToMmapFlagsRepresentation(int value)

{

    int res = 0;

    

    if(MAP_SHARED & value)

    {

        res = res | SUT_MAP_SHARED;

    }

    if(MAP_PRIVATE & value)

    {

        res = res | SUT_MAP_PRIVATE;

    }

    if(MAP_FIXED & value)

    {

        res = res | SUT_MAP_FIXED;

    }

    

    return res;

}



/* MsyncFlags */

int convertMsyncFlagsReprezentationToIntRealization(int value)

{

    int res = 0;

    if(SUT_MS_ASYNC & value)

    {

        res = res | MS_ASYNC;

    }

    if(SUT_MS_SYNC & value)

    {

        res = res | MS_SYNC;

    }

    if(SUT_MS_INVALIDATE & value)

    {

        res = res | MS_INVALIDATE;

    }

    return res;

}



int convertIntRealizationToMsyncFlagsRepresentation(int value)

{

    int res = 0;

    

    if(MS_ASYNC & value)

    {

        res = res | SUT_MS_ASYNC;

    }

    if(MS_SYNC & value)

    {

        res = res | SUT_MS_SYNC;

    }

    if(MS_INVALIDATE & value)

    {

        res = res | SUT_MS_INVALIDATE;

    }

    

    return res;

}



/* Shm_openOflags */

int convertShm_openOflagsReprezentationToIntRealization(int value)

{

    int res = 0;

    if(SUT_O_RDONLY & value)

    {

        res = res | O_RDONLY;

    }

    if(SUT_O_RDWR & value)

    {

        res = res | O_RDWR;

    }

    if(SUT_O_CREAT & value)

    {

        res = res | O_CREAT;

    }

    if(SUT_O_EXCL & value)

    {

        res = res | O_EXCL;

    }

    if(SUT_O_TRUNC & value)

    {

        res = res | O_TRUNC;

    }

    return res;

}



int convertIntRealizationToShm_openOflagsRepresentation(int value)

{

    int res = 0;

    

    if(O_RDONLY & value)

    {

        res = res | SUT_O_RDONLY;

    }

    if(O_RDWR & value)

    {

        res = res | SUT_O_RDWR;

    }

    if(O_CREAT & value)

    {

        res = res | SUT_O_CREAT;

    }

    if(O_EXCL & value)

    {

        res = res | SUT_O_EXCL;

    }

    if(O_TRUNC & value)

    {

        res = res | SUT_O_TRUNC;

    }

    

    return res;

}

/********************************************************************/

/**                      Agent Initialization                      **/

/********************************************************************/

void register_memory_mman_commands(void)

{

    ta_register_command("mlock",mlock_cmd);

    ta_register_command("mlockall",mlockall_cmd);

    ta_register_command("mmap",mmap_cmd);

    ta_register_command("mmap64",mmap64_cmd);

    ta_register_command("mprotect",mprotect_cmd);

    ta_register_command("msync",msync_cmd);

    ta_register_command("munlock",munlock_cmd);

    ta_register_command("munlockall",munlockall_cmd);

    ta_register_command("munmap",munmap_cmd);

    ta_register_command("shm_open",shm_open_cmd);

    ta_register_command("shm_unlink",shm_unlink_cmd);

    ta_register_command("write_mapped_mem_block",write_mapped_memory_block_cmd);

    ta_register_command("read_mapped_mem_block",read_mapped_memory_block_cmd);

}



