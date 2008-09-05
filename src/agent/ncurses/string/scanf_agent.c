/*
 * File: ncurses/string/scanf_agent.c
 *
 * Author:
 * Version:  $Id: scanf_agent.c,v 1.3 2006/11/17 12:27:22 ivanov Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include <stdarg.h>
#include "ncurses/string/scanf_agent.h"
#include "process/process/process_common.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vw_scanwDotsShell( WINDOW * win, char * fmt, ... ) {
    int res;
    va_list argList;
    va_start( argList, fmt );
    res = vw_scanw( win, fmt, argList );
    va_end( argList );
    return res;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict mvscanw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = mvscanw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict mvwscanw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = mvwscanw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict scanw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = scanw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vw_scanw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = vw_scanw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

static TACommandVerdict vwscanw_cmd(TAThread thread,TAInputStream stream)
{
    sendException( thread, "#error GCC (version >= 4.0) no longer implements <varargs.h>." );
    return taDefaultVerdict;
}

static TACommandVerdict wscanw_cmd(TAThread thread,TAInputStream stream)
{
/****
    // Prepare
    // TO DO: Read parameters

    START_TARGET_OPERATION(thread);

    // Execute
    // TO DO: Call target function
    res = wscanw(...);

    END_TARGET_OPERATION(thread);

    // Response
    // TO DO: Write response
****/

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_ncurses_string_scanf_commands(void)
{
    // ta_register_command( "mvscanw" , mvscanw_cmd  );
    // ta_register_command( "mvwscanw", mvwscanw_cmd );
    // ta_register_command( "scanw"   , scanw_cmd    );
    // ta_register_command( "vw_scanw", vw_scanw_cmd );
    ta_register_command   ( "vwscanw" , vwscanw_cmd  );
    // ta_register_command( "wscanw"  , wscanw_cmd   );

    ta_register_command( "functionWithDotsCall", functionWithDotsCall_cmd );
}
