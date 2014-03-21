/*
 * Copyright (c) 2005-2014 Institute for System Programming
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
#include "pthread/mutex/mutexattr_agent.h"
#include "pthread/pthread/pthread_agent.h"
#include "common/agent.h"


/********************************************************************/
/**                        Format Functions                        **/
/********************************************************************/
void writeMutexType(TAThread thread,int type)
{
  writeType_TAStream(thread,"mutype");
  switch (type)
   {
    case PTHREAD_MUTEX_NORMAL :
      writeString( thread, "PTHREAD_MUTEX_NORMAL" );
      return;
    case PTHREAD_MUTEX_ERRORCHECK :
      writeString( thread, "PTHREAD_MUTEX_ERRORCHECK" );
      return;
    case PTHREAD_MUTEX_RECURSIVE :
      writeString( thread, "PTHREAD_MUTEX_RECURSIVE" );
      return;
    default :
      if (type == PTHREAD_MUTEX_DEFAULT)
       {
        writeString( thread, "PTHREAD_MUTEX_DEFAULT" );
        return;
       }
   }
  writeInt( thread, type );
}

#define PTHREAD_MUTEX_INVALID_VALUE -11

int readMutexType(TAInputStream* stream)
{
int res;

  verifyType_TAInputStream(stream,"mutype");
  if (startsWith_TAInputStream(stream,"str"))
   {
    char* value = readString(stream);
    if (strcmp(value,"PTHREAD_MUTEX_NORMAL") == 0)
      return PTHREAD_MUTEX_NORMAL;
    if (strcmp(value,"PTHREAD_MUTEX_ERRORCHECK") == 0)
      return PTHREAD_MUTEX_ERRORCHECK;
    if (strcmp(value,"PTHREAD_MUTEX_RECURSIVE") == 0)
      return PTHREAD_MUTEX_RECURSIVE;
    if (strcmp(value,"PTHREAD_MUTEX_DEFAULT") == 0)
      return PTHREAD_MUTEX_DEFAULT;
    assertion( 0, "Invalid mutex type: %s", value );
   }
  res = readInt(stream);
  switch (res)
   {
    case PTHREAD_MUTEX_NORMAL :
    case PTHREAD_MUTEX_ERRORCHECK :
    case PTHREAD_MUTEX_RECURSIVE :
      res = PTHREAD_MUTEX_INVALID_VALUE;
      break;
    default :
      if (res == PTHREAD_MUTEX_DEFAULT)
       {
        res = PTHREAD_MUTEX_INVALID_VALUE;
       }
   }
  return res;
}

void writeMutexProtocol(TAThread thread,int protocol)
{
    writeType_TAStream(thread,"muprotocol");
    switch (protocol)
    {
        case PTHREAD_PRIO_INHERIT:
            writeString( thread, "PTHREAD_PRIO_INHERIT" );
            return;
        case PTHREAD_PRIO_NONE:
            writeString( thread, "PTHREAD_PRIO_NONE" );
            return;
        case PTHREAD_PRIO_PROTECT:
            writeString( thread, "PTHREAD_PRIO_PROTECT" );
            return;
    }
    writeInt( thread, protocol );
}

int readMutexProtocol(TAInputStream* stream)
{
    int res;

    verifyType_TAInputStream(stream,"muprotocol");

    if (startsWith_TAInputStream(stream,"str")){

        char* value = readString(stream);

        if (strcmp(value,"PTHREAD_PRIO_INHERIT") == 0)
            return PTHREAD_PRIO_INHERIT;
        if (strcmp(value,"PTHREAD_PRIO_NONE") == 0)
            return PTHREAD_PRIO_NONE;
        if (strcmp(value,"PTHREAD_PRIO_PROTECT") == 0)
            return PTHREAD_PRIO_PROTECT;
        assertion( 0, "Invalid mutex type: %s", value );
    }
    res = readInt(stream);
    switch (res)
    {
        case PTHREAD_PRIO_INHERIT:
        case PTHREAD_PRIO_NONE:
        case PTHREAD_PRIO_PROTECT:
            res = PTHREAD_MUTEX_INVALID_VALUE;
            break;
    }
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict pthread_mutexattr_init_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int res;

    // Prepare
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_init(attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_gettype_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int is_not_null;
int type_value;
int* type;
int res;

    // Prepare
    attr = readPointer(&stream);
    is_not_null = readInt(&stream);
    if (is_not_null)
      type = &type_value;
    else
      type = NULL;

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_gettype(attr,type);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    if (is_not_null)
     {
      writeMutexType(thread,*type);
     }
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_settype_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int type;
int res;

    // Prepare
    attr = readPointer(&stream);
    type = readMutexType(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_settype(attr,type);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_getpshared_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int is_not_null;
int pshared_value;
int* pshared;
int res;

    // Prepare
    attr = readPointer(&stream);
    is_not_null = readInt(&stream);
    if (is_not_null)
      pshared = &pshared_value;
    else
      pshared = NULL;

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_getpshared(attr,pshared);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    if (is_not_null)
     {
      writePShared(thread,*pshared);
     }
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_setpshared_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int pshared;
int res;

    // Prepare
    attr = readPointer(&stream);
    pshared = readPShared(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_setpshared(attr,pshared);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_getprioceiling_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int prioceiling;
int res;

    // Prepare
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_getprioceiling(attr, &prioceiling);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeInt(thread,prioceiling);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_setprioceiling_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int prioceiling;
int res;

    // Prepare
    attr = readPointer(&stream);
    prioceiling = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_setprioceiling(attr,prioceiling);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict pthread_mutexattr_getprotocol_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int protocol;
int res;

    // Prepare
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_getprotocol(attr, &protocol);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    writeMutexProtocol(thread, protocol);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_setprotocol_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int protocol;
int res;

    // Prepare
    attr = readPointer(&stream);
    protocol = readMutexProtocol(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_setprotocol(attr,protocol);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pthread_mutexattr_destroy_cmd(TAThread thread,TAInputStream stream)
{
pthread_mutexattr_t* attr;
int res;

    // Prepare
    attr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pthread_mutexattr_destroy(attr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread,res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_pthread_mutex_mutexattr_commands(void)
{
    ta_register_command("pthread_mutexattr_init",pthread_mutexattr_init_cmd);
    ta_register_command("pthread_mutexattr_gettype",pthread_mutexattr_gettype_cmd);
    ta_register_command("pthread_mutexattr_settype",pthread_mutexattr_settype_cmd);
    ta_register_command("pthread_mutexattr_getpshared",pthread_mutexattr_getpshared_cmd);
    ta_register_command("pthread_mutexattr_setpshared",pthread_mutexattr_setpshared_cmd);
    ta_register_command("pthread_mutexattr_getprioceiling",pthread_mutexattr_getprioceiling_cmd);
    ta_register_command("pthread_mutexattr_setprioceiling",pthread_mutexattr_setprioceiling_cmd);
    ta_register_command("pthread_mutexattr_getprotocol",pthread_mutexattr_getprotocol_cmd);
    ta_register_command("pthread_mutexattr_setprotocol",pthread_mutexattr_setprotocol_cmd);
    ta_register_command("pthread_mutexattr_destroy",pthread_mutexattr_destroy_cmd);
}

