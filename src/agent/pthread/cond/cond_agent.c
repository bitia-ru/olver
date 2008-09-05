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

#include <pthread.h>
#include "pthread/cond/cond_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_cond_init_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t* cond;
    pthread_condattr_t* attr;
    int res;

    // Prepare
    cond = readPointer(&stream);
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_init(cond, attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_cond_destroy_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t* cond;
    int res;

    // Prepare
    cond = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_destroy(cond);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;    
}

static TACommandVerdict pthread_cond_broadcast_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t* cond;
    int res;

    // Prepare
    cond = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_broadcast(cond);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_cond_broadcast_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_cond_signal_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t* cond;
    int res;

    // Prepare
    cond = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_signal(cond);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_cond_signal_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_cond_wait_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t* cond;
    pthread_mutex_t* mutex; 
    int res;

    // Prepare
    cond = readPointer(&stream);
    mutex = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_wait(cond, mutex);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_cond_wait_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_cond_timedwait_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t*  cond;
    pthread_mutex_t* mutex;
    TimeUnit         timeout;
    struct timespec  abstime;
    int res;

    // Prepare
    cond = readPointer(&stream);
    mutex = readPointer(&stream);
    timeout = readTimeUnit(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    abstime = addTimeUnit(thread->start_time, timeout); 

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_timedwait(cond, mutex, &abstime);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_cond_timedwait_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_cond_timedwait_bad_cmd(TAThread thread, TAInputStream stream)
{
    pthread_cond_t*  cond;
    pthread_mutex_t* mutex;
    int              nsec;
    struct timespec  abstime;
    int res;

    // Prepare
    cond  = readPointer(&stream);
    mutex = readPointer(&stream);
    nsec  = readInt(&stream);

    abstime = thread->start_time;
    abstime.tv_sec += 2;
    abstime.tv_nsec = nsec;

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_cond_timedwait(cond, mutex, &abstime);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_cond_cond_commands(void)
{
    ta_register_command("pthread_cond_init", pthread_cond_init_cmd);
    ta_register_command("pthread_cond_destroy", pthread_cond_destroy_cmd);
    ta_register_command("pthread_cond_broadcast", pthread_cond_broadcast_cmd);
    ta_register_command("pthread_cond_signal", pthread_cond_signal_cmd);
    ta_register_command("pthread_cond_wait", pthread_cond_wait_cmd);
    ta_register_command("pthread_cond_timedwait", pthread_cond_timedwait_cmd);
    ta_register_command("pthread_cond_timedwait_bad", pthread_cond_timedwait_bad_cmd);
}

