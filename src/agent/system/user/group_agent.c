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


#include "system/user/group_agent.h"
#include <grp.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void endgrent(void);
struct group *getgrent(void);
void setgrent(void); 

struct group *getgrgid(gid_t gid);
int getgrgid_r(gid_t gid, struct group *grp, char *buffer,
               size_t bufsize, struct group **result); 

int getgrouplist(const char * user, gid_t group, gid_t * groups, 
                 int * ngroups);




/********************************************************************/
/**                        Utility Commands                        **/
/********************************************************************/
static TACommandVerdict get_SC_GETGR_R_SIZE_MAX_cmd(TAThread thread,
                                                    TAInputStream stream)
{
    long res;
    START_TARGET_OPERATION(thread);
    res = sysconf(_SC_GETGR_R_SIZE_MAX);
    END_TARGET_OPERATION(thread);
    
    writeLong(thread,res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict endgrent_cmd(TAThread thread,TAInputStream stream)
{
 
    errno = 0;
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    endgrent();
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getgrent_cmd(TAThread thread,TAInputStream stream)
{
    struct group* result;
    int i=0;
    
    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    result = getgrent();
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
 

    writePointer(thread,(void*)result);
    
    if(result)
    {
        writeString(thread, result->gr_name);
        writeInt(thread, result->gr_gid);
        while ((result->gr_mem)[i]!=NULL)
        {
            i++;
        }
        writeInt(thread, i);
        i=0;
        while ((result->gr_mem)[i]!=NULL)
        {
            writeString(thread, (result->gr_mem)[i]);
            i++;
        }
    } 
    
    writeInt(thread,errno);
    sendResponse(thread);
    
    
    return taDefaultVerdict;
}

static TACommandVerdict getgrgid_cmd(TAThread thread,TAInputStream stream)
{
    struct group* result;
    gid_t gid;
    int i=0;
    
    gid = readInt(&stream);
    
    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    result = getgrgid(gid);
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    writePointer(thread,(void*)result);
    
    if(result)
    {
        writeString(thread, result->gr_name);
        writeInt(thread, result->gr_gid);
        while ((result->gr_mem)[i]!=NULL)
        {
            i++;
        }
        writeInt(thread, i);
        i=0;
        while ((result->gr_mem)[i]!=NULL)
        {
            writeString(thread, (result->gr_mem)[i]);
            i++;
        }
    } 
    
    
    writeInt(thread,errno);
    sendResponse(thread);
    
    
    return taDefaultVerdict;
}

static TACommandVerdict getgrgid_r_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    gid_t gid;
    struct group *grp;
    char *buffer;
    size_t bufsize;
    struct group *result;
    int i=0;
    
    gid = readInt(&stream);
    grp = (struct group *)readPointer(&stream);
    bufsize = readSize(&stream);
    buffer=(char *) ta_alloc_memory(bufsize*sizeof(char));
    
    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    res = getgrgid_r(gid, grp, buffer, bufsize, &result); 
    
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    writeInt(thread, res);
    writeInt(thread,errno);
    writePointer(thread,(void*)result);
    
    if(result)
    {
        writeString(thread, result->gr_name);
        writeInt(thread, result->gr_gid);
        while ((result->gr_mem)[i]!=NULL)
        {
            i++;
        }
        writeInt(thread, i);
        i=0;
        while ((result->gr_mem)[i]!=NULL)
        {
            writeString(thread, (result->gr_mem)[i]);
            i++;
        }
    } 
    
    
    sendResponse(thread);
    ta_dealloc_memory(buffer);
    return taDefaultVerdict;

}

static TACommandVerdict getgrnam_cmd(TAThread thread,TAInputStream stream)
{
    struct group* result;
    char* name;
    int i=0;
    
    name = readString(&stream);
    errno = 0;

    
    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    result = getgrnam(name);
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    writePointer(thread,(void*)result);
    
    if(result)
    {
        writeString(thread, result->gr_name);
        writeInt(thread, result->gr_gid);
        while ((result->gr_mem)[i]!=NULL)
        {
            i++;
        }
        writeInt(thread, i);
        i=0;
        while ((result->gr_mem)[i]!=NULL)
        {
            writeString(thread, (result->gr_mem)[i]);
            i++;
        }
    } 
    
    
    writeInt(thread,errno);
    sendResponse(thread);
    
    
    return taDefaultVerdict;
}

static TACommandVerdict getgrnam_r_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* name;
    struct group *grp;
    char *buffer;
    size_t bufsize;
    struct group *result;
    int i=0;
    
    name = readString(&stream);
    grp = (struct group *)readPointer(&stream);
    bufsize = readSize(&stream);
    buffer=(char *) ta_alloc_memory(bufsize*sizeof(char));
    
    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    res = getgrnam_r(name, grp, buffer, bufsize, &result); 
    
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    writeInt(thread, res);
    writeInt(thread,errno);
    writePointer(thread,(void*)result);
    
    if(result)
    {
        writeString(thread, result->gr_name);
        writeInt(thread, result->gr_gid);
        while ((result->gr_mem)[i]!=NULL)
        {
            i++;
        }
        writeInt(thread, i);
        i=0;
        while ((result->gr_mem)[i]!=NULL)
        {
            writeString(thread, (result->gr_mem)[i]);
            i++;
        }
    } 
    
    
    sendResponse(thread);
    ta_dealloc_memory(buffer);
    return taDefaultVerdict;
}

static TACommandVerdict getgrouplist_cmd(TAThread thread,TAInputStream stream)
{
    int result;
    int i=0;
    char* user;
    gid_t group;
    int ngroups;
    gid_t * groups;
    int old_groups;
    
    user = readString(&stream);
    group = readInt(&stream);
    ngroups = readInt(&stream);
    
    old_groups = ngroups;
    
    groups=(gid_t *)ta_alloc_memory((ngroups+20)*sizeof(gid_t));

    errno = 0;

    START_TARGET_OPERATION(thread);
    result=getgrouplist(user, group, groups, &ngroups);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, result);
    writeInt(thread, ngroups);

    if(ngroups>old_groups)
        ngroups=old_groups;
    writeInt(thread, ngroups);
    for (i=0; i<ngroups; i++)
    {
        writeInt(thread, groups[i]);
    }
   
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict setgrent_cmd(TAThread thread,TAInputStream stream)
{
    errno = 0;

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    setgrent();
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    writeInt(thread,errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}




/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_system_user_group_commands(void)
{
    ta_register_command("get_SC_GETGR_R_SIZE_MAX", 
                        get_SC_GETGR_R_SIZE_MAX_cmd);
    ta_register_command("endgrent",endgrent_cmd);
    ta_register_command("getgrent",getgrent_cmd);
    ta_register_command("getgrgid",getgrgid_cmd);
    ta_register_command("getgrgid_r",getgrgid_r_cmd);
    ta_register_command("getgrnam",getgrnam_cmd);
    ta_register_command("getgrnam_r",getgrnam_r_cmd);
    ta_register_command("getgrouplist",getgrouplist_cmd);
    ta_register_command("setgrent",setgrent_cmd);
}

