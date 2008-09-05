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


#include "system/sysconf/sysconf_agent.h"
#include <unistd.h>
#include <errno.h>

/*
 * These function declarations represents binary interface definition of
 *   Linux Standard Base Core Specification 3.1
 *   Copyright (c) 2004, 2005 Free Standards Group
 *
 *   See section 'Interface Definitions for libc'.
 */
long __sysconf(int name);
int __getpagesize(void);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict sysconf_cmd(TAThread thread,TAInputStream stream)
{
    int name;
    long res;

    /* Prepare */
    name = readInt(&stream);

    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    /* Execute */
    res = sysconf(name);

    END_TARGET_OPERATION(thread);

    /* Response */
    writeLong(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __sysconf_cmd(TAThread thread,TAInputStream stream)
{
    int name;
    long res;

    /* Prepare */
    name = readInt(&stream);

    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    /* Execute */
    res = __sysconf(name);

    END_TARGET_OPERATION(thread);

    /* Response */
    writeLong(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict confstr_cmd(TAThread thread,TAInputStream stream)
{
    int name;
    size_t res;
    char * buf;
    size_t len;

    /* Prepare */
    name = readInt(&stream);
    buf = (char*)readPointer(&stream);
    len = readSize(&stream);

    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    /* Execute */
    res = confstr(name,buf,len);

    END_TARGET_OPERATION(thread);

    /* Response */
    writeSize(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getpagesize_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = getpagesize();

    END_TARGET_OPERATION(thread);

    /* Response */
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __getpagesize_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    res = __getpagesize();

    END_TARGET_OPERATION(thread);

    /* Response */
    writeInt(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pathconf_cmd(TAThread thread,TAInputStream stream)
{
    int name;
    char* path;
    long res;

    /* Prepare */
    path = readString(&stream);
    name = readInt(&stream);

    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    /* Execute */
    res = pathconf(path,name);

    END_TARGET_OPERATION(thread);

    /* Response */
    writeLong(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fpathconf_cmd(TAThread thread,TAInputStream stream)
{
    int name;
    int fildes;
    long res;

    /* Prepare */
    fildes = readInt(&stream);
    name = readInt(&stream);

    /* [ Set errno ] */
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    /* Execute */
    res = fpathconf(fildes,name);

    END_TARGET_OPERATION(thread);

    /* Response */
    writeLong(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_system_sysconf_commands(void)
{
      ta_register_command("sysconf",sysconf_cmd);
      ta_register_command("__sysconf",__sysconf_cmd);
      ta_register_command("confstr",confstr_cmd);
      ta_register_command("getpagesize",getpagesize_cmd);
      ta_register_command("__getpagesize",__getpagesize_cmd);
      ta_register_command("pathconf",pathconf_cmd);
      ta_register_command("fpathconf",fpathconf_cmd);
}

