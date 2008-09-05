/*
 * File: ncurses/string/scanf_agent_vwscanw.c
 *
 * Author:
 * Version:  $Id: scanf_agent_vwscanw.c,v 1.1 2006/11/17 12:27:22 ivanov Exp $
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

#include "ncurses/string/scanf_agent.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

/*
 * The use of the vwscanw() and the vw_scanw() functions in the same file will not work, due to
 * the requirement to include varargs.h and stdarg.h which both contain definitions of va_list.
 */
int vwscanwDotsShell( WINDOW * win, char * fmt, ... ) {
    int res;
    #if 0 // #error GCC (version >= 4.0) no longer implements <varargs.h>.
        va_list argList;
        va_start( argList, fmt );
        res = vwscanw( win, fmt, argList );
        va_end( argList );
    #else
        va_list argList;
        va_start( argList, fmt );
        res = vw_scanw( win, fmt, argList );
        va_end( argList );
    #endif
    return res;
}
