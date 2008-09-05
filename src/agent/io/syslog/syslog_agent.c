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


#include "io/syslog/syslog_agent.h"
#include <syslog.h>
#include <stdio.h>
#include <stdarg.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict closelog_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    // No arguments to read

    START_TARGET_OPERATION(thread);

    // Execute
    closelog();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict openlog_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    const char* ident = readString(&stream);
    int logopt = readInt(&stream);
    int facility = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    openlog(ident, logopt, facility);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict setlogmask_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    int maskpri = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    
    res = setlogmask(maskpri);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict syslog_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int priority = readInt(&stream);
    const char* message = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    syslog(priority, message);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

void vsyslog_aux(int pri, char* msg, ...)
{
    va_list list;

    va_start(list, msg);

    vsyslog(pri, msg, list);

    va_end(list);
}

static TACommandVerdict vsyslog_cmd(TAThread thread, TAInputStream stream)
{
    int priority = readInt(&stream);
    char* message = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    vsyslog_aux(priority, message);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_io_syslog_commands(void)
{
    ta_register_command("closelog", closelog_cmd);
    ta_register_command("openlog", openlog_cmd);
    ta_register_command("setlogmask", setlogmask_cmd);
    ta_register_command("syslog", syslog_cmd);
    ta_register_command("vsyslog", vsyslog_cmd);
}
