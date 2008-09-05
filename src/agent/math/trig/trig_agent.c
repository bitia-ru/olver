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


#include "math/trig/trig_agent.h"
#include <errno.h>
#include <math.h>
#include <fenv.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict acos_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = acos(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict acosf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = acosf(x);
   
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict acosl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = acosl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict asin_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = asin(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict asinf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = asinf(x);
   
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict asinl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = asinl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atan_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = atan(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atanf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = atanf(x);
   
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atanl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = atanl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict atan2_cmd(TAThread thread,TAInputStream stream)
{
    double x, y, res;
    y = readDouble(&stream);
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = atan2(y, x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atan2f_cmd(TAThread thread,TAInputStream stream)
{
    float x, y, res;
    y = readFloat(&stream);
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = atan2f(y, x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atan2l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, y, res;
    y = readLongDouble(&stream);
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = atan2l(y, x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cos_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = cos(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cosf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = cosf(x);
   
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cosl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;

    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = cosl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sin_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = sin(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sinf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = sinf(x);
   
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sinl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = sinl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sincos_cmd(TAThread thread,TAInputStream stream)
{
    double x, s, c;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    sincos(x, &s, &c);
    
    END_TARGET_OPERATION(thread);
    
    writeDouble(thread, s);
    writeDouble(thread, c);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sincosf_cmd(TAThread thread,TAInputStream stream)
{
    float x, s, c;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    sincosf(x, &s, &c);
    
    END_TARGET_OPERATION(thread);
    
    writeFloat(thread, s);
    writeFloat(thread, c);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict sincosl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, s, c;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    sincosl(x, &s, &c);
    
    END_TARGET_OPERATION(thread);
    
    writeLongDouble(thread, s);
    writeLongDouble(thread, c);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict tan_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = tan(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict tanf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = tanf(x);
   
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict tanl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = tanl(x);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict cos_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int round;
   
    x = readDouble(&stream);
    round = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    fesetround(round * 1024);

    ta_debug_printf("search for cos (182894194848)...\n");
    printf("Current settings = %d\n", fegetround());

    printf("%.20e\n", x);
    errno = 0;
    res = cos(x);
    printf("%.20e\n", res);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict tan_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int round;
   
    x = readDouble(&stream);
    round = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    fesetround(round * 1024);

    ta_debug_printf("search for tan (182894194848)...\n");
    printf("Current settings = %d\n", fegetround());

    printf("%.20e\n", x);
    errno = 0;
    res = tan(x);
    printf("%.20e\n", res);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict atan_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int round;
    
    x = readDouble(&stream);
    round = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    fesetround(round * 1024);
    
    ta_debug_printf("search for atan (182894194848)...\n");
    printf("Current settings = %d\n", fegetround());

    printf("%e\n", x);
    errno = 0;
    res = atan(x);
    printf("%e\n", res);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    return taDefaultVerdict;
}

static TACommandVerdict acos_adv_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int round;
   
    x = readDouble(&stream);
    round = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    fesetround(round * 1024);
    
    ta_debug_printf("search for acos (182894194848)...\n");
    printf("Current settings = %d\n", fegetround());

    printf("%e\n", x);
    errno = 0;
    res = acos(x);
    printf("%e\n", res);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_trig_commands(void)
{
    ta_register_command("acos",acos_cmd);
    ta_register_command("acosf",acosf_cmd);
    ta_register_command("acosl",acosl_cmd);
    ta_register_command("asin",asin_cmd);
    ta_register_command("asinf",asinf_cmd);
    ta_register_command("asinl",asinl_cmd);
    ta_register_command("atan",atan_cmd);
    ta_register_command("atanf",atanf_cmd);
    ta_register_command("atanl",atanl_cmd);
    ta_register_command("atan2",atan2_cmd);
    ta_register_command("atan2f",atan2f_cmd);
    ta_register_command("atan2l",atan2l_cmd);
    ta_register_command("cos",cos_cmd);
    ta_register_command("cosf",cosf_cmd);
    ta_register_command("cosl",cosl_cmd);
    ta_register_command("sin",sin_cmd);
    ta_register_command("sinf",sinf_cmd);
    ta_register_command("sinl",sinl_cmd);
    ta_register_command("sincos",sincos_cmd);
    ta_register_command("sincosf",sincosf_cmd);
    ta_register_command("sincosl",sincosl_cmd);
    ta_register_command("tan",tan_cmd);
    ta_register_command("tanf",tanf_cmd);
    ta_register_command("tanl",tanl_cmd);
    ta_register_command("tan_adv",tan_adv_cmd);
    ta_register_command("cos_adv",cos_adv_cmd);
    ta_register_command("atan_adv",atan_adv_cmd);
    ta_register_command("acos_adv",acos_adv_cmd);
}

