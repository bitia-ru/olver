/* 
 * File: ncurses/chstr/add_agent.c
 * 
 * Author:
 * Version:  $Id: add_agent.c,v 1.5 2006/05/11 09:46:11 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/chstr/add_agent.h"
#include <curses.h>

chtype readChType(TAInputStream *stream);

/********************************************************************/
/**                           Readers                             **/
/********************************************************************/
chtype* readChStr(TAInputStream *stream)
{
    chtype* res = 0;
    int size;
    int i=0;
    
    verifyType_TAInputStream(stream, "charray");

    size=readInt(stream);

    res= (chtype*) ta_alloc_memory(size*sizeof(chtype));

    
    for (i=0;i<size;i++)
    {
        res[i]= readChType(stream);
    }
   
    return res;
}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict addchnstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int n;
    int res;
    
    chstr = readChStr(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = addchnstr(chstr, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
    
}

static TACommandVerdict addchstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int n;
    int res;
    
    chstr = readChStr(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = addchstr(chstr);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
    
}

static TACommandVerdict mvaddchnstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int n;
    int res;
    int y;
    int x;
    
    y=readInt(&stream);
    x=readInt(&stream);
    chstr = readChStr(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvaddchnstr(y, x, chstr, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvaddchstr_cmd(TAThread thread,TAInputStream stream)
{
    chtype *chstr;
    int res;
    int y;
    int x;
    
    y=readInt(&stream);
    x=readInt(&stream);
    chstr = readChStr(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvaddchstr(y, x, chstr);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvwaddchnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int n;
    int res;
    int y;
    int x;
    
    win = readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    chstr = readChStr(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvwaddchnstr(win, y, x, chstr, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict mvwaddchstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int res;
    int y;
    int x;
    
    win = readPointer(&stream);
    y=readInt(&stream);
    x=readInt(&stream);
    chstr = readChStr(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = mvwaddchstr(win, y, x, chstr);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict waddchnstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int n;
    int res;
    
    win = readPointer(&stream);
    chstr = readChStr(&stream);
    n = readInt(&stream);
    
    
    START_TARGET_OPERATION(thread);
    res = waddchnstr(win, chstr, n);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}

static TACommandVerdict waddchstr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    chtype *chstr;
    int n;
    int res;
    
    win = readPointer(&stream);
    chstr = readChStr(&stream);
    
    START_TARGET_OPERATION(thread);
    res = waddchstr(win, chstr);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    ta_dealloc_memory(chstr);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_chstr_add_commands(void)
{
    ta_register_command("addchnstr",addchnstr_cmd);
    ta_register_command("addchstr",addchstr_cmd);
    ta_register_command("mvaddchnstr",mvaddchnstr_cmd);
    ta_register_command("mvaddchstr",mvaddchstr_cmd);
    ta_register_command("mvwaddchnstr",mvwaddchnstr_cmd);
    ta_register_command("mvwaddchstr",mvwaddchstr_cmd);
    ta_register_command("waddchnstr",waddchnstr_cmd);
    ta_register_command("waddchstr",waddchstr_cmd);
}

