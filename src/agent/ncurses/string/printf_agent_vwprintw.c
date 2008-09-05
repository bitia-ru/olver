/*
 * File: ncurses/string/printf_agent_vwprintw.c
 *
 * Author:
 * Version:  $Id: printf_agent_vwprintw.c,v 1.1 2006/11/08 12:51:39 ivanov Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#if 0 // #error GCC (version >= 4.0) no longer implements <varargs.h>.
    #include <varargs.h>
#else
    #include <stdarg.h>
#endif

#include "ncurses/string/printf_agent.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

/*
 * The use of the vwprintw() and the vw_printw() functions in the same file will not work, due to
 * the requirement to include varargs.h and stdarg.h which both contain definitions of va_list.
 */
int vwprintwDotsShell( WINDOW * win, char * fmt, ... ) {
    int res;
    #if 0 // #error GCC (version >= 4.0) no longer implements <varargs.h>.
        va_list argList;
        va_start( argList, fmt );
        res = vwprintw( win, fmt, argList );
        va_end( argList );
    #else
        va_list argList;
        va_start( argList, fmt );
        res = vw_printw( win, fmt, argList );
        va_end( argList );
    #endif
    return res;
}
