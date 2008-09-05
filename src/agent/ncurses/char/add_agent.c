/* 
 * File: ncurses/char/add_agent.c
 * 
 * Author:
 * Version:  $Id: add_agent.c,v 1.6 2007/07/25 11:10:52 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/char/add_agent.h"
#include <curses.h>


/********************************************************************/
/**                           Readers                             **/
/********************************************************************/
chtype readChType(TAInputStream *stream)
{
    chtype res = 0;
    int color;
    
    verifyType_TAInputStream(stream, "chtype");

    res = readInt(stream) != 0 ? res | A_ALTCHARSET :res ;   // Alternate character set
    res = readInt(stream) != 0 ? res | A_BLINK :res ;       // Blinking
    res = readInt(stream) != 0 ? res | A_BOLD :res ;        // Extra bright or bold
    res = readInt(stream) != 0 ? res | A_DIM  :res ;        // Half bright
    res = readInt(stream) != 0 ? res | A_INVIS :res ;       // Invisible
    res = readInt(stream) != 0 ? res | A_PROTECT :res ;     // Protected
    res = readInt(stream) != 0 ? res | A_REVERSE  :res ;    // Reverse video
    res = readInt(stream) != 0 ? res | A_STANDOUT  :res ;   // Best highlighting mode of the terminal
    res = readInt(stream) != 0 ? res | A_UNDERLINE  :res ;  // Underlining
    
    color= readInt(stream);
    color = color << 8;
    res = res | color;
    res = res | readWChar(stream);

    return res;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict addch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int res;
    
    ch=readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    res = addch(ch);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict echochar_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int res;
    
    ch=readChType(&stream);
    
    START_TARGET_OPERATION(thread);
    res = echochar(ch);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvaddch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    int y;
    int x;
    int res;

    y=readInt(&stream);
    x=readInt(&stream);
    ch=readChType(&stream);

    START_TARGET_OPERATION(thread);
    res =  mvaddch(y, x, ch);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwaddch_cmd(TAThread thread,TAInputStream stream)
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
    res =  mvwaddch(win, y, x, ch);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict waddch_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    WINDOW *win;
    int res;
    
    win=readPointer(&stream);
    ch=readChType(&stream);

    START_TARGET_OPERATION(thread);
    res =  waddch(win, ch);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wechochar_cmd(TAThread thread,TAInputStream stream)
{
    chtype ch;
    WINDOW *win;
    int res;
    
    win=readPointer(&stream);
    ch=readChType(&stream);

    START_TARGET_OPERATION(thread);
    res =  wechochar(win, ch);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_char_add_commands(void)
{
    ta_register_command("addch",addch_cmd);
    ta_register_command("echochar",echochar_cmd);
    ta_register_command("mvaddch",mvaddch_cmd);
    ta_register_command("mvwaddch",mvwaddch_cmd);
    ta_register_command("waddch",waddch_cmd);
    ta_register_command("wechochar",wechochar_cmd);
}

