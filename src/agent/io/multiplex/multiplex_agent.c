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


#include "process/process/process_common.h"
#include "io/multiplex/multiplex_agent.h"
#include <poll.h>
#include <errno.h>
#include <sys/select.h>

/********************************************************************/
/**                       PollFd List Reader                       **/
/********************************************************************/

#define POLL_NUM 16
#define FDSET_NUM 16

struct pollfd poll_list[POLL_NUM];
int fdset_rd[FDSET_NUM];
int fdset_wr[FDSET_NUM];
int fdset_er[FDSET_NUM];

nfds_t readPollFdList(TAInputStream* stream)
{
    nfds_t num, i;

    num = readLong(stream);

    assertion(num >= 0, "readPollFdList: num < 0");
    assertion(num <= POLL_NUM, "readPollFdList: num is greater then POLL_NUM");

    if(num == 0) return 0;

    for(i = 0; i < num; i++)
    {
        poll_list[i].fd = readInt(stream);
        poll_list[i].events = readShort(stream);
        poll_list[i].revents = readShort(stream);
    }

    return num;
}

void writePollFdList(TAThread thread, nfds_t num)
{
    nfds_t i;

    assertion(num > 0, "writePollFdList: num <= 0");

    writeLong(thread, num);

    for(i = 0; i < num; i++)
    {
        writeInt(thread, poll_list[i].fd);
        writeShort(thread, poll_list[i].events);
        writeShort(thread, poll_list[i].revents);
    }
}

int readFDSet(TAInputStream* stream, int *fdset)
{
    int num, i;

    num = readInt(stream);
    
    assertion(num >= -1, "readFDSet: num < -1");
    assertion(num <= FDSET_NUM, "readFDSet: size is greater then FDSET_NUM");

    if(num < 1) return num;

    for(i = 0; i < num; i++) fdset[i] = readInt(stream);

    return num;
}

void writeFDSet(TAThread thread, int *fdset, int num)
{
    int i;

    assertion(num >= -1, "writeFDSet: num <= 0");

    writeInt(thread, num);

    if(num < 1) return;

    for(i = 0; i < num; i++) writeInt(thread, fdset[i]);
}

void composeFDSet(fd_set* pfs, int* fdset, int num)
{
    int i;

    assertion(num <= FDSET_NUM, "composeFDSet: size is greater then FDSET_NUM");

    FD_ZERO(pfs);

    if(num < 1) return;

    for(i = 0; i < num; i++) FD_SET(fdset[i], pfs);
}

int translateFDSet(fd_set* pfs, int* fdset, int num)
{
    int i, v;
    
    if(num < 1) return num;

    assertion(num <= FDSET_NUM,
        "translateFDSet: size is greater then FDSET_NUM");

    for(i = 0, v = 0; i < num; i++)
    {
        if(!FD_ISSET(fdset[i], pfs)) fdset[i] = -1;
        else fdset[v++] = fdset[i];
    }

    return v;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict poll_cmd(TAThread thread, TAInputStream stream)
{
    int res, timeout;
    nfds_t nfds;

    // Prepare
    nfds = readPollFdList(&stream);
    timeout = readInt(&stream);

    START_TARGET_OPERATION(thread);
    errno = 0;
    res = poll(nfds == 0 ? NULL : poll_list, nfds, timeout); 
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    writePollFdList(thread, nfds);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict select_cmd(TAThread thread, TAInputStream stream)
{
    fd_set fdRd, fdWr, fdEr;
    int res, numr, numw, nume, nfds, btm;
    struct timeval timeout;
	
    // Prepare
    nfds = readInt(&stream);
    btm = readTimeVal(&stream, &timeout);
    numr = readFDSet(&stream, fdset_rd); composeFDSet(&fdRd, fdset_rd, numr);
    numw = readFDSet(&stream, fdset_wr); composeFDSet(&fdWr, fdset_wr, numw);
    nume = readFDSet(&stream, fdset_er); composeFDSet(&fdEr, fdset_er, nume);

    START_TARGET_OPERATION(thread);
    errno = 0;
	res = select (     nfds,
	                   numr == -1 ? NULL : &fdRd,
	                   numw == -1 ? NULL : &fdWr,
	                   nume == -1 ? NULL : &fdEr,
	                   btm == 0 ? NULL : &timeout
	             );
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);

    writeTimeVal(thread, &timeout);

    numr = translateFDSet(&fdRd, fdset_rd, numr);
    numw = translateFDSet(&fdWr, fdset_wr, numw);
    nume = translateFDSet(&fdEr, fdset_er, nume);

    writeFDSet(thread, fdset_rd, numr);
    writeFDSet(thread, fdset_wr, numw);
    writeFDSet(thread, fdset_er, nume);

    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_io_multiplex_commands(void)
{
    ta_register_command("poll", poll_cmd);
    ta_register_command("select", select_cmd);
}

