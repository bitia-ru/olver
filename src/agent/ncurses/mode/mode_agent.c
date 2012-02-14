/* 
 * File: ncurses/mode/mode_agent.c
 * 
 * Author:
 * Version:  $Id: mode_agent.c,v 1.3 2006/10/11 07:26:49 levenkov Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/mode/mode_agent.h"
#include <curses.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict def_prog_mode_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = def_prog_mode();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict def_shell_mode_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = def_shell_mode();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict reset_prog_mode_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = reset_prog_mode();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict reset_shell_mode_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = reset_shell_mode();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict resetty_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = resetty();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict savetty_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    
    START_TARGET_OPERATION(thread);
    
    // Execute
    res = savetty();
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_mode_commands(void)
{
    ta_register_command("def_prog_mode", def_prog_mode_cmd);
    ta_register_command("def_shell_mode", def_shell_mode_cmd);
    ta_register_command("reset_prog_mode", reset_prog_mode_cmd);
    ta_register_command("reset_shell_mode", reset_shell_mode_cmd);
    ta_register_command("resetty", resetty_cmd);
    ta_register_command("savetty", savetty_cmd);
}

