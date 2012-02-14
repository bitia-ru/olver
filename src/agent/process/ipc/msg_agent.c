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
#include <sys/msg.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <utime.h>
#include <string.h>

#include "process/ipc/msg_agent.h"


/********************************************************************/
/**               Data Types Readers And Writers                   **/
/********************************************************************/

void readIpcPerm(TAInputStream* stream, struct ipc_perm* perms )
{
    verifyType_TAInputStream(stream,"ipcperm");

    perms->uid = readUInt(stream);
    perms->gid = readUInt(stream);
    perms->cuid = readUInt(stream);
    perms->cgid = readUInt(stream);
    perms->mode = readFilePermissions(stream); 
}


void readMsqid(TAInputStream* stream, struct msqid_ds * data )
{
    verifyType_TAInputStream(stream,"msqid");

    readIpcPerm(stream, &(data->msg_perm));
        
    data->msg_qnum=readUShort(stream);
    data->msg_qbytes=readUShort(stream);
    data->msg_lspid=readInt(stream);
    data->msg_lrpid=readInt(stream);
    data->msg_stime=readLong(stream);
    data->msg_rtime=readLong(stream);
    data->msg_ctime=readLong(stream);
}


void writeFilePermissions(TAThread thread, mode_t  mode)
{
    //Encoding S_IRWXU
    if(mode & S_IRUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_IWUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_IXUSR)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    
    //Encoding S_IRWXG
    if(mode & S_IRGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_IWGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_IXGRP)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    
    //Encoding S_IRWXO
    if(mode & S_IROTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_IWOTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_IXOTH)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    
    
    if(mode & S_ISUID)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_ISGID)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
    if(mode & S_ISVTX)
        writeInt(thread, 1);
    else
        writeInt(thread, 0);
 
}


void writeIpcPerm(TAThread thread, struct ipc_perm* perms)
{

    writeUInt(thread, perms->uid);
    writeUInt(thread, perms->gid);
    writeUInt(thread, perms->cuid);
    writeUInt(thread, perms->cgid);

    writeFilePermissions(thread, perms->mode);
   
}


void writeMsqid(TAThread thread, struct msqid_ds* data)
{
    writeIpcPerm(thread, &(data->msg_perm));
    writeUShort(thread, data->msg_qnum);
    writeUShort(thread, data->msg_qbytes);
    writeInt(thread, data->msg_lspid);
    writeInt(thread, data->msg_lrpid);
    writeLong(thread, data->msg_stime);
    writeLong(thread, data->msg_rtime);
    writeLong(thread, data->msg_ctime);
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict msgctl_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int msqid;
    int cmd;
    struct msqid_ds buf;

    // Prepare
    msqid = readInt(&stream);
    cmd = readInt(&stream);
    readMsqid(&stream, &buf);
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = msgctl(msqid, cmd, &buf); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);

    writeMsqid(thread, &buf);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict msgget_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    key_t key;
    int msgflg;

    // Prepare
    key = readInt(&stream);
    msgflg = readInt(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);
    res = msgget(key, msgflg); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict msgrcv_cmd(TAThread thread,TAInputStream stream)
{
    ssize_t res;
    

    int msqid=readInt(&stream);
    size_t msgsz=readSize(&stream);
    long msgtyp=readLong(&stream);
    int msgflg=readInt(&stream);
    void *msgp;

    msgp = ta_alloc_memory(msgsz+sizeof(long)+5);
    
    // Prepare
    
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = msgrcv(msqid, msgp, msgsz, msgtyp, msgflg); 

    END_TARGET_OPERATION(thread);
    
    // Response
    writeSSize(thread,res);
    writeByteArray(thread, msgp, msgsz+sizeof(long));
    writeInt(thread,errno);
    sendResponse(thread);
    
    ta_dealloc_memory(msgp);
    
    return taDefaultVerdict;
}

static TACommandVerdict msgsnd_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    int msqid=readInt(&stream);
    long mtype=readLong(&stream);
    char* mtext;
    size_t msgsz;
    int msgflag;
    void *msgp;
    
    readByteArray(&stream, &mtext, &msgsz);
    msgflag=readInt(&stream);


    msgp = ta_alloc_memory(msgsz+sizeof(long)+5);
    *((long*)msgp)=mtype;
    memcpy(msgp+sizeof(long), mtext, msgsz);

    // Prepare

    errno = 0;
    
    START_TARGET_OPERATION(thread);
    res = msgsnd(msqid, msgp, msgsz+sizeof(long), msgflag); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread,res);
    writeInt(thread,errno);
    sendResponse(thread);
    
    ta_dealloc_memory(msgp);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_ipc_msg_commands(void)
{
    ta_register_command("msgctl",msgctl_cmd);
    ta_register_command("msgget",msgget_cmd);
    ta_register_command("msgrcv",msgrcv_cmd);
    ta_register_command("msgsnd",msgsnd_cmd);
}

