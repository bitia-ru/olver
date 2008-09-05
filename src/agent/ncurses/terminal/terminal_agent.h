/* 
 * File: ncurses/terminal/terminal_agent.h
 * 
 * Author:
 * Version:  $Id: terminal_agent.h,v 1.1 2006/04/17 09:56:58 hed Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_TERMINAL_AGENT_H
#define TA_NCURSES_TERMINAL_AGENT_H

#include "common/agent.h"


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_terminal_commands(void);


#endif

