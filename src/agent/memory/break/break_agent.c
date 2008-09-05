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

#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>

#include "common/agent.h"
#include "memory/break/break_agent.h"
    
/********************************************************************/
/**                             Emulator                           **/
/********************************************************************/

#define MAX_BREAK_VALUE 1024

void* pstart_brk = NULL;
void* pcur_brk = NULL;
void* pmax_brk = NULL;

int ta_init_break_system(void)
{
    pstart_brk = ta_alloc_memory(MAX_BREAK_VALUE);

    if(errno == ENOMEM) return -1;

    memset(pstart_brk, 0xAA, MAX_BREAK_VALUE);

    pcur_brk = pmax_brk = pstart_brk;

    return 0;
}

void* ta_sbrk(intptr_t incr)
{
    if(pstart_brk == NULL)
        if(ta_init_break_system() != 0)
            return (void*)-1;

    pcur_brk += incr;

    if((char*)pcur_brk - (char*)pstart_brk > MAX_BREAK_VALUE)
    {
        errno = ENOMEM;
        pcur_brk -= incr;

        return (void*)-1;
    }

    if((char*)pcur_brk - (char*)pmax_brk > 0)
    {
        memset(pmax_brk, 0, (char*)pcur_brk - (char*)pmax_brk);
        pmax_brk = pcur_brk;
    }

    return pcur_brk - incr;
}

int ta_brk(void* ptr)
{
    return ta_sbrk((char*)ptr - (char*)pcur_brk) == (void*)-1 ? -1 : 0;
}

/********************************************************************/
/**                             Support                            **/
/********************************************************************/

TACommandVerdict getmemmode_cmd(TAThread thread, TAInputStream stream)
{
    int res = ta_is_standard_memode();
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict brk_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    int res;
    void* addr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = /*ta_*/brk(addr);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sbrk_cmd(TAThread thread, TAInputStream stream)
{
    // Prepare
    void* res;
    intptr_t incr = readInt/*Ptr*/(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = /*ta_*/sbrk(incr);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_memory_break_commands(void)
{
    ta_register_command("brk", brk_cmd);
    ta_register_command("sbrk", sbrk_cmd);
    ta_register_command("getmemmode", getmemmode_cmd);
}

