/* 
 * File: ncurses/chgat/chgat_agent.c
 * 
 * Author:
 * Version:  $Id: chgat_agent.c,v 1.4 2006/05/15 13:01:35 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/chgat/chgat_agent.h"
#include <curses.h>


/********************************************************************/
/**                           Readers                             **/
/********************************************************************/
attr_t readNcursesAttrT(TAInputStream *stream)
{
    attr_t res = 0;
    int color;
    
    verifyType_TAInputStream(stream, "curses_attr");
    
    res = readInt(stream) != 0 ? res | A_ALTCHARSET :res ;  
    res = readInt(stream) != 0 ? res | A_BLINK :res ;       
    res = readInt(stream) != 0 ? res | A_BOLD :res ;        
    res = readInt(stream) != 0 ? res | A_DIM  :res ;        
    res = readInt(stream) != 0 ? res | A_HORIZONTAL :res ;  
    res = readInt(stream) != 0 ? res | A_INVIS :res ;     
    res = readInt(stream) != 0 ? res | A_LEFT :res ;    
    res = readInt(stream) != 0 ? res | A_LOW  :res ;   
    res = readInt(stream) != 0 ? res | A_PROTECT  :res ;
    res = readInt(stream) != 0 ? res | A_REVERSE  :res ;
    res = readInt(stream) != 0 ? res | A_RIGHT :res ;   
    res = readInt(stream) != 0 ? res | A_STANDOUT :res ;
    res = readInt(stream) != 0 ? res | A_TOP :res ;    
    res = readInt(stream) != 0 ? res | A_UNDERLINE  :res ; 
    res = readInt(stream) != 0 ? res | A_VERTICAL   :res ; 
    
    color= readInt(stream);
    color = color << 8;
    res = res | color;
    
    return res;
}




/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict chgat_cmd(TAThread thread,TAInputStream stream)
{
    attr_t attr;
    int n;
    int color;
    int res;
    
    n=readInt(&stream);
    attr=readNcursesAttrT(&stream);
    color=readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  chgat(n,  attr, color, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
    
}

static TACommandVerdict mvchgat_cmd(TAThread thread,TAInputStream stream)
{
    attr_t attr;
    int y;
    int x;
    int n;
    int color;
    int res;
    
    y=readInt(&stream);
    x=readInt(&stream);
    n=readInt(&stream);
    attr=readNcursesAttrT(&stream);
    color=readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  mvchgat(y,  x,  n,  attr, color, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mvwchgat_cmd(TAThread thread,TAInputStream stream)
{
    attr_t attr;
    int y;
    int x;
    int n;
    WINDOW *win;
    int color;
    int res;

    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    n=readInt(&stream);
    attr=readNcursesAttrT(&stream);
    color=readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  mvwchgat(win,  y,  x,  n,  attr, color, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;

}

static TACommandVerdict wchgat_cmd(TAThread thread,TAInputStream stream)
{
    attr_t attr;
    int n;
    WINDOW *win;
    int color;
    int res;
    
    win=readPointer(&stream);
    n=readInt(&stream);
    attr=readNcursesAttrT(&stream);
    color=readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res =  wchgat(win,  n,  attr, color, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
    
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_chgat_commands(void)
{
    ta_register_command("chgat",chgat_cmd);
    ta_register_command("mvchgat",mvchgat_cmd);
    ta_register_command("mvwchgat",mvwchgat_cmd);
    ta_register_command("wchgat",wchgat_cmd);
}

