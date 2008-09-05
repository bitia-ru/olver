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


#include "math/ctrig/ctrig_agent.h"
#include <complex.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict cacos_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);

    START_TARGET_OPERATION(thread);
    
    res = cacos(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cacosf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = cacosf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cacosl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = cacosl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict casin_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = casin(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict casinf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = casinf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict casinl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = casinl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict catan_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = catan(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict catanf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = catanf(x);

    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict catanl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = catanl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ccos_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = ccos(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ccosf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = ccosf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ccosl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);

    res = ccosl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict csin_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = csin(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict csinf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = csinf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict csinl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = csinl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ctan_cmd(TAThread thread,TAInputStream stream)
{
    double complex x, res;
   
    __real__ x = readDouble(&stream);
    __imag__ x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = ctan(x);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, __real__ res);
    writeDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ctanf_cmd(TAThread thread,TAInputStream stream)
{
    float complex x, res;
   
    __real__ x = readFloat(&stream);
    __imag__ x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = ctanf(x);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, __real__ res);
    writeFloat(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ctanl_cmd(TAThread thread,TAInputStream stream)
{
    long double complex x, res;
   
    __real__ x = readLongDouble(&stream);
    __imag__ x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = ctanl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, __real__ res);
    writeLongDouble(thread, __imag__ res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_ctrig_commands(void)
{
    ta_register_command("cacos",cacos_cmd);
    ta_register_command("cacosf",cacosf_cmd);
    ta_register_command("cacosl",cacosl_cmd);
    ta_register_command("casin",casin_cmd);
    ta_register_command("casinf",casinf_cmd);
    ta_register_command("casinl",casinl_cmd);
    ta_register_command("catan",catan_cmd);
    ta_register_command("catanf",catanf_cmd);
    ta_register_command("catanl",catanl_cmd);
    ta_register_command("ccos",ccos_cmd);
    ta_register_command("ccosf",ccosf_cmd);
    ta_register_command("ccosl",ccosl_cmd);
    ta_register_command("csin",csin_cmd);
    ta_register_command("csinf",csinf_cmd);
    ta_register_command("csinl",csinl_cmd);
    ta_register_command("ctan",ctan_cmd);
    ta_register_command("ctanf",ctanf_cmd);
    ta_register_command("ctanl",ctanl_cmd);
}

