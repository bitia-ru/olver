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


#include "util/search/queue_agent.h"

#include <stdio.h>
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict insque_cmd(TAThread thread,TAInputStream stream)
{
    void *element, *pred;

    element = (void*)readPointer(&stream);
    pred = (void*)readPointer(&stream);
 
    START_TARGET_OPERATION(thread);
    
    insque(element, pred);
    
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict remque_cmd(TAThread thread,TAInputStream stream)
{
    void* element;

    element = (void*)readPointer(&stream);
   
    START_TARGET_OPERATION(thread);
    
    remque(element);
    
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict create_circular_queue_cmd(TAThread thread,TAInputStream stream)
{
    void* element;

    element = (void*)readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    ((void**)element)[0] = element;
    ((void**)element)[1] = element;
    
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict create_linear_queue_cmd(TAThread thread,TAInputStream stream)
{
    void* element;

    element = (void*)readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    
    ((void**)element)[0] = NULL;
    ((void**)element)[1] = NULL;
    
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict read_queue_element_cmd(TAThread thread,TAInputStream stream)
{
    void* element;

    element = (void*)readPointer(&stream);
    
    //Response
    writePointer(thread, (void*) ((void**)element)[0]);
    writePointer(thread, (void*) ((void**)element)[1]);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_search_queue_commands(void)
{
    ta_register_command("read_queue_element",read_queue_element_cmd);
    ta_register_command("create_circular_queue",create_circular_queue_cmd);
    ta_register_command("create_linear_queue",create_linear_queue_cmd);
    ta_register_command("insque",insque_cmd);
    ta_register_command("remque",remque_cmd);
}

