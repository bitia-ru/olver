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


#include "math/chyper/chyper_agent.h"
#include <math.h>
#include <complex.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cacosh_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cacosh(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cacoshf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cacoshf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict cacoshl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = cacoshl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict casinh_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = casinh(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict casinhf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = casinhf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict casinhl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = casinhl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict catanh_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = catanh(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict catanhf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = catanhf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict catanhl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = catanhl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ccosh_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = ccosh(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ccoshf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = ccoshf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ccoshl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = ccoshl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict csinh_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = csinh(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict csinhf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = csinhf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict csinhl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = csinhl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ctanh_cmd(TAThread thread,TAInputStream stream)
{
    double RE, IM;
    double complex x, res;

    RE = readDouble(&stream);
    IM = readDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = ctanh(x);

    END_TARGET_OPERATION(thread);
 
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);

    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ctanhf_cmd(TAThread thread,TAInputStream stream)
{
    float RE, IM;
    float complex x, res;

    RE = readFloat(&stream);
    IM = readFloat(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = ctanhf(x);

    END_TARGET_OPERATION(thread);

    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ctanhl_cmd(TAThread thread,TAInputStream stream)
{
    long double RE, IM;
    long double complex x, res;

    RE = readLongDouble(&stream);
    IM = readLongDouble(&stream);
    
    __real__ x = RE;
    __imag__ x = IM;

    START_TARGET_OPERATION(thread);

    res = ctanhl(x);

    END_TARGET_OPERATION(thread);

    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_chyper_commands(void)
{
    ta_register_command("cacosh",cacosh_cmd);
    ta_register_command("cacoshf",cacoshf_cmd);
    ta_register_command("cacoshl",cacoshl_cmd);
    ta_register_command("casinh",casinh_cmd);
    ta_register_command("casinhf",casinhf_cmd);
    ta_register_command("casinhl",casinhl_cmd);
    ta_register_command("catanh",catanh_cmd);
    ta_register_command("catanhf",catanhf_cmd);
    ta_register_command("catanhl",catanhl_cmd);
    ta_register_command("ccosh",ccosh_cmd);
    ta_register_command("ccoshf",ccoshf_cmd);
    ta_register_command("ccoshl",ccoshl_cmd);
    ta_register_command("csinh",csinh_cmd);
    ta_register_command("csinhf",csinhf_cmd);
    ta_register_command("csinhl",csinhl_cmd);
    ta_register_command("ctanh",ctanh_cmd);
    ta_register_command("ctanhf",ctanhf_cmd);
    ta_register_command("ctanhl",ctanhl_cmd);
}

