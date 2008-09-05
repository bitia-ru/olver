/* 
 * File: ncurses/terminal/control_agent.h
 * 
 * Author:
 * Version:  $Id: control_agent.h,v 1.1 2006/04/17 09:55:48 hed Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_TERMINAL_CONTROL_AGENT_H
#define TA_NCURSES_TERMINAL_CONTROL_AGENT_H

#include "common/agent.h"


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_control_commands(void);


#endif

