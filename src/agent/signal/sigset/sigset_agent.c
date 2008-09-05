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


#include "signal/sigset/sigset_agent.h"

#include <stdio.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict sigaddset_cmd(TAThread thread,TAInputStream stream)
{ 
    // Prepare           
    sigset_t* set;
    int signo, res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);
    signo = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigaddset(set, signo);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigandset_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    sigset_t* set,* left,* right;
    int res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);
    left = (sigset_t*) readPointer(&stream);
    right = (sigset_t*) readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigandset(set, left, right);
    
    // Response
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigdelset_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    sigset_t* set;
    int signo, res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);
    signo = readInt(&stream);
        
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigdelset(set, signo);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigemptyset_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    sigset_t* set;
    int res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigemptyset(set);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sigfillset_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare 
    sigset_t* set;
    int res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigfillset(set);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
    
    return taDefaultVerdict;
}

static TACommandVerdict sigisemptyset_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    sigset_t* set;
    int res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);
        
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigisemptyset(set);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigismember_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    sigset_t* set;
    int res, signo;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);
    signo = readInt(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigismember(set, signo);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigorset_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    sigset_t* set,* left,* right;
    int res;
    errno = 0;

    set = (sigset_t*) readPointer(&stream);
    left = (sigset_t*) readPointer(&stream);
    right = (sigset_t*) readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigorset(set, left, right);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/*
static TACommandVerdict get_SIGRT_const_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare 
    int min, max;

    START_TARGET_OPERATION(thread);
    
    // Execute
    min = __libc_current_sigrtmin();
    max = __libc_current_sigrtmax();

    END_TARGET_OPERATION(thread);

    writeInt(thread, min);
    writeInt(thread, max);
    sendResponse(thread);
}*/

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_signal_sigset_commands(void)
{
    ta_register_command("sigaddset",sigaddset_cmd);
    ta_register_command("sigandset",sigandset_cmd);
    ta_register_command("sigdelset",sigdelset_cmd);
    ta_register_command("sigemptyset",sigemptyset_cmd);
    ta_register_command("sigfillset",sigfillset_cmd);
    ta_register_command("sigisemptyset",sigisemptyset_cmd);
    ta_register_command("sigismember",sigismember_cmd);
    ta_register_command("sigorset",sigorset_cmd);
//    ta_register_command("get_SIGRT_const", get_SIGRT_const_cmd);
}

