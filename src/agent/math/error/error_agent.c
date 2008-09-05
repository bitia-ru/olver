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


#include "math/error/error_agent.h"
#include <errno.h>
#include <math.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict erf_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = erf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erff_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = erff(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erfl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = erfl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erfc_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = erfc(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erfcf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = erfcf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erfcl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = erfcl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_error_commands(void)
{
    ta_register_command("erf",erf_cmd);
    ta_register_command("erff",erff_cmd);
    ta_register_command("erfl",erfl_cmd);
    ta_register_command("erfc",erfc_cmd);
    ta_register_command("erfcf",erfcf_cmd);
    ta_register_command("erfcl",erfcl_cmd);

}

