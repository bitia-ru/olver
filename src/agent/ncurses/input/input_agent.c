/* 
 * File: ncurses/input/input_agent.c
 * 
 * Author:
 * Version:  $Id: input_agent.c,v 1.5 2007/07/25 11:10:54 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/input/input_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cbreak_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = cbreak();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict flushinp_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = flushinp();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict halfdelay_cmd(TAThread thread,TAInputStream stream)
{
    int res, tenth;
    
    tenth = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = halfdelay(tenth);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nl_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = nl();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nocbreak_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = nocbreak();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nonl_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = nonl();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict noraw_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = noraw();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict raw_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = raw();
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_input_input_commands(void)
{
    ta_register_command("cbreak",cbreak_cmd);
    ta_register_command("flushinp",flushinp_cmd);
    ta_register_command("halfdelay",halfdelay_cmd);
    ta_register_command("nl",nl_cmd);
    ta_register_command("nocbreak",nocbreak_cmd);
    ta_register_command("nonl",nonl_cmd);
    ta_register_command("noraw",noraw_cmd);
    ta_register_command("raw",raw_cmd);
}

