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
#include "util/format/wprintf_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vfwprintfDotsShell( FILE * stream, const wchar_t * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vfwprintf( stream, format, argList );
    va_end( argList );
    return res;
}

int vswprintfDotsShell( wchar_t * ws, size_t n, const wchar_t * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vswprintf( ws, n, format, argList );
    va_end( argList );
    return res;
}

int vwprintfDotsShell ( const wchar_t * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vwprintf( format, argList );
    va_end( argList );
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict fwprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = fwprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict swprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = swprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vfwprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vfwprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vswprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vswprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vwprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vwprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict wprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = wprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_util_format_wprintf_commands(void)
{
    // ta_register_command( "fwprintf" , fwprintf_cmd  );
    // ta_register_command( "swprintf" , swprintf_cmd  );
    // ta_register_command( "vfwprintf", vfwprintf_cmd );
    // ta_register_command( "vswprintf", vswprintf_cmd );
    // ta_register_command( "vwprintf" , vwprintf_cmd  );
    // ta_register_command( "wprintf"  , wprintf_cmd   );

    ta_register_command( "fwreadFile"          , fwreadFile_cmd           );
    ta_register_command( "functionWithDotsCall", functionWithDotsCall_cmd );
}
