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

#include <stdio.h>
#include <err.h>
#include "util/assert/assert_agent.h"
#include "process/process/process_common.h"

void error(int exitstatus, int errnum, const char * format, ...);

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

void verrxDotsShell( int eval, const char * fmt, ... ) {
    va_list argList;
    va_start( argList, fmt );
    verrx( eval, fmt, argList );
    va_end( argList );
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __assert_fail_cmd(TAThread thread,TAInputStream stream)
{
    FILE * old_std;
    FILE * stubfile;

    // Prepare
    const char * assertion = readString(&stream);
    const char * file = readString(&stream);
    unsigned int line = readUInt(&stream);
    int ind = readInt(&stream);
    const char * function = NULL;

    if (ind)
        function = readString(&stream);

    START_TARGET_OPERATION(thread);

    //writeDeferredReaction( thread, "assertFail_processTerminated" );
    //sendResponse( thread );

    // Execute
    stubfile = fopen("stderr_stub.txt","wt");

    old_std = stderr;
    stderr = stubfile;

    __assert_fail(assertion, file, line, function);
    stderr = old_std;
    fclose(stubfile);

    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "assertFail_return" );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict get_stderr_cmd(TAThread thread,TAInputStream stream)
{
    FILE * f;
    size_t fileSize;
    char* buffer;
    size_t readBytes;

    f = fopen("stderr_stub.txt", "rb");
    if (!f)
    {
        ta_debug_printf("assert_agent.c:Error:1\n");
        writeString( thread, "");
        sendResponse( thread );
        return taDefaultVerdict;
    }

      if(fseek(f, 0, SEEK_END))
    {
        ta_debug_printf("assert_agent.c:Error:2\n");
        writeString( thread, "");
        sendResponse( thread );
        return taDefaultVerdict;
    }

    fileSize = ftell(f);
    if(fseek(f, 0, SEEK_SET))
    {
        ta_debug_printf("assert_agent.c:Error:3\n");
        writeString( thread, "");
        sendResponse( thread );
        return taDefaultVerdict;
    }

    buffer = (char*)malloc(fileSize + 1);
    readBytes = fread(buffer, 1, fileSize, f);
    buffer[fileSize] = 0;
    if (readBytes != fileSize)
    {
        ta_debug_printf("assert_agent.c:Error:4\n");
        writeString( thread, "");
        sendResponse( thread );
        return taDefaultVerdict;
    }

    writeString( thread,  buffer);
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict err_cmd(TAThread thread,TAInputStream stream)
{
    long * arguments                                                 ;
    int    argumentsSize = readDotsArguments( & stream, & arguments );
    char * fileForStderr = readString       ( & stream              );
    FILE * stderrAsFile;
    FILE * oldStderr;
    arguments[ 0 ] = (long)err;
    stderrAsFile = fopen( fileForStderr, "w" );
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString( thread, "Ok" );
    sendResponse(thread);
    START_TARGET_OPERATION(thread);
    writeDeferredReaction( thread, "err_processTerminated" );
    writeString( thread, "err" );
    sendResponse( thread );
    oldStderr = stderr;
    stderr = stderrAsFile;
    functionLongValuesCall( argumentsSize, arguments );
    stderr = oldStderr;
    END_TARGET_OPERATION(thread);
    fclose( stderrAsFile );
    writeDeferredReaction( thread, "errCalledProcess_return" );
    writeString( thread, "err" );
    sendResponse( thread );
    ta_dealloc_memory( arguments );
    return taDefaultVerdict;
}

static TACommandVerdict error_cmd(TAThread thread,TAInputStream stream)
{
    long * arguments                                                 ;
    int    argumentsSize = readDotsArguments( & stream, & arguments );
    char * fileForStderr = readString       ( & stream              );
    FILE * stderrAsFile;
    FILE * oldStderr;
    arguments[ 0 ] = (long)error;
    stderrAsFile = fopen( fileForStderr, "w" );
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString( thread, "Ok" );
    sendResponse(thread);
    START_TARGET_OPERATION(thread);
    if ( arguments[ 1 ] != 0 ) { // arguments[ 1 ] == exitstatus
        writeDeferredReaction( thread, "err_processTerminated" );
        writeString( thread, "error" );
        sendResponse( thread );
    }
    oldStderr = stderr;
    stderr = stderrAsFile;
    functionLongValuesCall( argumentsSize, arguments );
    stderr = oldStderr;
    END_TARGET_OPERATION(thread);
    fclose( stderrAsFile );
    writeDeferredReaction( thread, "errCalledProcess_return" );
    writeString( thread, "error" );
    sendResponse( thread );
    ta_dealloc_memory( arguments );
    return taDefaultVerdict;
}

static TACommandVerdict errx_cmd(TAThread thread,TAInputStream stream)
{
    long * arguments                                                 ;
    int    argumentsSize = readDotsArguments( & stream, & arguments );
    char * fileForStderr = readString       ( & stream              );
    FILE * stderrAsFile;
    FILE * oldStderr;
    arguments[ 0 ] = (long)errx;
    stderrAsFile = fopen( fileForStderr, "w" );
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString( thread, "Ok" );
    sendResponse(thread);
    START_TARGET_OPERATION(thread);
    writeDeferredReaction( thread, "err_processTerminated" );
    writeString( thread, "errx" );
    sendResponse( thread );
    oldStderr = stderr;
    stderr = stderrAsFile;
    functionLongValuesCall( argumentsSize, arguments );
    stderr = oldStderr;
    END_TARGET_OPERATION(thread);
    fclose( stderrAsFile );
    writeDeferredReaction( thread, "errCalledProcess_return" );
    writeString( thread, "errx" );
    sendResponse( thread );
    ta_dealloc_memory( arguments );
    return taDefaultVerdict;
}

static TACommandVerdict verrx_cmd(TAThread thread,TAInputStream stream)
{
    long * arguments                                                 ;
    int    argumentsSize = readDotsArguments( & stream, & arguments );
    char * fileForStderr = readString       ( & stream              );
    FILE * stderrAsFile;
    FILE * oldStderr;
    arguments[ 0 ] = (long)verrxDotsShell;
    stderrAsFile = fopen( fileForStderr, "w" );
    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString( thread, "Ok" );
    sendResponse(thread);
    START_TARGET_OPERATION(thread);
    writeDeferredReaction( thread, "err_processTerminated" );
    writeString( thread, "verrx" );
    sendResponse( thread );
    oldStderr = stderr;
    stderr = stderrAsFile;
    functionLongValuesCall( argumentsSize, arguments );
    stderr = oldStderr;
    END_TARGET_OPERATION(thread);
    fclose( stderrAsFile );
    writeDeferredReaction( thread, "errCalledProcess_return" );
    writeString( thread, "verrx" );
    sendResponse( thread );
    ta_dealloc_memory( arguments );
    return taDefaultVerdict;
}

static TACommandVerdict warn_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = warn(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict warnx_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = warnx(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_assert_commands(void)
{
    ta_register_command("__assert_fail", __assert_fail_cmd);
    ta_register_command("get_stderr", get_stderr_cmd);
    ta_register_command( "err"  , err_cmd   );
    ta_register_command( "error", error_cmd );
    ta_register_command( "errx" , errx_cmd  );
    ta_register_command( "verrx", verrx_cmd );
 // ta_register_command( "warn" , warn_cmd  );
 // ta_register_command( "warnx", warnx_cmd );

    ta_register_command( "getFileContents"     , getFileContents_cmd      );
    ta_register_command( "functionWithDotsCall", functionWithDotsCall_cmd );
}
