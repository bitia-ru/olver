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

#include <stdarg.h>
#include "util/format/scanf_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vfscanfDotsShell( FILE * stream, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vfscanf( stream, format, argList );
    va_end( argList );
    return res;
}

int vscanfDotsShell ( const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vscanf( format, argList );
    va_end( argList );
    return res;
}

int vsscanfDotsShell( const char * ws, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vsscanf( ws, format, argList );
    va_end( argList );
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict fscanf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = fscanf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict scanf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = scanf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict sscanf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = sscanf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vfscanf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vfscanf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vscanf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vscanf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vsscanf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vsscanf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_util_format_scanf_commands(void)
{
    // ta_register_command( "fscanf" , fscanf_cmd  );
    // ta_register_command( "scanf"  , scanf_cmd   );
    // ta_register_command( "sscanf" , sscanf_cmd  );
    // ta_register_command( "vfscanf", vfscanf_cmd );
    // ta_register_command( "vscanf" , vscanf_cmd  );
    // ta_register_command( "vsscanf", vsscanf_cmd );

    ta_register_command( "freadFile"           , freadFile_cmd            );
    ta_register_command( "functionWithDotsCall", functionWithDotsCall_cmd );
}
