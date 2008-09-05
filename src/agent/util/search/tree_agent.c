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


#include "util/search/tree_agent.h"

#include <search.h>
#include <stdio.h>

/********************************************************************/
/**                        Callback Operations                     **/
/********************************************************************/
static void ta_tree_visit_action(const void *node, VISIT visit, int level)
{
    TAThread    thread = ta_current_thread();
    writeType_TAStream(thread, "visit");
    writePointer(thread, (void*)node);
    if(NULL!=node)
        writePointer(thread, *((void**)node) );
    writeInt(thread, visit);
    writeInt(thread, level);
}

static int ta_tree_compare_action(const void *v1, const void *v2)
{
    long long res = 0;
    TAThread    thread = ta_current_thread();
    writeType_TAStream(thread, "compare");
    writePointer(thread, (void*)v1);
    writePointer(thread, (void*)v2);

    res = (long long)((unsigned int)v1)-(long long)((unsigned int)v2);
    return (res>0)?1:(res==0?0:-1);
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict tdelete_cmd(TAThread thread,TAInputStream stream)
{
    void *pkey;
    void *proot;
    void *pres;

    pkey = readPointer(&stream);
    proot = readPointer(&stream);

    /* Execute */
    START_TARGET_OPERATION(thread);
    pres = tdelete( pkey, &proot, ta_tree_compare_action);
    END_TARGET_OPERATION(thread);

    writePointer(thread,(void*)pres);
    writePointer(thread,(void*)proot);

    if(proot)
        writePointer(thread,*(void**)proot);
    else
        writePointer(thread, (void*)NULL);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tfind_cmd(TAThread thread,TAInputStream stream)
{
    void *pkey;
    void *proot;
    void *pres;

    pkey = readPointer(&stream);
    proot = readPointer(&stream);

    /* Execute */
    START_TARGET_OPERATION(thread);
    pres = tfind(pkey, &proot, ta_tree_compare_action);
    END_TARGET_OPERATION(thread);

    writePointer(thread,(void*)pres);
    writePointer(thread,(void*)proot);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tsearch_cmd(TAThread thread,TAInputStream stream)
{
    void *pkey;
    void *proot;
    void *pres;

    pkey = readPointer(&stream);
    proot = readPointer(&stream);

    /* Execute */
    START_TARGET_OPERATION(thread);
    pres = tsearch(pkey, &proot, ta_tree_compare_action);
    END_TARGET_OPERATION(thread);

    writePointer(thread,(void*)pres);
    writePointer(thread,(void*)proot);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict twalk_cmd(TAThread thread,TAInputStream stream)
{
    void *proot;

    proot = readPointer(&stream);

    /* Execute */
    START_TARGET_OPERATION(thread);
    twalk(proot, (__action_fn_t)ta_tree_visit_action);
    END_TARGET_OPERATION(thread);

    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_search_tree_commands(void)
{
    ta_register_command("tdelete",tdelete_cmd);
    ta_register_command("tfind",tfind_cmd);
    ta_register_command("tsearch",tsearch_cmd);
    ta_register_command("twalk",twalk_cmd);
}

