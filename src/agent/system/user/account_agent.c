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


#include "system/user/account_agent.h"
#include <utmp.h>
#include <utmpx.h>
#include <string.h>
#include <errno.h>

/********************************************************************/
/**                        Helper Functions                        **/
/********************************************************************/

static TACommandVerdict write_utmp_cmd(TAThread thread,TAInputStream stream)
{
    struct utmp * utmp;

    // Prepare
    utmp = (struct utmp *)readPointer(&stream);
    memset(utmp, 0, sizeof(struct utmp));
        
    // Execute
    utmp->ut_type = readShort(&stream);
    utmp->ut_pid = readInt(&stream);
    strcpy(utmp->ut_line, readString(&stream));
    strcpy(utmp->ut_id, readString(&stream));
    strcpy(utmp->ut_user, readString(&stream));
    strcpy(utmp->ut_host, readString(&stream));
    utmp->ut_tv.tv_sec = readLong(&stream);
    utmp->ut_tv.tv_usec = readLong(&stream);
    
    // Response
    writeString(thread,"Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict write_utmpx_cmd(TAThread thread,TAInputStream stream)
{
    struct utmpx * utmpx;

    // Prepare
    utmpx = (struct utmpx *)readPointer(&stream);
    memset(utmpx, 0, sizeof(struct utmpx));
    
    // Execute
    utmpx->ut_type = readShort(&stream);
    utmpx->ut_pid = readInt(&stream);
    strcpy(utmpx->ut_line, readString(&stream));
    strcpy(utmpx->ut_id, readString(&stream));
    strcpy(utmpx->ut_user, readString(&stream));
    strcpy(utmpx->ut_host, readString(&stream));
    utmpx->ut_tv.tv_sec = readLong(&stream);
    utmpx->ut_tv.tv_usec = readLong(&stream);
    
    // Response
    writeString(thread,"Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

void writeUtmp(TAThread thread, struct utmp * utmp)
{
    if( utmp == NULL)
        writeInt( thread, 1 );
    else
    {
        writeInt( thread, 0 );
        writePointer( thread, utmp );
        writeShort( thread, utmp->ut_type );
        writeInt( thread, utmp->ut_pid );
        writeString( thread, utmp->ut_line );
        writeString( thread, utmp->ut_id );
        writeString( thread, utmp->ut_user );
        writeString( thread, utmp->ut_host );
        writeLong( thread, utmp->ut_tv.tv_sec );
        writeLong( thread, utmp->ut_tv.tv_usec );
    }
}

void writeUtmpx(TAThread thread, struct utmpx * utmpx)
{
    if( utmpx == NULL)
        writeInt( thread, 1 );
    else
    {
        writeInt( thread, 0 );
        writePointer( thread, utmpx );
        writeShort( thread, utmpx->ut_type );
        writeInt( thread, utmpx->ut_pid );
        writeString( thread, utmpx->ut_line );
        writeString( thread, utmpx->ut_id );
        writeString( thread, utmpx->ut_user );
        writeString( thread, utmpx->ut_host );
        writeLong( thread, utmpx->ut_tv.tv_sec );
        writeLong( thread, utmpx->ut_tv.tv_usec );
    }
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict endutent_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    START_TARGET_OPERATION(thread);

    // Execute
    endutent();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict endutxent_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    START_TARGET_OPERATION(thread);

    // Execute
    endutxent();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict getutxent_cmd(TAThread thread,TAInputStream stream)
{
    struct utmpx * res;
    // Prepare

    START_TARGET_OPERATION(thread);

    // Execute
    res = getutxent();

    END_TARGET_OPERATION(thread);

    // Response
    writeUtmpx(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getutxid_cmd(TAThread thread,TAInputStream stream)
{
    struct utmpx * res;
    struct utmpx * id;
    // Prepare

    id = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = getutxid(id);

    END_TARGET_OPERATION(thread);

    // Response
    writeUtmpx(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getutxline_cmd(TAThread thread,TAInputStream stream)
{
    struct utmpx * res;
    struct utmpx * line;

    // Prepare

    line = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = getutxline(line);

    END_TARGET_OPERATION(thread);

    // Response
    writeUtmpx(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict pututxline_cmd(TAThread thread,TAInputStream stream)
{
    struct utmpx * res;
    struct utmpx * utmpx;

    // Prepare

    utmpx = readPointer(&stream);
    errno = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = pututxline(utmpx);

    END_TARGET_OPERATION(thread);

    // Response
    writeUtmpx(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setutxent_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    START_TARGET_OPERATION(thread);

    // Execute
    setutxent();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getutent_cmd(TAThread thread,TAInputStream stream)
{
    struct utmp * res;
    // Prepare
    START_TARGET_OPERATION(thread);

    // Execute
    res = getutent();

    END_TARGET_OPERATION(thread);

    // Response
    writeUtmp(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getutent_r_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    struct utmp * buffer;
    struct utmp ** result;
    // Prepare
    buffer = readPointer(&stream);
    result = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = getutent_r( buffer, result );

    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res);
    writePointer( thread, result);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict login_cmd(TAThread thread,TAInputStream stream)
{
    struct utmp * ut;

    // Prepare
    ut = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    login(ut);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict logout_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char * line;
    // Prepare
    line = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = logout(line);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict logwtmp_cmd(TAThread thread,TAInputStream stream)
{
    char * line;
    char * name;
    char * host;
    // Prepare

    line = readString(&stream);
    name = readString(&stream);
    host = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    logwtmp(line,name,host);

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setutent_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare

    START_TARGET_OPERATION(thread);

    // Execute
    setutent();

    END_TARGET_OPERATION(thread);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict utmpname_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char * dbname;

    // Prepare
    dbname = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = utmpname(dbname);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt( thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_system_user_account_commands(void)
{
    ta_register_command("endutent",endutent_cmd);
    ta_register_command("endutxent",endutxent_cmd);
    ta_register_command("getutent",getutent_cmd);
    ta_register_command("getutent_r",getutent_r_cmd);
    ta_register_command("getutxent",getutxent_cmd);
    ta_register_command("getutxid",getutxid_cmd);
    ta_register_command("getutxline",getutxline_cmd);
    ta_register_command("login",login_cmd);
    ta_register_command("logout",logout_cmd);
    ta_register_command("logwtmp",logwtmp_cmd);
    ta_register_command("pututxline",pututxline_cmd);
    ta_register_command("setutent",setutent_cmd);
    ta_register_command("setutxent",setutxent_cmd);
    ta_register_command("utmpname",utmpname_cmd);
    
    ta_register_command("write_utmp",write_utmp_cmd);
    ta_register_command("write_utmpx",write_utmpx_cmd);
}

