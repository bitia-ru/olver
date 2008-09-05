/* 
 * File: ncurses/string/insert_agent.c
 * 
 * Author:
 * Version:  $Id: insert_agent.c,v 1.2 2006/05/02 11:32:22 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/string/insert_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict insnstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int n;
    int res;
    
    str = readString(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = insnstr(str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict insstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int res;
    
    str = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    res = insstr(str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvinsnstr_cmd(TAThread thread,TAInputStream stream)
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
    res = mvinsnstr(y, x, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvinsstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int res;
    int y;
    int x;
    
    y=readInt(&stream);
    x=readInt(&stream);
    str = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    res = mvinsstr(y, x, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwinsnstr_cmd(TAThread thread,TAInputStream stream)
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
    res = mvwinsnstr(win, y, x, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwinsstr_cmd(TAThread thread,TAInputStream stream)
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
    res = mvwinsstr(win, y, x, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict winsnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    
    win = readPointer(&stream);
    str = readString(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = winsnstr(win, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict winsstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int res;
    
    win = readPointer(&stream);
    str = readString(&stream);
    
    START_TARGET_OPERATION(thread);
    res = winsstr(win, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_string_insert_commands(void)
{
    ta_register_command("insnstr",insnstr_cmd);
    ta_register_command("insstr",insstr_cmd);
    ta_register_command("mvinsnstr",mvinsnstr_cmd);
    ta_register_command("mvinsstr",mvinsstr_cmd);
    ta_register_command("mvwinsnstr",mvwinsnstr_cmd);
    ta_register_command("mvwinsstr",mvwinsstr_cmd);
    ta_register_command("winsnstr",winsnstr_cmd);
    ta_register_command("winsstr",winsstr_cmd);
}

