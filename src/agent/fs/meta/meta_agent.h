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


#ifndef TA_FS_META_AGENT_H
#define TA_FS_META_AGENT_H

#define IS_IN_rtld
#define _LARGEFILE_SOURCE 1
#define _GNU_SOURCE

#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <utime.h>

#include "common/agent.h"

void writeFileStatus(TAThread thread, struct stat* buffer);
void writeFileStatus64(TAThread thread, struct stat64* buffer);
struct utimbuf readUTimBuf(TAInputStream* stream);
void readTimeValPair(TAInputStream* stream, struct timeval* times);
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_fs_meta_meta_commands(void);


#endif

