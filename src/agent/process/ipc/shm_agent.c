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


#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <utime.h>

#include "process/ipc/shm_agent.h"


/********************************************************************/
/**       shmid_ds Data Type Readers And Writers                   **/
/********************************************************************/

void readShmid(TAInputStream* stream, struct shmid_ds * data )
{
    verifyType_TAInputStream(stream,"shmid");
    
    readIpcPerm(stream, &(data->shm_perm));
    
    data->shm_segsz=readSize(stream);
    data->shm_lpid=readInt(stream);
    data->shm_cpid=readInt(stream);
    data->shm_nattch=readUShort(stream);
    
    data->shm_atime=readLong(stream);
    data->shm_dtime=readLong(stream);
    data->shm_ctime=readLong(stream);
}


void writeShmid(TAThread thread, struct shmid_ds* data)
{
    writeIpcPerm(thread, &(data->shm_perm));
    writeSize(thread, data->shm_segsz);
    writeInt(thread, data->shm_lpid);
    writeInt(thread, data->shm_cpid);
    writeUShort(thread, data->shm_nattch);
    writeLong(thread, data->shm_atime);
    writeLong(thread, data->shm_dtime);
    writeLong(thread, data->shm_ctime);
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict shmat_cmd(TAThread thread,TAInputStream stream)
{
    void* res;
    int shmid;
    const void *shmaddr;
    int shmflg;

    // Prepare
    shmid = readInt(&stream);
    shmaddr = readPointer(&stream);
    shmflg = readInt(&stream);
    
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = shmat(shmid, shmaddr, shmflg); 

    END_TARGET_OPERATION(thread);
    
    // Response
    writePointer(thread, res);
    writeInt(thread, errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict shmctl_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int shmid;
    int cmd;
    struct shmid_ds buf;

    // Prepare
    shmid = readInt(&stream);
    cmd = readInt(&stream);
    readShmid(&stream, &buf);

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = shmctl(shmid, cmd, &buf); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeShmid(thread, &buf);
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict shmdt_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    void *shmaddr;
        
    // Prepare
    shmaddr = readPointer(&stream);
    
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = shmdt(shmaddr);  

    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict shmget_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    key_t key;
    size_t size;
    int shmflg;

    // Prepare
    key = readInt(&stream);
    size = readSize(&stream);
    shmflg = readInt(&stream);

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = shmget(key, size, shmflg); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;

}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_ipc_shm_commands(void)
{
    ta_register_command("shmat",shmat_cmd);
    ta_register_command("shmctl",shmctl_cmd);
    ta_register_command("shmdt",shmdt_cmd);
    ta_register_command("shmget",shmget_cmd);
}

