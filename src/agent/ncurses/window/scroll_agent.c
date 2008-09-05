/*
 * File: ncurses/window/scroll_agent.c
 *
 * Author:
 * Version:  $Id: scroll_agent.c,v 1.2 2006/05/19 13:11:02 flint Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/window/scroll_agent.h"
#include <curses.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict scrl_cmd(TAThread thread, TAInputStream stream)
{
    int n;
    int  res;

    // Prepare
    n = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = scrl(n);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict scroll_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    int  res;

    // Prepare
    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = scroll(win);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wscrl_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    int n;
    int  res;

    // Prepare
    win = readPointer(&stream);
    n = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wscrl(win, n);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_window_scroll_commands(void)
{
    ta_register_command("scrl", scrl_cmd);
    ta_register_command("scroll", scroll_cmd);
    ta_register_command("wscrl", wscrl_cmd);
}
