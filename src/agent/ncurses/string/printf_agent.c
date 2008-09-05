/*
 * File: ncurses/string/printf_agent.c
 *
 * Author:
 * Version:  $Id: printf_agent.c,v 1.3 2006/11/08 12:43:45 ivanov Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include <stdarg.h>
#include "ncurses/string/printf_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vw_printwDotsShell( WINDOW * win, char * fmt, ... ) {
    int res;
    va_list argList;
    va_start( argList, fmt );
    res = vw_printw( win, fmt, argList );
    va_end( argList );
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict mvprintw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = mvprintw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict mvwprintw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = mvwprintw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict printw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = printw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vw_printw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vw_printw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vwprintw_cmd(TAThread thread,TAInputStream stream)
{
    sendException( thread, "#error GCC (version >= 4.0) no longer implements <varargs.h>." );
    return taDefaultVerdict;
}

static TACommandVerdict wprintw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = wprintw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_ncurses_string_printf_commands(void)
{
    // ta_register_command( "mvprintw" , mvprintw_cmd  );
    // ta_register_command( "mvwprintw", mvwprintw_cmd );
    // ta_register_command( "printw"   , printw_cmd    );
    // ta_register_command( "vw_printw", vw_printw_cmd );
    ta_register_command   ( "vwprintw" , vwprintw_cmd  );
    // ta_register_command( "wprintw"  , wprintw_cmd   );

    ta_register_command( "functionWithDotsCall", functionWithDotsCall_cmd );
}
