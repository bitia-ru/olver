/* 
 * File: ncurses/chstr/input_agent.c
 * 
 * Author:
 * Version:  $Id: input_agent.c,v 1.13 2006/05/11 10:23:25 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/chstr/input_agent.h"
#include <curses.h>

void writeChType(TAThread thread, chtype val);

void writeChStr(TAThread thread, chtype *chstr, int lim)
{
    int i;
    int num=0;
 
    for (i=0;i<lim;i++)
    {
        if ((chstr[i] & A_CHARTEXT)==0)
        {
            break;
        }
        num++;
    }
    
    writeInt(thread, num);
    
    for (i=0;i<num;i++)
    {
        writeChType(thread, chstr[i]);
    }

}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict inchnstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int n;
    int res;
    
    n=readInt(&stream);
    chstr=(chtype *)ta_alloc_memory((n+1)*sizeof(chtype));

    START_TARGET_OPERATION(thread);
    res = inchnstr(chstr, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeChStr(thread, chstr, n);
 
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict inchstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int res;
    int num=0;
    
    chstr=(chtype *)ta_alloc_memory((COLS+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = inchstr(chstr);
    END_TARGET_OPERATION(thread);
   
    writeInt(thread, res);
    writeChStr(thread, chstr, COLS);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvinchnstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int n;
    int res;
    int y, x;
    
    y=readInt(&stream);
    x=readInt(&stream);
    n=readInt(&stream);
    chstr=(chtype *)ta_alloc_memory((n+1)*sizeof(chtype));

    START_TARGET_OPERATION(thread);
    res = mvinchnstr(y, x, chstr, n);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeChStr(thread, chstr, n);
    
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvinchstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int res;
    int num=0;
    int y, x;
    
    y=readInt(&stream);
    x=readInt(&stream);
     
    chstr=(chtype *)ta_alloc_memory((COLS+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = mvinchstr(y, x, chstr);
    END_TARGET_OPERATION(thread);
   
    writeInt(thread, res);
    writeChStr(thread, chstr, COLS);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvwinchnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int n;
    int res;
    int y, x;
    

    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    n=readInt(&stream);
    chstr=(chtype *)ta_alloc_memory((n+1)*sizeof(chtype));

    START_TARGET_OPERATION(thread);
    res = mvwinchnstr(win, y, x, chstr, n);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    writeChStr(thread, chstr, n);
    
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvwinchstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int res;
    int y, x;
    
    
    win=readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    chstr=(chtype *)ta_alloc_memory((COLS+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = mvwinchstr(win, y, x, chstr);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeChStr(thread, chstr, COLS);
    
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict winchnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int n;
    int res;
    
   
    win=readPointer(&stream);
    n=readInt(&stream);
    chstr=(chtype *)ta_alloc_memory((n+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = winchnstr(win, chstr, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeChStr(thread, chstr, n);
    
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict winchstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int res;
    
    win=readPointer(&stream);
    chstr=(chtype *)ta_alloc_memory((COLS+1)*sizeof(chtype));
    
    START_TARGET_OPERATION(thread);
    res = winchstr(win, chstr);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeChStr(thread, chstr, COLS);
    
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_chstr_input_commands(void)
{
    ta_register_command("inchnstr",inchnstr_cmd);
    ta_register_command("inchstr",inchstr_cmd);
    ta_register_command("mvinchnstr",mvinchnstr_cmd);
    ta_register_command("mvinchstr",mvinchstr_cmd);
    ta_register_command("mvwinchnstr",mvwinchnstr_cmd);
    ta_register_command("mvwinchstr",mvwinchstr_cmd);
    ta_register_command("winchnstr",winchnstr_cmd);
    ta_register_command("winchstr",winchstr_cmd);
}

