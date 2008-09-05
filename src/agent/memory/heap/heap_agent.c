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


#include "memory/heap/heap_agent.h"
#include <stdlib.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict calloc_cmd(TAThread thread,TAInputStream stream)
{
    size_t nelem;
    size_t elsize;
    void* res;

    // Prepare
    nelem = readSize(&stream);
    elsize = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;
    res = calloc(nelem, elsize);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno); 
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict free_cmd(TAThread thread,TAInputStream stream)
{
    void* ptr;

    // Prepare
    ptr = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    free(ptr);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict malloc_cmd(TAThread thread,TAInputStream stream)
{
    size_t size;
    void* res;

    // Prepare
    size = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;    
    res = malloc(size);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writeInt(thread, errno); 
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict posix_memalign_cmd(TAThread thread,TAInputStream stream)
{
    void *memptr;
    size_t alignment;
    size_t size;
    int res;

    // Prepare
    alignment = readSize(&stream);
    size = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = posix_memalign(&memptr, alignment, size);

    END_TARGET_OPERATION(thread);

    // Response
    if (res)
    {
        memptr = NULL;
    }
    
    writePointer(thread, memptr);
    writeInt(thread, res); 
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict realloc_cmd(TAThread thread,TAInputStream stream)
{
    void* ptr;    
    size_t size;
    void* res;

    // Prepare
    ptr = readPointer(&stream);
    size = readSize(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    errno = 0;    
    res = realloc(ptr, size);

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
void register_memory_heap_commands(void)
{
    ta_register_command("calloc",calloc_cmd);
    ta_register_command("free",free_cmd);
    ta_register_command("malloc",malloc_cmd);
    ta_register_command("posix_memalign",posix_memalign_cmd);
    ta_register_command("realloc",realloc_cmd);
}

