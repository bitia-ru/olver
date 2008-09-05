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


#include "pthread/attr/attr_agent.h"
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>



/********************************************************************/
/**                        Special Commands                        **/
/********************************************************************/
static TACommandVerdict get_SC_THREAD_STACK_MIN_cmd(TAThread thread,
                                                    TAInputStream stream)
{
    long res;
    START_TARGET_OPERATION(thread);
    res = sysconf(_SC_THREAD_STACK_MIN);
    END_TARGET_OPERATION(thread);

    writeLong(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict get_SC_PAGE_SIZE_cmd(TAThread thread,
                                                    TAInputStream stream)
{
    long res;
    START_TARGET_OPERATION(thread);
    res = sysconf(_SC_PAGESIZE);
    END_TARGET_OPERATION(thread);
    
    writeLong(thread,res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_attr_destroy_cmd(TAThread thread,
                                                 TAInputStream stream)
{
    int res;
    pthread_attr_t *attr;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_destroy(attr);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writePointer(thread,(void*)attr);

    sendResponse(thread);
    return taDefaultVerdict;

}

static TACommandVerdict pthread_attr_getdetachstate_cmd(TAThread thread,
                                                        TAInputStream stream)
{
    pthread_attr_t *attr;
    int            detachstate;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getdetachstate(attr, &detachstate);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, detachstate);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_getguardsize_cmd(TAThread thread,
                                                      TAInputStream stream)
{
    pthread_attr_t *attr;
    size_t          guardsize;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getguardsize(attr, &guardsize);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeSize(thread, guardsize);

    sendResponse(thread);
    return taDefaultVerdict;

}

static TACommandVerdict pthread_attr_getinheritsched_cmd(TAThread thread,
                                                         TAInputStream stream)
{
    pthread_attr_t *attr;
    int            inheritedsched;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getinheritsched(attr, &inheritedsched);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, inheritedsched);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_getschedparam_cmd(TAThread thread,
                                                       TAInputStream stream)
{
    pthread_attr_t *attr;
    struct sched_param  param;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getschedparam(attr, &param);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, param.sched_priority);


#if (defined(_POSIX_THREAD_SPORADIC_SERVER) && _POSIX_THREAD_SPORADIC_SERVER >0) || ( defined(_POSIX_SPORADIC_SERVER) && _POSIX_SPORADIC_SERVER>0)

    writeInt(thread, param.sched_ss_low_priority);
    writeLong(thread, param.sched_ss_repl_period.tv_sec);
    writeLong(thread, param.sched_ss_repl_period.tv_nsec);
    writeLong(thread, param.sched_ss_init_budget.tv_sec);
    writeLong(thread, param.sched_ss_init_budget.tv_nsec);
    writeInt(thread, param.sched_ss_max_repl);
#else
    writeInt(thread, 0);
    writeLong(thread, 0);
    writeLong(thread, 0);
    writeLong(thread, 0);
    writeLong(thread, 0);
    writeInt(thread, 0);
#endif

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_getschedpolicy_cmd(TAThread thread,
                                                        TAInputStream stream)
{
    pthread_attr_t *attr;

    int policy;

    int res;



    attr = (pthread_attr_t *)readPointer(&stream);





    START_TARGET_OPERATION(thread);

    res = pthread_attr_getschedpolicy(attr, &policy);

    END_TARGET_OPERATION(thread);



    writeInt(thread, res);

    writeInt(thread, policy);





    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict pthread_attr_getscope_cmd(TAThread thread,
                                                  TAInputStream stream)
{
    pthread_attr_t *attr;
    int contScope;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getscope(attr, &contScope);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeInt(thread, contScope);


    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_getstack_cmd(TAThread thread,
                                                  TAInputStream stream)
{
    pthread_attr_t *attr;
    void *stackaddr;
    size_t stacksize;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getstack(attr, &stackaddr, &stacksize);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writePointer(thread, stackaddr);
    writeSize(thread, stacksize);


    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_getstackaddr_cmd(TAThread thread,
                                                      TAInputStream stream)
{
    pthread_attr_t *attr;
    void *stackaddr;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getstackaddr(attr, &stackaddr);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writePointer(thread, stackaddr);


    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_getstacksize_cmd(TAThread thread,
                                                      TAInputStream stream)
{
    pthread_attr_t *attr;
    size_t stacksize;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_getstacksize(attr, &stacksize);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeSize(thread, stacksize);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_init_cmd(TAThread thread,
                                              TAInputStream stream)
{
    int res;
    pthread_attr_t *attr;

    attr = (pthread_attr_t *)readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_init(attr);

    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writePointer(thread,(void*)attr);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setdetachstate_cmd(TAThread thread,
                                                        TAInputStream stream)
{
    pthread_attr_t *attr;
    int            detachstate;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    detachstate = readInt(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setdetachstate(attr, detachstate);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setguardsize_cmd(TAThread thread,
                                                      TAInputStream stream)
{
    pthread_attr_t *attr;
    size_t         guardsize;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    guardsize = readSize(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setguardsize(attr, guardsize);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setinheritsched_cmd(TAThread thread,
                                                         TAInputStream stream)
{
    pthread_attr_t *attr;
    int          inheritedsched;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    inheritedsched = readInt(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setinheritsched(attr, inheritedsched);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setschedparam_cmd(TAThread thread,
                                                       TAInputStream stream)
{
    pthread_attr_t *attr;
    struct sched_param param;
    int res;

#if (defined(_POSIX_THREAD_SPORADIC_SERVER) && _POSIX_THREAD_SPORADIC_SERVER >0) || ( defined(_POSIX_SPORADIC_SERVER) && _POSIX_SPORADIC_SERVER>0)
    attr = (pthread_attr_t *)readPointer(&stream);
    param.sched_priority = readInt(&stream);
    param.sched_ss_low_priority = readInt(&stream);
    param.sched_ss_repl_period.tv_sec  = readLong(&stream);
    param.sched_ss_repl_period.tv_nsec = readLong(&stream); 
    param.sched_ss_init_budget.tv_sec = readLong(&stream); 
    param.sched_ss_init_budget.nsec = readLong(&stream);  
    param.sched_ss_max_repl = readInt(&stream);
#else
    attr = (pthread_attr_t *)readPointer(&stream);
    param.sched_priority = readInt(&stream);
    readInt(&stream);
    readLong(&stream);
    readLong(&stream); 
    readLong(&stream); 
    readLong(&stream);  
    readInt(&stream);
#endif


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setschedparam(attr, &param);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setschedpolicy_cmd(TAThread thread,
                                                        TAInputStream stream)
{
    pthread_attr_t *attr;

    int policy;

    int res;



    attr = (pthread_attr_t *)readPointer(&stream);

    policy = readInt(&stream);



    START_TARGET_OPERATION(thread);

    res = pthread_attr_setschedpolicy(attr, policy);

    END_TARGET_OPERATION(thread);



    writeInt(thread, res);



    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict pthread_attr_setscope_cmd(TAThread thread,
                                                  TAInputStream stream)
{
    pthread_attr_t *attr;
    int contScope;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    contScope = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = pthread_attr_setscope(attr, contScope);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setstack_cmd(TAThread thread,
                                                  TAInputStream stream)
{
    pthread_attr_t *attr;
    void *stackaddr;
    size_t stacksize;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    stackaddr = readPointer(&stream);
    stacksize = readSize(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setstack(attr, stackaddr, stacksize);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setstackaddr_cmd(TAThread thread,
                                                      TAInputStream stream)
{
    pthread_attr_t *attr;
    void *stackaddr;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    stackaddr = readPointer(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setstackaddr(attr, stackaddr);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pthread_attr_setstacksize_cmd(TAThread thread,
                                                      TAInputStream stream)
{

    pthread_attr_t *attr;
    void *stackaddr;
    size_t stacksize;
    int res;

    attr = (pthread_attr_t *)readPointer(&stream);
    stacksize = readSize(&stream);


    START_TARGET_OPERATION(thread);
    res = pthread_attr_setstacksize(attr, stacksize);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_attr_commands(void)
{
    ta_register_command("get_SC_THREAD_STACK_MIN",
        get_SC_THREAD_STACK_MIN_cmd);
    ta_register_command("get_SC_PAGE_SIZE",
        get_SC_PAGE_SIZE_cmd);
    ta_register_command("pthread_attr_destroy",pthread_attr_destroy_cmd);
    ta_register_command("pthread_attr_getdetachstate",
        pthread_attr_getdetachstate_cmd);
    ta_register_command("pthread_attr_getguardsize",
        pthread_attr_getguardsize_cmd);
    ta_register_command("pthread_attr_getinheritsched",
        pthread_attr_getinheritsched_cmd);
    ta_register_command("pthread_attr_getschedparam",
        pthread_attr_getschedparam_cmd);
    ta_register_command("pthread_attr_getschedpolicy",
        pthread_attr_getschedpolicy_cmd);
    ta_register_command("pthread_attr_getscope",pthread_attr_getscope_cmd);
    ta_register_command("pthread_attr_getstack",pthread_attr_getstack_cmd);
    ta_register_command("pthread_attr_getstackaddr",
        pthread_attr_getstackaddr_cmd);
    ta_register_command("pthread_attr_getstacksize",
        pthread_attr_getstacksize_cmd);
    ta_register_command("pthread_attr_init",pthread_attr_init_cmd);
    ta_register_command("pthread_attr_setdetachstate",
        pthread_attr_setdetachstate_cmd);
    ta_register_command("pthread_attr_setguardsize",
        pthread_attr_setguardsize_cmd);
    ta_register_command("pthread_attr_setinheritsched",
        pthread_attr_setinheritsched_cmd);
    ta_register_command("pthread_attr_setschedparam",
        pthread_attr_setschedparam_cmd);
    ta_register_command("pthread_attr_setschedpolicy",
        pthread_attr_setschedpolicy_cmd);
    ta_register_command("pthread_attr_setscope",pthread_attr_setscope_cmd);
    ta_register_command("pthread_attr_setstack",pthread_attr_setstack_cmd);
    ta_register_command("pthread_attr_setstackaddr",
        pthread_attr_setstackaddr_cmd);
    ta_register_command("pthread_attr_setstacksize",
        pthread_attr_setstacksize_cmd);
}

