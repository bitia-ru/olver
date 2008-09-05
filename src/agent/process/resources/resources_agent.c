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


#include "process/resources/resources_agent.h"
#include <sys/resource.h>
#include <errno.h>
#include <ulimit.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getrlimit_cmd(TAThread thread,TAInputStream stream)
{
    struct rlimit lim;
    int resource;
    int isNull;

    int res;

    resource = readInt(&stream);
    isNull = readInt(&stream);
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(isNull)
        res = getrlimit(resource,NULL);
    else
        res = getrlimit(resource, &lim);

    END_TARGET_OPERATION(thread);

    if(!isNull)
    {
        writeULong(thread, lim.rlim_cur);
        writeULong(thread, lim.rlim_max);
    }
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setrlimit_cmd(TAThread thread,TAInputStream stream)
{
    struct rlimit lim;
    int resource;
    int isNull;

    int res;

    resource = readInt(&stream);
    isNull = readInt(&stream);
    if(!isNull)
    {
        lim.rlim_cur = readULong(&stream);
        lim.rlim_max = readULong(&stream);
    }
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);
    if(isNull)
        res = setrlimit(resource, NULL);
    else
        res = setrlimit(resource, &lim);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

typedef struct rlimit64t
{
    unsigned long long int rlim_cur;
    unsigned long long int rlim_max;
}rlimit64t;

static TACommandVerdict getrlimit64_cmd(TAThread thread,TAInputStream stream)
{
    struct rlimit64 lim;
    int resource;
    int isNull;

    int res;

    resource = readInt(&stream);
    isNull = readInt(&stream);
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(isNull)
        res = getrlimit64(resource,NULL);
    else
        res = getrlimit64(resource, &lim);

    END_TARGET_OPERATION(thread);

    if(!isNull)
    {
        writeULLong(thread, lim.rlim_cur);
        writeULLong(thread, lim.rlim_max);
    }
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setrlimit64_cmd(TAThread thread,TAInputStream stream)
{
    struct rlimit64 lim;
    int resource;
    int isNull;

    int res;

    resource = readInt(&stream);
    isNull = readInt(&stream);
    if(!isNull)
    {
        lim.rlim_cur = readULLong(&stream);
        lim.rlim_max = readULLong(&stream);
    }
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);
    if(isNull)
        res = setrlimit64(resource, NULL);
    else
        res = setrlimit64(resource, &lim);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict getrusage_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int who;
    struct rusage r_usage;

    who = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = getrusage(who,&r_usage);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeRUsage(thread,r_usage);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict ulimit_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    int cmd;
    int i;
    long param1;

    cmd = readInt(&stream);
    i = readInt(&stream);
    if(i==1)
        param1 = readLong(&stream);
    if(i>1)
    {
        ta_debug_printf("ulimit_agent: Too many params!");
        return taDefaultVerdict;
    }
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    if(i==0)
        res = ulimit(cmd);
    else if(i==1)
        res = ulimit(cmd,param1);

    END_TARGET_OPERATION(thread);

    writeLong(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Helper Functions                          **/
/********************************************************************/

void writeRUsage(TAThread thread,struct rusage r_usage)
{
    writeLong(thread, r_usage.ru_utime.tv_sec);
    writeLong(thread, r_usage.ru_utime.tv_usec);
    writeLong(thread, r_usage.ru_stime.tv_sec);
    writeLong(thread, r_usage.ru_stime.tv_usec);

    writeLong(thread, r_usage.ru_maxrss);
    writeLong(thread, r_usage.ru_ixrss);
    writeLong(thread, r_usage.ru_idrss);
    writeLong(thread, r_usage.ru_isrss);
    writeLong(thread, r_usage.ru_minflt);
    writeLong(thread, r_usage.ru_majflt);
    writeLong(thread, r_usage.ru_nswap);
    writeLong(thread, r_usage.ru_inblock);
    writeLong(thread, r_usage.ru_oublock);
    writeLong(thread, r_usage.ru_msgsnd);
    writeLong(thread, r_usage.ru_msgrcv);
    writeLong(thread, r_usage.ru_nsignals);
    writeLong(thread, r_usage.ru_nvcsw);
    writeLong(thread, r_usage.ru_nivcsw);
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_resources_commands(void)
{
    ta_register_command("getrlimit",getrlimit_cmd);
    ta_register_command("setrlimit",setrlimit_cmd);

    ta_register_command("getrusage",getrusage_cmd);

    ta_register_command("getrlimit64",getrlimit64_cmd);
    ta_register_command("setrlimit64",setrlimit64_cmd);

    ta_register_command("ulimit",ulimit_cmd);
}
