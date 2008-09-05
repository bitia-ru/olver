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


#include "fs/meta/access_agent.h"
#include "fs/fs/fs_agent.h"
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int readAccessModeAccess(TAInputStream* stream)
{ 
    int ret=0;
    verifyType_TAInputStream(stream,"accessmodeaccess");

    ret|= readInt(stream) == 1 ? R_OK : 0; 
    ret|= readInt(stream) == 1 ? W_OK : 0; 
    ret|= readInt(stream) == 1 ? X_OK : 0; 
    ret|= readInt(stream) == 1 ? F_OK : 0; 
    return ret;
}
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict access_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int res;    
    int amode;
    
    // Prepare
    path = readString(&stream);
    amode= readAccessModeAccess(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = access(path, amode);    
    END_TARGET_OPERATION(thread);  

    // Response    
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict chmod_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int mode;
    int res;    

    // Prepare
    path = readString(&stream);
    mode = readFilePermissions(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = chmod(path, mode);    
    END_TARGET_OPERATION(thread);  

    // Response    
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict chown_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int res;
    uid_t uid;
    gid_t gid;

    // Prepare
    path = readString(&stream);
    uid =  readUInt(&stream);
    gid =  readUInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = chown(path, uid, gid);    
    END_TARGET_OPERATION(thread);  

    // Response    
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fchmod_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int mode;
    int res;    

    // Prepare
    fildes = readInt(&stream);
    mode = readFilePermissions(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = fchmod(fildes, mode);    
    END_TARGET_OPERATION(thread);  

    // Response    
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fchown_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res;
    uid_t uid;
    gid_t gid;

    // Prepare
    fildes = readInt(&stream);
    uid =  readUInt(&stream);
    gid =  readUInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = fchown(fildes, uid, gid);    
    END_TARGET_OPERATION(thread);  

    // Response    
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lchown_cmd(TAThread thread,TAInputStream stream)
{
    char* path;
    int res;
    uid_t uid;
    gid_t gid;

    // Prepare
    path = readString(&stream);
    uid =  readUInt(&stream);
    gid =  readUInt(&stream);

    START_TARGET_OPERATION(thread);
    errno=0;
    res = lchown(path, uid, gid);    
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
void register_fs_meta_access_commands(void)
{
    ta_register_command("access",access_cmd);
    ta_register_command("chmod",chmod_cmd);
    ta_register_command("chown",chown_cmd);
    ta_register_command("fchmod",fchmod_cmd);
    ta_register_command("fchown",fchown_cmd);
    ta_register_command("lchown",lchown_cmd);
}

