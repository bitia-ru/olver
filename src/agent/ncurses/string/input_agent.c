/* 
 * File: ncurses/string/input_agent.c
 * 
 * Author:
 * Version:  $Id: input_agent.c,v 1.25 2006/05/12 14:48:04 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include <stdlib.h>
#include "ncurses/string/input_agent.h"
#include <curses.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict innstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int n;
    int res;
    
    n=readInt(&stream);
    str=(char *)ta_alloc_memory((n+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = innstr(str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);

    ta_dealloc_memory(str);

    return taDefaultVerdict;
}

static TACommandVerdict instr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int res;
    
    str=(char *)ta_alloc_memory((COLS+1)*sizeof(chtype));
  
    START_TARGET_OPERATION(thread);
    res = instr(str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);

    ta_dealloc_memory(str);

    return taDefaultVerdict;
}

static TACommandVerdict mvinnstr_cmd(TAThread thread,TAInputStream stream)
{
    char *buffer;
    int n;
    int res;
    int y, x;
    
    
    y=readInt(&stream);
    x=readInt(&stream);
    n=readInt(&stream);
    buffer=ta_alloc_memory((n+1)*sizeof(chtype));

    
    START_TARGET_OPERATION(thread);
    res = mvinnstr(y, x, buffer, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, buffer);
    
    sendResponse(thread);

    ta_dealloc_memory(buffer);

    return taDefaultVerdict;
}

static TACommandVerdict mvinstr_cmd(TAThread thread,TAInputStream stream)
{
    char *str;
    int res;
    int y, x;
    int i=0;
    
    
    y=readInt(&stream);
    x=readInt(&stream);
    str=(char *)ta_alloc_memory((COLS+1)*sizeof(chtype));
  
    
    START_TARGET_OPERATION(thread);
    res = mvinstr(y, x, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);

    ta_dealloc_memory(str);

    return taDefaultVerdict;
}

static TACommandVerdict mvwinnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    int y, x;
    
    
    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    n=readInt(&stream);
    str=(char *)ta_alloc_memory((n+1)*sizeof(chtype));

    
    START_TARGET_OPERATION(thread);
    res = mvwinnstr(win, y, x, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);

    ta_dealloc_memory(str);

    return taDefaultVerdict;
}

static TACommandVerdict mvwinstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    int y, x;
    
    
    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    str=(char *)ta_alloc_memory((COLS+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = mvwinstr(win, y, x, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);
 
    ta_dealloc_memory(str);

    return taDefaultVerdict;
}

static TACommandVerdict winnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    
    
    win=readPointer(&stream);
    n=readInt(&stream);
    str=(char *)ta_alloc_memory((n+1)*sizeof(chtype));

    
    START_TARGET_OPERATION(thread);
    res = winnstr(win, str, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);
    
    ta_dealloc_memory(str);

    return taDefaultVerdict;
}

static TACommandVerdict winstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    char *str;
    int n;
    int res;
    
    
    win=readPointer(&stream);
    str=(char *)ta_alloc_memory((COLS+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = winstr(win, str);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeString(thread, str);
    
    sendResponse(thread);
    
    ta_dealloc_memory(str);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_string_input_commands(void)
{
    ta_register_command("innstr",innstr_cmd);
    ta_register_command("instr",instr_cmd);
    ta_register_command("mvinnstr",mvinnstr_cmd);
    ta_register_command("mvinstr",mvinstr_cmd);
    ta_register_command("mvwinnstr",mvwinnstr_cmd);
    ta_register_command("mvwinstr",mvwinstr_cmd);
    ta_register_command("winnstr",winnstr_cmd);
    ta_register_command("winstr",winstr_cmd);
}

