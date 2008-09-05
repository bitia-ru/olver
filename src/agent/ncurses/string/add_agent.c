/* 
 * File: ncurses/string/add_agent.c
 * 
 * Author:
 * Version:  $Id: add_agent.c,v 1.2 2006/04/27 13:49:24 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/string/add_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict addnstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int n;
    int res;
    
    str = readString(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = addnstr(str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict addstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int res;
    
    str = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    res = addstr(str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvaddnstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int n;
    int res;
    int y;
    int x;
    
    y=readInt(&stream);
    x=readInt(&stream);
    str = readString(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvaddnstr(y, x, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvaddstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int res;
    int y;
    int x;
    
    y=readInt(&stream);
    x=readInt(&stream);
    str = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    res = mvaddstr(y, x, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwaddnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    int y;
    int x;
    
    win = readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    str = readString(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvwaddnstr(win, y, x, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwaddstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int res;
    int y;
    int x;
    
    win = readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    str = readString(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvwaddstr(win, y, x, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict waddnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    
    win = readPointer(&stream);
    str = readString(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = waddnstr(win, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict waddstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int res;
    
    win = readPointer(&stream);
    str = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    res = waddstr(win, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_string_add_commands(void)
{
    ta_register_command("addnstr",addnstr_cmd);
    ta_register_command("addstr",addstr_cmd);
    ta_register_command("mvaddnstr",mvaddnstr_cmd);
    ta_register_command("mvaddstr",mvaddstr_cmd);
    ta_register_command("mvwaddnstr",mvwaddnstr_cmd);
    ta_register_command("mvwaddstr",mvwaddstr_cmd);
    ta_register_command("waddnstr",waddnstr_cmd);
    ta_register_command("waddstr",waddstr_cmd);
}

