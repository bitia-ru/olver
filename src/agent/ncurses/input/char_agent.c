/* 
 * File: ncurses/input/char_agent.c
 * 
 * Author:
 * Version:  $Id: char_agent.c,v 1.3 2007/07/25 11:10:54 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/input/char_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict getch_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
    res = getch();    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mvgetch_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;

    y = readInt(&stream);
    x = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = mvgetch(y, x);    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict mvwgetch_cmd(TAThread thread,TAInputStream stream)
{
    int res, y, x;
    WINDOW* win;

    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = mvwgetch(win, y, x);    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ungetch_cmd(TAThread thread,TAInputStream stream)
{
    int res, ch;

    ch = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = ungetch(ch);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wgetch_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    WINDOW* win;

    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = wgetch(win);    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_input_char_commands(void)
{
    ta_register_command("getch",getch_cmd);
    ta_register_command("mvgetch",mvgetch_cmd);
    ta_register_command("mvwgetch",mvwgetch_cmd);
    ta_register_command("ungetch",ungetch_cmd);
    ta_register_command("wgetch",wgetch_cmd);
}

