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


#include "math/gamma/gamma_agent.h"
#include <errno.h>
#include <math.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict gamma_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gamma(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeDouble(thread, res);
    writeInt(thread, signgam);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gammaf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    x = readFloat(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gammaf(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeFloat(thread, res);
    writeInt(thread, signgam);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict gammal_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    x = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = gammal(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeLongDouble(thread, res);
    writeInt(thread, signgam);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lgamma_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = lgamma(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeDouble(thread, res);
    writeInt(thread, signgam);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lgammaf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    x = readFloat(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = lgammaf(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeFloat(thread, res);
    writeInt(thread, signgam);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lgammal_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    x = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = lgammal(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeLongDouble(thread, res);
    writeInt(thread, signgam);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lgamma_r_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int signp;

    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = lgamma_r(x, &signp);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeDouble(thread, res);
    writeInt(thread, signp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lgammaf_r_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
    int signp;

    x = readFloat(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = lgammaf_r(x, &signp);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeFloat(thread, res);
    writeInt(thread, signp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict lgammal_r_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    int signp;

    x = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = lgammal_r(x, &signp);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeLongDouble(thread, res);
    writeInt(thread, signp);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgamma_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = tgamma(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgammaf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    x = readFloat(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = tgammaf(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeFloat(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgammal_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    x = readLongDouble(&stream);

    START_TARGET_OPERATION(thread);

    errno = 0;
    res = tgammal(x);

    END_TARGET_OPERATION(thread);

    writeInt(thread, errno);
    writeLongDouble(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_gamma_commands(void)
{
    ta_register_command("gamma",gamma_cmd);
    ta_register_command("gammaf",gammaf_cmd);
    ta_register_command("gammal",gammal_cmd);
    ta_register_command("lgamma",lgamma_cmd);
    ta_register_command("lgamma_r",lgamma_r_cmd);
    ta_register_command("lgammaf",lgammaf_cmd);
    ta_register_command("lgammaf_r",lgammaf_r_cmd);
    ta_register_command("lgammal",lgammal_cmd);
    ta_register_command("lgammal_r",lgammal_r_cmd);
    ta_register_command("tgamma",tgamma_cmd);
    ta_register_command("tgammaf",tgammaf_cmd);
    ta_register_command("tgammal",tgammal_cmd);
}

