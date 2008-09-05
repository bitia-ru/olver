/* 
 * File: ncurses/char/input_agent.c
 * 
 * Author:
 * Version:  $Id: input_agent.c,v 1.11 2006/04/27 14:50:45 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/char/input_agent.h"
#include <curses.h>



/********************************************************************/
/**                           Writers                              **/
/********************************************************************/
void writeChType(TAThread thread, chtype val)
{
    writeInt(thread, val&A_ALTCHARSET ? 1 : 0);
    writeInt(thread, val&A_BLINK ? 1 : 0);
    writeInt(thread, val&A_BOLD ? 1 : 0);
    writeInt(thread, val&A_DIM ? 1 : 0);
    writeInt(thread, val&A_INVIS ? 1 : 0);
    writeInt(thread, val&A_PROTECT ? 1 : 0);
    writeInt(thread, val&A_REVERSE ? 1 : 0);
    writeInt(thread, val&A_STANDOUT ? 1 : 0);
    writeInt(thread, val&A_UNDERLINE ? 1 : 0);

    writeInt(thread, (val&A_COLOR)>>8);
    if (val==(chtype)ERR)
    {
        writeWChar(thread, -1);
    }
    else
    {
        writeWChar(thread, val&A_CHARTEXT);
    }
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict inch_cmd(TAThread thread,TAInputStream stream)
{
    chtype res;
    
   
    START_TARGET_OPERATION(thread);
    res = inch();
    END_TARGET_OPERATION(thread);
    
    writeChType(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvinch_cmd(TAThread thread,TAInputStream stream)
{
    chtype res;
    int y;
    int x;
    
    y=readInt(&stream);
    x=readInt(&stream);
        START_TARGET_OPERATION(thread);
    res = mvinch(y, x);    END_TARGET_OPERATION(thread);
    
    writeChType(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwinch_cmd(TAThread thread,TAInputStream stream)
{
    chtype res;
    WINDOW* win;
    int y;
    int x;
    
    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvwinch(win, y, x);    END_TARGET_OPERATION(thread);
    
    writeChType(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict winch_cmd(TAThread thread,TAInputStream stream)
{
    chtype res;
    WINDOW* win;
    
    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = winch(win);
    END_TARGET_OPERATION(thread);
    
    writeChType(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_char_input_commands(void)
{
    ta_register_command("inch",inch_cmd);
    ta_register_command("mvinch",mvinch_cmd);
    ta_register_command("mvwinch",mvwinch_cmd);
    ta_register_command("winch",winch_cmd);
}

