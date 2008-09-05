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


#include "system/user/user_agent.h"
#include <errno.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>

void endpwent(void);
struct passwd *getpwent(void);
void setpwent(void);
struct passwd *getpwnam(const char *name);

int getpwnam_r(const char *name, struct passwd *pwd, char *buffer,
               size_t bufsize, struct passwd **result);

struct passwd *getpwuid(uid_t uid);
int getpwuid_r(uid_t uid, struct passwd *pwd, char *buffer,
               size_t bufsize, struct passwd **result);

/********************************************************************/
/**                        Utility Commands                        **/
/********************************************************************/
static TACommandVerdict get_SC_GETPW_R_SIZE_MAX_cmd(TAThread thread,
                                                    TAInputStream stream)
{
    long res;
    START_TARGET_OPERATION(thread);
    res = sysconf(_SC_GETPW_R_SIZE_MAX);
    END_TARGET_OPERATION(thread);

    writeLong(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict endpwent_cmd(TAThread thread,TAInputStream stream)
{

    errno = 0;
    
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    endpwent();
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getpwent_cmd(TAThread thread,TAInputStream stream)
{
    struct passwd* result=NULL;


    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    result = getpwent();
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    writePointer(thread,(void*)result);

    if(result)
    {
        writeString(thread, result->pw_name);
        writeInt(thread, result->pw_uid);
        writeInt(thread, result->pw_gid);
        writeString(thread, result->pw_dir);
        writeString(thread, result->pw_shell);
    }
    else
    {
        writeString(thread, (char*)NULL);
        writeInt(thread, 0);
        writeInt(thread, 0);
        writeString(thread, (char*)NULL);
        writeString(thread, (char*)NULL);
    }

    writeInt(thread,errno);
    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict getpwnam_cmd(TAThread thread,TAInputStream stream)
{
    struct passwd* result;
    char* s1;

    s1 = readString(&stream);

    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    result = getpwnam(s1);
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    writePointer(thread,(void*)result);

    if(result)
    {
        writeString(thread, result->pw_name);
        writeInt(thread, result->pw_uid);
        writeInt(thread, result->pw_gid);
        writeString(thread, result->pw_dir);
        writeString(thread, result->pw_shell);
    }
    else
    {
        writeString(thread, (char*)NULL);
        writeInt(thread, 0);
        writeInt(thread, 0);
        writeString(thread, (char*)NULL);
        writeString(thread, (char*)NULL);
    }


    writeInt(thread,errno);
    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict getpwnam_r_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* name;
    struct passwd *pwd;
    char *buffer;
    size_t bufsize;
    struct passwd *result;

    name = readString(&stream);
    pwd = (struct passwd *)readPointer(&stream);
    bufsize = readSize(&stream);
    buffer=ta_alloc_memory(bufsize*sizeof(char));

    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    res = getpwnam_r(name, pwd, buffer, bufsize, &result);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    writeInt(thread, res);
    writeInt(thread,errno);
    writePointer(thread,(void*)result);

    if(result)
    {
        writeString(thread, result->pw_name);
        writeInt(thread, result->pw_uid);
        writeInt(thread, result->pw_gid);
        writeString(thread, result->pw_dir);
        writeString(thread, result->pw_shell);
    }
    else
    {
        writeString(thread, (char*)NULL);
        writeInt(thread, 0);
        writeInt(thread, 0);
        writeString(thread, (char*)NULL);
        writeString(thread, (char*)NULL);
    }


    sendResponse(thread);

    ta_dealloc_memory(buffer);
    return taDefaultVerdict;
}

static TACommandVerdict getpwuid_cmd(TAThread thread,TAInputStream stream)
{
    struct passwd* result;
    uid_t uid;

    uid = readInt(&stream);

    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    result = getpwuid(uid);
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    writePointer(thread,(void*)result);

    if(result)
    {
        writeString(thread, result->pw_name);
        writeInt(thread, result->pw_uid);
        writeInt(thread, result->pw_gid);
        writeString(thread, result->pw_dir);
        writeString(thread, result->pw_shell);
    }
    else
    {
        writeString(thread, (char*)NULL);
        writeInt(thread, 0);
        writeInt(thread, 0);
        writeString(thread, (char*)NULL);
        writeString(thread, (char*)NULL);
    }


    writeInt(thread,errno);
    sendResponse(thread);


    return taDefaultVerdict;
}

static TACommandVerdict getpwuid_r_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    uid_t uid;
    struct passwd *pwd;
    char *buffer;
    size_t bufsize;
    struct passwd *result;

    uid = readInt(&stream);
    pwd = (struct passwd *)readPointer(&stream);
    bufsize = readSize(&stream);
    buffer=ta_alloc_memory(bufsize*sizeof(char));

    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    res = getpwuid_r(uid, pwd, buffer, bufsize, &result);

    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);

    writeInt(thread, res);
    writeInt(thread,errno);
    writePointer(thread,(void*)result);

    if(result)
    {
        writeString(thread, result->pw_name);
        writeInt(thread, result->pw_uid);
        writeInt(thread, result->pw_gid);
        writeString(thread, result->pw_dir);
        writeString(thread, result->pw_shell);
    }
    else
    {
        writeString(thread, (char*)NULL);
        writeInt(thread, 0);
        writeInt(thread, 0);
        writeString(thread, (char*)NULL);
        writeString(thread, (char*)NULL);
    }


    sendResponse(thread);
    ta_dealloc_memory(buffer);
    return taDefaultVerdict;
}

static TACommandVerdict setpwent_cmd(TAThread thread,TAInputStream stream)
{

    START_TARGET_OPERATION(thread);
    setpwent();
    END_TARGET_OPERATION(thread);

    writeInt(thread,errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_system_user_user_commands(void)
{
    ta_register_command("get_SC_GETPW_R_SIZE_MAX", 
                        get_SC_GETPW_R_SIZE_MAX_cmd);
    ta_register_command("endpwent",endpwent_cmd);
    ta_register_command("getpwent",getpwent_cmd);
    ta_register_command("getpwnam",getpwnam_cmd);
    ta_register_command("getpwnam_r",getpwnam_r_cmd);
    ta_register_command("getpwuid",getpwuid_cmd);
    ta_register_command("getpwuid_r",getpwuid_r_cmd);
    ta_register_command("setpwent",setpwent_cmd);
}

