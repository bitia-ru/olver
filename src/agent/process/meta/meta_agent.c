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
#include "process/meta/meta_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getpid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getpid();
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

static TACommandVerdict getppid_cmd(TAThread thread,TAInputStream stream)
{
   pid_t res;

   // Execute
   START_TARGET_OPERATION(thread);
   res = getppid();
   END_TARGET_OPERATION(thread);

   // Response
   writeInt( thread, res );
   sendResponse( thread );

   return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_meta_meta_commands(void)
{
   ta_register_command("getpid",getpid_cmd);
   ta_register_command("getppid",getppid_cmd);
}
