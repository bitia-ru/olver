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


#include "signal/sigsend/sigsend_agent.h"

#include <stdio.h>
#include <errno.h> 
#include <signal.h>
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict kill_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int signo, res;
    pid_t pid;
    errno = 0;
    
    pid   = readInt(&stream);
    signo = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    ta_debug_printf("Kill pid %d signo %d \n", pid, signo);
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = kill(pid, signo);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    //ta_debug_printf("sig %d\n", signo);
    writeDeferredReaction(thread, "kill_react");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict killpg_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int signo, res;
    pid_t pid;
    errno = 0;

    pid   = readInt(&stream);
    signo = readInt(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    // Execute
    res = killpg(pid, signo);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction(thread, "kill_react");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_kill_cmd(TAThread thread,TAInputStream stream)

{
    // Prepare
    int signo, res;
    pthread_t thr;
    errno = 0;
    
    thr   = readULong(&stream);
    signo    = readInt(&stream);
    
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res =  pthread_kill(thr, signo); 
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDeferredReaction(thread, "pthread_kill_react");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



static TACommandVerdict raise_cmd(TAThread thread,TAInputStream stream)

{
    int signo, res;
    pthread_t thr;
    int threadSupp;
    errno = 0;
    
    threadSupp = readInt(&stream);
    signo    = readInt(&stream);
    
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res =  raise(signo); 
    
    END_TARGET_OPERATION(thread);
    
    // Response
    if (threadSupp)
    {
        writeDeferredReaction(thread, "pthread_kill_react");
    }
    else
    {
        writeDeferredReaction(thread, "kill_react");
    }
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



static TACommandVerdict sigqueue_cmd(TAThread thread,TAInputStream stream)

{
    // Prepare
    int signo, res;
    pid_t pid;
    errno = 0;
    union sigval value;
    int isInt;
    int    sival_int;
    void  *sival_ptr;    

    pid   = readInt(&stream);
    signo = readInt(&stream);
    isInt = readInt(&stream);
    sival_int = readInt(&stream);
    sival_ptr = readPointer(&stream);

    if (isInt)
    {
        value.sival_int=sival_int;
    }
    else
    {
        value.sival_ptr=sival_ptr;
    }

    
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigqueue(pid, signo, value); 
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDeferredReaction(thread, "sigqueue_react");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Done function for signals                 **/
/********************************************************************/

static TACommandVerdict signals_done_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare nothing to prepare
    
    START_TARGET_OPERATION(thread);
    
    // so time marks are wrote and nothing else to do
    
    END_TARGET_OPERATION(thread);
    
    // Response nothing to response
    sendResponse(thread);
    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_signal_sigsend_commands(void)
{
    ta_register_command("kill", kill_cmd);
    ta_register_command("signals_done", signals_done_cmd);
    ta_register_command("killpg",killpg_cmd);
    ta_register_command("pthread_kill",pthread_kill_cmd);
    ta_register_command("raise",raise_cmd);
    ta_register_command("sigqueue",sigqueue_cmd);
}

