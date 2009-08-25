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


#ifndef TA_COMMON_AGENT_SEH
#define TA_COMMON_AGENT_SEH

#include <config/config.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>
#include <setjmp.h>
#include <time.h>
#include "common/ta_stream.h"
#include "common/ta_assertion.h"
#include "common/verbose.h"


/********************************************************************/
/**                     Test Agent Debug&Verbose                   **/
/********************************************************************/
extern const char* ta_agent_log;
extern const char* ta_program_name;

int     is_ta_debug(void);
void    ta_debug_on(void);
void    ta_debug_off(void);

int     is_ta_verbose(void);
void    ta_verbose_on(void);
void    ta_verbose_off(void);

int ta_debug_printf(char* format, ...);


/********************************************************************/
/**                       Exception Handling                       **/
/********************************************************************/
int ta_exception_handling_enable( int enable );


/********************************************************************/
/**                       Test Agent Recovery                      **/
/********************************************************************/
void test_agent_recovery(void);
void test_agent_recovery_thread(TAThread thread);


/********************************************************************/
/**                     Test Agent Memory Pool                     **/
/********************************************************************/
void ta_init_mempool(void);
void* ta_alloc_memory(size_t size);
void* ta_realloc_memory(void* ptr, size_t newsize);
void ta_dealloc_memory(void* ptr);
int ta_is_standard_memode(void);
size_t ta_pointer_getsize(void* ptr);


/********************************************************************/
/**                   Test Agent TCP Communicator                  **/
/********************************************************************/
typedef struct TestAgentTCPCommunicator
{
  int sockid;
} TestAgentTCPCommunicator;

void ta_setup_tcp_communicator(int argc,const char** argv);


/********************************************************************/
/**                 Test Agent Message Communicator                **/
/********************************************************************/
typedef struct TestAgentMessageCommunicator
{
  int    sockid;
  struct sockaddr_in peer_addr;
  int    cmdsockid;
} TestAgentMessageCommunicator;

void ta_setup_message_communicator(int well_known_port);


/********************************************************************/
/**                      Test Agent Communicator                   **/
/********************************************************************/
typedef struct TestAgentCommunicator TestAgentCommunicator;

typedef int  (*TestAgentCommunicatorInit)(TAThread thread);
typedef int  (*TestAgentCommandReceiver)(TAThread thread,char** buffer_ptr,int buffer_size);
typedef void (*TestAgentMessageSender)(TAThread thread,const char* buffer,int length);
typedef void (*TestAgentCommunicatorDestructor)(TAThread thread);

struct TestAgentCommunicator
{
  union {
    TestAgentTCPCommunicator     tcp;
    TestAgentMessageCommunicator message;
  } data;
  /*---*/
  TestAgentCommandReceiver         receive_command;
  TestAgentMessageSender           send_message;
  TestAgentCommunicatorDestructor  destructor;
};

void ta_setup_communicator(TestAgentCommunicatorInit init_communicator);


/********************************************************************/
/**                       Test Agent Timemarks                     **/
/********************************************************************/
#define TIMEMARKS_ENABLED

void start_target_operation(TAThread thread);
void end_target_operation(TAThread thread);

#if defined (TIMEMARKS_ENABLED)
  #define START_TARGET_OPERATION(thread)   start_target_operation(thread)
  #define END_TARGET_OPERATION(thread)     end_target_operation(thread)

  #define BEFORE_BLOCKED_TARGET_OPERATION(thread)   start_target_operation(thread)
#else
  #define START_TARGET_OPERATION(thread)
  #define END_TARGET_OPERATION(thread)

  #define BEFORE_BLOCKED_TARGET_OPERATION(thread)
#endif

/*
ta_debug_printf("STARTED...");
ta_debug_printf("TARGET OPERATION STARTED...")
ta_debug_printf("TARGET OPERATION DONE...");
ta_debug_printf("PUSHED...");
ta_debug_printf("ENDED in POP...");
*/

#define START_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread) ENABLE_CANCELPOINT_DETECTION(thread); \
                                                                     START_TARGET_OPERATION(thread)




#define END_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread)   END_TARGET_OPERATION(thread); \
                                                                     DISABLE_CANCELPOINT_DETECTION(thread)


#define START_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, opparam)   pthread_cleanup_push(dr_cancelpoint_detector, &opparam); \
                                                                                        START_TARGET_OPERATION(thread)


#define END_BLOCKED_TARGET_OPERATION_WHICH_MAY_CONTAIN_CANCELPOINT(thread, reaction_name) END_TARGET_OPERATION(thread); \
                                                                                          pthread_cleanup_pop(0); \
                                                                                          printf("ENDED in DR POP..."); \
                                                                                          writeDeferredReaction(thread, reaction_name); \
                                                                                          writeInt(thread,0)


/********************************************************************/
/**                      Test Agent Response                       **/
/********************************************************************/
void sendResponse(TAThread thread);
void sendException(TAThread thread,const char* buff);


/********************************************************************/
/**                  Test Agent Auto Registration                  **/
/********************************************************************/
int ta_auto_registration_enable(int enable);


/********************************************************************/
/**                        Test Agent Thread                       **/
/********************************************************************/
struct TAThread
{
  TAOuputStream* stream;
  sigjmp_buf start_point;
  struct timespec start_time;
  struct timespec end_time;
  int level;
  /*---*/
  TestAgentCommunicator communicator;
};

extern pthread_key_t ta_thread_key;
TAThread ta_current_thread(void);
void ta_thread_reinit(TAThread thread);


/********************************************************************/
/**                     Test Agent Main Functions                  **/
/********************************************************************/
typedef union TAThreadArg
{
  void* pthread_arg;
  struct TAProcessArg
  {
    int          argc;
    const char** argv;
  } process_arg;
} TAThreadArg;

typedef struct TAThreadParam
{
  enum { TANewProcess, TANewThread, TARequest } kind;
  TAThreadArg arg;
} TAThreadParam;

void ta_process_main_init(void);
int   ta_process_main_routine(int argc,const char** argv);
void* ta_thread_main_routine(void* arg);
void* ta_main_routine(TAThreadParam* par);


/********************************************************************/
/**                   Test Agent Command Processors                **/
/********************************************************************/
typedef struct TACommandVerdict
{
  int  finish;
  void *status;
} TACommandVerdict;

extern TACommandVerdict taDefaultVerdict;

typedef TACommandVerdict (*CommandProcessorRoutine)(TAThread thread,TAInputStream stream);

void ta_register_command(const char* command,CommandProcessorRoutine routine);
CommandProcessorRoutine ta_get_command_processor(const char* command);


/********************************************************************/
/**             Test Agent Cancellation Point Detection            **/
/********************************************************************/
struct CancelPointDetectorParam {
    TAThread thread;
    char* defferedReactionName;
};

void cancelpoint_detector(void* thread);
void dr_cancelpoint_detector(void* thread);

void clear_timemark(struct timespec* timemark);

#define ENABLE_CANCELPOINT_DETECTION(thread)    pthread_cleanup_push(cancelpoint_detector,thread)



#define DISABLE_CANCELPOINT_DETECTION(thread)   pthread_cleanup_pop(0); \
                                                writeInt(thread,0);


#endif

/********************************************************************/
/**                        Test Agent Sandbox                      **/
/********************************************************************/
const char* ta_get_test_file_path(const char* path);
