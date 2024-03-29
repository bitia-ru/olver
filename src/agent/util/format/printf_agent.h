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

#ifndef TA_UTIL_FORMAT_PRINTF_AGENT_H
#define TA_UTIL_FORMAT_PRINTF_AGENT_H

#include <stdio.h>
#include "common/agent.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vasprintfDotsShell( char ** ptr  ,           const char * format, ... );
int vdprintfDotsShell ( int fd       ,           const char * format, ... );
int vfprintfDotsShell ( FILE * stream,           const char * format, ... );
int vprintfDotsShell  (                          const char * format, ... );
int vsnprintfDotsShell( char * s     , size_t n, const char * format, ... );
int vsprintfDotsShell ( char * s     ,           const char * format, ... );

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_util_format_printf_commands(void);

#endif
