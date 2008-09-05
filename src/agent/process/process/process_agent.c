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

#include <errno.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <pthread.h>
#include <pty.h>
#include "process/process/process_agent.h"
#include "process/process/process_common.h"

int __cxa_atexit(void (*func) (void *), void * arg, void * dso_handle);

int __libc_start_main(int (*main) (int, char * *, char * *), int argc, char * * ubp_av, void (*init) (void),
 void (*fini) (void), void (*rtld_fini) (void), void (* stack_end));

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

static void funcAtExit1( void * unused ) {}

static void prepareAtFork1( void ) {}
static void parentAtFork1 ( void ) {}
static void childAtFork1  ( void ) {}

static int  mainStartMain1     ( int argc, char ** argv, char ** envp ) { return 0; }
static void initStartMain1     ( void                                 ) {           }
static void finiStartMain1     ( void                                 ) {           }
static void rtld_finiStartMain1( void                                 ) {           }

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict _Exit_cmd(TAThread thread,TAInputStream stream)
{
    int status;

    // correct errors in agent.log filling
    ta_debug_printf( "search for _Exit (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    status = readInt( & stream );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);

    writeDeferredReaction( thread, "exit_processTerminated" );
    writeString( thread, "_Exit" );
    sendResponse( thread );

    _Exit( status );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "exitCalledProcess_return" );
    writeString( thread, "_Exit" );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict __cxa_atexit_cmd(TAThread thread,TAInputStream stream)
{
    char * func      ;
    void * arg       ;
    void * dso_handle;
    int    res       ;

    // Prepare
    func       = readString ( & stream );
    arg        = readPointer( & stream );
    dso_handle = readPointer( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    if ( strcmp( func, "funcAtExit1" ) == 0 ) {
        res = __cxa_atexit( funcAtExit1, arg, dso_handle );
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict __libc_start_main_cmd(TAThread thread,TAInputStream stream)
{
    char *  main_func  ;
    int     argc       ;
    int     ubp_av_size;
    char ** ubp_av     ;
    char *  init       ;
    char *  fini       ;
    char *  rtld_fini  ;
    void *  stack_end  ;
    int     res        ;

    // Prepare
    main_func   = readString                  ( & stream           );
    argc        = readInt                     ( & stream           );
    ubp_av_size = readStringNullTerminatedList( & stream, & ubp_av );
    init        = readString                  ( & stream           );
    fini        = readString                  ( & stream           );
    rtld_fini   = readString                  ( & stream           );
    stack_end   = readPointer                 ( & stream           );

    // Execute
    START_TARGET_OPERATION(thread);
    if ( strcmp( main_func, "mainStartMain1" ) == 0 && strcmp( init     , "initStartMain1"      ) == 0 &&
         strcmp( fini     , "finiStartMain1" ) == 0 && strcmp( rtld_fini, "rtld_finiStartMain1" ) == 0
       ) {
        res = __libc_start_main( mainStartMain1, argc, ubp_av,
                                 initStartMain1, finiStartMain1, rtld_finiStartMain1,
                                 stack_end
                               );
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeStringNullTerminatedList( thread, ubp_av_size, ubp_av );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict __register_atfork_cmd(TAThread thread,TAInputStream stream)
{
    char * prepare     ;
    char * parent      ;
    char * child       ;
    void * __dso_handle;
    int    res         ;

    // Prepare
    prepare      = readString ( & stream );
    parent       = readString ( & stream );
    child        = readString ( & stream );
    __dso_handle = readPointer( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    if ( strcmp( prepare, "prepareAtFork1" ) == 0 &&
         strcmp( parent , "parentAtFork1"  ) == 0 &&
         strcmp( child  , "childAtFork1"   ) == 0
       ) {
        res = __register_atfork( prepareAtFork1, parentAtFork1, childAtFork1, __dso_handle );
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict _exit_cmd(TAThread thread,TAInputStream stream)
{
    int status;

    // correct errors in agent.log filling
    ta_debug_printf( "search for _exit (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    status = readInt( & stream );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);

    writeDeferredReaction( thread, "exit_processTerminated" );
    writeString( thread, "_exit" );
    sendResponse( thread );

    _exit( status );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "exitCalledProcess_return" );
    writeString( thread, "_exit" );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict abort_cmd(TAThread thread,TAInputStream stream)
{
    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);

    writeDeferredReaction( thread, "abort_processTerminated" );
    sendResponse( thread );

    abort();
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "abortCalledProcess_return" );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict daemon_cmd(TAThread thread,TAInputStream stream)
{
    int nochdir;
    int noclose;
    int res    ;

    // Prepare
    nochdir = readInt( & stream );
    noclose = readInt( & stream );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = daemon( nochdir, noclose );
    END_TARGET_OPERATION(thread);

    // Response
    if ( res == -1 ) {
        writeDeferredReaction( thread, "fork_return" );
        writeString( thread, "daemon" );
        writeInt( thread, res );
        writeInt( thread, errno );
        sendResponse( thread );
    } else {
        // ta_thread_reinit( thread );
        pthread_t childThread = pthread_self();
        writeDeferredReaction( thread, "forkToChild_return" );
        writeString( thread, "daemon" );
        writeInt( thread, res );
        writeInt( thread, errno );
        writeULong( thread, childThread );
        sendResponse( thread );
        writeDeferredReaction( thread, "fork_return" );
        writeString( thread, "daemon" );
        writeInt( thread, getpid() );
        writeInt( thread, errno );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict execl_cmd(TAThread thread,TAInputStream stream)
{
    char *  path     ;
    int     argv_size;
    char ** argv     ;
    int     res      ;

    int     fictivEnvp_size;
    char ** fictivEnvp     ;

    // correct errors in agent.log filling
    ta_debug_printf( "search for execl (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    path = readString( & stream );
    argv_size = readStringNullTerminatedList( & stream, & argv );
    fictivEnvp_size = readStringNullTerminatedList( & stream, & fictivEnvp );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    switch ( argv_size ) {
        case  0: res = execl( path,                                                        0 );   break;
        case  1: res = execl( path, argv[ 0 ],                                             0 );   break;
        case  2: res = execl( path, argv[ 0 ], argv[ 1 ],                                  0 );   break;
        case  3: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ],                       0 );   break;
        case  4: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ],            0 );   break;
        case  5: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ], 0 );   break;
        case  6: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                    argv[ 5 ],                                             0 );   break;
        case  7: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                    argv[ 5 ], argv[ 6 ],                                  0 );   break;
        case  8: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                    argv[ 5 ], argv[ 6 ], argv[ 7 ],                       0 );   break;
        case  9: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                    argv[ 5 ], argv[ 6 ], argv[ 7 ], argv[ 8 ],            0 );   break;
        case 10: res = execl( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                    argv[ 5 ], argv[ 6 ], argv[ 7 ], argv[ 8 ], argv[ 9 ], 0 );   break;
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "execOldProcess_return" );
    writeInt( thread, res );
    writeString( thread, path );
    writeStringNullTerminatedList( thread, argv_size, argv );
    writeStringNullTerminatedList( thread, fictivEnvp_size, fictivEnvp );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict execle_cmd(TAThread thread,TAInputStream stream)
{
    char *  path     ;
    int     argv_size;
    char ** argv     ;
    int     envp_size;
    char ** envp     ;
    int     res      ;

    // correct errors in agent.log filling
    ta_debug_printf( "search for execle (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    path = readString( & stream );
    argv_size = readStringNullTerminatedList( & stream, & argv );
    envp_size = readStringNullTerminatedList( & stream, & envp );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    switch ( argv_size ) {
        case  0: res = execle( path,                                                        0, envp );   break;
        case  1: res = execle( path, argv[ 0 ],                                             0, envp );   break;
        case  2: res = execle( path, argv[ 0 ], argv[ 1 ],                                  0, envp );   break;
        case  3: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ],                       0, envp );   break;
        case  4: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ],            0, envp );   break;
        case  5: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ], 0, envp );   break;
        case  6: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ],                                             0, envp );   break;
        case  7: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ],                                  0, envp );   break;
        case  8: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ], argv[ 7 ],                       0, envp );   break;
        case  9: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ], argv[ 7 ], argv[ 8 ],            0, envp );   break;
        case 10: res = execle( path, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ], argv[ 7 ], argv[ 8 ], argv[ 9 ], 0, envp );   break;
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "execOldProcess_return" );
    writeInt( thread, res );
    writeString( thread, path );
    writeStringNullTerminatedList( thread, argv_size, argv );
    writeStringNullTerminatedList( thread, envp_size, envp );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict execlp_cmd(TAThread thread,TAInputStream stream)
{
    char *  file     ;
    int     argv_size;
    char ** argv     ;
    int     res      ;

    int     fictivEnvp_size;
    char ** fictivEnvp     ;

    // correct errors in agent.log filling
    ta_debug_printf( "search for execlp (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    file = readString( & stream );
    argv_size = readStringNullTerminatedList( & stream, & argv );
    fictivEnvp_size = readStringNullTerminatedList( & stream, & fictivEnvp );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    switch ( argv_size ) {
        case  0: res = execlp( file,                                                        0 );   break;
        case  1: res = execlp( file, argv[ 0 ],                                             0 );   break;
        case  2: res = execlp( file, argv[ 0 ], argv[ 1 ],                                  0 );   break;
        case  3: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ],                       0 );   break;
        case  4: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ],            0 );   break;
        case  5: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ], 0 );   break;
        case  6: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ],                                             0 );   break;
        case  7: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ],                                  0 );   break;
        case  8: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ], argv[ 7 ],                       0 );   break;
        case  9: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ], argv[ 7 ], argv[ 8 ],            0 );   break;
        case 10: res = execlp( file, argv[ 0 ], argv[ 1 ], argv[ 2 ], argv[ 3 ], argv[ 4 ],
                                     argv[ 5 ], argv[ 6 ], argv[ 7 ], argv[ 8 ], argv[ 9 ], 0 );   break;
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "execOldProcess_return" );
    writeInt( thread, res );
    writeString( thread, file );
    writeStringNullTerminatedList( thread, argv_size, argv );
    writeStringNullTerminatedList( thread, fictivEnvp_size, fictivEnvp );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict execv_cmd(TAThread thread,TAInputStream stream)
{
    char *  path     ;
    int     argv_size;
    char ** argv     ;
    int     res      ;

    int     fictivEnvp_size;
    char ** fictivEnvp     ;

    // correct errors in agent.log filling
    ta_debug_printf( "search for execv (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    path = readString( & stream );
    argv_size = readStringNullTerminatedList( & stream, & argv );
    fictivEnvp_size = readStringNullTerminatedList( & stream, & fictivEnvp );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = execv( path, argv );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "execOldProcess_return" );
    writeInt( thread, res );
    writeString( thread, path );
    writeStringNullTerminatedList( thread, argv_size, argv );
    writeStringNullTerminatedList( thread, fictivEnvp_size, fictivEnvp );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict execve_cmd(TAThread thread,TAInputStream stream)
{
    char *  path     ;
    int     argv_size;
    char ** argv     ;
    int     envp_size;
    char ** envp     ;
    int     res      ;

    // correct errors in agent.log filling
    ta_debug_printf( "search for execve (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    path = readString( & stream );
    argv_size = readStringNullTerminatedList( & stream, & argv );
    envp_size = readStringNullTerminatedList( & stream, & envp );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = execve( path, argv, envp );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "execOldProcess_return" );
    writeInt( thread, res );
    writeString( thread, path );
    writeStringNullTerminatedList( thread, argv_size, argv );
    writeStringNullTerminatedList( thread, envp_size, envp );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict execvp_cmd(TAThread thread,TAInputStream stream)
{
    char *  file     ;
    int     argv_size;
    char ** argv     ;
    int     res      ;

    int     fictivEnvp_size;
    char ** fictivEnvp     ;

    // correct errors in agent.log filling
    ta_debug_printf( "search for execvp (%u)...\n", (unsigned long)pthread_self() );    fflush( stdout );

    // Prepare
    file = readString( & stream );
    argv_size = readStringNullTerminatedList( & stream, & argv );
    fictivEnvp_size = readStringNullTerminatedList( & stream, & fictivEnvp );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = execvp( file, argv );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "execOldProcess_return" );
    writeInt( thread, res );
    writeString( thread, file );
    writeStringNullTerminatedList( thread, argv_size, argv );
    writeStringNullTerminatedList( thread, fictivEnvp_size, fictivEnvp );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict exit_cmd(TAThread thread,TAInputStream stream)
{
    int status;

    // Prepare
    status = readInt( & stream );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);

    writeDeferredReaction( thread, "exit_processTerminated" );
    writeString( thread, "exit" );
    sendResponse( thread );

    exit( status );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "exitCalledProcess_return" );
    writeString( thread, "exit" );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict fork_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    // Prepare
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = fork();
    END_TARGET_OPERATION(thread);

    // Response
    if ( res == 0 ) {
        // ta_thread_reinit( thread );
        pthread_t childThread = pthread_self();
    	usleep(300000);
        writeDeferredReaction( thread, "forkToChild_return" );
        writeString( thread, "fork" );
        writeInt( thread, res );
        writeInt( thread, errno );
        writeULong( thread, childThread );
        sendResponse( thread );
    } else {
        writeDeferredReaction( thread, "fork_return" );
        writeString( thread, "fork" );
        writeInt( thread, res );
        writeInt( thread, errno );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict forkpty_cmd(TAThread thread,TAInputStream stream)
{
    int amaster;
    int res    ;

    // Prepare
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = forkpty( & amaster, NULL, NULL, NULL );
    END_TARGET_OPERATION(thread);

    // Response
    if ( res == 0 ) {
        // ta_thread_reinit( thread );
        pthread_t childThread = pthread_self();
        usleep(300000);
        writeDeferredReaction( thread, "forkToChild_return" );
        writeString( thread, "forkpty" );
        writeInt( thread, res );
        writeInt( thread, errno );
        writeULong( thread, childThread );
        sendResponse( thread );
    } else {
        writeDeferredReaction( thread, "fork_return" );
        writeString( thread, "forkpty" );
        writeInt( thread, res );
        writeInt( thread, errno );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict pclose_cmd(TAThread thread,TAInputStream stream)
{
    FILE * Stream;
    int    res   ;

    // Prepare
    Stream = (FILE *)readPointer( & stream );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = pclose( Stream );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "pclose_return" );
    writeInt( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict popen_cmd(TAThread thread,TAInputStream stream)
{
    char * command;
    char * mode   ;
    FILE * res    ;

    // Prepare
    command = readString( & stream );
    mode    = readString( & stream );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = popen( command, mode );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "popen_return" );
    writePointer( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict return_from_main_cmd(TAThread thread,TAInputStream stream)
{
    int              status   ;
    TACommandVerdict taVerdict;

    // Prepare
    status = readInt( & stream );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    writeDeferredReaction( thread, "exit_processTerminated" );
    writeString( thread, "return_from_main" );
    sendResponse( thread );

    taVerdict.finish = 1;
    taVerdict.status = (void *)status;
    return taVerdict;

    // Response
    writeDeferredReaction( thread, "exitCalledProcess_return" );
    writeString( thread, "return_from_main" );
    sendResponse( thread );
}

static TACommandVerdict system_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    int res;
    const char *command = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = system(command);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict vfork_cmd(TAThread thread,TAInputStream stream)
{
    char * func;
    int    res ;

    // Prepare
    func  = readString( & stream );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    if ( strcmp( func, "_exit" ) == 0 ) {
        pthread_t childThread = 0; // fake
        writeDeferredReaction( thread, "forkToChild_return" );
        writeString( thread, "vfork" );
        writeInt( thread, 0 );
        writeInt( thread, errno );
        writeULong( thread, childThread );
        sendResponse( thread );

        writeDeferredReaction( thread, "exit_processTerminated" );
        writeString( thread, "_exit" );
        sendResponse( thread );

        res = vfork();
        if ( res == 0 ) { _exit( 0 ); }
    } else if ( strcmp( func, "execl" ) == 0 ) {
        pthread_t childThread = 0; // fake
        writeDeferredReaction( thread, "forkToChild_return" );
        writeString( thread, "vfork" );
        writeInt( thread, 0 );
        writeInt( thread, errno );
        writeULong( thread, childThread );
        sendResponse( thread );

        res = vfork();
        if ( res == 0 ) { execl( "./agent", "agent", 0 ); }
    }
    END_TARGET_OPERATION(thread);

    // Response
    if ( strcmp( func, "_exit" ) == 0 ) {
        if ( res == 0 ) {
            writeDeferredReaction( thread, "exitCalledProcess_return" );
            writeString( thread, "_exit" );
            sendResponse( thread );
        } else {
            writeDeferredReaction( thread, "fork_return" );
            writeString( thread, "vfork" );
            writeInt( thread, res );
            writeInt( thread, errno );
            sendResponse( thread );
        }
    } else if ( strcmp( func, "execl" ) == 0 ) {
        if ( res == 0 ) {
            // no reaction from here
        } else {
            writeDeferredReaction( thread, "fork_return" );
            writeString( thread, "vfork" );
            writeInt( thread, res );
            writeInt( thread, errno );
            sendResponse( thread );
        }
    }

    return taDefaultVerdict;
}

static TACommandVerdict wait_cmd(TAThread thread,TAInputStream stream)
{
    int isStatLocNull;
    int stat_loc     ;
    int res          ;

    // Prepare
    isStatLocNull = readInt( & stream );
    stat_loc = 0;
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = wait( isStatLocNull ? NULL : & stat_loc );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "wait_return" );
    writeInt( thread, res                                                          );
    writeInt( thread, errno                                                        );
    writeInt( thread, stat_loc                                                     );
    writeInt( thread,                                WIFEXITED   ( stat_loc )      );
    writeInt( thread, WIFEXITED  ( stat_loc ) != 0 ? WEXITSTATUS ( stat_loc ) : -1 );
    writeInt( thread,                                WIFSIGNALED ( stat_loc )      );
    writeInt( thread, WIFSIGNALED( stat_loc ) != 0 ? WTERMSIG    ( stat_loc ) : -1 );
    writeInt( thread,                                WIFSTOPPED  ( stat_loc )      );
    writeInt( thread, WIFSTOPPED ( stat_loc ) != 0 ? WSTOPSIG    ( stat_loc ) : -1 );
 // writeInt( thread,                                WIFCONTINUED( stat_loc )      );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict wait4_cmd(TAThread thread,TAInputStream stream)
{
    int           pid          ;
    int           isStatLocNull;
    int           stat_loc     ;
    int           options      ;
    int           isRusageNull ;
    struct rusage rusage       ;
    int           res          ;

    // Prepare
    pid           = readInt( & stream );
    isStatLocNull = readInt( & stream );
    options       = readInt( & stream );
    isRusageNull  = readInt( & stream );
    stat_loc = 0;
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = wait4( pid, isStatLocNull ? NULL : & stat_loc, options, isRusageNull ? NULL : & rusage );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "wait_return" );
    writeInt( thread, res                                                          );
    writeInt( thread, errno                                                        );
    writeInt( thread, stat_loc                                                     );
    writeInt( thread,                                WIFEXITED   ( stat_loc )      );
    writeInt( thread, WIFEXITED  ( stat_loc ) != 0 ? WEXITSTATUS ( stat_loc ) : -1 );
    writeInt( thread,                                WIFSIGNALED ( stat_loc )      );
    writeInt( thread, WIFSIGNALED( stat_loc ) != 0 ? WTERMSIG    ( stat_loc ) : -1 );
    writeInt( thread,                                WIFSTOPPED  ( stat_loc )      );
    writeInt( thread, WIFSTOPPED ( stat_loc ) != 0 ? WSTOPSIG    ( stat_loc ) : -1 );
 // writeInt( thread,                                0                             );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict waitpid_cmd(TAThread thread,TAInputStream stream)
{
    int pid          ;
    int isStatLocNull;
    int stat_loc     ;
    int options      ;
    int res          ;

    // Prepare
    pid           = readInt( & stream );
    isStatLocNull = readInt( & stream );
    options       = readInt( & stream );
    stat_loc = 0;
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = waitpid( pid, isStatLocNull ? NULL : & stat_loc, options );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "wait_return" );
    writeInt( thread, res                                                          );
    writeInt( thread, errno                                                        );
    writeInt( thread, stat_loc                                                     );
    writeInt( thread,                                WIFEXITED   ( stat_loc )      );
    writeInt( thread, WIFEXITED  ( stat_loc ) != 0 ? WEXITSTATUS ( stat_loc ) : -1 );
    writeInt( thread,                                WIFSIGNALED ( stat_loc )      );
    writeInt( thread, WIFSIGNALED( stat_loc ) != 0 ? WTERMSIG    ( stat_loc ) : -1 );
    writeInt( thread,                                WIFSTOPPED  ( stat_loc )      );
    writeInt( thread, WIFSTOPPED ( stat_loc ) != 0 ? WSTOPSIG    ( stat_loc ) : -1 );
 // writeInt( thread,                                WIFCONTINUED( stat_loc )      );
    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_process_commands(void)
{
    ta_register_command( "_Exit"            , _Exit_cmd             );
    ta_register_command( "__cxa_atexit"     , __cxa_atexit_cmd      );
    ta_register_command( "__libc_start_main", __libc_start_main_cmd );
    ta_register_command( "__register_atfork", __register_atfork_cmd );
    ta_register_command( "_exit"            , _exit_cmd             );
    ta_register_command( "abort"            , abort_cmd             );
    ta_register_command( "daemon"           , daemon_cmd            );
    ta_register_command( "execl"            , execl_cmd             );
    ta_register_command( "execle"           , execle_cmd            );
    ta_register_command( "execlp"           , execlp_cmd            );
    ta_register_command( "execv"            , execv_cmd             );
    ta_register_command( "execve"           , execve_cmd            );
    ta_register_command( "execvp"           , execvp_cmd            );
    ta_register_command( "exit"             , exit_cmd              );
    ta_register_command( "fork"             , fork_cmd              );
    ta_register_command( "forkpty"          , forkpty_cmd           );
    ta_register_command( "pclose"           , pclose_cmd            );
    ta_register_command( "popen"            , popen_cmd             );
    ta_register_command( "return_from_main" , return_from_main_cmd  );
    ta_register_command("system",system_cmd);
    ta_register_command( "vfork"            , vfork_cmd             );
    ta_register_command( "wait"             , wait_cmd              );
    ta_register_command( "wait4"            , wait4_cmd             );
    ta_register_command( "waitpid"          , waitpid_cmd           );
}

