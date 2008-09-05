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



#include "signal/sigwait/sigwait_agent.h"



#include <errno.h>

#include <signal.h>

#include <stdio.h>

    

int get_sigval_data(TAInputStream stream, union sigval* val);

void writeSigval_data(TAThread thread, union sigval val);

int get_siginfo_t_data(TAInputStream stream, siginfo_t* info);

void writeSiginfo_t_data(TAThread thread, siginfo_t* info);

static TACommandVerdict set_siginfo_t_cmd(TAThread thread,TAInputStream stream);

static TACommandVerdict get_siginfo_t_cmd(TAThread thread,TAInputStream stream);

/********************************************************************/

/**                         Agent Commands                         **/

/********************************************************************/



static TACommandVerdict sigtimedwait_cmd(TAThread thread,TAInputStream stream)

{

    siginfo_t* info;

    sigset_t* set;

    struct timespec   timeout;

    TimeUnit          delta;

    int res;

    

    errno = 0; 

    

    ta_debug_printf("start sigwait command\n");

    // Prepare

    set = readPointer(&stream);

    info = readPointer(&stream);

    delta = readTimeUnit(&stream);

    

    BEFORE_BLOCKED_TARGET_OPERATION(thread);



    timeout = addTimeUnit(thread->start_time, delta);



    writeString(thread,"Ok");

    sendResponse(thread);



    START_TARGET_OPERATION(thread);

    

    // Execute


    res = sigtimedwait(set, info, &timeout);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    writeDeferredReaction(thread, "sigtimedwait_react");

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);

    

    return taDefaultVerdict;

}



static TACommandVerdict sigwait_cmd(TAThread thread,TAInputStream stream)

{

    int* int_ptr;

    void* sset_ptr;

    int res;

    ta_debug_printf("start sigwait command\n");

    // Prepare

    sset_ptr = readPointer(&stream);

    int_ptr = readPointer(&stream);

    

    errno = 0; 

    

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");

    sendResponse(thread);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

    ta_debug_printf("start sigwait\n");

    res = sigwait((sigset_t*) sset_ptr, int_ptr);

    ta_debug_printf("end sigwait\n");

    

    END_TARGET_OPERATION(thread);

    

    // Response

    

    writeDeferredReaction(thread, "sigwait_react");

    writePointer(thread, sset_ptr);

    writeInt(thread, *int_ptr);

    writeInt(thread, res);

    writeInt(thread, errno);

    sendResponse(thread);



    return taDefaultVerdict;

}



static TACommandVerdict sigwaitinfo_cmd(TAThread thread,TAInputStream stream)

{

    siginfo_t* info;

    sigset_t* set;

    int res;

    

    errno = 0; 

    // Prepare

    ta_debug_printf("sigwaitinfo command starts\n");

    set = readPointer(&stream);

    info = readPointer(&stream);

    

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");

    sendResponse(thread);

    

    START_TARGET_OPERATION(thread);

    

    // Execute


    res = sigwaitinfo(set, info);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    

    //write values of raeaction fildes

    writeDeferredReaction(thread, "sigwaitinfo_react");

    writePointer(thread, set);

    writePointer(thread, (void *)info);

    writeInt(thread, res);

    writeInt(thread, errno);

    

    //write siginfo data to update info specification structure

    writeSiginfo_t_data(thread, info);    

    sendResponse(thread);

    ta_debug_printf("sigwaitinfo command ends\n");

    return taDefaultVerdict;

}

/********************************************************************/

/**        Sigval struct and siginfo_t struct helper functions     **/

/********************************************************************/

int get_sigval_data(TAInputStream stream, union sigval* val)

{

    int is_int, int_val;

    void* ptr_val;

    

    is_int = readInt(&stream);

    int_val = readInt(&stream);

    ptr_val = readPointer(&stream);

    if(is_int != 0)

    {

        val->sival_int = int_val;

    }

    else

    {

        val->sival_ptr = ptr_val;

    }

}



void writeSigval_data(TAThread thread, union sigval val)

{

    writeInt(thread, val.sival_int);

    writePointer(thread, val.sival_ptr);

}





int get_siginfo_t_data(TAInputStream stream, siginfo_t* info)

{

    info->si_signo = readInt(&stream);

    info->si_errno = readInt(&stream);

    info->si_pid = readInt(&stream);

    info->si_uid = readUInt(&stream);

    info->si_addr = readPointer(&stream);

    info->si_status = readInt(&stream);

    info->si_band = readLong(&stream);

}



void writeSiginfo_t_data(TAThread thread, siginfo_t* info)

{

    writeInt(thread, info->si_signo);

    writeInt(thread, info->si_code);

    writeInt(thread, info->si_errno);

    writeInt(thread, info->si_pid);

    writeUInt(thread, info->si_uid);

    writePointer(thread, info->si_addr);

    writeInt(thread, info->si_status);

    writeLong(thread, info->si_band);

    writeSigval_data(thread, info->si_value);

    return;

}



/*

 * Command at first it reads pointer to siginfo_t variable, then reads data from 

 * stream and change this variable

 */

 



static TACommandVerdict set_siginfo_t_cmd(TAThread thread,TAInputStream stream)

{

    siginfo_t* info;

    // Prepare

    info = readPointer(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

        writeSiginfo_t_data(thread, info);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    

    return taDefaultVerdict; 

}



/*

 * Command at first it reads pointer to siginfo_t variable, then returns variable value 

 */

static TACommandVerdict get_siginfo_t_cmd(TAThread thread,TAInputStream stream)

{

    siginfo_t* info;

    // Prepare

    info = readPointer(&stream);

    

    START_TARGET_OPERATION(thread);

    

    // Execute

        get_siginfo_t_data(stream, info);

    

    END_TARGET_OPERATION(thread);

    

    // Response

    

    return taDefaultVerdict; 

}

/********************************************************************/

/**                      Agent Initialization                      **/

/********************************************************************/

void register_signal_sigwait_commands(void)

{

    ta_register_command("sigtimedwait",sigtimedwait_cmd);

    ta_register_command("sigwait",sigwait_cmd);

    ta_register_command("sigwaitinfo",sigwaitinfo_cmd);

    ta_register_command("set_siginfo_t", set_siginfo_t_cmd);

    ta_register_command("get_siginfo_t", get_siginfo_t_cmd);

}



