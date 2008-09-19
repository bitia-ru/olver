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
#include <sys/sem.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <utime.h>


#include "process/ipc/sem_agent.h"

/********************************************************************/
/**               Data Types Readers And Writers                   **/
/********************************************************************/

void readSemBuf(TAInputStream* stream, struct sembuf* buf )
{
    verifyType_TAInputStream(stream,"sembuf");
    
    buf->sem_num = readShort(stream);
    buf->sem_op = readShort(stream);
    buf->sem_flg = readShort(stream);
}


void writeSemid(TAThread thread, struct semid_ds* data)
{
    writeIpcPerm(thread, &(data->sem_perm));
    writeUShort(thread, data->sem_nsems);
    writeLong(thread, data->sem_otime);
    writeLong(thread, data->sem_ctime);
}


void readSemid(TAInputStream* stream, struct semid_ds * data)
{
    verifyType_TAInputStream(stream,"semid");
    
    readIpcPerm(stream, &(data->sem_perm));
    
    data->sem_nsems=readUShort(stream);
    data->sem_otime=readLong(stream);
    data->sem_ctime=readLong(stream);
}


/********************************************************************/
/**                         semun Data Type                        **/
/********************************************************************/

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict semctl_get_int_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cmd;
    int semid;
    int semnum; 

    // Prepare
    cmd = readInt(&stream);
    semid = readInt(&stream);
    semnum = readInt(&stream);

    ta_debug_printf( "search for semctl (%u)...\n", (unsigned long)pthread_self() ); 

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semctl(semid, semnum, cmd); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict semctl_SETVAL_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cmd;
    int semid;
    int semnum; 
    union semun semval;
    
    // Prepare
    cmd = readInt(&stream);
    semid = readInt(&stream);
    semnum = readInt(&stream);
    semval.val = readInt(&stream);
    
    ta_debug_printf( "search for semctl (%u)...\n", (unsigned long)pthread_self() ); 
 
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semctl(semid, semnum, cmd, semval); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict semctl_GETALL_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cmd;
    int semid;
    int semnum;
    unsigned short nsems;
    union semun arg;
    int i=0;
    
    // Prepare
    cmd = readInt(&stream);
    semid = readInt(&stream);
    semnum = readInt(&stream);
    nsems = readUShort(&stream);
    
    arg.array = ta_alloc_memory(nsems*sizeof(unsigned short)+5);

    ta_debug_printf( "search for semctl (%u)...\n", (unsigned long)pthread_self() ); 

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semctl(semid, semnum, cmd, arg); 
    END_TARGET_OPERATION(thread);
    
    // Response

    for (i=0;i<nsems;i++)
    {
        writeUShort(thread, (arg.array)[i]);
    }

    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict semctl_SETALL_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cmd;
    int semid;
    int semnum;
    int  nsems;
    union semun arg;
    int i=0;
    
    // Prepare
    cmd = readInt(&stream);
    semid = readInt(&stream);
    semnum = readInt(&stream);
    nsems = readInt(&stream);
    
    arg.array = ta_alloc_memory(nsems*sizeof(unsigned short)+5);
    
    for (i=0;i<nsems;i++)
    {
        (arg.array)[i]=readUShort(&stream);
    }

    ta_debug_printf( "search for semctl (%u)...\n", (unsigned long)pthread_self() ); 

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semctl(semid, semnum, cmd, arg); 
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict semctl_IPC_STAT_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cmd;
    int semid;
    int semnum;
    unsigned short nsems;
    union semun arg;
    int i=0;
    
    // Prepare
    cmd = readInt(&stream);
    semid = readInt(&stream);
    semnum = readInt(&stream);
    
    arg.buf = ta_alloc_memory(sizeof(struct semid_ds)+5);
    
    ta_debug_printf( "search for semctl (%u)...\n", (unsigned long)pthread_self() );    
   
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semctl(semid, semnum, cmd, arg); 
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeInt(thread,res);
    writeSemid(thread, arg.buf);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict semctl_IPC_SET_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cmd;
    int semid;
    int semnum;
    union semun arg;
    struct semid_ds data;
    
    // Prepare
    cmd = readInt(&stream);
    semid = readInt(&stream);
    semnum = readInt(&stream);
    
    readSemid(&stream, &data);

    arg.buf = &data;

    ta_debug_printf( "search for semctl (%u)...\n", (unsigned long)pthread_self() ); 
       
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semctl(semid, semnum, cmd, arg); 
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict semget_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    key_t key;
    int nsems;
    int semflg;

    // Prepare
    key = readInt(&stream);
    nsems = readInt(&stream);
    semflg = readInt(&stream);

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = semget(key, nsems, semflg); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict semop_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int semid;
    int nsops, i;
    struct sembuf *sops;

    // Prepare
    semid = readInt(&stream);
    nsops = readInt(&stream);

    sops = (struct sembuf *)ta_alloc_memory(nsops*sizeof(struct sembuf)+5);

    for (i=0;i<nsops;i++)
    {
        readSemBuf(&stream, &(sops[i]));
    }
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = semop(semid, sops, nsops); 
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
void register_process_ipc_sem_commands(void)
{
//    ta_register_command("semctl",semctl_cmd);
    ta_register_command("semctl_get_int", semctl_get_int_cmd);
    ta_register_command("semctl_SETVAL", semctl_SETVAL_cmd);
    ta_register_command("semctl_GETALL", semctl_GETALL_cmd);
    ta_register_command("semctl_SETALL", semctl_SETALL_cmd);
    ta_register_command("semctl_IPC_STAT", semctl_IPC_STAT_cmd);
    ta_register_command("semctl_IPC_SET", semctl_IPC_SET_cmd);

    ta_register_command("semget",semget_cmd);
    ta_register_command("semop",semop_cmd);
}

