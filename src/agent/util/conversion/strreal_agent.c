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


#include "util/conversion/strreal_agent.h"
#include <stdlib.h>
#include <errno.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict __strtod_internal_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    char * endptr;
    double res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  __strtod_internal(st, &endptr, 0);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDouble(thread, res);
    writeInt(thread, (int)( endptr - st));
    writeInt(thread, errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict __strtof_internal_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    char * endptr;
    float res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  __strtof_internal(st, &endptr, 0);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeFloat(thread, res);
    writeInt(thread, (int)( endptr - st));
    writeInt(thread, errno);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict __strtold_internal_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    char * endptr;
    long double res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  __strtold_internal(st, &endptr, 0);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeLongDouble(thread, res);
    writeInt(thread, (int)( endptr - st));
    writeInt(thread, errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atof_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    double res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  atof(st);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDouble(thread, res);
    writeInt(thread, errno);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ecvt_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    double value;
    int ndigit;
    int decpt;
    int sign;
    
    // Prepare
    value = readDouble(&stream);
    ndigit = readInt(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res = ecvt(value, ndigit, &decpt, &sign);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeString(thread, res);
    writeInt(thread, decpt);
    writeInt(thread, sign);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict fcvt_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    double value;
    int ndigit;
    int decpt;
    int sign;
    
    // Prepare
    value = readDouble(&stream);
    ndigit = readInt(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res = fcvt(value, ndigit, &decpt, &sign);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeString(thread, res);
    writeInt(thread, decpt);
    writeInt(thread, sign);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict gcvt_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    double value;
    int ndigit;
    char* buf;
    
    // Prepare
    value = readDouble(&stream);
    ndigit = readInt(&stream);
    buf = ta_alloc_memory(1000); 
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res = gcvt(value, ndigit, buf);
    END_TARGET_OPERATION(thread);
    
    
    // Response
    writeString(thread, res);
    writeString(thread, buf);
    
    sendResponse(thread);
    
    ta_dealloc_memory(buf);

    return taDefaultVerdict;
}

static TACommandVerdict strtod_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    char * endptr;
    double res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  strtod(st, &endptr);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeDouble(thread, res);
    writeInt(thread, (int)( endptr - st));
    writeInt(thread, errno);
//    ta_dealloc_memory(st);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict strtof_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    char * endptr;
    float res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  strtof(st, &endptr);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeFloat(thread, res);
    writeInt(thread, (int)(endptr - st));
    writeInt(thread, errno);
//    ta_dealloc_memory(st);
    
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict strtold_cmd(TAThread thread,TAInputStream stream)
{
	char* st;
    char * endptr;
    long double res;

    // Prepare
    st = readString(&stream);
    
    errno = 0;
    START_TARGET_OPERATION(thread);
    res =  strtold(st, &endptr);
    END_TARGET_OPERATION(thread);
    
    // Response
    writeLongDouble(thread, res);
    writeInt(thread, (int)( endptr - st));
    writeInt(thread, errno);
//    ta_dealloc_memory(st);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_util_conversion_strreal_commands(void)
{
    ta_register_command("__strtod_internal",__strtod_internal_cmd);
    ta_register_command("__strtof_internal",__strtof_internal_cmd);
    ta_register_command("__strtold_internal",__strtold_internal_cmd);
    ta_register_command("atof",atof_cmd);
    ta_register_command("ecvt",ecvt_cmd);
    ta_register_command("fcvt",fcvt_cmd);
    ta_register_command("gcvt",gcvt_cmd);
    ta_register_command("strtod",strtod_cmd);
    ta_register_command("strtof",strtof_cmd);
    ta_register_command("strtold",strtold_cmd);
}

