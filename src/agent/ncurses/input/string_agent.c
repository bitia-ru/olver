/* 
 * File: ncurses/input/string_agent.c
 * 
 * Author:
 * Version:  $Id: string_agent.c,v 1.3 2007/07/25 11:10:54 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/input/string_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getnstr_cmd(TAThread thread,TAInputStream stream)
{
    int res, n;
    char* str;

    str = readPointer(&stream);
    n = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = getnstr(str, n);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getstr_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* str;

    str = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = getstr(str);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mvgetnstr_cmd(TAThread thread,TAInputStream stream)
{
    int res, n, y, x;
    char* str;

    y = readInt(&stream);
    x = readInt(&stream);
    str = readPointer(&stream);
    n = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = mvgetnstr(y, x, str, n);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mvgetstr_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;
    char* str;

    y = readInt(&stream);
    x = readInt(&stream);
    str = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = mvgetstr(y, x, str);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mvwgetnstr_cmd(TAThread thread,TAInputStream stream)
{
    int res, n, y, x;
    char* str;
    WINDOW* win;

    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);
    str = readPointer(&stream);
    n = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = mvwgetnstr(win, y, x, str, n);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mvwgetstr_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;
    char* str;
    WINDOW* win;

    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);
    str = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = mvwgetstr(win, y, x, str);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wgetnstr_cmd(TAThread thread,TAInputStream stream)
{
    int res, n;
    char* str;
    WINDOW* win;

    win = readPointer(&stream);
    str = readPointer(&stream);
    n = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = wgetnstr(win, str, n);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wgetstr_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    char* str;
    WINDOW* win;

    win = readPointer(&stream);
    str = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = wgetstr(win, str);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_input_string_commands(void)
{
    ta_register_command("getnstr",getnstr_cmd);
    ta_register_command("getstr",getstr_cmd);
    ta_register_command("mvgetnstr",mvgetnstr_cmd);
    ta_register_command("mvgetstr",mvgetstr_cmd);
    ta_register_command("mvwgetnstr",mvwgetnstr_cmd);
    ta_register_command("mvwgetstr",mvwgetstr_cmd);
    ta_register_command("wgetnstr",wgetnstr_cmd);
    ta_register_command("wgetstr",wgetstr_cmd);
}

