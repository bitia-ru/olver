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
#include "util/format/printf_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vasprintfDotsShell( char ** ptr, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vasprintf( ptr, format, argList );
    va_end( argList );
    return res;
}

int vdprintfDotsShell( int fd, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vdprintf( fd, format, argList );
    va_end( argList );
    return res;
}

int vfprintfDotsShell( FILE * stream, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vfprintf( stream, format, argList );
    va_end( argList );
    return res;
}

int vprintfDotsShell( const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vprintf( format, argList );
    va_end( argList );
    return res;
}

int vsnprintfDotsShell( char * s, size_t n, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vsnprintf( s, n, format, argList );
    va_end( argList );
    return res;
}

int vsprintfDotsShell( char * s, const char * format, ... ) {
    int res;
    va_list argList;
    va_start( argList, format );
    res = vsprintf( s, format, argList );
    va_end( argList );
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict asprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = asprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict fprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = fprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict printf_cmd(TAThread thread,TAInputStream stream)
{
    assertion( 0, "printf_cmd should not be called" );

    return taDefaultVerdict;
}

static TACommandVerdict snprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = snprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict sprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = sprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vasprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vasprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vdprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vdprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vfprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vfprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vsnprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vsnprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vsprintf_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vsprintf(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_util_format_printf_commands(void)
{
    // ta_register_command( "asprintf" , asprintf_cmd  );
    // ta_register_command( "fprintf"  , fprintf_cmd   );
    // ta_register_command( "printf"   , printf_cmd    );
    // ta_register_command( "snprintf" , snprintf_cmd  );
    // ta_register_command( "sprintf"  , sprintf_cmd   );
    // ta_register_command( "vasprintf", vasprintf_cmd );
    // ta_register_command( "vdprintf" , vdprintf_cmd  );
    // ta_register_command( "vfprintf" , vfprintf_cmd  );
    // ta_register_command( "vprintf"  , vprintf_cmd   );
    // ta_register_command( "vsnprintf", vsnprintf_cmd );
    // ta_register_command( "vsprintf" , vsprintf_cmd  );

    ta_register_command( "freadFile"           , freadFile_cmd            );
    ta_register_command( "readFile"            , readFile_cmd             );
    ta_register_command( "functionWithDotsCall", functionWithDotsCall_cmd );
}
