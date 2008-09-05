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
#include "pthread/rwlock/rwlock_agent.h"
#include <stdio.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_rwlock_destroy_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int res;

    // Prepare
    rwlock = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_destroy(rwlock);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_init_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    pthread_rwlockattr_t* attr;
    int res;

    // Prepare
    rwlock = readPointer(&stream);
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_init(rwlock, attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_rdlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int res;

    // Prepare
    rwlock = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_rdlock(rwlock);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_rwlock_rdlock_return");
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_timedrdlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    TimeUnit          delta;
    struct timespec   timeout;
    int res;

    // Prepare
    rwlock  = readPointer(&stream);
    delta   = readTimeUnit(&stream);        // Reading the relative time

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    timeout = addTimeUnit(thread->start_time, delta);       // Get the absolute timeout value

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_timedrdlock(rwlock, &timeout);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_rwlock_timedrdlock_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_timedrdlock_bad_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int               nsec;
    struct timespec   timeout;
    int res;

    // Prepare
    rwlock = readPointer(&stream);
    nsec   = readInt(&stream);

    timeout = thread->start_time;
    timeout.tv_sec += 2;
    timeout.tv_nsec = nsec;

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_timedrdlock(rwlock, &timeout);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_timedwrlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    TimeUnit          delta;
    struct timespec   timeout;
    int res;

    // Prepare
    rwlock  = readPointer(&stream);
    delta   = readTimeUnit(&stream);        // Reading the relative time

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    timeout = addTimeUnit(thread->start_time, delta);       // Get the absolute timeout value

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_timedwrlock(rwlock, &timeout);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_rwlock_timedwrlock_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_timedwrlock_bad_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int               nsec;
    struct timespec   timeout;
    int res;

    // Prepare
    rwlock = readPointer(&stream);
    nsec   = readInt(&stream);

    timeout = thread->start_time;
    timeout.tv_sec += 2;
    timeout.tv_nsec = nsec;

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_timedwrlock(rwlock, &timeout);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_tryrdlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int res;

    // Prepare
    rwlock = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_tryrdlock(rwlock);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_trywrlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int res;

    // Prepare
    rwlock = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_trywrlock(rwlock);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_unlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int res;

    // Prepare
    rwlock = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_unlock(rwlock);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_rwlock_unlock_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlock_wrlock_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlock_t* rwlock;
    int res;

    // Prepare
    rwlock = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread, "Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlock_wrlock(rwlock);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "pthread_rwlock_wrlock_return");
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_rwlock_rwlock_commands(void)
{
    ta_register_command("pthread_rwlock_destroy", pthread_rwlock_destroy_cmd);
    ta_register_command("pthread_rwlock_init", pthread_rwlock_init_cmd);
    ta_register_command("pthread_rwlock_rdlock", pthread_rwlock_rdlock_cmd);

    ta_register_command("pthread_rwlock_timedrdlock", pthread_rwlock_timedrdlock_cmd);
    ta_register_command("pthread_rwlock_timedrdlock_bad", pthread_rwlock_timedrdlock_bad_cmd);
    ta_register_command("pthread_rwlock_timedwrlock", pthread_rwlock_timedwrlock_cmd);
    ta_register_command("pthread_rwlock_timedwrlock_bad", pthread_rwlock_timedwrlock_bad_cmd);

    ta_register_command("pthread_rwlock_tryrdlock", pthread_rwlock_tryrdlock_cmd);

    ta_register_command("pthread_rwlock_trywrlock", pthread_rwlock_trywrlock_cmd);
    ta_register_command("pthread_rwlock_unlock", pthread_rwlock_unlock_cmd);
    ta_register_command("pthread_rwlock_wrlock", pthread_rwlock_wrlock_cmd);
}
