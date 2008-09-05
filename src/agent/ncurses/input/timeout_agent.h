/* 
 * File: ncurses/input/timeout_agent.h
 * 
 * Author:
 * Version:  $Id: timeout_agent.h,v 1.3 2006/06/09 05:32:23 aram Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_INPUT_TIMEOUT_AGENT_H
#define TA_NCURSES_INPUT_TIMEOUT_AGENT_H

#include "common/agent.h"
#include "ncurses/border/border_agent.h"


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_input_timeout_commands(void);


#endif

