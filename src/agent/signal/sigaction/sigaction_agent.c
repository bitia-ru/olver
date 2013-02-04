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

#include "signal/sigaction/sigaction_agent.h"
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

/********************************************************************/
/**                         Data Types Readers And Writers         **/
/********************************************************************/

void readStackType(TAInputStream * stream, stack_t* val)
{
    
    verifyType_TAInputStream(stream, "stackt");
    
    val->ss_sp = readPointer(stream);
    val->ss_flags = readInt(stream);
    val->ss_size = readSize(stream);
}


void writeStackType(TAThread  thread, stack_t* val)
{
    writePointer(thread, val->ss_sp);
    writeInt(thread, val->ss_flags);
    writeSize(thread, val->ss_size);
}

void readSigset_tData(TAInputStream* stream,sigset_t* set)
{
    size_t i;
    size_t size;
    int temp;
    
    sigemptyset(set);
    size = readSize(stream);
    for( i = 0; i < size; i++ )
    {
        temp = readInt(stream);
        sigaddset(set, temp);
    }
    return;
}

int get_struct_sigaction(TAInputStream* stream, struct sigaction* sigaction_struct)
{
    int sa_h, sa_f, sa_sa;
    
    verifyType_TAInputStream(stream,"sigaction_data");
    
    sa_h = readInt(stream);
    sa_sa = readInt(stream);
    sa_f = readInt(stream);
    readSigset_tData(stream, &(sigaction_struct->sa_mask));
    
    sigaction_struct->sa_flags = convertSignalFlagsReprToInt(sa_f);
    if((sigaction_struct->sa_flags & SA_SIGINFO) == 0) //expected handler with prototype void f(int)
    {
        if(sa_h != SIG_UNDEFINED) //else do nothing whith sa_handler
        {
            sigaction_struct->sa_handler = get_catcher_handler(sa_h);
        }
    }else //expected handler with prototype void f(int, siginfo_t, void*)
    {
        if(sa_sa != SIGACT_UNDEFINED) //else do nothing whith sa_sigaction
        {
            sigaction_struct->sa_sigaction = get_catcher_sigaction(sa_sa);
        }
    }
    
    return 1;
}

void write_sigaction(TAThread thread, struct sigaction* sigaction_struct)
{    
    int sa_h, sa_f, sa_sa;
    
    sa_h = handler_number(sigaction_struct->sa_handler);
    sa_sa = sigaction_number(sigaction_struct->sa_sigaction);
    sa_f = signalConvertIntToFlagsRepr(sigaction_struct->sa_flags);
    
    writeInt(thread, sa_h);
    writeInt(thread, sa_sa);
    writeInt(thread, sa_f);
}


TAThread thread;
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __libc_current_sigrtmax_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = __libc_current_sigrtmax();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict __libc_current_sigrtmin_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = __libc_current_sigrtmin();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
    
}

static TACommandVerdict __sysv_signal_cmd(TAThread thread,TAInputStream stream)
{
    void (*res)(int);
    void (*arg)(int);
    int sig;
    int handlerVal;
    
    // Prepare
    sig = readInt(&stream);
    handlerVal = readInt(&stream);
    
    arg = get_catcher_handler(handlerVal);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = __sysv_signal(sig, arg);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, handler_number(res));
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict bsd_signal_cmd(TAThread thread,TAInputStream stream)
{
    void (*res)(int);
    void (*arg)(int);
    int sig;
    int handlerVal;
    
    // Prepare
    sig = readInt(&stream);
    handlerVal = readInt(&stream);
    
    arg = get_catcher_handler(handlerVal);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = bsd_signal(sig, arg);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, handler_number(res));
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict pause_cmd(TAThread thread,TAInputStream stream)
{
    int res;
   
    ta_debug_printf("PAUSE called\n");
   
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
//    ta_debug_printf("After PAUSE blocked operation\n");

    START_TARGET_OPERATION(thread);
    
    res =  pause();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDeferredReaction(thread, "pause_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

   ta_debug_printf("PAUSE ended\n");

    return taDefaultVerdict;
}

static TACommandVerdict pthread_sigmask_cmd(TAThread thread,TAInputStream stream)
{
    sigset_t* set, *oset;
    int how, res;
    // Prepare
    
    how = readInt(&stream);
    how = convertSUTMaskChangeFlagToRealization(how);
    set = (sigset_t*) readPointer(&stream);
    oset = (sigset_t*) readPointer(&stream);
        
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    res = pthread_sigmask(how, set, oset);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDeferredReaction(thread, "pthread_sigmask_react");
    writeInt(thread, res);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sigaction_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    struct sigaction act, oact;
    struct sigaction *param_act, *param_oact;
    int res, signo;
    int is_act_NULL, is_oact_NULL;
    errno = 0;
    signo = readInt(&stream);
    is_act_NULL = readInt(&stream);
    is_oact_NULL = readInt(&stream);
    
    if(is_act_NULL == 0)
    {
        param_act = &act;
        get_struct_sigaction(&stream, &act);
    }
    else
    {
        param_act = NULL;
    }
    if(is_oact_NULL == 0)
    {
        param_oact = &oact;
    }
    else
    {
        param_oact = NULL;
    }
    
    START_TARGET_OPERATION(thread);
    

   // Execute
    res = sigaction(signo, param_act, param_oact);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    ta_debug_printf("signal_action %p\n", act.sa_handler);
    if(param_oact != NULL)
    {
        write_sigaction(thread, &oact);
    }
    writeInt(thread, res);
    writeInt(thread, errno); 

   
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sigaltstack_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int isNotZero;
    stack_t* ss=NULL;
    stack_t oss;
    stack_t readss;

    // Prepare
    
    isNotZero =  readInt(&stream);
    if (isNotZero)
    {
        readStackType(&stream, &readss);
        ss = &readss;
    }


    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigaltstack(ss, &oss); 

    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeStackType(thread, &oss);
    writeSize(thread, MINSIGSTKSZ);
    writeInt(thread, errno);


    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict siginterrupt_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    int sig;
    int flag;
    
    // Prepare
    
    sig =  readInt(&stream);
    flag =  readInt(&stream);
    

    START_TARGET_OPERATION(thread);
    res = siginterrupt(sig, flag); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict signal_cmd(TAThread thread,TAInputStream stream)
{
    void (*res)(int);
    void (*arg)(int);
    int sig;
    int handlerVal;
    
    // Prepare
    sig = readInt(&stream);
    handlerVal = readInt(&stream);
    
    arg = get_catcher_handler(handlerVal);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = signal(sig, arg);

    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, handler_number(res));
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigpending_cmd(TAThread thread,TAInputStream stream)
{
    sigset_t* set;
    int res;
    
    // Prepare
    set = (sigset_t*) readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = sigpending(set);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sigprocmask_cmd(TAThread thread,TAInputStream stream)
{
    sigset_t* set, *oset;
    int how, res;
    // Prepare
    
    how = readInt(&stream);
    how = convertSUTMaskChangeFlagToRealization(how);
    set = (sigset_t*) readPointer(&stream);
    oset = (sigset_t*) readPointer(&stream);
    
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    res = sigprocmask(how, set, oset);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDeferredReaction(thread, "sigprocmask_react");
    writeInt(thread, res);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sigreturn_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    // TO DO: Call target function
    res = sigreturn(...);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    // TO DO: Write response
****/
    
    return taDefaultVerdict;
}

static TACommandVerdict sigsuspend_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    sigset_t *sigmask;
    
    
    sigmask = (sigset_t*)readPointer(&stream);

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    res =  sigsuspend(sigmask); 
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDeferredReaction(thread, "sigsuspend_return");
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                Sigaction struct helper functions               **/
/********************************************************************/

/*
 * Get pointer to catcher function, returns int - number of 
 * corresponding element in enum SignalHandler
 */
int handler_number(void(*h) (int))
{
    if(h == SIG_DFL) 
        {return SUT_SIG_DFL;}
    else if (h == SIG_IGN)
        {return SUT_SIG_IGN;}
    else if (h == SIG_ERR)
        {return SUT_SIG_ERR;}
    else if (h == SIG_HOLD)
        {return SUT_SIG_HOLD;}
    else if (h == user_catcher_handler)
        {return SIG_USER_CATCHER;}
    else if (h == user_agent_handler)
        {return SIG_USER_AGENT;}
    else 
        {return SIG_UNDEFINED;};
}

/*
 * Get int - number of corresponding element in enum SignalHandler,
 * returns pointer to catcher function
 */

p_handl get_catcher_handler(int number)
{
    switch(number)
    {
        case SUT_SIG_DFL: return SIG_DFL;
        case SUT_SIG_IGN: return SIG_IGN;
        case SUT_SIG_ERR: return SIG_ERR;
        case SUT_SIG_HOLD: return SIG_HOLD;
        case SIG_USER_CATCHER: return user_catcher_handler;
        case SIG_USER_AGENT: return user_agent_handler;
        default: return NULL;
    }
}

/*
 * Get pointer to catcher function, returns int - number of 
 * corresponding element in enum SignalSigactionHandler
 */
int sigaction_number(void(*sa) (int, siginfo_t *, void *))
{
  if (sa == user_catcher_sigaction)
        {return SIGACT_USER_CATCHER;}
    else if (sa == user_agent_sigaction)
        {return SIGACT_USER_AGENT;}
    else 
        {return SIGACT_UNDEFINED;};
}

/*
 * Get int - number of corresponding element in enum 
 * SignalSigactionHandler, returns pointer to catcher function
 */
p_sigact get_catcher_sigaction(int sa)
{
    switch(sa)
    {
     /*   case SUT_SIGACT_DFL: return SIG_DFL; //watch if sigaction has such macros
        case SUT_SIGACT_IGN: return SIG_IGN;
        case SUT_SIGACT_ERR: return SIG_ERR;
        case SUT_SIGACT_HOLD: return SIG_HOLD; */
        case SIGACT_USER_CATCHER: return user_catcher_sigaction;
        case SIGACT_USER_AGENT: return user_agent_sigaction;
        default: return NULL;
    }
}
/********************************************************************/
/**                    User Handlers in Agent                      **/
/********************************************************************/
/********************************************************************/
/**       Catcher void f(int signo) returns right away as start    **/
/********************************************************************/
void user_catcher_handler(int signo)
{
    TAThread thread = ta_current_thread();
    sigset_t set;
    sigset_t oset;

    sigfillset(&set);
    sigemptyset(&oset);
    pthread_sigmask(SIG_SETMASK, &set, &oset);

    ta_debug_printf("handler\n");
    writeDeferredReaction(thread, "user_catcher_handler_reaction_start");
    writeInt(thread, signo);
    END_TARGET_OPERATION(thread);
    sendResponse(thread);
    
    START_TARGET_OPERATION(thread);
    
    writeDeferredReaction(thread, "user_catcher_handler_reaction_finish");
    writeInt(thread, signo);
    sendResponse(thread);
    ta_debug_printf("handler end\n");

    // It is not clear how to make sure sigreturn() is called.
    // TODO: Currently 'sigreturn' is absent in dependencies of agent binary, some more investigation required.
    // ta_debug_printf( "search for sigreturn (%u)...\n", (unsigned long)pthread_self() );

    pthread_sigmask(SIG_SETMASK, &oset, &set);

    return;
}
/********************************************************************/
/**           Catcher void f(int signo) listen for commands        **/
/********************************************************************/
void user_agent_handler(int signo)
{
    TAThread thread = ta_current_thread();

    sigset_t set;
    sigset_t oset;
    
    sigfillset(&set);
    sigemptyset(&oset);
    pthread_sigmask(SIG_SETMASK, &set, &oset);

    ta_debug_printf("handler agent\n");
    writeDeferredReaction(thread, "user_agent_handler_reaction_start");
    writeInt(thread, signo);
    END_TARGET_OPERATION(thread);
    sendResponse(thread);

    START_TARGET_OPERATION(thread);

    writeDeferredReaction(thread, "user_agent_handler_reaction_finish");
    writeInt(thread, signo);
    sendResponse(thread);

    // It is not clear how to make sure sigreturn() is called.
    // TODO: Currently 'sigreturn' is absent in dependencies of agent binary, some more investigation required.
    // ta_debug_printf( "search for sigreturn (%u)...\n", (unsigned long)pthread_self() );

    pthread_sigmask(SIG_SETMASK, &oset, &set);

    return;
}

/********************************************************************/
/**      Catcher void f(int signo, siginfo_t *info, void *context) **/
/**                returns right away as start                     **/
/********************************************************************/
void user_catcher_sigaction(int signo, siginfo_t *info, void *context)
{
    TAThread thread = ta_current_thread();
    sigset_t set;
    sigset_t oset;
    
    sigfillset(&set);
    sigemptyset(&oset);
    pthread_sigmask(SIG_SETMASK, &set, &oset);

    ta_debug_printf("sigaction catcher\n");    
    writeDeferredReaction(thread, "user_catcher_sigaction_reaction_start");
    writeInt(thread, signo);
    END_TARGET_OPERATION(thread);
    sendResponse(thread);
 
    START_TARGET_OPERATION(thread);
 
    writeDeferredReaction(thread, "user_catcher_sigaction_reaction_finish");
    writeInt(thread, signo);
    sendResponse(thread);

    // It is not clear how to make sure sigreturn() is called.
    // TODO: Currently 'sigreturn' is absent in dependencies of agent binary, some more investigation required.
    // ta_debug_printf( "search for sigreturn (%u)...\n", (unsigned long)pthread_self() );

    pthread_sigmask(SIG_SETMASK, &oset, &set);

    return;
}
/********************************************************************/
/**      Catcher void f(int signo, siginfo_t *info, void *context) **/
/**                      listen for commands                       **/
/********************************************************************/
void user_agent_sigaction(int signo, siginfo_t *info, void *context)
{
    TAThread thread = ta_current_thread();
    sigset_t set;
    sigset_t oset;
    
    sigfillset(&set);
    sigemptyset(&oset);
    pthread_sigmask(SIG_SETMASK, &set, &oset);

    ta_debug_printf("sigaction catcher agent\n");
    writeDeferredReaction(thread, "user_agent_sigaction_reaction_start");
    writeInt(thread, signo);
    END_TARGET_OPERATION(thread);
    sendResponse(thread);
 
    START_TARGET_OPERATION(thread); 
 
    writeDeferredReaction(thread, "user_agent_sigaction_reaction_finish");
    writeInt(thread, signo);
    sendResponse(thread);

    // It is not clear how to make sure sigreturn() is called.
    // TODO: Currently 'sigreturn' is absent in dependencies of agent binary, some more investigation required.
    // ta_debug_printf( "search for sigreturn (%u)...\n", (unsigned long)pthread_self() );

    pthread_sigmask(SIG_SETMASK, &oset, &set);

    return;
}
/********************************************************************/
/**   Converters for int mask action on instrumental and target    **/
/********************************************************************/
int convertSUTMaskChangeFlagToRealization(int how_SUT)
{
    switch(how_SUT)
    {
        case SUT_SIG_BLOCK  :
            return SIG_BLOCK;
            break;
        case SUT_SIG_UNBLOCK:
            return SIG_UNBLOCK;
            break;
        case SUT_SIG_SETMASK:
            return SIG_SETMASK;
            break;
        default:
            while(1 == 1)
            {
                if(how_SUT == SIG_BLOCK)
                {
                    how_SUT++;
                }
                else if(how_SUT == SIG_UNBLOCK)
                {
                    how_SUT++;
                }
                else if(how_SUT == SIG_SETMASK)
                {
                    how_SUT++;
                }
            };
            return how_SUT;
            break;
    }
    return 0;
}

int convertRealizationMaskChangeFlagToSUT(int how)
{
    switch(how)
    {
        case SIG_BLOCK  :
            return SUT_SIG_BLOCK;
            break;
        case SIG_UNBLOCK:
            return SUT_SIG_UNBLOCK;
            break;
        case SIG_SETMASK:
            return SUT_SIG_SETMASK;
            break;
        default: 
            while(1 == 1)
            {
                if(how == SUT_SIG_BLOCK)
                {
                    how++;
                }
                else if(how == SUT_SIG_UNBLOCK)
                {
                    how++;
                }
                else if(how == SUT_SIG_SETMASK)
                {
                    how++;
                }
            };
            return how;
            break;
    }
    return 0;
}

/********************************************************************/
/**                 Converters for int and signal flags            **/
/********************************************************************/

/*
 * Function converts our representation of flags sa_flags to 
 * realization representation of sa_flags
 */
int convertSignalFlagsReprToInt(int value)
{
    int res = 0;
    if(SUT_SA_NOCLDSTOP & value)
    {
        res = res | SA_NOCLDSTOP;
    }
    
    if(SUT_SA_ONSTACK & value)
    {
        res = res | SA_ONSTACK;
    }
    if(SUT_SA_RESETHAND & value)
    {
        res = res | SA_RESETHAND;
    }
    if(SUT_SA_RESTART & value)
    {
        res = res | SA_RESTART;
    }
    if(SUT_SA_INTERRUPT & value)
    {
     //   res = res | SA_INTERRUPT;
    }
    if(SUT_SA_SIGINFO & value)
    {
        res = res | SA_SIGINFO;
    }
    if(SUT_SA_NOCLDWAIT & value)
    {
        res = res | SA_NOCLDWAIT;
    }
    if(SUT_SA_NODEFER & value)
    {
        res = res | SA_NODEFER;
    }
    
    return res;
}

/*
 * Function converts realization representation of sa_flags to 
 * our representation of sa_flags
 */
int signalConvertIntToFlagsRepr(int value)
{
    int res = 0;
    if(SA_NOCLDSTOP & value)
    {
        res = res | SUT_SA_NOCLDSTOP;
    }

    if(SA_ONSTACK & value)
    {
        res = res | SUT_SA_ONSTACK;
    }
    if(SA_RESETHAND & value)
    {
        res = res | SUT_SA_RESETHAND;
    }
    if(SA_RESTART & value)
    {
        res = res | SUT_SA_RESTART;
    }
 /*   if(SA_INTERRUPT & value)
    {
        res = res | SUT_SA_INTERRUPT;
    }*/
    if(SA_SIGINFO & value)
    {
        res = res | SUT_SA_SIGINFO;
    }
    if(SA_NOCLDWAIT & value)
    {
        res = res | SUT_SA_NOCLDWAIT;
    }
    if(SA_NODEFER & value)
    {
        res = res | SUT_SA_NODEFER;
    }
    
    return res;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_signal_sigaction_commands(void)
{
    ta_register_command("__libc_current_sigrtmax",__libc_current_sigrtmax_cmd);
    ta_register_command("__libc_current_sigrtmin",__libc_current_sigrtmin_cmd);
    ta_register_command("__sysv_signal",__sysv_signal_cmd);
    ta_register_command("bsd_signal",bsd_signal_cmd);
    ta_register_command("pause",pause_cmd);
    ta_register_command("pthread_sigmask",pthread_sigmask_cmd);
    ta_register_command("sigaction",sigaction_cmd);
    ta_register_command("sigaltstack",sigaltstack_cmd);
    ta_register_command("siginterrupt",siginterrupt_cmd);
    ta_register_command("signal",signal_cmd);
    ta_register_command("sigpending",sigpending_cmd);
    ta_register_command("sigprocmask",sigprocmask_cmd);
//    ta_register_command("sigreturn",sigreturn_cmd);
    ta_register_command("sigsuspend",sigsuspend_cmd);
}

