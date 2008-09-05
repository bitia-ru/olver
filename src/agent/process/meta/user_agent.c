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
#include <stdio.h>

#include <grp.h>
#include <sys/types.h>

#include "process/meta/user_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

/********************************************************************/
/**                        Special Commands                        **/
/********************************************************************/

static TACommandVerdict get_SC_NGROUPS_MAX_cmd( TAThread thread, TAInputStream stream ) {
   long res;
   START_TARGET_OPERATION( thread );
   res = sysconf( _SC_NGROUPS_MAX );
   END_TARGET_OPERATION( thread );
   writeLong( thread, res );
   sendResponse( thread );
   return taDefaultVerdict;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cuserid_cmd(TAThread thread,TAInputStream stream)
{
   char * s  ;
   char * res;

   // Prepare
   s = (char *)readPointer( & stream );

   // Execute
   START_TARGET_OPERATION(thread);
   res = cuserid( s );
   END_TARGET_OPERATION(thread);

   // Response
   writePointer( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getegid_cmd(TAThread thread,TAInputStream stream)
{
   unsigned int res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getegid();
   END_TARGET_OPERATION(thread);

   // Response
   writeUInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict geteuid_cmd(TAThread thread,TAInputStream stream)
{
   unsigned int res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = geteuid();
   END_TARGET_OPERATION(thread);

   // Response
   writeUInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getgid_cmd(TAThread thread,TAInputStream stream)
{
   unsigned int res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getgid();
   END_TARGET_OPERATION(thread);

   // Response
   writeUInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getgroups_cmd(TAThread thread,TAInputStream stream)
{
   int            gidsetsize    ;
   int            grouplist_size;
   unsigned int * grouplist     ;
   int            res           ;

   // Prepare
   gidsetsize = readInt( & stream );
   grouplist_size = readUintList( & stream, & grouplist );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getgroups( gidsetsize, grouplist );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res );
   writeUintList( thread, grouplist_size, grouplist );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getuid_cmd(TAThread thread,TAInputStream stream)
{
   unsigned int res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getuid();
   END_TARGET_OPERATION(thread);

   // Response
   writeUInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict initgroups_cmd(TAThread thread,TAInputStream stream)
{
   char * user ;
   int    group;
   int    res  ;

   // Prepare
   user  = readString( & stream );
   group = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = initgroups( user, group );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setegid_cmd(TAThread thread,TAInputStream stream)
{
   int gid;
   int res;

   // Prepare
   gid = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setegid( gid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict seteuid_cmd(TAThread thread,TAInputStream stream)
{
   int uid;
   int res;

   // Prepare
   uid = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = seteuid( uid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setgid_cmd(TAThread thread,TAInputStream stream)
{
   int gid;
   int res;

   // Prepare
   gid = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setgid( gid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setgroups_cmd(TAThread thread,TAInputStream stream)
{
   int            size     ;
   int            list_size;
   unsigned int * list     ;
   int            res      ;

   // Prepare
   size = readSize( & stream );
   list_size = readUintList( & stream, & list );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setgroups( size, list );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res );
   writeUintList( thread, list_size, list );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setregid_cmd(TAThread thread,TAInputStream stream)
{
   int rgid;
   int egid;
   int res;

   // Prepare
   rgid = readInt( & stream );
   egid = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setregid( rgid, egid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setreuid_cmd(TAThread thread,TAInputStream stream)
{
   int ruid;
   int euid;
   int res;

   // Prepare
   ruid = readInt( & stream );
   euid = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setreuid( ruid, euid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setuid_cmd(TAThread thread,TAInputStream stream)
{
   int uid;
   int res;

   // Prepare
   uid = readInt( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setuid( uid );
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
void register_process_meta_user_commands(void)
{
   ta_register_command( "get_SC_NGROUPS_MAX", get_SC_NGROUPS_MAX_cmd );

   ta_register_command( "cuserid"   , cuserid_cmd    );
   ta_register_command( "getegid"   , getegid_cmd    );
   ta_register_command( "geteuid"   , geteuid_cmd    );
   ta_register_command( "getgid"    , getgid_cmd     );
   ta_register_command( "getgroups" , getgroups_cmd  );
   ta_register_command( "getuid"    , getuid_cmd     );
   ta_register_command( "initgroups", initgroups_cmd );
   ta_register_command( "setegid"   , setegid_cmd    );
   ta_register_command( "seteuid"   , seteuid_cmd    );
   ta_register_command( "setgid"    , setgid_cmd     );
   ta_register_command( "setgroups" , setgroups_cmd  );
   ta_register_command( "setregid"  , setregid_cmd   );
   ta_register_command( "setreuid"  , setreuid_cmd   );
   ta_register_command( "setuid"    , setuid_cmd     );
}
