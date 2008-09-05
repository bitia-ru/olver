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

#define _GNU_SOURCE
#include <string.h>
#include <signal.h>
#include "common/ta_stream.h"
#include "signal/sigstr/sigstr_agent.h"

//extern const char * const sys_siglist[];

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

TACommandVerdict a_signalAsCString_cmd( TAThread thread, TAInputStream stream ) {
    int sig = readInt( & stream );
    //if ( sig < 1 || sizeof( sys_siglist ) / sizeof( sys_siglist[ 0 ] ) <= sig ) {
    char * tmp = strsignal( sig );
    // ta_debug_printf( "a_signalAsCString_cmd : strsignal( %d ) is \"%s\"\n", sig, tmp == NULL ? "NULL" : tmp );
    if ( tmp == NULL || strncmp( tmp, "unknown signal", strlen( "unknown signal" ) ) == 0 ||
                        strncmp( tmp, "Unknown signal", strlen( "unknown signal" ) ) == 0
       ) {
        writeInt( thread, 0 );
    } else {
        writeInt   ( thread, 1   );
        writeString( thread, tmp );
        //writeString( thread, sys_siglist[ sig ] );
    }
    sendResponse( thread );
    return taDefaultVerdict;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict psignal_cmd(TAThread thread,TAInputStream stream)
{
    int    sig           = readInt   ( & stream );
    char * s             = readString( & stream );
    char * fileForStderr = readString( & stream );
    FILE * stderrAsFile;
    FILE * oldStderr;
    // psignal( sig, s );
    stderrAsFile = fopen( fileForStderr, "w" );
    assertion( stderrAsFile != NULL, "psignal_cmd : stderrAsFile is NULL\n" );
    oldStderr = stderr;
    stderr = stderrAsFile;
    // ta_debug_printf( "psignal_cmd : sig           is %d\n"    , sig           );   fflush( stdout );
    // ta_debug_printf( "psignal_cmd : s             is \"%s\"\n", s             );   fflush( stdout );
    // ta_debug_printf( "psignal_cmd : fileForStderr is \"%s\"\n", fileForStderr );   fflush( stdout );
    START_TARGET_OPERATION( thread );
    // ta_debug_printf( "psignal_cmd : before psignal\n" );   fflush( stdout );
    psignal( sig, s );
    // ta_debug_printf( "psignal_cmd : after  psignal\n" );   fflush( stdout );
    END_TARGET_OPERATION( thread );
    stderr = oldStderr;
    // ta_debug_printf( "psignal_cmd : 1\n" );   fflush( stdout );
    fclose( stderrAsFile );
    // ta_debug_printf( "psignal_cmd : 2\n" );   fflush( stdout );
    writeString( thread, "Ok" );
    // ta_debug_printf( "psignal_cmd : 3\n" );   fflush( stdout );
    sendResponse( thread );
    // ta_debug_printf( "psignal_cmd : return\n" );   fflush( stdout );
    return taDefaultVerdict;
}

static TACommandVerdict strsignal_cmd(TAThread thread,TAInputStream stream)
{
    int sig = readInt( & stream );
    char * res;
    START_TARGET_OPERATION( thread );
    res = strsignal( sig );
    END_TARGET_OPERATION( thread );
    writeString( thread, res );
    sendResponse( thread );
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_signal_sigstr_commands( void ) {
    ta_register_command( "a_signalAsCString", a_signalAsCString_cmd );

    ta_register_command( "psignal"  , psignal_cmd   );
    ta_register_command( "strsignal", strsignal_cmd );
}
