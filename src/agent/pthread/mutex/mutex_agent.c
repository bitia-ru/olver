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
#include "pthread/mutex/mutex_agent.h"

/*
 * This is a workaround for bug http://bugs.linuxbase.org/show_bug.cgi?id=1432
 * in LSB headers. Early versions of LSB SDK have these constants
 * incorrectly defined.
 */
#if (PTHREAD_MUTEX_DEFAULT == 1)
    #undef PTHREAD_MUTEX_DEFAULT
    #undef PTHREAD_MUTEX_NORMAL
    #undef PTHREAD_MUTEX_RECURSIVE
    #undef PTHREAD_MUTEX_ERRORCHECK

    #define PTHREAD_MUTEX_DEFAULT 0
    #define PTHREAD_MUTEX_NORMAL  0
    #define PTHREAD_MUTEX_RECURSIVE 1
    #define PTHREAD_MUTEX_ERRORCHECK 2
#endif

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_mutex_static_init_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* ptr;

    // Prepare
    ptr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    {
     pthread_mutex_t static_mutex_init_value = PTHREAD_MUTEX_INITIALIZER;
     *ptr = static_mutex_init_value;
    }

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread,"Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutex_init_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
pthread_mutexattr_t* attr;
int res;

    // Prepare
    mutex = readPointer(&stream);
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_init(mutex,attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutex_destroy_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
int res;

    // Prepare
    mutex = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_destroy(mutex);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutex_lock_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
int res;

    // Prepare
    mutex = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_lock(mutex);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_mutex_lock_return");
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutex_trylock_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
int res;

    // Prepare
    mutex = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_trylock(mutex);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutex_unlock_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
int res;

    // Prepare
    mutex = readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_unlock(mutex);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_mutex_unlock_return");
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict pthread_mutex_getprioceiling_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
int prioceiling;
int res;

    // Prepare
    mutex = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_getprioceiling(mutex, &prioceiling);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,prioceiling);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutex_setprioceiling_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutex_t* mutex;
int new_prioceiling;
int old_prioceiling;
int res;

    // Prepare
    mutex = readPointer(&stream);
    new_prioceiling = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutex_setprioceiling(mutex, new_prioceiling, &old_prioceiling);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_mutex_setprioceiling_return");
    writeInt(thread,res);
    writeInt(thread,old_prioceiling);
    sendResponse(thread);

    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_mutex_mutex_commands(void)
{
    ta_register_command("pthread_mutex_static_init",pthread_mutex_static_init_cmd);
    ta_register_command("pthread_mutex_init",pthread_mutex_init_cmd);
    ta_register_command("pthread_mutex_destroy",pthread_mutex_destroy_cmd);
    ta_register_command("pthread_mutex_lock",pthread_mutex_lock_cmd);
    ta_register_command("pthread_mutex_trylock",pthread_mutex_trylock_cmd);
    ta_register_command("pthread_mutex_unlock",pthread_mutex_unlock_cmd);
    ta_register_command("pthread_mutex_getprioceiling",pthread_mutex_getprioceiling_cmd);
    ta_register_command("pthread_mutex_setprioceiling",pthread_mutex_setprioceiling_cmd);
}

