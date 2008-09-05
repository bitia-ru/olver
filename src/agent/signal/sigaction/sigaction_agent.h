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

#ifndef TA_SIGNAL_SIGACTION_AGENT_H
#define TA_SIGNAL_SIGACTION_AGENT_H

#include "common/agent.h"

#include <signal.h>

/********************************************************************/
/*                   Signal Action Flags on Main Machine            */
/********************************************************************/

#define SUT_SA_NOCLDSTOP  1
#define SUT_SA_ONSTACK    2
#define SUT_SA_RESETHAND  4
#define SUT_SA_RESTART    8
#define SUT_SA_INTERRUPT  16
#define SUT_SA_SIGINFO    32
#define SUT_SA_NOCLDWAIT  64
#define SUT_SA_NODEFER    128
    
#define SUT_SIG_BLOCK     0
#define SUT_SIG_UNBLOCK   1
#define SUT_SIG_SETMASK   2

typedef enum SignalHandler

{
    SUT_SIG_DFL,
    SUT_SIG_ERR,
    SUT_SIG_HOLD,
    SUT_SIG_IGN,
    SIG_USER_CATCHER,
    SIG_USER_AGENT,
    SIG_UNDEFINED
} SignalHandler;

/*
 * Get pointer to catcher function, returns int - number of 
 * corresponding element in enum SignalHandler
 */
int handler_number(void(h)(int));

typedef enum SignalSigactionHandler
{
    SUT_SIGACT_DFL,
    SUT_SIGACT_ERR,
    SUT_SIGACT_HOLD,
    SUT_SIGACT_IGN,
    SIGACT_USER_CATCHER,
    SIGACT_USER_AGENT,
    SIGACT_UNDEFINED
} SignalSigactionHandler;
  
/*
 * Get pointer to catcher function, returns int - number of 
 * corresponding element in enum SignalSigactionHandler
 */
int sigaction_number(void(sa)(int, siginfo_t *, void *)); 

typedef void (*p_handl)(int);
p_handl get_catcher_handler(int number);

typedef void (*p_sigact) (int, siginfo_t*, void*);
p_sigact get_catcher_sigaction(int);

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_signal_sigaction_commands(void);

/********************************************************************/
/**                Sigaction struct helper functions               **/
/********************************************************************/
int get_struct_sigaction(TAInputStream* stream, struct sigaction* sigaction_struct);
void write_sigaction(TAThread thread, struct sigaction* sigaction_struct);
/********************************************************************/
/**                    User Handlers in Agent                      **/
/********************************************************************/
void user_catcher_handler(int signo);
void user_agent_handler(int signo);

void user_catcher_sigaction(int signo, siginfo_t *info, void *context);
void user_agent_sigaction(int signo, siginfo_t *info, void *context);

/********************************************************************/
/**   Converters for int mask action on instrumental and target    **/
/********************************************************************/
int convertSUTMaskChangeFlagToRealization(int how_SUT);
int convertRealizationMaskChangeFlagToSUT(int how);
/********************************************************************/
/**                 Converters for int and signal flags            **/
/********************************************************************/

/*
 * Function converts our representation of flags sa_flags to 
 * realization representation of sa_flags
 */
int convertSignalFlagsReprToInt(int flags);
/*
 * Function converts realization representation of sa_flags to 
 * our representation of sa_flags

*/
int signalConvertIntToFlagsRepr(int value);

#endif

