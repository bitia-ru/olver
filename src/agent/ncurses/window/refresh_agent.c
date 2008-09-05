/* 
 * File: ncurses/window/refresh_agent.c
 * 
 * Author:
 * Version:  $Id: refresh_agent.c,v 1.7 2007/07/25 11:10:56 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */
#include <curses.h>
#include "ncurses/window/refresh_agent.h"


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict doupdate_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
    res = doupdate();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict is_linetouched_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, line;

    win = readPointer(&stream);
    line = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = is_linetouched(win, line);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict is_wintouched_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = is_wintouched(win);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict isendwin_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
    res = isendwin();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict redrawwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = redrawwin(win);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict refresh_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = refresh();    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
        
    return taDefaultVerdict;
}

static TACommandVerdict syncok_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, bf;

    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = syncok(win, bf);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict touchline_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, start, count;

    win = readPointer(&stream);
    start = readInt(&stream);
    count = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = touchline(win, start, count);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict touchwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = touchwin(win);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict untouchwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = untouchwin(win);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcursyncup_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    wcursyncup(win);
    END_TARGET_OPERATION(thread);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wnoutrefresh_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = wnoutrefresh(win);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wredrawln_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, beg_line, num_lines;

    win = readPointer(&stream);
    beg_line = readInt(&stream);
    num_lines = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = wredrawln(win, beg_line, num_lines);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wrefresh_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    WINDOW* win;

    win = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wrefresh(win);    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wsyncdown_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    wsyncdown(win);
    END_TARGET_OPERATION(thread);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wsyncup_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    wsyncup(win);
    END_TARGET_OPERATION(thread);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wtouchln_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, y, n, changed;

    win = readPointer(&stream);
    y = readInt(&stream);
    n = readInt(&stream);
    changed = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = wtouchln(win, y, n, changed);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_window_refresh_commands(void)
{
    ta_register_command("doupdate",doupdate_cmd);
    ta_register_command("is_linetouched",is_linetouched_cmd);
    ta_register_command("is_wintouched",is_wintouched_cmd);
    ta_register_command("isendwin",isendwin_cmd);
    ta_register_command("redrawwin",redrawwin_cmd);
    ta_register_command("refresh",refresh_cmd);
    ta_register_command("syncok",syncok_cmd);
    ta_register_command("touchline",touchline_cmd);
    ta_register_command("touchwin",touchwin_cmd);
    ta_register_command("untouchwin",untouchwin_cmd);
    ta_register_command("wcursyncup",wcursyncup_cmd);
    ta_register_command("wnoutrefresh",wnoutrefresh_cmd);
    ta_register_command("wredrawln",wredrawln_cmd);
    ta_register_command("wrefresh",wrefresh_cmd);
    ta_register_command("wsyncdown",wsyncdown_cmd);
    ta_register_command("wsyncup",wsyncup_cmd);
    ta_register_command("wtouchln",wtouchln_cmd);
}

