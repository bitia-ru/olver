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


#include "math/complex/complex_agent.h"
#include <errno.h>
#include <math.h>
#include <complex.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cabs_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM, res;
    double complex x;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cabs(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cabsf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM, res;
    float complex x;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cabsf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cabsl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM, res;
    long double complex x;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cabsl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict carg_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM, res;
    double complex x;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = carg(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cargf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM, res;
    float complex x;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cargf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cargl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM, res;
    long double complex x;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cargl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cimag_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM, res;
    double complex x;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cimag(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cimagf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM, res;
    float complex x;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cimagf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cimagl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM, res;
    long double complex x;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cimagl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict conj_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = conj(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict conjf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = conjf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict conjl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = conjl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cproj_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cproj(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cprojf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cprojf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cprojl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cprojl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict creal_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM, res;
    double complex x;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = creal(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict crealf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM, res;
    float complex x;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = crealf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict creall_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM, res;
    long double complex x;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = creall(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_complex_commands(void)
{
    ta_register_command("cabs",cabs_cmd);
    ta_register_command("cabsf",cabsf_cmd);
    ta_register_command("cabsl",cabsl_cmd);
    ta_register_command("carg",carg_cmd);
    ta_register_command("cargf",cargf_cmd);
    ta_register_command("cargl",cargl_cmd);
    ta_register_command("cimag",cimag_cmd);
    ta_register_command("cimagf",cimagf_cmd);
    ta_register_command("cimagl",cimagl_cmd);
    ta_register_command("conj",conj_cmd);
    ta_register_command("conjf",conjf_cmd);
    ta_register_command("conjl",conjl_cmd);
    ta_register_command("cproj",cproj_cmd);
    ta_register_command("cprojf",cprojf_cmd);
    ta_register_command("cprojl",cprojl_cmd);
    ta_register_command("creal",creal_cmd);
    ta_register_command("crealf",crealf_cmd);
    ta_register_command("creall",creall_cmd);
}

