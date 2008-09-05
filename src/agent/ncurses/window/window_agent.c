/* 
 * File: ncurses/window/window_agent.c
 * 
 * Author:
 * Version:  $Id: window_agent.c,v 1.10 2007/07/25 11:10:56 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/window/window_agent.h"
#include <curses.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict copywin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* srcwin, *dstwin;
    int sminrow, smincol, dminrow, dmincol, dmaxrow, dmaxcol, overlay, res;
    
    srcwin = readPointer(&stream);
    dstwin = readPointer(&stream);
    sminrow = readInt(&stream);
    smincol = readInt(&stream);
    dminrow = readInt(&stream);
    dmincol = readInt(&stream);
    dmaxrow = readInt(&stream);
    dmaxcol = readInt(&stream);
    overlay  = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = copywin(srcwin, dstwin, sminrow, smincol, dminrow, dmincol, dmaxrow,
                    dmaxcol, overlay);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict curs_set_cmd(TAThread thread,TAInputStream stream)
{
    int res, visibility;

    visibility = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = curs_set(visibility);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict delwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int  res;
    
    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = delwin(win);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;

}

static TACommandVerdict derwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* orig, *res;
    int  nlines, ncols, begin_y, begin_x;
    
    orig = readPointer(&stream);
    nlines = readInt(&stream);
    ncols = readInt(&stream);
    begin_y = readInt(&stream);
    begin_x = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = derwin(orig, nlines, ncols, begin_y, begin_x);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict dupwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win, *res;
    
    win = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = dupwin(win);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getwin_cmd(TAThread thread,TAInputStream stream)
{
    char* filename;
    FILE* filep;
    WINDOW *res;
    
    filename = readString(&stream);

    filep = fopen(filename, "r+");

    START_TARGET_OPERATION(thread);
    res = getwin(filep);
    END_TARGET_OPERATION(thread);

    fclose(filep);

    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict intrflush_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, bf;
    
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = intrflush(win, bf);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict keypad_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, bf;
    
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = keypad(win, bf);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict meta_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, bf;
    
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = meta(win, bf);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvderwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, y, x;
    
    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = mvderwin(win, y, x);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int y, x, res;
    
    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = mvwin(win, y, x);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict newwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* res;
    int nlines, ncols, begin_y, begin_x, lines, cols;    
    
    ta_debug_printf("NewWin!\n");
    
    nlines=readInt(&stream);
    ncols=readInt(&stream);
    begin_y=readInt(&stream);
    begin_x=readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = newwin(nlines, ncols, begin_y, begin_x);
    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);

    getmaxyx(res, lines, cols);

    writeInt(thread, cols);
    writeInt(thread, lines);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nodelay_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    int res, bf;
    
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = nodelay(win, bf);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict overlay_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* srcwin, *dstwin;
    int res;
    
    srcwin = readPointer(&stream);
    dstwin = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = overlay(srcwin, dstwin);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict overwrite_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* srcwin, *dstwin;
    int res;
    
    srcwin = readPointer(&stream);
    dstwin = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = overwrite(srcwin, dstwin);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict putwin_cmd(TAThread thread,TAInputStream stream)
{
    char* filename;
    FILE* filep;
    WINDOW *win;
    int res;
    
    win = readPointer(&stream);
    filename = readString(&stream);

    filep = fopen(filename, "w+");

    START_TARGET_OPERATION(thread);
    res = putwin(win, filep);
    END_TARGET_OPERATION(thread);

    fclose(filep);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict subwin_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* orig, *res;
    int  nlines, ncols, begin_y, begin_x;
    
    orig = readPointer(&stream);
    nlines = readInt(&stream);
    ncols = readInt(&stream);
    begin_y = readInt(&stream);
    begin_x = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = subwin(orig, nlines, ncols, begin_y, begin_x);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_window_window_commands(void)
{
    ta_register_command("copywin",copywin_cmd);
    ta_register_command("curs_set",curs_set_cmd);
    ta_register_command("delwin",delwin_cmd);
    ta_register_command("derwin",derwin_cmd);
    ta_register_command("dupwin",dupwin_cmd);
    ta_register_command("getwin",getwin_cmd);
    ta_register_command("intrflush",intrflush_cmd);
    ta_register_command("keypad",keypad_cmd);
    ta_register_command("meta",meta_cmd);
    ta_register_command("mvderwin",mvderwin_cmd);
    ta_register_command("mvwin",mvwin_cmd);
    ta_register_command("newwin",newwin_cmd);
    ta_register_command("nodelay",nodelay_cmd);
    ta_register_command("overlay",overlay_cmd);
    ta_register_command("overwrite",overwrite_cmd);
    ta_register_command("putwin",putwin_cmd);
    ta_register_command("subwin",subwin_cmd);
}

