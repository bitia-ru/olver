/*
 * File: ncurses/bkgd/bkgd_agent.c
 *
 * Author:
 * Version:  $Id: bkgd_agent.c,v 1.2 2006/05/03 16:23:33 flint Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/bkgd/bkgd_agent.h"
#include <curses.h>

chtype readChType(TAInputStream *stream);
void writeChType(TAThread thread, chtype val);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict bkgd_cmd(TAThread thread, TAInputStream stream)
{
    chtype ch;
    int res;

    // Prepare
    ch = readChType(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = bkgd(ch);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict bkgdset_cmd(TAThread thread, TAInputStream stream)
{
    chtype ch;

    // Prepare
    ch = readChType(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    bkgdset(ch);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict getbkgd_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    chtype res;

    // Prepare
    win = (WINDOW*)readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = getbkgd(win);

    END_TARGET_OPERATION(thread);

    // Response
    writeChType(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wbkgd_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    chtype ch;
    int res;

    // Prepare
    win = (WINDOW*)readPointer(&stream);
    ch = readChType(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wbkgd(win, ch);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wbkgdset_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    chtype ch;

    // Prepare
    win = (WINDOW*)readPointer(&stream);
    ch = readChType(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    wbkgdset(win, ch);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_bkgd_commands(void)
{
    ta_register_command("bkgd", bkgd_cmd);
    ta_register_command("bkgdset", bkgdset_cmd);
    ta_register_command("getbkgd", getbkgd_cmd);
    ta_register_command("wbkgd", wbkgd_cmd);
    ta_register_command("wbkgdset", wbkgdset_cmd);
}
