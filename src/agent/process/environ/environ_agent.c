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

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "process/environ/environ_agent.h"

extern char **environ;

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

/* Read environment strings from environ variable. */
static TACommandVerdict readEnviron_cmd( TAThread thread, TAInputStream stream ) {
   char ** p;
   for ( p = environ; ; p++ ) {
      writeString( thread, * p );
      if ( * p == NULL ) { break; }
   }
   sendResponse( thread );
   return taDefaultVerdict;
}

/* Agent commands for testing functions. */

static TACommandVerdict getenv_cmd(TAThread thread,TAInputStream stream)
{
   char * name;
   char * res ;

   // Prepare
   name = readString( & stream );

   // Execute
   START_TARGET_OPERATION(thread);
   res = getenv( name );
   END_TARGET_OPERATION(thread);

   // Response
   writeString( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict putenv_cmd(TAThread thread,TAInputStream stream)
{
   char * name;
   int    res ;

   char * namePlace;

   // Prepare
   name = readString( & stream );
   namePlace = (char *)ta_alloc_memory( ( strlen( name ) + 1 ) * sizeof( char ) );
   strcpy( namePlace, name );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = putenv( namePlace );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setenv_cmd(TAThread thread,TAInputStream stream)
{
   char * envname  ;
   char * envval   ;
   int    overwrite;
   int    res      ;

   // Prepare
   envname   = readString( & stream );
   envval    = readString( & stream );
   overwrite = readInt   ( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setenv( envname, envval, overwrite );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict unsetenv_cmd(TAThread thread,TAInputStream stream)
{
   char * name;
   int    res ;

   // Prepare
   name = readString( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = unsetenv( name );
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
void register_process_environ_commands(void)
{
   ta_register_command( "readEnviron", readEnviron_cmd );

   ta_register_command("getenv",getenv_cmd);
   ta_register_command("putenv",putenv_cmd);
   ta_register_command("setenv",setenv_cmd);
   ta_register_command("unsetenv",unsetenv_cmd);
}
