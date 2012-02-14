/* 
 * File: ncurses/char/insert_agent.c
 * 
 * Author:
 * Version:  $Id: insert_agent.c,v 1.2 2006/04/24 10:12:25 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/char/insert_agent.h"
#include <curses.h>

chtype readChType(TAInputStream *stream);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict insch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int res;
    
    ch=readChType(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = insch(ch);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvinsch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int y;
    int x;
    int res;

    y=readInt(&stream);
    x=readInt(&stream);
    ch=readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  mvinsch(y, x, ch);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwinsch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int y;
    int x;
    WINDOW *win;
    int res;

    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    ch=readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  mvwinsch(win, y, x, ch);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict winsch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    WINDOW *win;
    int res;
    
    win=readPointer(&stream);
    ch=readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  winsch(win, ch);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_char_insert_commands(void)
{
    ta_register_command("insch",insch_cmd);
    ta_register_command("mvinsch",mvinsch_cmd);
    ta_register_command("mvwinsch",mvwinsch_cmd);
    ta_register_command("winsch",winsch_cmd);
}

