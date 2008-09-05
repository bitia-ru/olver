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


#include "math/bessel/bessel_agent.h"
#include <errno.h>
#include <math.h>
#include <fenv.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict j0_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = j0(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict j0f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = j0f(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict j0l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = j0l(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict j1_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = j1(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict j1f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = j1f(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict j1l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = j1l(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict jn_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int n;

    n = readInt(&stream);
    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = jn(n, x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict jnf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
    int n;

    n = readInt(&stream);
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = jnf(n, x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict jnl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    int n;

    n = readInt(&stream);
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = jnl(n, x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict y0_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = y0(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict y0f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = y0f(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict y0l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = y0l(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict y1_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
   
    x = readDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = y1(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict y1f_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
   
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = y1f(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict y1l_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
   
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = y1l(x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict yn_cmd(TAThread thread,TAInputStream stream)
{
    double x, res;
    int n;

    n = readInt(&stream);
    x = readDouble(&stream);

    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = yn(n, x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ynf_cmd(TAThread thread,TAInputStream stream)
{
    float x, res;
    int n;

    n = readInt(&stream);
    x = readFloat(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ynf(n, x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeFloat(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict ynl_cmd(TAThread thread,TAInputStream stream)
{
    long double x, res;
    int n;

    n = readInt(&stream);
    x = readLongDouble(&stream);
    
    START_TARGET_OPERATION(thread);
    
    errno = 0;
    res = ynl(n, x);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, errno); 
    writeLongDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict BesselJ_cmd(TAThread thread, TAInputStream stream)
{
  double x, res;
  int n, round_mode;
  
  n = readInt(&stream);
  x = readDouble(&stream);
  round_mode = readInt(&stream);
  
  START_TARGET_OPERATION(thread);

  ta_debug_printf("search for jn (182894194848)...\n");

  fesetround(round_mode * 1024);
  
  //printf("FLT_ROUNDS=%d\n", fegetround()/1024);
  //printf("X=%.20e\n", x);
  //printf("N=%d\n", n);
  
  errno = 0;
  
  res = jn(n, x);
  //printf("RES=%.20e\n", res);
  
  END_TARGET_OPERATION(thread);
  
  writeInt(thread, errno);
  writeDouble(thread, res);
  sendResponse(thread);
  
  return taDefaultVerdict;
}

static TACommandVerdict BesselY_cmd(TAThread thread, TAInputStream stream)
{
  double x, res;
  int n, round_mode;
  
  n = readInt(&stream);
  x = readDouble(&stream);
  round_mode = readInt(&stream);
  
  START_TARGET_OPERATION(thread);
  
  ta_debug_printf("search for yn (182894194848)...\n");
  
  fesetround(round_mode * 1024);
  
  //verbose("FLT_ROUNDS=%d\n", fegetround()/1024);
  //verbose("N=%d\n", n);
  //verbose("X=%.20e\n", x);
  
  errno = 0;
  
  res = yn(n, x);
  //verbose("RES=%.20e\n", res);
  
  END_TARGET_OPERATION(thread);
  
  writeInt(thread, errno);
  writeDouble(thread, res);
  sendResponse(thread);
  
  return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_bessel_commands(void)
{
    ta_register_command("j0",j0_cmd);
    ta_register_command("j0f",j0f_cmd);
    ta_register_command("j0l",j0l_cmd);
    ta_register_command("j1",j1_cmd);
    ta_register_command("j1f",j1f_cmd);
    ta_register_command("j1l",j1l_cmd);
    ta_register_command("jn",jn_cmd);
    ta_register_command("jnf",jnf_cmd);
    ta_register_command("jnl",jnl_cmd);
    ta_register_command("y0",y0_cmd);
    ta_register_command("y0f",y0f_cmd);
    ta_register_command("y0l",y0l_cmd);
    ta_register_command("y1",y1_cmd);
    ta_register_command("y1f",y1f_cmd);
    ta_register_command("y1l",y1l_cmd);
    ta_register_command("yn",yn_cmd);
    ta_register_command("ynf",ynf_cmd);
    ta_register_command("ynl",ynl_cmd);
    ta_register_command("BesselJ", BesselJ_cmd);
    ta_register_command("BesselY", BesselY_cmd);
}

