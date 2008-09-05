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

#include "process/meta/fs_agent.h"
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict chdir_cmd(TAThread thread,TAInputStream stream)
{
    char * path;
    int    res ;

    // Prepare
    path = readString( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = chdir( path );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict chroot_cmd(TAThread thread,TAInputStream stream)
{
    char * path;
    int    res ;

    // Prepare
    path = readString( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = chroot( path );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict fchdir_cmd(TAThread thread,TAInputStream stream)
{
    int fildes;
    int res   ;

    // Prepare
    fildes = readInt( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = fchdir( fildes );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict getcwd_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    char *res;
    char *buf = readPointer(&stream);
    size_t size = readSize(&stream);

    errno = 0;

    START_TARGET_OPERATION(thread);

    // Execute
    res = getcwd(buf, size);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getwd_cmd(TAThread thread,TAInputStream stream)
{
    char * path_name;
    char * res      ;

    // Prepare
    path_name = readPointer( & stream );
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = getwd( path_name );
    END_TARGET_OPERATION(thread);

    // Response
    writePointer( thread, res );
    writeInt( thread, errno );
    sendResponse( thread );

    return taDefaultVerdict;
}

static TACommandVerdict umask_cmd(TAThread thread,TAInputStream stream)
{
    int cmask;
    int res;

    // Prepare
    cmask = 0;

    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IRUSR; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IWUSR; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IXUSR; }

    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IRGRP; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IWGRP; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IXGRP; }

    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IROTH; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IWOTH; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_IXOTH; }

    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_ISUID; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_ISGID; }
    if ( readInt( & stream ) != 0 ) { cmask = cmask | S_ISVTX; }

    // Execute
    START_TARGET_OPERATION(thread);
    res = umask( cmask );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res & S_IRUSR );
    writeInt( thread, res & S_IWUSR );
    writeInt( thread, res & S_IXUSR );

    writeInt( thread, res & S_IRGRP );
    writeInt( thread, res & S_IWGRP );
    writeInt( thread, res & S_IXGRP );

    writeInt( thread, res & S_IROTH );
    writeInt( thread, res & S_IWOTH );
    writeInt( thread, res & S_IXOTH );

    writeInt( thread, res & S_ISUID );
    writeInt( thread, res & S_ISGID );
    writeInt( thread, res & S_ISVTX );

    sendResponse( thread );

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_meta_fs_commands(void)
{
    ta_register_command( "chdir" , chdir_cmd  );
    ta_register_command( "chroot", chroot_cmd );
    ta_register_command( "fchdir", fchdir_cmd );
    ta_register_command( "getcwd", getcwd_cmd );
    ta_register_command( "getwd" , getwd_cmd  );
    ta_register_command( "umask" , umask_cmd  );
}
