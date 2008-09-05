/*
 * Copyright (c) 2005-2006 Institute for System Programming
 * Russian Academy of Sciences
 * All rights reserved. 
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at 
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef TA_SOCKET_NETDB_AGENT_H
#define TA_SOCKET_NETDB_AGENT_H

#include "common/agent.h"
#include <netdb.h>

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_socket_netdb_commands(void);


void writeServent(TAThread thread, struct servent * se);
void writeProtoent(TAThread thread, struct protoent * pe);
void writeHostent(TAThread thread, struct hostent * he);
void writeAddrinfo(TAThread thread, struct addrinfo * ai);
/**/

#endif

