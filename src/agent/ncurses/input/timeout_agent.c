/* 
 * File: ncurses/input/timeout_agent.c
 * 
 * Author:
 * Version:  $Id: timeout_agent.c,v 1.3 2006/09/25 12:59:21 levenkov Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/input/timeout_agent.h"
#include <curses.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict notimeout_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    WINDOW* wnd;
    bool bf;
    
    wnd = (WINDOW*)readPointer(&stream);
    bf = (bool)readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = notimeout(wnd, bf);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict timeout_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int delay;
    
    delay = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    timeout(delay);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wtimeout_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    WINDOW* wnd;
    int delay;
    
    wnd = (WINDOW*)readPointer(&stream);
    delay = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    wtimeout(wnd, delay);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_input_timeout_commands(void)
{
    ta_register_command("notimeout", notimeout_cmd);
    ta_register_command("timeout", timeout_cmd);
    ta_register_command("wtimeout", wtimeout_cmd);
}

