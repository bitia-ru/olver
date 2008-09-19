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


#include "common/agent.h"
#include "common/ta_assertion.h"
/*
* Define for FE_DFL_ENV macro, all bits zero.
*/
const double __fe_dfl_env = { 0 };
#include <fenv.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>
#include <locale.h>

/********************************************************************/
/**                         System Commands                        **/
/********************************************************************/
TACommandVerdict create_process_cmd(TAThread thread,TAInputStream stream)
{
int code;

  // Init test system descriptor
  code = fork();
  if (code == 0)
   {
    if (is_ta_verbose())
    {
      if(is_ta_debug())
      {
        code = execl("agent", "agent", "-debug", NULL);
      } else {
        code = execl("agent", "agent", "", NULL);
      }
    }
    else
      if(is_ta_debug())
      {
          code = execl("agent","agent","-debug", "-silent",NULL);
      } else {
          code = execl("agent","agent", "-silent",NULL);
      }

    perror("create_process");
    assertion( 0, "create_process failed" );
   }

  // Response
  if (code != -1)
   {
    writeString(thread,"Ok");
   }
  else
    writeString(thread,"Failed");
  sendResponse(thread);

  return taDefaultVerdict;
}

TACommandVerdict fork_process_cmd(TAThread thread,TAInputStream stream)
{
int code;

  // Init test system descriptor
  code = fork();
  if (code == 0)
   {
    ta_thread_reinit(thread);
   }

  // Response
  if (code != -1)
   {
    writeString(thread,"Ok");
   }
  else
    writeString(thread,"Failed");
  sendResponse(thread);

  return taDefaultVerdict;
}

void* ta_thread_main_routine(void* par);

TACommandVerdict create_thread_cmd(TAThread thread,TAInputStream stream)
{
pthread_t pthread;
//TAThreadParam threadParam;
int code;

  // Init test system descriptor
//  threadParam.addr = tsControlCenter;
//  threadParam.par = NULL;
  code = pthread_create(&pthread,NULL,ta_thread_main_routine,NULL);

  ta_debug_printf( "pthread_create returns %d\n", code );

  // Response
  if (code == 0)
   {
    writeString(thread,"Ok");
    //writeByteArray(thread,(char*)&pthread,sizeof(pthread));
   }
  else
    writeString(thread,"Failed");
  sendResponse(thread);

  return taDefaultVerdict;
}

TACommandVerdict terminate_process_cmd(TAThread thread,TAInputStream stream)
{
int code;

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  // Execute
  exit(1);

  sendException(thread,"exit() returned control");

  return taDefaultVerdict;
}

TACommandVerdict finish_cmd(TAThread thread,TAInputStream stream)
{
  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  // Execute
  pthread_detach(pthread_self());
  pthread_exit(NULL);

  sendException(thread,"pthread_exit() returned control");

  return taDefaultVerdict;
}

TACommandVerdict reboot_cmd(TAThread thread,TAInputStream stream)
{
  ta_debug_printf("Reboot...\n");

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);
  sleep(1);

  // Execute
  system("/sbin/shutdown -r");
  //exit(0);

  return taDefaultVerdict;
}

TACommandVerdict test_model_init_cmd(TAThread thread,TAInputStream stream)
{
pid_t parent;
pid_t pgroup;
pid_t session;
char  cterm[L_ctermid];
uid_t real_userid;
gid_t real_groupid;
uid_t effective_userid;
gid_t effective_groupid;

  // Prepare

  // Execute
  parent = getppid();
  pgroup = getpgrp();
  session = getsid((pid_t)0);
  ctermid(cterm);
  real_userid = getuid();
  real_groupid = getgid();
  effective_userid = geteuid();
  effective_groupid = getegid();

  // Response
  // 1. System Configuration
  // Byte Order

  // 2. Process meta info
  // Parent
  writeInt(thread,parent);
  // Process Group
  writeInt(thread,pgroup);
  // Session
  writeInt(thread,session);
  // Controlling Terminal
  writeString(thread,cterm);
  // User Attributes
  writeUInt(thread,real_userid);
  writeUInt(thread,real_groupid);
  writeUInt(thread,effective_userid);
  writeUInt(thread,effective_groupid);
  // Floating-Point Environment
  writePointer(thread, (void*)FE_DFL_ENV);

  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict agent_log_cmd(TAThread thread,TAInputStream stream)
{
char* message;

  // Prepare
  message = readString(&stream);

  // Log
  ta_debug_printf( "%s", message );

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}


/********************************************************************/
/**                     Configuration Commands                     **/
/********************************************************************/
#define SIZEOF_TYPE(t) if (strcmp(type,#t) == 0) size = sizeof(t); else

#include <fenv.h>
#include <glob.h>

// TODO: glob64_t is defined in the glob_agent.h
#include "fs/glob/glob_agent.h"

#include <semaphore.h>
#include <signal.h>
#include <termios.h>
#include <wordexp.h>
#include <rpc/rpc.h>
#include <net/if.h>

static TACommandVerdict sizeof_type_cmd(TAThread thread,TAInputStream stream)
{
char* type;
size_t size;

  // Prepare
  type = readString(&stream);

  // Embed types
  SIZEOF_TYPE(char)
  SIZEOF_TYPE(short)
  SIZEOF_TYPE(int)
  SIZEOF_TYPE(long)
  SIZEOF_TYPE(void*)
  SIZEOF_TYPE(size_t)
  SIZEOF_TYPE(ssize_t)
  // fenv.h types
  SIZEOF_TYPE(fenv_t)
  SIZEOF_TYPE(fexcept_t)
  // glob.h types
  SIZEOF_TYPE(glob_t)
  SIZEOF_TYPE(glob64_t)
  // pthread.h types
  SIZEOF_TYPE(pthread_t)
  SIZEOF_TYPE(pthread_attr_t)
  SIZEOF_TYPE(pthread_key_t)
  SIZEOF_TYPE(pthread_once_t)
  SIZEOF_TYPE(pthread_mutex_t)
  SIZEOF_TYPE(pthread_mutexattr_t)
  SIZEOF_TYPE(pthread_cond_t)
  SIZEOF_TYPE(pthread_condattr_t)
  SIZEOF_TYPE(pthread_rwlock_t)
  SIZEOF_TYPE(pthread_rwlockattr_t)
  // semaphore.h types
  SIZEOF_TYPE(sem_t)
  // signal.h types
  SIZEOF_TYPE(sigset_t)
  SIZEOF_TYPE(siginfo_t)
  // termios.h types
  SIZEOF_TYPE(struct termios)
  // wordexp.h types
  SIZEOF_TYPE(wordexp_t)
  // locale.h types
  SIZEOF_TYPE(locale_t)
  // rpc/xdr.h types
  SIZEOF_TYPE(XDR)
  SIZEOF_TYPE(struct xdr_discrim)
  // rpc/rpc_msg.h types
  SIZEOF_TYPE(struct accepted_reply)
  SIZEOF_TYPE(struct rejected_reply)
  SIZEOF_TYPE(struct rpc_msg)
  // rpc/auth.h types
  SIZEOF_TYPE(struct opaque_auth)
  // rpc/clnt.h types
  SIZEOF_TYPE(struct rpc_err)
  // net/if.h
  SIZEOF_TYPE(struct if_nameindex)
  // math.h types
  SIZEOF_TYPE(float)
  SIZEOF_TYPE(double)
  SIZEOF_TYPE(long double)

  // Unsupported type
   {
    char errMsg[512];
    sprintf( errMsg, "sizeof_type_cmd: Unsupported type '%s'", type );
    sendException(thread,errMsg);
    return taDefaultVerdict;
   }

  // Response
  writeSize(thread,size);
  sendResponse(thread);

  return taDefaultVerdict;
}


/********************************************************************/
/**                       Allocation Commands                      **/
/********************************************************************/
static TACommandVerdict allocate_cmd(TAThread thread,TAInputStream stream)
{
size_t size;
void* res;

  // Prepare
  size = readSize(&stream);

  // Execute
  res = ta_alloc_memory(size);

  // Response
  writePointer(thread,res);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict deallocate_cmd(TAThread thread,TAInputStream stream)
{
void* ptr;

  // Prepare
  ptr = readPointer(&stream);

  // Execute
  ta_dealloc_memory(ptr);

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}


/********************************************************************/
/**                         Memory Readers                         **/
/********************************************************************/
static TACommandVerdict read_char_cmd(TAThread thread,TAInputStream stream)
{
char* ptr;

  // Prepare
  ptr = (char*)readPointer(&stream);

  // Execute

  // Response
  writeChar(thread,*ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_wchar_cmd(TAThread thread,TAInputStream stream)
{
wchar_t* ptr;

  // Prepare
  ptr = (wchar_t*)readPointer(&stream);

  // Execute

  // Response
  writeWChar(thread,*ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_byte_array_cmd(TAThread thread,TAInputStream stream)
{
size_t size;
void* ptr;


  // Prepare
  ptr  = readPointer(&stream);
  size = readSize(&stream);

  // Execute

  // Response
  writeByteArray(thread,ptr,size);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_wchar_array_cmd(TAThread thread,TAInputStream stream)
{
wchar_t* ptr;
size_t size;

  // Prepare
  ptr  = (wchar_t*)readPointer(&stream);
  size = readSize(&stream);

  // Execute

  // Response
  writeWCharArray(thread,ptr,size);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_string_cmd(TAThread thread,TAInputStream stream)
{
char* ptr;

  // Prepare
  ptr = (char*)readPointer(&stream);

  // Execute

  // Response
  writeString(thread,ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_limited_string_cmd(TAThread thread,TAInputStream stream)
{
char* ptr;
size_t size;

  // Prepare
  ptr = (char*)readPointer(&stream);
  size = readSize(&stream);

  // Execute

  // Response
  writeLimitedString(thread,ptr,size);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_wstring_cmd(TAThread thread,TAInputStream stream)
{
wchar_t* ptr;

  // Prepare
  ptr = (wchar_t*)readPointer(&stream);

  // Execute

  // Response
  writeWString(thread,ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_limited_wstring_cmd(TAThread thread,TAInputStream stream)
{
wchar_t* ptr;
size_t size;

  // Prepare
  ptr = (wchar_t*)readPointer(&stream);
  size = readSize(&stream);

  // Execute

  // Response
  writeLimitedWString(thread,ptr,size);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_short_cmd(TAThread thread,TAInputStream stream)
{
  short* ptr;

  // Prepare
  ptr = (short*)readPointer(&stream);

  // Execute

  // Response
  writeShort(thread,*ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_int_cmd(TAThread thread,TAInputStream stream)
{
  int* ptr;

  // Prepare
  ptr = (int*)readPointer(&stream);

  // Execute

  // Response
  writeInt(thread,*ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict read_pointer_cmd(TAThread thread,TAInputStream stream)
{
  void** ptr;

  // Prepare
  ptr = (void**)readPointer(&stream);

  // Execute

  // Response
  writePointer(thread,*ptr);
  sendResponse(thread);

  return taDefaultVerdict;
}

/********************************************************************/
/**                         Memory Writers                         **/
/********************************************************************/
static TACommandVerdict write_char_cmd(TAThread thread,TAInputStream stream)
{
char* ptr;
char value;

  // Prepare
  ptr = (char*)readPointer(&stream);
  value = readChar(&stream);

  // Execute
  *ptr = value;

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict write_int_cmd(TAThread thread,TAInputStream stream)
{
int* ptr;
int value;

  // Prepare
  ptr = (int*)readPointer(&stream);
  value = readInt(&stream);

  // Execute
  *ptr = value;

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict write_long_cmd(TAThread thread,TAInputStream stream)
{
long* ptr;
long value;

  // Prepare
  ptr = (long*)readPointer(&stream);
  value = readLong(&stream);

  // Execute
  *ptr = value;

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict write_byte_array_cmd(TAThread thread,TAInputStream stream)
{
char* ptr;
char* data;
size_t size;

  // Prepare
  ptr = (char*)readPointer(&stream);
  readByteArray(&stream,&data,&size);

  // Execute
  memcpy(ptr,data,size);

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict write_wchar_array_cmd(TAThread thread,TAInputStream stream)
{
wchar_t* ptr;
size_t size;

  // Prepare
  ptr = (wchar_t*)readPointer(&stream);
  readWCharArray(&stream,ptr,&size);

  // Execute

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}

static TACommandVerdict write_pointer_cmd(TAThread thread,TAInputStream stream)
{
  void** ptr;
  void* value;

  // Prepare
  ptr = (void**)readPointer(&stream);
  value = readPointer(&stream);

  // Execute
  *ptr = value;

  // Response
  writeString(thread,"Ok");
  sendResponse(thread);

  return taDefaultVerdict;
}


/********************************************************************/
/**                  Test Agent Commands Registration              **/
/********************************************************************/
void register_system_commands(void)
{
  // System
  ta_register_command("create_process",create_process_cmd);
  ta_register_command("fork_process",fork_process_cmd);
  ta_register_command("create_thread",create_thread_cmd);
  ta_register_command("terminate_process",terminate_process_cmd);
  ta_register_command("finish",finish_cmd);
  ta_register_command("reboot",reboot_cmd);
  ta_register_command("test_model_init",test_model_init_cmd);
  ta_register_command("agent_log",agent_log_cmd);
  // Configuration
  ta_register_command("sizeof_type",sizeof_type_cmd);
  // Allocation
  ta_register_command("allocate",allocate_cmd);
  ta_register_command("deallocate",deallocate_cmd);
  // Memory readers
  ta_register_command("read_char",read_char_cmd);
  ta_register_command("read_wchar",read_wchar_cmd);
  ta_register_command("read_byte_array",read_byte_array_cmd);
  ta_register_command("read_wchar_array",read_wchar_array_cmd);
  ta_register_command("read_string",read_string_cmd);
  ta_register_command("read_limited_string",read_limited_string_cmd);
  ta_register_command("read_wstring",read_wstring_cmd);
  ta_register_command("read_limited_wstring",read_limited_wstring_cmd);
  ta_register_command("read_short",read_short_cmd);
  ta_register_command("read_int",read_int_cmd);
  ta_register_command("read_pointer",read_pointer_cmd);
  // Memory writers
  ta_register_command("write_char",write_char_cmd);
  ta_register_command("write_byte_array",write_byte_array_cmd);
  ta_register_command("write_wchar_array",write_wchar_array_cmd);
  ta_register_command("write_int",write_int_cmd);
  ta_register_command("write_long",write_long_cmd);
  ta_register_command("write_pointer",write_pointer_cmd);
}
