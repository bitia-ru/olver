/* 
 * File: ncurses/window/refresh_agent.h
 * 
 * Author:
 * Version:  $Id: refresh_agent.h,v 1.1 2006/04/17 09:56:48 hed Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#ifndef TA_NCURSES_WINDOW_REFRESH_AGENT_H
#define TA_NCURSES_WINDOW_REFRESH_AGENT_H

#include "common/agent.h"


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_window_refresh_commands(void);


#endif

