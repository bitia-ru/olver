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


#include "math/cexp/cexp_agent.h"
#include <complex.h>

double complex clog10(double complex x);

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cexp_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);

    res = cexp(x);
   
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cexpf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);

    res = cexpf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cexpl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = cexpl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clog_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = clog(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clogf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = clogf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clogl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = clogl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clog10_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = clog10(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clog10f_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = clog10f(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict clog10l_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = clog10l(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cpow_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, y, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    __real__ y = readDouble(&stream);
    __imag__ y = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = cpow(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cpowf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, y, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    __real__ y = readFloat(&stream);
    __imag__ y = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = cpowf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cpowl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, y, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    __real__ y = readLongDouble(&stream);
    __imag__ y = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = cpowl(x, y);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict csqrt_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = csqrt(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict csqrtf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = csqrtf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict csqrtl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = csqrtl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_cexp_commands(void)
{
    ta_register_command("cexp",cexp_cmd);
    ta_register_command("cexpf",cexpf_cmd);
    ta_register_command("cexpl",cexpl_cmd);
    ta_register_command("clog",clog_cmd);
    ta_register_command("clog10",clog10_cmd);
    ta_register_command("clog10f",clog10f_cmd);
    ta_register_command("clog10l",clog10l_cmd);
    ta_register_command("clogf",clogf_cmd);
    ta_register_command("clogl",clogl_cmd);
    ta_register_command("cpow",cpow_cmd);
    ta_register_command("cpowf",cpowf_cmd);
    ta_register_command("cpowl",cpowl_cmd);
    ta_register_command("csqrt",csqrt_cmd);
    ta_register_command("csqrtf",csqrtf_cmd);
    ta_register_command("csqrtl",csqrtl_cmd);
}

