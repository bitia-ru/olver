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

#include <time.h>
#include <errno.h>
#include "time/clock/clock_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict clock_getcpuclockid_cmd(TAThread thread,TAInputStream stream)
{
    int       pid     ;
    int       res     ;
    clockid_t clock_id;

    // Prepare
    pid = readInt( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    res = clock_getcpuclockid( pid, & clock_id );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeInt( thread, clock_id );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict clock_getres_cmd(TAThread thread,TAInputStream stream)
{
    clockid_t       clock_id ;
    int             result   ;
    int             resIsNull;
    struct timespec res      ;

    // Prepare
    clock_id  = readInt( & stream );
    resIsNull = readInt( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    result = clock_getres( clock_id, resIsNull != 0 ? NULL : & res );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, result );
    if ( resIsNull == 0 ) {
        writeInt( thread, res.tv_sec  );
        writeInt( thread, res.tv_nsec );
    }
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict clock_gettime_cmd(TAThread thread,TAInputStream stream)
{
    clockid_t       clock_id;
    int             res     ;
    struct timespec tp      ;

    // Prepare
    clock_id = readInt( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = clock_gettime( clock_id, & tp );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeInt( thread, tp.tv_sec  );
    writeInt( thread, tp.tv_nsec );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict clock_nanosleep_cmd(TAThread thread,TAInputStream stream)
{
    clockid_t       clock_id  ;
    int             flags     ;
    struct timespec rqtp      ;
    int             rmtpIsNull;
    struct timespec rmtp      ;
    int             res       ;

    // Prepare
    clock_id     = readInt( & stream );
    flags        = readInt( & stream );
    rqtp.tv_sec  = readInt( & stream );
    rqtp.tv_nsec = readInt( & stream );
    if ( ( rmtpIsNull = readInt( & stream ) ) == 0 ) {
        rmtp.tv_sec  = readInt( & stream );
        rmtp.tv_nsec = readInt( & stream );
    }

    BEFORE_BLOCKED_TARGET_OPERATION(thread);

    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    res = clock_nanosleep( clock_id, flags, & rqtp, rmtpIsNull != 0 ? NULL : & rmtp );
    END_TARGET_OPERATION(thread);

    // Response
    writeDeferredReaction( thread, "sleep_return" );
    writeString( thread, "clock_nanosleep" );
    writeInt( thread, res );
    writeInt( thread, rmtpIsNull );
    if ( rmtpIsNull == 0 ) {
        writeInt( thread, rmtp.tv_sec  );
        writeInt( thread, rmtp.tv_nsec );
    }
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict clock_settime_cmd(TAThread thread,TAInputStream stream)
{
    clockid_t       clock_id;
    struct timespec tp      ;
    int             res     ;

    // Prepare
    clock_id   = readInt( & stream );
    tp.tv_sec  = readInt( & stream );
    tp.tv_nsec = readInt( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = clock_settime( clock_id, & tp );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_time_clock_commands(void)
{
    ta_register_command( "clock_getcpuclockid", clock_getcpuclockid_cmd );
    ta_register_command( "clock_getres"       , clock_getres_cmd        );
    ta_register_command( "clock_gettime"      , clock_gettime_cmd       );
    ta_register_command( "clock_nanosleep"    , clock_nanosleep_cmd     );
    ta_register_command( "clock_settime"      , clock_settime_cmd       );
}
