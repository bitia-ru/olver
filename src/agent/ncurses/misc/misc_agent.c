/* 
 * File: ncurses/misc/misc_agent.c
 * 
 * Author:
 * Version:  $Id: misc_agent.c,v 1.4 2007/07/25 11:10:54 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/misc/misc_agent.h"
#include <curses.h>

chtype readChType(TAInputStream *stream);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict baudrate_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
    res = baudrate();    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict beep_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
    res = beep();    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict flash_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
    res = flash();    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict keyname_cmd(TAThread thread,TAInputStream stream)
{
    int c;
    char* res;

    c = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = keyname(c);
    END_TARGET_OPERATION(thread);

    writeString(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict napms_cmd(TAThread thread,TAInputStream stream)
{
    int ms, res;

    ms = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = napms(ms);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict typeahead_cmd(TAThread thread,TAInputStream stream)
{
    int fildes, res;

    fildes = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = typeahead(fildes);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict unctrl_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    chtype c;

    c = readChType(&stream);

    START_TARGET_OPERATION(thread);
    res = unctrl(c);
    END_TARGET_OPERATION(thread);

    writeString(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_misc_commands(void)
{
    ta_register_command("baudrate",baudrate_cmd);
    ta_register_command("beep",beep_cmd);
    ta_register_command("flash",flash_cmd);
    ta_register_command("keyname",keyname_cmd);
    ta_register_command("napms",napms_cmd);
    ta_register_command("typeahead",typeahead_cmd);
    ta_register_command("unctrl",unctrl_cmd);
}

