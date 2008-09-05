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


#include "math/integer/integer_agent.h"
#include <inttypes.h>
#include "common/ta_stream.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict abs_cmd(TAThread thread,TAInputStream stream)
{
    int i;
    int res;
    
    /* Prepare */
    i = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = abs(i);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict div_cmd(TAThread thread,TAInputStream stream)
{
    int numer;
    int denom;
    div_t res;
    
    /* Prepare */
    numer = readInt(&stream);
    denom = readInt(&stream);    
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = div(numer,denom);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeInt(thread, res.quot);
    writeInt(thread, res.rem);    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict imaxabs_cmd(TAThread thread,TAInputStream stream)
{
    intmax_t i;
    intmax_t res;
    
    /* Prepare */
    i = readIntMax(&stream);
    
    START_TARGET_OPERATION(thread);

    /* Execute */
    res = imaxabs(i);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeIntMax(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict imaxdiv_cmd(TAThread thread,TAInputStream stream)
{
    intmax_t numer;
    intmax_t denom;
    imaxdiv_t res;
    
    /* Prepare */
    numer = readIntMax(&stream);
    denom = readIntMax(&stream);    
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = imaxdiv(numer,denom);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeIntMax(thread, res.quot);
    writeIntMax(thread, res.rem);    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict labs_cmd(TAThread thread,TAInputStream stream)
{
    long i;
    long res;
    
    /* Prepare */
    i = readLong(&stream);
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = labs(i);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
    
}

static TACommandVerdict llabs_cmd(TAThread thread,TAInputStream stream)
{
    long long i;
    long long res;
    
    /* Prepare */
    i = readLLong(&stream);
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = llabs(i);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeLLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
    
}

static TACommandVerdict ldiv_cmd(TAThread thread,TAInputStream stream)
{
    long numer;
    long denom;
    ldiv_t res;
    
    /* Prepare */
    numer = readLong(&stream);
    denom = readLong(&stream);    
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = ldiv(numer,denom);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeLong(thread, res.quot);
    writeLong(thread, res.rem);    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lldiv_cmd(TAThread thread,TAInputStream stream)
{
    long long numer;
    long long denom;
    lldiv_t res;
    
    /* Prepare */
    numer = readLLong(&stream);
    denom = readLLong(&stream);    
    
    START_TARGET_OPERATION(thread);
    
    /* Execute */
    res = lldiv(numer,denom);
    
    END_TARGET_OPERATION(thread);
    
    /* Response */
    writeLLong(thread, res.quot);
    writeLLong(thread, res.rem);    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_integer_commands(void)
{
    ta_register_command("abs",abs_cmd);
    ta_register_command("div",div_cmd);
    ta_register_command("imaxabs",imaxabs_cmd);
    ta_register_command("imaxdiv",imaxdiv_cmd);
    ta_register_command("labs",labs_cmd);
    ta_register_command("ldiv",ldiv_cmd);
    ta_register_command("llabs",llabs_cmd);
    ta_register_command("lldiv",lldiv_cmd);
}

