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

#include <semaphore.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#include "pthread/sem/sem_agent.h"
#include "io/file/file_agent.h"
#include "fs/fs/fs_agent.h" 
 

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict sem_close_cmd(TAThread thread,TAInputStream stream)
{
    sem_t* semaphore;
    int res;
    int save_errno;

    // Prepare
    semaphore = readPointer(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute

    res = sem_close(semaphore);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno); 
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_destroy_cmd(TAThread thread,TAInputStream stream)
{
    sem_t *sem;
    int res, save_errno;
    
    // Prepare
    sem = readPointer(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sem_destroy(sem);
    save_errno = errno;

    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno);
    
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_getvalue_cmd(TAThread thread, TAInputStream stream)
{
    int val;
    int* sval = &val;
    sem_t* sem;
    int res, save_errno;
    
    // Prepare
    sem = readPointer(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);
    
    // Execute
    
    res = sem_getvalue(sem, sval);
    save_errno = errno;
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, *sval);
    writeInt(thread, res);
    writeInt(thread, save_errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_init_cmd(TAThread thread,TAInputStream stream)
{
    int res, save_errno;
    sem_t *sem;
    int pshared;
    unsigned value;
    
    // Prepare
    sem = readPointer(&stream);
    pshared = readInt(&stream);
    value = readUInt(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sem_init(sem, pshared, value);
    save_errno = errno;
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, save_errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_open_cmd(TAThread thread, TAInputStream stream)
{
    char* name;
    int oflag;
    unsigned mode, init_value;
    sem_t* semaphore;
    int save_errno;
    
    // Prepare
    name = readPointer(&stream);
    oflag = readOpenFlags(&stream);
    mode = readFilePermissions(&stream);
    init_value = readUInt(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute

    //cheat!!!!!!!!!!!!!!!!!!!!!!!!!
    // should be -> semaphore = sem_open(name, oflag, mode, init_value);
    semaphore = sem_open(name, oflag, mode, init_value);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, semaphore);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_post_cmd(TAThread thread,TAInputStream stream)
{
    sem_t* semaphore;
    int res;
    int save_errno;

    // Prepare
    semaphore = readPointer(&stream);

    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = sem_post(semaphore);
    save_errno = errno;
    
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_sem_post_return");
    writeInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sem_timedwait_cmd(TAThread thread,TAInputStream stream)
{
    sem_t* semaphore;
    int res;
    int save_errno;
    struct timespec   timeout;
    TimeUnit          delta;
    
    // Prepare
    semaphore = readPointer(&stream);
    delta = readTimeUnit(&stream);
    
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    timeout = addTimeUnit(thread->start_time, delta);       // Get the absolute timeout value

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = sem_timedwait(semaphore, &timeout);
    save_errno = errno;
    
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_sem_timedwait_return");
    writeInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sem_trywait_cmd(TAThread thread,TAInputStream stream)
{
    sem_t* semaphore;
    int res, save_errno;

    // Prepare
    semaphore = readPointer(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute

    res = sem_trywait(semaphore);
    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_unlink_cmd(TAThread thread,TAInputStream stream)
{
    char* name;
    int res, save_errno;
    
    // Prepare
    name = readPointer(&stream);
    
    errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute
    res = sem_unlink(name);

    save_errno = errno;

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sem_wait_cmd(TAThread thread,TAInputStream stream)
{
    sem_t* semaphore;
    int res;
    int save_errno;
    // Prepare
    semaphore = readPointer(&stream);

    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = sem_wait(semaphore);
    save_errno = errno;
    
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread,"pthread_sem_wait_return");
    writeInt(thread, res);
    writeInt(thread, save_errno);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_sem_commands(void)
{
        ta_register_command("sem_close",sem_close_cmd);
        ta_register_command("sem_destroy",sem_destroy_cmd);
        ta_register_command("sem_getvalue",sem_getvalue_cmd);
        ta_register_command("sem_init",sem_init_cmd);
        ta_register_command("sem_open",sem_open_cmd);
        ta_register_command("sem_post",sem_post_cmd);
        ta_register_command("sem_timedwait",sem_timedwait_cmd);
        ta_register_command("sem_trywait",sem_trywait_cmd);
        ta_register_command("sem_unlink",sem_unlink_cmd);
        ta_register_command("sem_wait", sem_wait_cmd);
}
