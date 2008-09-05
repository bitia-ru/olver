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


#include "pthread/tls/tls_agent.h"
#include <pthread.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
    
typedef struct SpecificT
{
    void * ta_data;
//    int scen_data;
} SpecificT;

/********************************************************************/
/**                           Destructor                           **/
/********************************************************************/

void destructorFunc(void* specific)
{
    SpecificT * specific_t = specific;
    pthread_setspecific(ta_thread_key, (specific_t->ta_data)); // temporary reparing deleted ta_data
    ta_debug_printf("<%d> Destructor. Registering reaction. data = %d\n",pthread_self(),specific_t->ta_data);
    TAThread thread = ta_current_thread();
    writeDeferredReaction(thread,"pthread_key_destructor_call");
    writePointer(thread,specific);
    sendResponse(thread);

    ta_debug_printf("<%d> Destructor. Start recieving commands\n",pthread_self());
     ta_main_routine(NULL);
    ta_debug_printf("Destructor. Finish recieving commands\n");
    pthread_setspecific(ta_thread_key, NULL); //
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict _destructor_return(TAThread thread, TAInputStream stream)
{
    TACommandVerdict taVerdict;

    writeString(thread, "Ok");
    sendResponse(thread);

    taVerdict.finish = 1;
    return taVerdict;
}
/**/

static TACommandVerdict pthread_getspecific_cmd(TAThread thread,TAInputStream stream)
{
    void *keyPtr;
    void *res;
    // Prepare
//    void *pthread_getspecific(pthread_key_t key);
    keyPtr = readPointer(&stream);
    errno = readInt(&stream); 
    
    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_getspecific( *(pthread_key_t*)keyPtr );

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread,res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_setspecific_cmd(TAThread thread,TAInputStream stream)
{
//     int pthread_setspecific(pthread_key_t key, const void *value);
    void *keyPtr;
    void *value;
    int res;
    // Prepare
    keyPtr = readPointer(&stream);
    value = readPointer(&stream);

    //ta_debug_printf("pid:%p \tsetspecific:%p \tval:%p\n", getpid(), keyPtr, value);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_setspecific( *(pthread_key_t*)keyPtr, value );

    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict pthread_key_create_cmd(TAThread thread,TAInputStream stream)
{
//     int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));
    void* key;
    int destructor;
    int res;
    // Prepare
    key = readPointer( &stream );
    destructor = readInt( &stream );

    START_TARGET_OPERATION(thread);

    // Execute
    if(destructor)
    {
        res = pthread_key_create((pthread_key_t*)key, destructorFunc);
        ta_debug_printf("Destructor setup!\n");
    }
    else
        res = pthread_key_create((pthread_key_t*)key, NULL);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict pthread_key_delete_cmd(TAThread thread,TAInputStream stream)
{
//      int pthread_key_delete(pthread_key_t key);
    void *keyPtr;
    int res;

    // Prepare
    keyPtr = readPointer( &stream );

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_key_delete(*(pthread_key_t*)keyPtr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict postpone_thread_cleanup_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);

    thread->level++; // Hacked! Thread won't cleanup.
    ta_debug_printf("<%d> postponed. level = %d\n",pthread_self(),thread->level);
    
    END_TARGET_OPERATION(thread);

    // Response
    writePointer( thread, (void *)thread ); // sending `thread`
    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_tls_commands(void)
{
 //   ta_register_command("get_SC_THREAD_KEYS_MAX", get_SC_THREAD_KEYS_MAX_cmd);
    ta_register_command("_destructor_return",_destructor_return); 
    ta_register_command("pthread_getspecific",pthread_getspecific_cmd);
    ta_register_command("pthread_setspecific",pthread_setspecific_cmd);
    ta_register_command("pthread_key_create",pthread_key_create_cmd);
    ta_register_command("pthread_key_delete",pthread_key_delete_cmd);
    
    ta_register_command("postpone_thread_cleanup",postpone_thread_cleanup_cmd);    
}
