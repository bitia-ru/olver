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

#include "process/pgroup/pgroup_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __getpgid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t pid, res;

   // Prepare
   pid = readLong( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = __getpgid( pid );
   END_TARGET_OPERATION(thread);

   ta_debug_printf("res=%d, pid=%d\n", res, pid);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getpgid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t pid, res;

   // Prepare
   pid = readLong( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getpgid( pid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getpgrp_cmd(TAThread thread,TAInputStream stream)
{
   pid_t res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getpgrp();
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getsid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t pid, res;

   // Prepare
   pid = readLong( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getsid( pid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setpgid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t pid, pgid;
   int res;

   // Prepare
   pid  = readLong( & stream );
   pgid = readLong( & stream );
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setpgid( pid, pgid );
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res   );
   writeInt( thread, errno );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setpgrp_cmd(TAThread thread,TAInputStream stream)
{
   pid_t res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setpgrp();
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict setsid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t res;

   // Prepare
   errno = 0;

   // Execute
   START_TARGET_OPERATION(thread);
   res = setsid();
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

void register_process_pgroup_commands(void)
{
   ta_register_command( "__getpgid", __getpgid_cmd );
   ta_register_command( "getpgid"  , getpgid_cmd   );
   ta_register_command( "getpgrp"  , getpgrp_cmd   );
   ta_register_command( "getsid"   , getsid_cmd    );
   ta_register_command( "setpgid"  , setpgid_cmd   );
   ta_register_command( "setpgrp"  , setpgrp_cmd   );
   ta_register_command( "setsid"   , setsid_cmd    );
}
