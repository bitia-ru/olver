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
#include <time.h>
#include "time/conversion/conversion_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict asctime_cmd(TAThread thread,TAInputStream stream)
{
    struct tm   time;
    char      * res ;

    // Prepare
    readTm( & stream, & time );

    // Execute
    START_TARGET_OPERATION(thread);
    res = asctime( & time );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res == NULL );
    if ( res != NULL ) { writeString( thread, res ); }
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict asctime_r_cmd(TAThread thread,TAInputStream stream)
{
    struct tm   time;
    char      * buf ;
    char      * res ;

    // Prepare
    readTm( & stream, & time );
    buf = readString( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    res = asctime_r( & time, buf );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res == NULL );
    if ( res != NULL ) { writeString( thread, res ); }
    writeString( thread, buf );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict ctime_cmd(TAThread thread,TAInputStream stream)
{
    time_t   clock;
    char   * res  ;

    // Prepare
    clock = readLong( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    res = ctime( & clock );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res == NULL );
    if ( res != NULL ) { writeString( thread, res ); }
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict ctime_r_cmd(TAThread thread,TAInputStream stream)
{
    time_t   clock;
    char   * buf  ;
    char   * res  ;

    // Prepare
    clock = readLong   ( & stream );
    buf   = readString( & stream );

    // Execute
    START_TARGET_OPERATION(thread);
    res = ctime_r( & clock, buf );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res == NULL );
    if ( res != NULL ) { writeString( thread, res ); }
    writeString( thread, buf );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict gmtime_cmd(TAThread thread,TAInputStream stream)
{
    time_t      timer;
    struct tm * res  ;

    // Prepare
    timer = readLong( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = gmtime( & timer );
    END_TARGET_OPERATION(thread);

    ta_debug_printf("gmtime_param: %d, res: %d", timer, res->tm_sec);

    // Response
    writeTm ( thread, res   );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict gmtime_r_cmd(TAThread thread,TAInputStream stream)
{
    time_t      timer ;
    struct tm   result;
    struct tm * res   ;

    // Prepare
    timer = readLong( & stream );
    readTm( & stream, & result );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = gmtime_r( & timer, & result );
    END_TARGET_OPERATION(thread);

    // Response
    writeTm ( thread, res      );
    writeTm ( thread, & result );
    writeInt( thread, errno    );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict localtime_cmd(TAThread thread,TAInputStream stream)
{
    time_t      timer;
    struct tm * res  ;

    // Prepare
    timer = readLong( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = localtime( & timer );
    END_TARGET_OPERATION(thread);

    // Response
    writeTm ( thread, res   );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict localtime_r_cmd(TAThread thread,TAInputStream stream)
{
    time_t      timer ;
    struct tm   result;
    struct tm * res   ;

    // Prepare
    timer = readLong( & stream );
    readTm( & stream, & result );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = localtime_r( & timer, & result );
    END_TARGET_OPERATION(thread);

    // Response
    writeTm ( thread, res      );
    writeTm ( thread, & result );
    writeInt( thread, errno    );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict mktime_cmd(TAThread thread,TAInputStream stream)
{
    struct tm time;
    time_t    res ;

    // Prepare
    readTm( & stream, & time );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = mktime( & time );
    END_TARGET_OPERATION(thread);

    // Response
    writeLong( thread, res   );
    writeTm ( thread, &time      );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_time_conversion_commands(void)
{
    ta_register_command( "asctime"    , asctime_cmd     );
    ta_register_command( "asctime_r"  , asctime_r_cmd   );
    ta_register_command( "ctime"      , ctime_cmd       );
    ta_register_command( "ctime_r"    , ctime_r_cmd     );
    ta_register_command( "gmtime"     , gmtime_cmd      );
    ta_register_command( "gmtime_r"   , gmtime_r_cmd    );
    ta_register_command( "localtime"  , localtime_cmd   );
    ta_register_command( "localtime_r", localtime_r_cmd );
    ta_register_command( "mktime"     , mktime_cmd      );
}
