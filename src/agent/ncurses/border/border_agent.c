/* 
 * File: ncurses/border/border_agent.c
 * 
 * Author:
 * Version:  $Id: border_agent.c,v 1.8 2007/10/23 10:38:18 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "common/ta_stream.h"
#include "ncurses/border/border_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict acsmap_update_cmd(TAThread thread,TAInputStream stream)
{
	
    // Prepare
    int sz = 128;
	
    // Response
    writeInt(thread, sz);
    
    while(sz--) writeChType(thread, acs_map[sz]);
        
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict border_cmd(TAThread thread,TAInputStream stream)
{

    // Prepare
    int res;
    chtype ls, rs, ts, bs, tl, tr, bl, br;
    
    ls = readChType(&stream);
    rs = readChType(&stream);
    ts = readChType(&stream);
    bs = readChType(&stream);
    tl = readChType(&stream);
    tr = readChType(&stream);
    bl = readChType(&stream);
    br = readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = border(ls, rs, ts, bs, tl, tr, bl, br);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict box_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;
    chtype ch1, ch2;
    WINDOW* wnd;
    
    wnd = (WINDOW*)readPointer(&stream);
    ch1 = readChType(&stream);
    ch2 = readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = box(wnd, ch1, ch2);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wborder_cmd(TAThread thread, TAInputStream stream)
{    
    // Prepare
    WINDOW* wnd;
    int res, maxx, maxy;
    chtype ls, rs, ts, bs, tl, tr, bl, br;
    
    wnd = (WINDOW*)readPointer(&stream);
    ls = readChType(&stream);
    rs = readChType(&stream);
    ts = readChType(&stream);
    bs = readChType(&stream);
    tl = readChType(&stream);
    tr = readChType(&stream);
    bl = readChType(&stream);
    br = readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = wborder(wnd, ls, rs, ts, bs, tl, tr, bl, br);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_border_commands(void)
{
    ta_register_command("border", border_cmd);
    ta_register_command("box", box_cmd);
    ta_register_command("wborder", wborder_cmd);
    ta_register_command("acsmap_update", acsmap_update_cmd);
}

