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

#define _SVID_SOURCE

extern int daylight;
extern long timezone;
extern char *tzname[2];

#include <errno.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include "time/time/time_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict adjtime_cmd(TAThread thread,TAInputStream stream)
{
    struct timeval delta         ;
    int            olddeltaIsNull;
    struct timeval olddelta      ;
    int            res           ;

    // Prepare
    readTimeVal( & stream, & delta );
    olddeltaIsNull = readInt( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = adjtime( & delta, olddeltaIsNull ? NULL : & olddelta );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    if ( ! olddeltaIsNull ) { writeTimeVal( thread, & olddelta ); }
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict difftime_cmd(TAThread thread,TAInputStream stream)
{
    time_t    time1;
    time_t    time0;
    // double res  ;
    int    res  ;

    // Prepare
    time1 = readLong( & stream );
    time0 = readLong( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    res = difftime( time1, time0 );
    END_TARGET_OPERATION(thread);

    // Response
    // writeDouble( thread, res );
    writeInt( thread, res );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict ftime_cmd(TAThread thread,TAInputStream stream)
{
    struct timeb tp ;
    int          res;

    // Execute
    START_TARGET_OPERATION(thread);
    res = ftime( & tp );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res        );
    writeInt( thread, tp.time    );
    writeInt( thread, tp.millitm );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict gettimeofday_cmd(TAThread thread,TAInputStream stream)
{
    struct timeval tp ;
    int            res;

    // Execute
    START_TARGET_OPERATION(thread);
    res = gettimeofday( & tp, NULL );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt    ( thread, res  );
    writeTimeVal( thread, & tp );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict stime_cmd(TAThread thread,TAInputStream stream)
{
    int    tIsNull;
    time_t t      ;
    int    res    ;

    // Prepare
    tIsNull = readInt( & stream );
    if ( ! tIsNull ) { t = readLong( & stream ); }
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = stime( tIsNull ? NULL : & t );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res   );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict time_cmd(TAThread thread,TAInputStream stream)
{
    int    tlocIsNull;
    time_t tloc      ;
    time_t res       ;

    // Prepare
    tlocIsNull = readInt( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    res = time( tlocIsNull ? NULL : & tloc );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    if ( ! tlocIsNull ) { writeInt( thread, tloc ); }
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict tzset_cmd(TAThread thread,TAInputStream stream)
{
    // Execute
    START_TARGET_OPERATION(thread);
    tzset();
    END_TARGET_OPERATION(thread);

    // Response
    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_time_time_commands(void)
{
    ta_register_command( "adjtime"     , adjtime_cmd      );
    ta_register_command( "difftime"    , difftime_cmd     );
    ta_register_command( "ftime"       , ftime_cmd        );
    ta_register_command( "gettimeofday", gettimeofday_cmd );
    ta_register_command( "stime"       , stime_cmd        );
    ta_register_command( "time"        , time_cmd         );
    ta_register_command( "tzset"       , tzset_cmd        );
}
