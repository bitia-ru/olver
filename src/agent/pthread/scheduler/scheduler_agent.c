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


#include "pthread/scheduler/scheduler_agent.h"
#include "pthread.h"

/********************************************************************/
/**                            Config                              **/
/********************************************************************/

#define PTHREAD_SETSCHEDPRIO_IS_SUPPORTED 0

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_getconcurrency_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);

    res = pthread_getconcurrency();

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_setconcurrency_cmd(TAThread thread,TAInputStream stream)
{
    int new_level;
    int res;

    new_level = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = pthread_setconcurrency(new_level);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_getschedparam_cmd(TAThread thread,TAInputStream stream)
{
    pthread_t param_thread;
    int policy;
    struct sched_param param_sched;
    int res;
    int isPolicyNull, isSchedNull;

    param_thread = readULong(&stream);
    isPolicyNull = readInt(&stream);
    isSchedNull = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = pthread_getschedparam(param_thread, (isPolicyNull?NULL:&policy), (isSchedNull?NULL:&param_sched));

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    if(!isPolicyNull)
        writeInt(thread, policy);
    if(!isSchedNull)
        writeInt(thread, param_sched.sched_priority);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_setschedparam_cmd(TAThread thread,TAInputStream stream)
{
    pthread_t param_thread;
    int policy;
    struct sched_param param_sched;
    int res;
    int isSchedNull;

    param_thread = readULong(&stream);
    policy = readInt(&stream);
    isSchedNull = readInt(&stream);
    param_sched.sched_priority = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = pthread_setschedparam(param_thread, policy, (isSchedNull?NULL:&param_sched) );

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_setschedprio_cmd(TAThread thread,TAInputStream stream)
{
    pthread_t param_thread;
    int prio;
    int res;

//    #if PTHREAD_SETSCHEDPRIO_IS_SUPPORTED<=0
//        sendException(thread, "Function <i>pthread_setschedprio</i>() is not supported!");
//        return taDefaultVerdict;
//    #else
    param_thread = readULong(&stream);
    prio = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = pthread_setschedprio(param_thread, prio );

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
 //   #endif
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_scheduler_commands(void)
{
    ta_register_command("pthread_getconcurrency",pthread_getconcurrency_cmd);
    ta_register_command("pthread_setconcurrency",pthread_setconcurrency_cmd);
    ta_register_command("pthread_getschedparam",pthread_getschedparam_cmd);
    ta_register_command("pthread_setschedparam",pthread_setschedparam_cmd);
    ta_register_command("pthread_setschedprio",pthread_setschedprio_cmd);
}
