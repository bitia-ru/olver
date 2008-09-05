/* 
 * File: ncurses/window/pad_agent.c
 * 
 * Author:
 * Version:  $Id: pad_agent.c,v 1.4 2007/07/25 11:10:56 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/window/pad_agent.h"
#include <curses.h>

chtype readChType(TAInputStream *stream);
void writeChType(TAThread thread, chtype val); 

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict newpad_cmd(TAThread thread,TAInputStream stream)
{
    int ncols, nlines;
    WINDOW* res;

    nlines = readInt(&stream);
    ncols = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = newpad(nlines, ncols);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict pechochar_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* pad;
    chtype ch;
    int res;

    pad = readPointer(&stream);
    ch = readChType(&stream);

    START_TARGET_OPERATION(thread);
    res = pechochar(pad, ch);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict pnoutrefresh_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* pad;
    int res, pminrow, pmincol, sminrow, smincol, smaxrow, smaxcol;

    pad = readPointer(&stream);
    pminrow = readInt(&stream);
    pmincol = readInt(&stream);
    sminrow = readInt(&stream);
    smincol = readInt(&stream);
    smaxrow = readInt(&stream);    
    smaxcol = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = pnoutrefresh(pad, pminrow, pmincol, sminrow,smincol,smaxrow,smaxcol);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict prefresh_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* pad;
    int res, pminrow, pmincol, sminrow, smincol, smaxrow, smaxcol;

    pad = readPointer(&stream);
    pminrow = readInt(&stream);
    pmincol = readInt(&stream);
    sminrow = readInt(&stream);
    smincol = readInt(&stream);
    smaxrow = readInt(&stream);    
    smaxcol = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = prefresh(pad, pminrow, pmincol, sminrow, smincol, smaxrow, smaxcol);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict subpad_cmd(TAThread thread,TAInputStream stream)
{
    int ncols, nlines, begin_y, begin_x;
    WINDOW* orig, *res;

    orig = readPointer(&stream);
    nlines = readInt(&stream);
    ncols = readInt(&stream);
    begin_y = readInt(&stream);
    begin_x = readInt(&stream);


    START_TARGET_OPERATION(thread);
    res = subpad(orig, nlines, ncols, begin_y, begin_x);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_window_pad_commands(void)
{
    ta_register_command("newpad",newpad_cmd);
    ta_register_command("pechochar",pechochar_cmd);
    ta_register_command("pnoutrefresh",pnoutrefresh_cmd);
    ta_register_command("prefresh",prefresh_cmd);
    ta_register_command("subpad",subpad_cmd);
}

