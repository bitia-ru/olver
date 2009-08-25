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


#include "util/format/time_agent.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

/********************************************************************/
/**            Data Types Readers And Writers                      **/
/********************************************************************/

void readTimeTm(TAInputStream* stream, struct tm* tmval)
{
    
    verifyType_TAInputStream(stream, "tm");
    
    tmval->tm_sec = readInt(stream);
    tmval->tm_min = readInt(stream);
    tmval->tm_hour = readInt(stream);
    tmval->tm_mday = readInt(stream);
    tmval->tm_mon = readInt(stream);
    tmval->tm_year = readInt(stream);
    tmval->tm_wday = readInt(stream);
    tmval->tm_yday = readInt(stream);
    tmval->tm_isdst = readInt(stream);
    tmval->tm_gmtoff = readLong(stream);
    tmval->tm_zone = readString(stream);
}


void writeTimeTm(TAThread thread, struct tm* tmval)
{
    writeInt(thread, tmval->tm_sec);
    writeInt(thread, tmval->tm_min);
    writeInt(thread, tmval->tm_hour);
    writeInt(thread, tmval->tm_mday);
    writeInt(thread, tmval->tm_mon);
    writeInt(thread, tmval->tm_year);
    writeInt(thread, tmval->tm_wday);
    writeInt(thread, tmval->tm_yday);
    writeInt(thread, tmval->tm_isdst);
    writeLong(thread, tmval->tm_gmtoff);
    writeString(thread, tmval->tm_zone);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getdate_cmd(TAThread thread,TAInputStream stream)
{
    struct tm * res;
    char *str;


    // Prepare
    str = readString(&stream);

    getdate_err = 0;
    
    START_TARGET_OPERATION(thread);
    res = getdate(str); 
    END_TARGET_OPERATION(thread);


    // Response
    writeInt(thread, res != NULL);
    if(res != NULL)
    {
        writeTimeTm(thread, res);
    }
    writeString(thread, str);
    writeInt(thread, getdate_err);
    
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict strftime_cmd(TAThread thread,TAInputStream stream)
{
    size_t     res;
    char      *s;
    size_t     maxsize;
    char      *format;
    struct tm  time;


    // Prepare
    s = readString(&stream);
    maxsize = readSize(&stream);
    format = readString(&stream);
    readTimeTm(&stream, &time);
    
    START_TARGET_OPERATION(thread);
    res = strftime(s, maxsize, format, &time);
    END_TARGET_OPERATION(thread);
    

    // Response
    writeSize(thread, res);
    writeString(thread, s);
    writeString(thread, format);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict strptime_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    char* buf;
    char* format;
    struct tm time;

    // Prepare
    buf = readString(&stream);
    format = readString(&stream);
    readTimeTm(&stream, &time);

    START_TARGET_OPERATION(thread);
    res = strptime(buf, format, &time); 
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res != NULL);
    if(res != NULL)
    {
        writeString(thread, res);
    }
    writeTimeTm(thread, &time);
    writeString(thread, buf);
    writeString(thread, format);

    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_format_time_commands(void)
{
    ta_register_command("getdate",getdate_cmd);
    ta_register_command("strftime",strftime_cmd);
    ta_register_command("strptime",strptime_cmd);
}

