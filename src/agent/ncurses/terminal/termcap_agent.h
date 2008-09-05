/* 
 * File: ncurses/terminal/termcap_agent.h
 * 
 * Author:
 * Version:  $Id: termcap_agent.h,v 1.1 2006/04/17 09:56:58 hed Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_TERMINAL_TERMCAP_AGENT_H
#define TA_NCURSES_TERMINAL_TERMCAP_AGENT_H

#include "common/agent.h"


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_termcap_commands(void);


#endif

