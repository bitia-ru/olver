/* 
 * File: ncurses/line/line_agent.c
 * 
 * Author:
 * Version:  $Id: line_agent.c,v 1.3 2006/05/15 10:11:38 biga Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/line/line_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

chtype readChType(TAInputStream *stream);

static TACommandVerdict hline_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int n;
    int res;
    
    ch = readChType(&stream);
    n = readInt(&stream);
        
    START_TARGET_OPERATION(thread);
    
    res = hline(ch,n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict whline_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    chtype ch;
    int n;
    int res;
    
    win = readPointer(&stream);
    ch = readChType(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = whline(win, ch, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvhline_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int n;
    int y;
    int x;
    int res;
    
    y = readInt(&stream);
    x = readInt(&stream);
    ch = readChType(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = mvhline(y, x, ch, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwhline_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    chtype ch;
    int n;
    int y;
    int x;
    int res;

    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);
    ch = readChType(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = mvwhline(win, y, x, ch, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict vline_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int n;
    int res;
    
    ch = readChType(&stream);
    n = readInt(&stream);
        
    START_TARGET_OPERATION(thread);
    
    res = vline(ch,n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wvline_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    chtype ch;
    int n;
    int res;
    
    win = readPointer(&stream);
    ch = readChType(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = wvline(win, ch, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvvline_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int n;
    int y;
    int x;
    int res;
    
    y = readInt(&stream);
    x = readInt(&stream);
    ch = readChType(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = mvvline(y, x, ch, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwvline_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    chtype ch;
    int n;
    int y;
    int x;
    int res;

    win = readPointer(&stream);
    y = readInt(&stream);
    x = readInt(&stream);
    ch = readChType(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = mvwvline(win, y, x, ch, n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict insertln_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = insertln();
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict winsertln_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    int res;
    
    win = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = winsertln(win);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict insdelln_cmd(TAThread thread,TAInputStream stream)
{
    int n;
    int res;
    
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = insdelln(n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict winsdelln_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW *win;
    int n;
    int res;
    
    win = readPointer(&stream);
    n = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = winsdelln(win,n);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

int init_func(WINDOW *win, int columns)
{
    TAThread thread = ta_current_thread();

    writeDeferredReaction(thread,"ripoffline_initfunc_call");
    writePointer(thread,win);
    writeInt(thread, columns);

    sendResponse(thread); 
}

static TACommandVerdict ripoffline_cmd(TAThread thread,TAInputStream stream)
{
    int line;
    int init;
    int res;
    
    line = readInt(&stream);
    init = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    if(init)
    {
        res = ripoffline(line, init_func);
    }
    else
    {
        res = ripoffline(line, NULL);
    }
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_line_commands(void)
{
    ta_register_command("hline",hline_cmd);
    ta_register_command("whline",whline_cmd);
    ta_register_command("mvhline",mvhline_cmd);
    ta_register_command("mvwhline",mvwhline_cmd);

    ta_register_command("vline",vline_cmd);
    ta_register_command("wvline",wvline_cmd);
    ta_register_command("mvvline",mvvline_cmd);
    ta_register_command("mvwvline",mvwvline_cmd);

    ta_register_command("insertln",insertln_cmd);
    ta_register_command("winsertln",winsertln_cmd);

    ta_register_command("insdelln",insdelln_cmd);
    ta_register_command("winsdelln",winsdelln_cmd);

    ta_register_command("ripoffline",ripoffline_cmd);
}

