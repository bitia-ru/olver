/* 
 * File: ncurses/move/move_agent.c
 * 
 * Author:
 * Version:  $Id: move_agent.c,v 1.3 2007/07/25 11:10:55 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/move/move_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict move_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;

    y = readInt(&stream);
    x = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = move(y, x);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
}

static TACommandVerdict mvcur_cmd(TAThread thread,TAInputStream stream)
{
    int oldrow, oldcol, newrow, newcol, res;

    oldrow = readInt(&stream);
    oldcol = readInt(&stream);
    newrow = readInt(&stream);
    newcol = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = mvcur(oldrow, oldcol, newrow, newcol);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
   
    return taDefaultVerdict;
}

static TACommandVerdict wmove_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;
    WINDOW* win;

    win = (WINDOW*)readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wmove(win, y, x);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_move_commands(void)
{
    ta_register_command("move",move_cmd);
    ta_register_command("mvcur",mvcur_cmd);
    ta_register_command("wmove",wmove_cmd);
}

