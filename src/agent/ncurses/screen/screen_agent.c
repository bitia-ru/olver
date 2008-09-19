/* 
 * File: ncurses/screen/screen_agent.c
 * 
 * Author:
 * Version:  $Id: screen_agent.c,v 1.4 2006/06/06 12:17:16 levenkov Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/screen/screen_agent.h"


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict scr_dump_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;
    char* sFileName;

    sFileName = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = scr_dump(sFileName);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict scr_init_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;
    char* sFileName;

    sFileName = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = scr_init(sFileName);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict scr_restore_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;
    char* sFileName;

    sFileName = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = scr_restore(sFileName);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict scr_set_cmd(TAThread thread,TAInputStream stream)
{
    // Prepare
    int res;
    char* sFileName;

    sFileName = (char*)readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    // Execute
    res = scr_set(sFileName);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}




/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_screen_commands(void)
{
    ta_register_command("scr_dump", scr_dump_cmd);
    ta_register_command("scr_init", scr_init_cmd);
    ta_register_command("scr_restore", scr_restore_cmd);
    ta_register_command("scr_set", scr_set_cmd);
}

