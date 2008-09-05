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


#ifndef TA_CONFIG_CONFIG_H
#define TA_CONFIG_CONFIG_H


// Workaround for the bug in LSB SDK (< 3.2): absence of O_LARGEFILE
#include <fcntl.h>
#if !defined(O_LARGEFILE)
  #if defined (__ia64__) || defined (__x86_64__) || defined (__s390x__)
    #define O_LARGEFILE 0
  #elif defined (__i386__)
    #define O_LARGEFILE 0100000
  #elif defined (__s390__) && !defined (__s390x__)
    #define O_LARGEFILE	0100000
  #elif defined (__powerpc__)
    #define O_LARGEFILE	0200000
  #endif
#endif

//#define TA_MEMPOOL_DEBUG

#endif
