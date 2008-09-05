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


#include "process/scheduler/scheduler_agent.h"
#include <errno.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>

/********************************************************************/
/**                         Scheduler Types Readers And Writers    **/
/********************************************************************/

void readSchedParam(TAInputStream * stream, struct sched_param * param)
{
    verifyType_TAInputStream(stream, "schpar");

    param->sched_priority = readInt(stream);
#if (defined(_POSIX_THREAD_SPORADIC_SERVER) && _POSIX_THREAD_SPORADIC_SERVER >0) || ( defined(_POSIX_SPORADIC_SERVER) && _POSIX_SPORADIC_SERVER>0)
    param->sched_ss_low_priority = readInt(stream);
    param->sched_ss_repl_period.tv_sec = readLong(stream);
    param->sched_ss_repl_period.tv_nsec = readLong(stream);
    param->sched_ss_init_budget.tv_sec = readLong(stream);
    param->sched_ss_init_budget.tv_nsec = readLong(stream);
    param->sched_ss_max_repl = readInt(stream);
#else
    readInt(stream);
    readLong(stream);
    readLong(stream); 
    readLong(stream); 
    readLong(stream);  
    readInt(stream);
#endif
}

void writeSchedParam(TAThread  thread, struct sched_param * param)
{
    writeInt(thread, param->sched_priority);
    
#if (defined(_POSIX_THREAD_SPORADIC_SERVER) && _POSIX_THREAD_SPORADIC_SERVER >0) || ( defined(_POSIX_SPORADIC_SERVER) && _POSIX_SPORADIC_SERVER>0)
    writeInt(thread, param->sched_ss_low_priority);
    writeLong(thread, param->sched_ss_repl_period.tv_sec);
    writeLong(thread, param->sched_ss_repl_period.tv_nsec);
    writeLong(thread, param->sched_ss_init_budget.tv_sec);
    writeLong(thread, param->sched_ss_init_budget.tv_nsec);
    writeInt(thread, param->sched_ss_max_repl);
#else
    writeInt(thread, 0);
    writeLong(thread, 0);
    writeLong(thread, 0);
    writeLong(thread, 0);
    writeLong(thread, 0);
    writeInt(thread, 0);
#endif
    
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict sched_get_priority_max_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int policy;

    // Prepare
    policy = readInt(&stream);
     
    START_TARGET_OPERATION(thread);
    res = sched_get_priority_max(policy);
    END_TARGET_OPERATION(thread);
  
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);     
    
    return taDefaultVerdict;
}

static TACommandVerdict sched_get_priority_min_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int policy;
        
    // Prepare
    policy = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = sched_get_priority_min(policy);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);     
    
    return taDefaultVerdict;
}

static TACommandVerdict sched_getparam_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pid_t pid;
    struct sched_param *param;
    
    // Prepare
    pid = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = sched_getparam(pid, &param); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    writeSchedParam(thread, &param);
    sendResponse(thread);     
    
    return taDefaultVerdict;
}

static TACommandVerdict sched_getscheduler_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int pid;
    
    // Prepare
    pid = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = sched_getscheduler(pid); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    
    sendResponse(thread);     
    
    return taDefaultVerdict;
}

static TACommandVerdict sched_rr_get_interval_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int pid;
    struct timespec interval;
    
    // Prepare
    pid = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = sched_rr_get_interval(pid, &interval); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
 
    writeLong(thread, interval.tv_sec);
    writeLong(thread, interval.tv_nsec);

    sendResponse(thread);     
    
    return taDefaultVerdict;
}

static TACommandVerdict sched_setparam_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pid_t pid;
    struct sched_param param;
        
    // Prepare
    pid = readInt(&stream);
    readSchedParam(&stream, &param);
    
    START_TARGET_OPERATION(thread);
    res =  sched_setparam(pid, &param); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    
    sendResponse(thread);     
    
    return taDefaultVerdict;
}

static TACommandVerdict sched_setscheduler_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pid_t pid;
    int policy;
    struct sched_param param;
    
    // Prepare
    pid = readInt(&stream);
    policy = readInt(&stream);
    readSchedParam(&stream, &param);
    
    START_TARGET_OPERATION(thread);
    res = sched_setscheduler(pid, policy, &param); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    
    sendResponse(thread);     

    return taDefaultVerdict;
}

static TACommandVerdict sched_yield_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = sched_yield(); 
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);     
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_scheduler_commands(void)
{
    ta_register_command("sched_get_priority_max",sched_get_priority_max_cmd);
    ta_register_command("sched_get_priority_min",sched_get_priority_min_cmd);
    ta_register_command("sched_getparam",sched_getparam_cmd);
    ta_register_command("sched_getscheduler",sched_getscheduler_cmd);
    ta_register_command("sched_rr_get_interval",sched_rr_get_interval_cmd);
    ta_register_command("sched_setparam",sched_setparam_cmd);
    ta_register_command("sched_setscheduler",sched_setscheduler_cmd);
    ta_register_command("sched_yield",sched_yield_cmd);
}
