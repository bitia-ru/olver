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

#include <setjmp.h>
#include <memory.h>
#include "process/goto/goto_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __sigsetjmp_cmd(TAThread thread,TAInputStream stream)
{
    int        id      ;
    int        savemask;
    sigjmp_buf env     ;
    int        res     ;
    int savedThreadLevel;

    // Prepare
    id       = readInt( & stream );
    savemask = readInt( & stream );

    // Execute
    START_TARGET_OPERATION( thread );
    res = __sigsetjmp( env, savemask );
    END_TARGET_OPERATION( thread );

    if ( res == 0 ) {
        // return from __sigsetjmp

        // Response
        writeInt( thread, res );
        writeSigJmpBuf( thread, id, & env );
        sendResponse( thread );

        // new agent circle
        savedThreadLevel = thread->level;
        ta_main_routine( NULL );
    } else {
        // return from siglongjmp
        thread->level = savedThreadLevel;

        // Response
        writeInt( thread, res );
        writeSigJmpBuf( thread, id, & env );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict _longjmp_cmd(TAThread thread,TAInputStream stream)
{
    int     id ;
    jmp_buf env;
    int     val;

    // Prepare
    readJmpBuf( & stream, & id, & env );
    val = readInt( & stream );

    // Execute
    START_TARGET_OPERATION( thread );
    _longjmp( env, val );
    END_TARGET_OPERATION( thread );

    sendException( thread, "unexpected return from _longjmp" );

    return taDefaultVerdict;
}

static TACommandVerdict _setjmp_cmd(TAThread thread,TAInputStream stream)
{
    int     id ;
    jmp_buf env;
    int     res;
    int savedThreadLevel;

    // Prepare
    id = readInt( & stream );

    // Execute
    START_TARGET_OPERATION( thread );
    res = _setjmp( env );
    END_TARGET_OPERATION( thread );

    if ( res == 0 ) {
        // return from _setjmp

        // Response
        writeInt( thread, res );
        writeJmpBuf( thread, id, & env );
        sendResponse( thread );

        // new agent circle
        savedThreadLevel = thread->level;
        ta_main_routine( NULL );
    } else {
        // return from _longjmp or longjmp
        thread->level = savedThreadLevel;

        // Response
        writeInt( thread, res );
        writeJmpBuf( thread, id, & env );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict longjmp_cmd(TAThread thread,TAInputStream stream)
{
    int     id ;
    jmp_buf env;
    int     val;

    // Prepare
    readJmpBuf( & stream, & id, & env );
    val = readInt( & stream );

    // Execute
    START_TARGET_OPERATION( thread );
    longjmp( env, val );
    END_TARGET_OPERATION( thread );

    sendException( thread, "unexpected return from longjmp" );

    return taDefaultVerdict;
}

static TACommandVerdict siglongjmp_cmd(TAThread thread,TAInputStream stream)
{
    int        id ;
    sigjmp_buf env;
    int        val;

    // Prepare
    readSigJmpBuf( & stream, & id, & env );
    val = readInt( & stream );

    // Execute
    START_TARGET_OPERATION( thread );
    siglongjmp( env, val );
    END_TARGET_OPERATION( thread );

    sendException( thread, "unexpected return from siglongjmp" );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_process_goto_commands( void )
{
    ta_register_command( "__sigsetjmp", __sigsetjmp_cmd );
    ta_register_command( "_longjmp"   , _longjmp_cmd    );
    ta_register_command( "_setjmp"    , _setjmp_cmd     );
    ta_register_command( "longjmp"    , longjmp_cmd     );
    ta_register_command( "siglongjmp" , siglongjmp_cmd  );
}

/********************************************************************/
/**                  write-read for user types                     **/
/********************************************************************/

/* $(sigjmp_buf) */
void readSigJmpBuf( TAInputStream * stream, int * id, sigjmp_buf * value ) {
    int charsReceived;
    char * charList;
    verifyType_TAInputStream( stream, "sigjmp_buf" );
    * id = readInt( stream );
    charsReceived = readCharList( stream, & charList );
    assertion( sizeof( sigjmp_buf ) == charsReceived, "readSigJmpBuf : sizeof( sigjmp_buf ) is %d, charsReceived is %d\n",
                                                      (int)sizeof( sigjmp_buf ), charsReceived
             );
    memcpy( value, charList, sizeof( sigjmp_buf ) );
    ta_dealloc_memory( charList );
}

void writeSigJmpBuf( TAThread thread, int id, const sigjmp_buf * value ) {
    writeInt( thread, id );
    writeCharList( thread, sizeof( sigjmp_buf ), (char *)value, 0 );
}

/* $(jmp_buf) */
void readJmpBuf( TAInputStream * stream, int * id, jmp_buf * value ) {
    int charsReceived;
    char * charList;
    verifyType_TAInputStream( stream, "jmp_buf" );
    * id = readInt( stream );
    charsReceived = readCharList( stream, & charList );
    assertion( sizeof( jmp_buf ) == charsReceived, "readJmpBuf : sizeof( jmp_buf ) is %d, charsReceived is %d\n",
                                                   (int)sizeof( jmp_buf ), charsReceived
             );
    memcpy( value, charList, sizeof( jmp_buf ) );
    ta_dealloc_memory( charList );
}

void writeJmpBuf( TAThread thread, int id, const jmp_buf * value ) {
    writeInt( thread, id );
    writeCharList( thread, sizeof( jmp_buf ), (char *)value, 0 );
}
