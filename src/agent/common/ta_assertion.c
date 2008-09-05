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
#include "common/ta_assertion.h"
#include <stdarg.h>
#include <stdio.h>
#include <pthread.h>

static void defaultAssertionExit(const char * format, va_list arg_list) {
  //  va_start( arg_list, format );
  vfprintf( stderr, format, arg_list );
  ta_debug_printf("\n");
  // va_end( arg_list );

  pthread_exit(NULL);
}

void assertion( int expr, const char* format, ... )
{
    if( !expr )
    {
        va_list arg_list;

        va_start(arg_list, format);
        defaultAssertionExit(format, arg_list);
        va_end(arg_list);
        pthread_exit(NULL);
    }
}

