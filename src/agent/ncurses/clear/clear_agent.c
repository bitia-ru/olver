/* 
 * File: ncurses/clear/clear_agent.c
 * 
 * Author:
 * Version:  $Id: clear_agent.c,v 1.3 2007/07/25 11:10:53 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */
#include "curses.h"
#include "ncurses/clear/clear_agent.h"


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict clear_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = clear();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clrtobot_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = clrtobot();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clrtoeol_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = clrtoeol();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict delch_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = delch();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict deleteln_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = deleteln();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erase_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = erase();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erasechar_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = erasechar();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict killchar_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = killchar();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvdelch_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;

    y = readInt(&stream);
    x = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = mvdelch(y, x);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwdelch_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;
    WINDOW *win;

    win=readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = mvwdelch(win, y, x);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wclear_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    int res;

    win=readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = wclear(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wclrtobot_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    int res;

    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wclrtobot(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wclrtoeol_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    int res;

    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wclrtoeol(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict wdelch_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    WINDOW *win;

    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wdelch(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wdeleteln_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    WINDOW *win;

    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wdeleteln(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict werase_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    int res;

    win=readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = werase(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_clear_commands(void)
{
    ta_register_command("clear",clear_cmd);
    ta_register_command("clrtobot",clrtobot_cmd);
    ta_register_command("clrtoeol",clrtoeol_cmd);
    ta_register_command("delch",delch_cmd);
    ta_register_command("deleteln",deleteln_cmd);
    ta_register_command("erase",erase_cmd);
    ta_register_command("erasechar",erasechar_cmd);
    ta_register_command("killchar",killchar_cmd);
    ta_register_command("mvdelch",mvdelch_cmd);
    ta_register_command("mvwdelch",mvwdelch_cmd);
    ta_register_command("wclear",wclear_cmd);
    ta_register_command("wclrtobot",wclrtobot_cmd);
    ta_register_command("wclrtoeol",wclrtoeol_cmd);
    ta_register_command("wdelch",wdelch_cmd);
    ta_register_command("wdeleteln",wdeleteln_cmd);
    ta_register_command("werase",werase_cmd);
}

