/*
 * File: ncurses/string/printf_agent.h
 *
 * Author:
 * Version:  $Id: printf_agent.h,v 1.3 2006/11/08 12:43:45 ivanov Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_STRING_PRINTF_AGENT_H
#define TA_NCURSES_STRING_PRINTF_AGENT_H

#include <curses.h>
#include "common/agent.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vw_printwDotsShell( WINDOW * win, char * fmt, ... );

int vwprintwDotsShell( WINDOW * win, char * fmt, ... );

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_ncurses_string_printf_commands(void);

#endif
