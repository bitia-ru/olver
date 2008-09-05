/*
 * File: ncurses/string/scanf_agent.h
 *
 * Author:
 * Version:  $Id: scanf_agent.h,v 1.2 2006/11/08 12:43:45 ivanov Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_STRING_SCANF_AGENT_H
#define TA_NCURSES_STRING_SCANF_AGENT_H

#include <curses.h>
#include "common/agent.h"

/********************************************************************/
/**                       Helper Functions                         **/
/********************************************************************/

int vw_scanwDotsShell( WINDOW * win, char * fmt, ... );

int vwscanwDotsShell( WINDOW * win, char * fmt, ... );

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/

void register_ncurses_string_scanf_commands(void);

#endif
