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


#include "math/exp/exp_agent.h"
#include <errno.h>
#include <math.h>
#include <fenv.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cbrt_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = cbrt(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict cbrtf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = cbrtf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict cbrtl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = cbrtl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict exp_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = exp(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict expf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = expf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict expl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = expl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict exp2_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = exp2(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict exp2f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = exp2f(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict exp2l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = exp2l(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict expm1_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = expm1(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict expm1f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = expm1f(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict expm1l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = expm1l(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict hypot_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;

    // Prepare

    x = readDouble(&stream);
    y = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = hypot(x, y);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict hypotf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;

    // Prepare

    x = readFloat(&stream);
    y = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = hypotf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict hypotl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    // Prepare

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = hypotl(x, y);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict logf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = logf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict logl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = logl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log10_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log10(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log10f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log10f(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log10l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log10l(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log1p_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log1p(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log1pf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log1pf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log1pl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log1pl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log2_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log2(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log2f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log2f(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log2l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = log2l(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pow_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;

    // Prepare

    x = readDouble(&stream);
    y = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = pow(x, y);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict powf_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;

    // Prepare

    x = readFloat(&stream);
    y = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = powf(x, y);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict powl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;

    // Prepare

    x = readLongDouble(&stream);
    y = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = powl(x, y);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pow10_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = pow10(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pow10f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = pow10f(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict pow10l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = pow10l(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sqrt_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = sqrt(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sqrtf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = sqrtf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sqrtl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = sqrtl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict exp_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int current, rounding;
    
    ta_debug_printf("search for exp (182894194848)...\n");
    // Prepare
    
    x = readDouble(&stream);
    rounding = readInt(&stream);
    errno = 0;
    current = fegetround();
    
    START_TARGET_OPERATION(thread);
    
    fesetround(rounding * 1024);
    
    // Execute
    
    res = exp(x);
    
    fesetround(current);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict expm1_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int current, rounding;
    
    ta_debug_printf("search for expm1 (182894194848)...\n");
    // Prepare

    x = readDouble(&stream);
    rounding = readInt(&stream);
    errno = 0;
    current = fegetround();
    
    START_TARGET_OPERATION(thread);
    
    fesetround(rounding * 1024);
    
    // Execute
    
    res = expm1(x);
    
    fesetround(current);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int current, rounding;
    
    ta_debug_printf("search for log (182894194848)...\n");
    // Prepare

    x = readDouble(&stream);
    rounding = readInt(&stream);
    errno = 0;
    current = fegetround();
    
    START_TARGET_OPERATION(thread);
    
    fesetround(rounding * 1024);
    
    // Execute
    
    res = log(x);
    
    fesetround(current);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict log1p_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int current, rounding;
    
    ta_debug_printf("search for log1p (182894194848)...\n");
    // Prepare

    x = readDouble(&stream);
    rounding = readInt(&stream);
    errno = 0;
    current = fegetround();
    
    START_TARGET_OPERATION(thread);
    
    fesetround(rounding * 1024);
    
    // Execute
    
    res = log1p(x);
    
    fesetround(current);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_exp_commands(void)
{
    ta_register_command("cbrt",cbrt_cmd);
    ta_register_command("cbrtf",cbrtf_cmd);
    ta_register_command("cbrtl",cbrtl_cmd);
    ta_register_command("exp",exp_cmd);
    ta_register_command("expf",expf_cmd);
    ta_register_command("expl",expl_cmd);
    ta_register_command("exp2",exp2_cmd);
    ta_register_command("exp2f",exp2f_cmd);
    ta_register_command("exp2l",exp2l_cmd);
    ta_register_command("expm1",expm1_cmd);
    ta_register_command("expm1f",expm1f_cmd);
    ta_register_command("expm1l",expm1l_cmd);
    ta_register_command("hypot",hypot_cmd);
    ta_register_command("hypotf",hypotf_cmd);
    ta_register_command("hypotl",hypotl_cmd);
    ta_register_command("log",log_cmd);
    ta_register_command("logf",logf_cmd);
    ta_register_command("logl",logl_cmd);
    ta_register_command("log10",log10_cmd);
    ta_register_command("log10f",log10f_cmd);
    ta_register_command("log10l",log10l_cmd);
    ta_register_command("log1p",log1p_cmd);
    ta_register_command("log1pf",log1pf_cmd);
    ta_register_command("log1pl",log1pl_cmd);
    ta_register_command("log2",log2_cmd);
    ta_register_command("log2f",log2f_cmd);
    ta_register_command("log2l",log2l_cmd);
    ta_register_command("pow",pow_cmd);
    ta_register_command("powf",powf_cmd);
    ta_register_command("powl",powl_cmd);
    ta_register_command("pow10",pow10_cmd);
    ta_register_command("pow10f",pow10f_cmd);
    ta_register_command("pow10l",pow10l_cmd);
    ta_register_command("sqrt",sqrt_cmd);
    ta_register_command("sqrtf",sqrtf_cmd);
    ta_register_command("sqrtl",sqrtl_cmd);
    ta_register_command("exp_adv",exp_adv_cmd);
    ta_register_command("expm1_adv",expm1_adv_cmd);
    ta_register_command("log_adv",log_adv_cmd);
    ta_register_command("log1p_adv",log1p_adv_cmd);
}

