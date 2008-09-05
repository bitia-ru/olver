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


#include "math/hyper/hyper_agent.h"
#include <errno.h>

#include <math.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict acosh_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = acosh(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;

}

static TACommandVerdict acoshf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = acoshf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict acoshl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = acoshl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict asinh_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = asinh(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict asinhf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = asinhf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict asinhl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = asinhl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict atanh_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = atanh(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict atanhf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = atanhf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict atanhl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = atanhl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict cosh_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = cosh(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict coshf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = coshf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict coshl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = coshl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sinh_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = sinh(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sinhf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = sinhf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict sinhl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = sinhl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict tanh_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;

    // Prepare

    x = readDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = tanh(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict tanhf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;

    // Prepare

    x = readFloat(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = tanhf(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeFloat(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict tanhl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    // Prepare

    x = readLongDouble(&stream);
    errno = 0;
    
    START_TARGET_OPERATION(thread);
    
    // Execute

    res = tanhl(x);
    
    END_TARGET_OPERATION(thread);
    
    // Response
    
    writeLongDouble(thread, res);
    writeInt(thread, errno);

    sendResponse(thread);
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_hyper_commands(void)
{
    ta_register_command("acosh",acosh_cmd);
    ta_register_command("acoshf",acoshf_cmd);
    ta_register_command("acoshl",acoshl_cmd);
    ta_register_command("asinh",asinh_cmd);
    ta_register_command("asinhf",asinhf_cmd);
    ta_register_command("asinhl",asinhl_cmd);
    ta_register_command("atanh",atanh_cmd);
    ta_register_command("atanhf",atanhf_cmd);
    ta_register_command("atanhl",atanhl_cmd);
    ta_register_command("cosh",cosh_cmd);
    ta_register_command("coshf",coshf_cmd);
    ta_register_command("coshl",coshl_cmd);
    ta_register_command("sinh",sinh_cmd);
    ta_register_command("sinhf",sinhf_cmd);
    ta_register_command("sinhl",sinhl_cmd);
    ta_register_command("tanh",tanh_cmd);
    ta_register_command("tanhf",tanhf_cmd);
    ta_register_command("tanhl",tanhl_cmd);
}

