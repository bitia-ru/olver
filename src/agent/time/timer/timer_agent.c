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
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include "time/timer/timer_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

// static void catcherForSigAlrm( int unused ) { ta_debug_printf( "catcherForSigAlrm :               time is %d\n", time( NULL ) ); }
static void catcherForSignal( int unused ) {}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict alarm_cmd(TAThread thread,TAInputStream stream)
{
    unsigned int seconds;
    unsigned int res    ;

    // struct timespec * t;

    // Prepare
    seconds = readUInt( & stream );
    sigset( SIGALRM, catcherForSignal );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    // ta_debug_printf( "alarm_cmd : seconds is %d\n", seconds );
    // clock_gettime( CLOCK_REALTIME, t );
    // ta_debug_printf( "alarm_cmd : before alarm       , time is [%ld|%ld]\n", t->tv_sec, t->tv_nsec );
    res = alarm( seconds );
    if ( seconds != 0 ) { sighold( SIGALRM ); sigpause( SIGALRM ); sigrelse( SIGALRM ); }
    // clock_gettime( CLOCK_REALTIME, t );
    // ta_debug_printf( "alarm_cmd : after  alarm       , time is [%ld|%ld]\n", t->tv_sec, t->tv_nsec );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "signal_receive" );
    writeString( thread, "alarm" );
    writeInt   ( thread, res     );
    sendResponse( thread );
    // clock_gettime( CLOCK_REALTIME, t );
    // ta_debug_printf( "alarm_cmd : after  alarm       , time is [%ld|%ld]\n", t->tv_sec, t->tv_nsec );

    return taDefaultVerdict;
}

static TACommandVerdict getitimer_cmd(TAThread thread,TAInputStream stream)
{
    int              which;
    int              res  ;
    struct itimerval value;

    // Prepare
    which = readInt( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = getitimer( which, & value );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt      ( thread, res     );
    writeITimerVal( thread, & value );
    writeInt      ( thread, errno   );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict nanosleep_cmd(TAThread thread,TAInputStream stream)
{
    struct timespec rqtp      ;
    int             rmtpIsNull;
    struct timespec rmtp      ;
    int             res       ;

    // Prepare
    rqtp.tv_sec  = readInt( & stream );
    rqtp.tv_nsec = readInt( & stream );
    if ( ( rmtpIsNull = readInt( & stream ) ) == 0 ) {
        rmtp.tv_sec  = readInt( & stream );
        rmtp.tv_nsec = readInt( & stream );
    }
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = nanosleep( & rqtp, rmtpIsNull != 0 ? NULL : & rmtp );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "sleep_return" );
    writeString( thread, "nanosleep" );
    writeInt   ( thread, res         );
    writeInt   ( thread, rmtpIsNull  );
    if ( rmtpIsNull == 0 ) {
        writeInt( thread, rmtp.tv_sec  );
        writeInt( thread, rmtp.tv_nsec );
    }
    writeInt   ( thread, errno       );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict setitimer_cmd(TAThread thread,TAInputStream stream)
{
    int              which       ;
    struct itimerval value       ;
    int              ovalueIsNull;
    struct itimerval ovalue      ;
    int              res         ;

    // Prepare
    which = readInt( & stream );
    readITimerVal( & stream, & value );
    ovalueIsNull = readInt( & stream );
    errno = 0;
    switch ( which ) {
        case ITIMER_REAL   : sigset( SIGALRM  , catcherForSignal ); break;
        case ITIMER_VIRTUAL: sigset( SIGVTALRM, catcherForSignal ); break;
        case ITIMER_PROF   : sigset( SIGPROF  , catcherForSignal ); break;
        default            :                                        break;
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = setitimer( which, & value, ovalueIsNull != 0 ? NULL : & ovalue );
    if ( ( which == ITIMER_REAL || which == ITIMER_VIRTUAL || which == ITIMER_PROF ) &&
         ( value.it_value.tv_sec != 0 || value.it_value.tv_usec != 0               )
       ) {
        switch ( which ) {
            case ITIMER_REAL   : sighold( SIGALRM   ); sigpause( SIGALRM   ); sigrelse( SIGALRM   ); break;
            case ITIMER_VIRTUAL: sighold( SIGVTALRM ); sigpause( SIGVTALRM ); sigrelse( SIGVTALRM ); break;
            case ITIMER_PROF   : sighold( SIGPROF   ); sigpause( SIGPROF   ); sigrelse( SIGPROF   ); break;
        }
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "signal_receive" );
    writeString   ( thread, "setitimer"      );
    writeInt      ( thread, res              );
    writeString   ( thread, "value.it_value" );
    writeITimerVal( thread, & ovalue         );
    writeInt      ( thread, errno            );
    sendResponse( thread );
    if ( ( which == ITIMER_REAL || which == ITIMER_VIRTUAL || which == ITIMER_PROF ) &&
         ( value.it_value   .tv_sec != 0 || value.it_value   .tv_usec != 0         ) &&
         ( value.it_interval.tv_sec != 0 || value.it_interval.tv_usec != 0         )
       ) {
        switch ( which ) {
            case ITIMER_REAL   : sighold( SIGALRM   ); sigpause( SIGALRM   ); sigrelse( SIGALRM   ); break;
            case ITIMER_VIRTUAL: sighold( SIGVTALRM ); sigpause( SIGVTALRM ); sigrelse( SIGVTALRM ); break;
            case ITIMER_PROF   : sighold( SIGPROF   ); sigpause( SIGPROF   ); sigrelse( SIGPROF   ); break;
        }
        END_TARGET_OPERATION(thread);
        writeDeferredReaction( thread, "signal_receive" );
        writeString   ( thread, "setitimer"         );
        writeInt      ( thread, res                 );
        writeString   ( thread, "value.it_interval" );
        writeITimerVal( thread, & ovalue            );
        writeInt      ( thread, errno               );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict sleep_cmd(TAThread thread,TAInputStream stream)
{
    unsigned int seconds;
    unsigned int res    ;

    // Prepare
    seconds = readUInt( & stream );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = sleep( seconds );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "sleep_return" );
    writeString( thread, "sleep" );
    writeInt   ( thread, res     );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict timer_create_cmd(TAThread thread,TAInputStream stream)
{
    clockid_t       clockid  ;
    int             evpIsNull;
    struct sigevent evp      ;
    int             res      ;
    timer_t         timerid  ;

    // Prepare
    clockid = readInt( & stream );
    if ( ( evpIsNull = readInt( & stream ) ) != 0 ) {
        readInt( & stream );
    } else {
        memset(&evp, 0, sizeof(struct sigevent));
        evp.sigev_notify = SIGEV_SIGNAL       ;
        evp.sigev_signo  = readInt( & stream );
    }
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = timer_create( clockid, evpIsNull != 0 ? NULL : & evp, & timerid );
    END_TARGET_OPERATION(thread);

    ta_debug_printf("timer_create: %d, %d\n", timerid, (int)sizeof(timerid));
    
    // Response
    writeInt( thread, res     );
    writePointer( thread, timerid );
    writeInt( thread, errno   );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict timer_delete_cmd(TAThread thread,TAInputStream stream)
{
    timer_t timerid;
    int     res    ;

    // Prepare
    timerid = readPointer( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    // ta_debug_printf( "timer_delete_cmd : before timer_delete, timerid is %d\n", timerid );
    res = timer_delete( timerid );
    // ta_debug_printf( "timer_delete_cmd : after  timer_delete, res is %d\n", res );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res   );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict timer_getoverrun_cmd(TAThread thread,TAInputStream stream)
{
    timer_t timerid;
    int     res    ;

    // Prepare
    timerid = readPointer( & stream );
    errno = 0;

    ta_debug_printf("timer_getoverrun: %d, %d\n", timerid, (int)sizeof(timerid));

    // Execute
    START_TARGET_OPERATION(thread);
    res = timer_getoverrun( timerid );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res   );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict timer_gettime_cmd(TAThread thread,TAInputStream stream)
{
    timer_t timerid         ;
    int     res             ;
    struct  itimerspec value;

    // Prepare
    timerid = readPointer( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = timer_gettime( timerid, & value );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt       ( thread, res     );
    writeITimerSpec( thread, & value );
    writeInt       ( thread, errno   );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict timer_settime_cmd(TAThread thread,TAInputStream stream)
{
    timer_t            timerid     ;
    int                flags       ;
    struct  itimerspec value       ;
    int                ovalueIsNull;
    struct  itimerspec ovalue      ;
    int                signal      ;
    int                res         ;

    // Prepare
    timerid = readPointer( & stream );
    flags = readInt( & stream );
    readITimerSpec( & stream, & value );
    ovalueIsNull = readInt( & stream );
    signal = readInt( & stream );
    errno = 0;
    sigset( signal, catcherForSignal );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = timer_settime( timerid, flags, & value, ovalueIsNull != 0 ? NULL : & ovalue );
    if ( value.it_value.tv_sec != 0 || value.it_value.tv_nsec != 0 ) {
        sighold( signal ); sigpause( signal ); sigrelse( signal );
    }
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "signal_receive" );
    writeString    ( thread, "timer_settime"  );
    writeInt       ( thread, res              );
    writeString    ( thread, "value.it_value" );
    writeITimerSpec( thread, & ovalue         );
    writeInt       ( thread, errno            );
    sendResponse( thread );
    if ( ( value.it_value   .tv_sec != 0 || value.it_value   .tv_nsec != 0 ) &&
         ( value.it_interval.tv_sec != 0 || value.it_interval.tv_nsec != 0 )
       ) {
        sighold( signal ); sigpause( signal ); sigrelse( signal );
        END_TARGET_OPERATION(thread);
        writeDeferredReaction( thread, "signal_receive" );
        writeString    ( thread, "timer_settime"     );
        writeInt       ( thread, res                 );
        writeString    ( thread, "value.it_interval" );
        writeITimerSpec( thread, & ovalue            );
        writeInt       ( thread, errno               );
        sendResponse( thread );
    }

    return taDefaultVerdict;
}

static TACommandVerdict ualarm_cmd(TAThread thread,TAInputStream stream)
{
    useconds_t useconds;
    useconds_t interval;
    useconds_t res     ;

    // Prepare
    useconds = readUInt( & stream );
    interval = readUInt( & stream );
    // ta_debug_printf( "ualarm_cmd : sigset( SIGALRM, catcherForSignal ) is %d\n", sigset( SIGALRM, catcherForSignal ) );
    sigset( SIGALRM, catcherForSignal );

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    // ta_debug_printf( "ualarm_cmd : useconds is %d\n", useconds );
    // ta_debug_printf( "ualarm_cmd : interval is %d\n", interval );
    // ta_debug_printf( "ualarm_cmd : before ualarm      , time is %d\n", time( NULL ) );
    res = ualarm( useconds, interval );
    if ( useconds != 0 ) {
        // ta_debug_printf( "ualarm_cmd : sighold( SIGALRM )                  is %d\n", sighold( SIGALRM )                  );
        // ta_debug_printf( "ualarm_cmd :     sigpause( SIGALRM )             is %d\n",     sigpause( SIGALRM )             );
        // ta_debug_printf( "ualarm_cmd : sigrelse( SIGALRM )                 is %d\n", sigrelse( SIGALRM )                 );
        sighold( SIGALRM ); sigpause( SIGALRM ); sigrelse( SIGALRM );
    }
    // ta_debug_printf( "ualarm_cmd : after  ualarm      , time is %d\n", time( NULL ) );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "signal_receive" );
    writeString( thread, "ualarm"   );
    writeInt   ( thread, res        );
    writeString( thread, "useconds" );
    sendResponse( thread );
    // ta_debug_printf( "ualarm_cmd : after  sendResponse, time is %d\n", time( NULL ) );
    if ( useconds != 0 && interval != 0 ) {
        // catch only first interval
        // ta_debug_printf( "ualarm_cmd : sighold( SIGALRM )                  is %d\n", sighold( SIGALRM )                  );
        // ta_debug_printf( "ualarm_cmd :     sigpause( SIGALRM )             is %d\n",     sigpause( SIGALRM )             );
        // ta_debug_printf( "ualarm_cmd : sigrelse( SIGALRM )                 is %d\n", sigrelse( SIGALRM )                 );
        sighold( SIGALRM ); sigpause( SIGALRM ); sigrelse( SIGALRM );
        END_TARGET_OPERATION(thread);
        writeDeferredReaction( thread, "signal_receive" );
        writeString( thread, "ualarm"   );
        writeInt   ( thread, res        );
        writeString( thread, "interval" );
        sendResponse( thread );
        // ta_debug_printf( "ualarm_cmd : after  sendResponse, time is %d\n", time( NULL ) );
    }

    return taDefaultVerdict;
}

static TACommandVerdict usleep_cmd(TAThread thread,TAInputStream stream)
{
    useconds_t useconds;
    useconds_t res     ;

    // Prepare
    useconds = readUInt( & stream );
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = usleep( useconds );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "sleep_return" );
    writeString( thread, "usleep" );
    writeInt   ( thread, res      );
    writeInt   ( thread, errno    );
    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_time_timer_commands(void)
{
    ta_register_command( "alarm"           , alarm_cmd            );
    ta_register_command( "getitimer"       , getitimer_cmd        );
    ta_register_command( "nanosleep"       , nanosleep_cmd        );
    ta_register_command( "setitimer"       , setitimer_cmd        );
    ta_register_command( "sleep"           , sleep_cmd            );
    ta_register_command( "timer_create"    , timer_create_cmd     );
    ta_register_command( "timer_delete"    , timer_delete_cmd     );
    ta_register_command( "timer_getoverrun", timer_getoverrun_cmd );
    ta_register_command( "timer_gettime"   , timer_gettime_cmd    );
    ta_register_command( "timer_settime"   , timer_settime_cmd    );
    ta_register_command( "ualarm"          , ualarm_cmd           );
    ta_register_command( "usleep"          , usleep_cmd           );
}
