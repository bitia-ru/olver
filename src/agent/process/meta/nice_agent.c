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

#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>
#include "process/meta/nice_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getpriority_cmd(TAThread thread,TAInputStream stream)
{
   int which;
   int who  ;
   int res  ;

   // Prepare
   which = readInt( & stream );
   who   = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getpriority( which, who );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict nice_cmd(TAThread thread,TAInputStream stream)
{
   int incr;
   int res ;

   // ta_debug_printf( "[%3d]", nice( 0 ) );
   // Prepare
   incr = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = nice( incr );
   END_TARGET_OPERATION(thread);

   // ta_debug_printf( "[%3d|%3d|%3d|%3d|%3d|%3d]\n", res, incr, getuid(), geteuid(), getgid(), getegid() );
   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setpriority_cmd(TAThread thread,TAInputStream stream)
{
   int which;
   int who  ;
   int value;
   int res  ;

   // Prepare
   which = readInt( & stream );
   who   = readInt( & stream );
   value = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setpriority( which, who, value );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_process_meta_nice_commands(void)
{
    ta_register_command( "getpriority", getpriority_cmd );
    ta_register_command( "nice"       , nice_cmd        );
    ta_register_command( "setpriority", setpriority_cmd );
}
