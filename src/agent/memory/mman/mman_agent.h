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


#ifndef TA_MEMORY_MMAN_AGENT_H
#define TA_MEMORY_MMAN_AGENT_H

#include "common/agent.h"
#include <sys/mman.h>
#include "fs/fs/fs_agent.h"

/********************************************************************/
/**                     Flag values on connection                  **/
/********************************************************************/

#define SUT_MCL_CURRENT    1
#define SUT_MCL_FUTURE     2

#define SUT_PROT_READ      1
#define SUT_PROT_WRITE     2
#define SUT_PROT_EXEC      4
#define SUT_PROT_NONE      8

#define SUT_MAP_SHARED     1
#define SUT_MAP_PRIVATE    2
#define SUT_MAP_FIXED      4

#define SUT_MS_ASYNC       1
#define SUT_MS_SYNC        2
#define SUT_MS_INVALIDATE  4

#define SUT_O_RDONLY       1
#define SUT_O_RDWR         2
#define SUT_O_CREAT        4
#define SUT_O_EXCL         8
#define SUT_O_TRUNC        16


int convertMLockallFlagsReprezentationToIntRealization(int value);
int convertIntRealizationToMLockallFlagsRepresentation(int value);
int convertMmanProtFlagsReprezentationToIntRealization(int value);
int convertIntRealizationToMmanProtFlagsRepresentation(int value);
int convertMmapFlagsReprezentationToIntRealization(int value);
int convertIntRealizationToMmapFlagsRepresentation(int value);
int convertMsyncFlagsReprezentationToIntRealization(int value);
int convertIntRealizationToMsyncFlagsRepresentation(int value);
int convertShm_openOflagsReprezentationToIntRealization(int value);
int convertIntRealizationToShm_openOflagsRepresentation(int value);

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_memory_mman_commands(void);


#endif

