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

#include "common/agent.h"
#include "common/ta_stream.h"

#include <ucontext.h>
#include <memory.h>
#include <errno.h>
#include "process/context/context_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

static void funcAtMakecontext1() {}

int isReturnFromSetcontext = ( 1 != 1 );

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getcontext_cmd( TAThread thread, TAInputStream stream ) {
    int        id ;
    ucontext_t ucp;
    int        res;
    int savedThreadLevel;
    // Prepare
    isReturnFromSetcontext = ( 1 != 1 );
    id = readInt( & stream );
    // Execute
    START_TARGET_OPERATION( thread );
    ta_debug_printf( "getcontext_cmd : 1\n" );
    res = getcontext( & ucp );
    ta_debug_printf( "getcontext_cmd : 2\n" );
    END_TARGET_OPERATION( thread );
    if ( isReturnFromSetcontext ) {
        // return from late setcontext, late swapcontext
        thread->level = savedThreadLevel;
        // Response
        writeInt( thread, res );
        writeMarkedByteChain( thread, id, & ucp, sizeof( ucontext_t ) );
        writeInt( thread, errno ); // for swapcontext
        sendResponse( thread );
    } else {
        // return from current getcontext
        // Response
        writeInt( thread, res );
        writeMarkedByteChain( thread, id, & ucp, sizeof( ucontext_t ) );
        writeInt( thread, errno ); // for swapcontext
        sendResponse( thread );
        // new agent circle
        savedThreadLevel = thread->level;
        ta_main_routine( NULL );
    }
    return taDefaultVerdict;
}

static TACommandVerdict makecontext_cmd(TAThread thread,TAInputStream stream)
{
    int          id  ;
    ucontext_t   ucp ;
    char       * func;
    int          argc;

    char stack1[ 8192 ];
    ucontext_t * ucpPtr;

    // Prepare
    readMarkedByteChain( & stream, & id, & ucp, sizeof( ucontext_t ) );
    func = readString( & stream );
    argc = readInt( & stream );

    ucpPtr = & ucp;
#if __ia64__
    ucpPtr->_u._mc.sc_stack.ss_sp   = stack1          ;
    ucpPtr->_u._mc.sc_stack.ss_size = sizeof( stack1 );
    ucpPtr->_u._uc._link = NULL;
#else
    ucpPtr->uc_stack.ss_sp   = stack1          ;
    ucpPtr->uc_stack.ss_size = sizeof( stack1 );
    ucpPtr->uc_link          = NULL            ;
#endif

    // Execute
    START_TARGET_OPERATION(thread);
    if ( strcmp( func, "funcAtMakecontext1" ) == 0 && argc == 0 ) {
        makecontext( & ucp, funcAtMakecontext1, argc );
    }
    END_TARGET_OPERATION(thread);
    // Response
    writeMarkedByteChain( thread, id, & ucp, sizeof( ucontext_t ) );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict setcontext_cmd( TAThread thread, TAInputStream stream ) {
    int        id ;
    ucontext_t ucp;
    int        res;
    // Prepare
    isReturnFromSetcontext = ( 1 == 1 );
    readMarkedByteChain( & stream, & id, & ucp, sizeof( ucontext_t ) );
    // Execute
    START_TARGET_OPERATION( thread );
    ta_debug_printf( "setcontext_cmd : 1\n" );
    res = setcontext( & ucp );
    ta_debug_printf( "setcontext_cmd : 2\n" );
    END_TARGET_OPERATION( thread );
    // Response
    writeInt( thread, res );
    writeMarkedByteChain( thread, id, & ucp, sizeof( ucontext_t ) );
    sendResponse( thread );
    return taDefaultVerdict;
}

static TACommandVerdict swapcontext_cmd( TAThread thread, TAInputStream stream ) {
    int        oid ;
    ucontext_t oucp;
    int        id  ;
    ucontext_t ucp ;
    int        res ;
    // Prepare
    isReturnFromSetcontext = ( 1 == 1 );
    oid = readInt( & stream );
    readMarkedByteChain( & stream, & id, & ucp, sizeof( ucontext_t ) );
    // Execute
    START_TARGET_OPERATION( thread );
    ta_debug_printf( "swapcontext_cmd : 1\n" );
    res = swapcontext( & oucp, & ucp );
    ta_debug_printf( "swapcontext_cmd : 2\n" );
    END_TARGET_OPERATION( thread );
    // Response
    writeInt( thread, res );
    // writeMarkedByteChain( thread, oid, & oucp, sizeof( ucontext_t ) );
    writeMarkedByteChain( thread, id, & ucp, sizeof( ucontext_t ) );
    writeInt( thread, errno );
    sendResponse( thread );
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_process_context_commands( void ) {
    ta_register_command( "getcontext" , getcontext_cmd  );
    ta_register_command( "makecontext", makecontext_cmd );
    ta_register_command( "setcontext" , setcontext_cmd  );
    ta_register_command( "swapcontext", swapcontext_cmd );
}
