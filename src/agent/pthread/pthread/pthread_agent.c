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
#include <string.h>
#include "pthread/pthread/pthread_agent.h"

#include <stdio.h>
#include <errno.h>


void* ta_thread_main_routine(void* par);

void cleaner(void* arg)
{
    TAThread thread = ta_current_thread();

    ta_debug_printf("cleaner..\n");

    END_TARGET_OPERATION(thread);
    writeDeferredReaction(thread, "_pthread_cleanup_return");
    writePointer(thread, arg);
    sendResponse(thread);
}


/********************************************************************/
/**                        Format Functions                        **/
/********************************************************************/
void writePShared(TAThread thread,int pshared)
{
    writeType_TAStream(thread,"pshared");
    switch (pshared)
    {
    case PTHREAD_PROCESS_PRIVATE :
        writeString( thread, "PTHREAD_PROCESS_PRIVATE" );
        return;
    case PTHREAD_PROCESS_SHARED :
        writeString( thread, "PTHREAD_PROCESS_SHARED" );
        return;
    }
    writeInt( thread, pshared );
}

#define PTHREAD_PROCESS_SHARED_INVALID_VALUE -11

int readPShared(TAInputStream* stream)
{
    int res;

    verifyType_TAInputStream(stream,"pshared");
    if (startsWith_TAInputStream(stream,"str"))
    {
        char* value = readString(stream);
        if (strcmp(value,"PTHREAD_PROCESS_PRIVATE") == 0)
            return PTHREAD_PROCESS_PRIVATE;
        if (strcmp(value,"PTHREAD_PROCESS_SHARED") == 0)
            return PTHREAD_PROCESS_SHARED;
        assertion( 0, "Invalid pshared: %s", value );
    }
    res = readInt(stream);
    switch (res)
    {
    case PTHREAD_PROCESS_PRIVATE :
    case PTHREAD_PROCESS_SHARED :
        res = PTHREAD_PROCESS_SHARED_INVALID_VALUE;
        break;
    }
    return res;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __errno_location_cmd(TAThread thread,TAInputStream stream)
{
    int* res;

    START_TARGET_OPERATION(thread);
    res = __errno_location();
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict _pthread_cleanup_pop_cmd(TAThread thread,
                                                 TAInputStream stream)
{
    TACommandVerdict taVerdict;
    void* exit_code;

    // Prepare
    exit_code = (void*)readInt(&stream);

    // Execute
    taVerdict.finish = 1;
    taVerdict.status = exit_code;

    return taVerdict;
}

static TACommandVerdict _pthread_cleanup_push_cmd(TAThread thread,
                                                  TAInputStream stream)
{
    int res;
    void* arg;

    // Execute
    ta_debug_printf("push_cmd\n");

    arg=readPointer(&stream);
    START_TARGET_OPERATION(thread);
    pthread_cleanup_push(cleaner, arg);
    END_TARGET_OPERATION(thread);

    // Response pthread_cleanup_push_spec
    writeString(thread,"Ok");
    sendResponse(thread);
    ta_debug_printf("Push response send...\n");
    res = (int) ta_main_routine(NULL);
    ta_debug_printf("aft_ta_main: res==%d\n", res);


    // Response pthread_cleanup_pop_spec
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);


    START_TARGET_OPERATION(thread);
    pthread_cleanup_pop(res);
    END_TARGET_OPERATION(thread);


    // Response _pthread_cleanup_pop_return
    writeDeferredReaction(thread, "_pthread_cleanup_pop_return");
    writeInt(thread,res);

    sendResponse(thread);
    ta_debug_printf("Pop response send...\n");

    return taDefaultVerdict;
}

static TACommandVerdict pthread_cancel_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pthread_t      threadp;
    
    threadp=readULong(&stream);
    
    START_TARGET_OPERATION(thread);
    res = pthread_cancel(threadp);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_create_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pthread_t      threadp;
    pthread_attr_t *attr;
    void* arg;
    
    attr = (pthread_attr_t *)readPointer(&stream);
    arg  = readPointer(&stream);
    
    ta_debug_printf("CREATING THREAD WITH PARAMETER: %ld\n", ((long)arg));
    START_TARGET_OPERATION(thread);
    res = pthread_create(&threadp, attr, ta_thread_main_routine, arg);
    
    END_TARGET_OPERATION(thread);
    
    ta_debug_printf("CREATED THREAD ID IS: %lu\n", ((unsigned long)threadp));

    writeInt(thread, res);
    writeULong(thread, threadp);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_detach_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pthread_t      threadp;
    
    threadp=readULong(&stream);
    
    ta_debug_printf("DETACH:%u", (int)threadp);
    
    
    START_TARGET_OPERATION(thread);
    res = pthread_detach(threadp);
    
    END_TARGET_OPERATION(thread);
    
    ta_debug_printf("DETACH:%u res:%d\n", (int)threadp);
    writeInt(thread, res);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_equal_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pthread_t      t1;
    pthread_t      t2;
    
    t1 = readULong(&stream);
    t2 = readULong(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = pthread_equal(t1, t2);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    
    sendResponse(thread);
    return taDefaultVerdict;
}


static TACommandVerdict pthread_exit_cmd(TAThread thread,TAInputStream stream)
{
    void* value_ptr;
    
    value_ptr = readPointer(&stream);
    
    ta_debug_printf("calling pthread_exit\n");

    START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    pthread_exit(value_ptr);
    END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread);
    
    sendException(thread,"pthread_exit returns");
    
    return taDefaultVerdict;
}

static TACommandVerdict pthread_join_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pthread_t      threadp;
    int            notZeroPointer;
    void *         value_ptr=NULL;
    struct CancelPointDetectorParam param;
    
    param.thread=thread;
    param.defferedReactionName="pthread_join_return";
    
    threadp = readULong(&stream);
    notZeroPointer = readInt(&stream);
    
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    
    writeString(thread,"Ok");
    sendResponse(thread);
    
    
    ta_debug_printf("JOIN:%u\n", (int)threadp);
    
    if (notZeroPointer)
    {
        START_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, param);
        res = pthread_join(threadp, &value_ptr);
        END_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, "pthread_join_return");
    }
    else
    {
        START_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, param);
        res = pthread_join(threadp, NULL);
        END_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, "pthread_join_return");
    }
    
    writeInt(thread, res);
    writePointer(thread, value_ptr);
    writeULong(thread, threadp);
    writeInt(thread, notZeroPointer);
    
    ta_debug_printf("JOIN RETURNED:%u res:%u\n", (int)threadp, (int)res);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static int onceCalled;

void pthread_once_init_routine(void)
{
    onceCalled=1;
}

static TACommandVerdict pthread_once_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    pthread_once_t *once_control;
    
    once_control = (pthread_once_t *)readPointer(&stream);
    onceCalled=0;
    
    
    START_TARGET_OPERATION(thread);
    res = pthread_once(once_control, pthread_once_init_routine);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, onceCalled);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict pthread_self_cmd(TAThread thread,TAInputStream stream)
{
    pthread_t res;
    
    START_TARGET_OPERATION(thread);
    res = pthread_self();
    
    END_TARGET_OPERATION(thread);
    
    writeULong(thread, res);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_setcancelstate_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cstate;
    int oldstate;
    
    cstate = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res =   pthread_setcancelstate(cstate, &oldstate);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, oldstate);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_setcanceltype_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int cancel_type;
    int oldtype;
    
    cancel_type = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res =   pthread_setcanceltype(cancel_type, &oldtype);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, oldtype);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_testcancel_cmd(TAThread thread,TAInputStream stream)
{
    struct CancelPointDetectorParam param;

    param.thread=thread;
    param.defferedReactionName="pthread_testcancel_return";


    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    ta_debug_printf("Before pthread_testcancel\n");

    START_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, param);
    pthread_testcancel();
    END_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, "pthread_testcancel_return");

    ta_debug_printf("Reached pthread_testcancel_return\n");

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

TACommandVerdict pthread_finish_cmd(TAThread thread,TAInputStream stream)
{
    TACommandVerdict taVerdict;
    void* exit_code;
    
    // Prepare
    exit_code = readPointer(&stream);
    
    writeString(thread,"Ok");
    sendResponse(thread);
    
    ta_debug_printf( "pthread_finish(%p)\n", exit_code );
    
    // Execute
    taVerdict.finish = 1;
    taVerdict.status = exit_code;
    return taVerdict;
}



/************************************************************************/
static TACommandVerdict test_create_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}
static TACommandVerdict test_kill_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}
static TACommandVerdict test_push_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}
static TACommandVerdict test_pop_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}
/************************************************************************/
/*                                                                      */
/************************************************************************/
static TACommandVerdict dim_add_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}
static TACommandVerdict dim_remove_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_pthread_commands(void)
{
    ta_register_command("__errno_location",__errno_location_cmd);
    ta_register_command("_pthread_cleanup_pop",_pthread_cleanup_pop_cmd);
    ta_register_command("_pthread_cleanup_push",_pthread_cleanup_push_cmd);
    ta_register_command("pthread_cancel",pthread_cancel_cmd);
    ta_register_command("pthread_create",pthread_create_cmd);
    ta_register_command("pthread_detach",pthread_detach_cmd);
    ta_register_command("pthread_equal",pthread_equal_cmd);
    ta_register_command("pthread_exit",pthread_exit_cmd);
    ta_register_command("pthread_join",pthread_join_cmd);
    ta_register_command("pthread_once",pthread_once_cmd);
    ta_register_command("pthread_self",pthread_self_cmd);
    ta_register_command("pthread_setcancelstate",pthread_setcancelstate_cmd);
    ta_register_command("pthread_setcanceltype",pthread_setcanceltype_cmd);
    ta_register_command("pthread_testcancel",pthread_testcancel_cmd);

    ta_register_command("pthread_finish",pthread_finish_cmd);

    ta_register_command("test_create",test_create_cmd);
    ta_register_command("test_kill",test_kill_cmd);
    ta_register_command("test_push",test_push_cmd);
    ta_register_command("test_pop",test_pop_cmd);

    ta_register_command("dim_add",dim_add_cmd);
    ta_register_command("dim_remove",dim_remove_cmd);
}

