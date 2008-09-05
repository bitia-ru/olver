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


#include "pthread/rwlock/rwlockattr_agent.h"
#include <pthread.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_rwlockattr_destroy_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlockattr_t* attr;
    int res;

    // Prepare
    attr = (pthread_rwlockattr_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlockattr_destroy(attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlockattr_getpshared_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlockattr_t* attr;
    int pshared;
    int res;

    // Prepare
    attr = (pthread_rwlockattr_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlockattr_getpshared(attr, &pshared);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, pshared);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlockattr_init_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlockattr_t* attr;
    int res;

    // Prepare
    attr = (pthread_rwlockattr_t*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlockattr_init(attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_rwlockattr_setpshared_cmd(TAThread thread, TAInputStream stream)
{
    pthread_rwlockattr_t* attr;
    int pshared;
    int res;

    // Prepare
    attr = (pthread_rwlockattr_t*)readPointer(&stream);
    pshared = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_rwlockattr_setpshared(attr, pshared);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_rwlock_rwlockattr_commands(void)
{
    ta_register_command("pthread_rwlockattr_destroy", pthread_rwlockattr_destroy_cmd);
    ta_register_command("pthread_rwlockattr_getpshared", pthread_rwlockattr_getpshared_cmd);
    ta_register_command("pthread_rwlockattr_init", pthread_rwlockattr_init_cmd);
    ta_register_command("pthread_rwlockattr_setpshared", pthread_rwlockattr_setpshared_cmd);
}

