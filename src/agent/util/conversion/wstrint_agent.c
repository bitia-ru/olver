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


#include "util/conversion/wstrint_agent.h"
#include <errno.h>
#include <wchar.h>
#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict wcstol_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    long res;
    int base, orient, endptr_isnull;

/*    freopen(NULL, "a+", stdout);
    orient=fwide(stdout, 0);
    wprintf(L"Before wcstol(wprintf): mode==%ls\n", orient>0?L"Wide": orient<0?L"Byte":L"Non oriented");
    wprintf(L"Test==%ls\n", test);
*/
    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

//    wprintf(L"nptr==%ls\n", nptr);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstol(nptr, (wchar_t**)NULL, base);
    else
        res = wcstol(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

//    wprintf(L"nptr==%ls\n", nptr);
//    wprintf(L"endptr==%ls\n", endptr);

    // Response    
    writeLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcstoll_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    long long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstoll(nptr, (wchar_t**)NULL, base);
    else
        res = wcstoll(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeLLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}
static TACommandVerdict wcstoq_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    long long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstoq(nptr, (wchar_t**)NULL, base);
    else
        res = wcstoq(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeLLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcstoul_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    unsigned long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstoul(nptr, (wchar_t**)NULL, base);
    else
        res = wcstoul(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeULong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcstoull_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    unsigned long long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstoull(nptr, (wchar_t**)NULL, base);
    else
        res = wcstoull(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeULLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __wcstol_internal_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = __wcstol_internal(nptr, (wchar_t**)NULL, base, 0);
    else
        res = __wcstol_internal(nptr, &endptr, base, 0);
    END_TARGET_OPERATION(thread);

    // Response    
    writeLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict __wcstoul_internal_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    unsigned long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = __wcstoul_internal(nptr, (wchar_t**)NULL, base, 0);
    else
        res = __wcstoul_internal(nptr, &endptr, base, 0);
    END_TARGET_OPERATION(thread);

    // Response    
    writeULong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcstoimax_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    intmax_t res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstoimax(nptr, (wchar_t**)NULL, base);
    else
        res = wcstoimax(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeLLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcstoumax_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr;
    uintmax_t res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstoumax(nptr, (wchar_t**)NULL, base);
    else
        res = wcstoumax(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeULLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wcstouq_cmd(TAThread thread,TAInputStream stream)
{
    wchar_t* nptr, *endptr ;
    unsigned long long res;
    int base, orient, endptr_isnull;

    // Prepare       
    nptr=(wchar_t*)readPointer(&stream);
    endptr_isnull=readInt(&stream);
    base=readInt(&stream);

    // Execute    
    START_TARGET_OPERATION(thread);
    errno=0;
    if(endptr_isnull)
        res = wcstouq(nptr, (wchar_t**)NULL, base);
    else
        res = wcstouq(nptr, &endptr, base);
    END_TARGET_OPERATION(thread);

    // Response    
    writeULLong(thread, res);
    if(!endptr_isnull)
        writePointer(thread, endptr);
    writeInt(thread, errno);

    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_wstrint_commands(void)
{
    ta_register_command("wcstol",wcstol_cmd);
    ta_register_command("wcstoll",wcstoll_cmd);
    ta_register_command("wcstoul",wcstoul_cmd);
    ta_register_command("wcstoull",wcstoull_cmd);
    ta_register_command("__wcstol_internal",__wcstol_internal_cmd);
    ta_register_command("__wcstoul_internal",__wcstoul_internal_cmd);
    ta_register_command("wcstoimax",wcstoimax_cmd);
    ta_register_command("wcstoq",wcstoq_cmd);
    ta_register_command("wcstoumax",wcstoumax_cmd);
    ta_register_command("wcstouq",wcstouq_cmd);
}

