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


#include "math/rand/rand_agent.h"
#include "stdlib.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict drand48_cmd(TAThread thread,TAInputStream stream)
{
    double res;
    
    START_TARGET_OPERATION(thread);

    res = drand48();
    
    END_TARGET_OPERATION(thread);
     
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict erand48_cmd(TAThread thread,TAInputStream stream)
{
    double res;
    unsigned short xsubi[3];
    xsubi[0] = readUShort(&stream);
    xsubi[1] = readUShort(&stream);
    xsubi[2] = readUShort(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = erand48(xsubi);
    
    END_TARGET_OPERATION(thread);
     
    writeDouble(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict jrand48_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    unsigned short xsubi[3];
    xsubi[0] = readUShort(&stream);
    xsubi[1] = readUShort(&stream);
    xsubi[2] = readUShort(&stream);
    
    START_TARGET_OPERATION(thread);

    res = jrand48(xsubi);
    
    END_TARGET_OPERATION(thread);
     
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lcong48_cmd(TAThread thread,TAInputStream stream)
{
    unsigned short param[7];

    param[0] = readUShort(&stream);
    param[1] = readUShort(&stream);
    param[2] = readUShort(&stream);
    param[3] = readUShort(&stream);
    param[4] = readUShort(&stream);
    param[5] = readUShort(&stream);
    param[6] = readUShort(&stream);
    
    START_TARGET_OPERATION(thread);
    
    lcong48(param);
    
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict lrand48_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    
    START_TARGET_OPERATION(thread);

    res = lrand48();
    
    END_TARGET_OPERATION(thread);
     
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict mrand48_cmd(TAThread thread,TAInputStream stream)
{
    long res;

    START_TARGET_OPERATION(thread);

    res = mrand48();
    
    END_TARGET_OPERATION(thread);
     
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict nrand48_cmd(TAThread thread,TAInputStream stream)
{
    long res;
    unsigned short xsubi[3];
    xsubi[0] = readUShort(&stream);
    xsubi[1] = readUShort(&stream);
    xsubi[2] = readUShort(&stream);
    
    START_TARGET_OPERATION(thread);

    res = nrand48(xsubi);
    
    END_TARGET_OPERATION(thread);
     
    writeLong(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict initstate_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    char* CurrentStatePointer;
    char* any_state;
    unsigned seed;
    size_t size;

    seed = readUInt(&stream);
    size = readInt(&stream);

    any_state = ta_alloc_memory(size);
    CurrentStatePointer = any_state;
    START_TARGET_OPERATION(thread);
    
    res = initstate(seed, any_state, size);
    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);
    writePointer(thread, CurrentStatePointer);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict setstate_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    char* StatePointer;

    StatePointer = readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
        
    res = setstate(StatePointer);

    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict srandom_cmd(TAThread thread,TAInputStream stream)
{
    unsigned seed;
    
    seed = readUInt(&stream);
    
    START_TARGET_OPERATION(thread);
        
    srandom(seed);

    END_TARGET_OPERATION(thread);
       
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict random_cmd(TAThread thread,TAInputStream stream)
{
    long res;

    START_TARGET_OPERATION(thread);
        
    res = random();
    
    END_TARGET_OPERATION(thread);

    writeLong(thread, res);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict rand_cmd(TAThread thread,TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);
        
    res = rand();

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);

    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict rand_r_cmd(TAThread thread,TAInputStream stream)
{
    unsigned seed;
    int res;

    seed = readUInt(&stream);

    START_TARGET_OPERATION(thread);
        
    res = rand_r(&seed);

    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict seed48_cmd(TAThread thread,TAInputStream stream)
{
    unsigned short *res, seed16v[3];
    
    seed16v[0] = readUShort(&stream);
    seed16v[1] = readUShort(&stream);
    seed16v[2] = readUShort(&stream);
    
    START_TARGET_OPERATION(thread);

    res = seed48(seed16v);
    
    END_TARGET_OPERATION(thread);

    writeUShort(thread, res[0]);
    writeUShort(thread, res[1]);
    writeUShort(thread, res[2]);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict srand48_cmd(TAThread thread,TAInputStream stream)
{
    long seedval;
    
    seedval = readLong(&stream);
    
    START_TARGET_OPERATION(thread);
    
    srand48(seedval);

    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict srand_cmd(TAThread thread,TAInputStream stream)
{
    unsigned seed;
    
    seed = readUInt(&stream);

    START_TARGET_OPERATION(thread);
        
    srand(seed);
        
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict get_SUT_SC_RAND_MAX_cmd(TAThread thread,TAInputStream stream)
{
    long res;

    START_TARGET_OPERATION(thread);
        
    res = RAND_MAX;
        
    END_TARGET_OPERATION(thread);
    
    writeLong(thread, res);

    sendResponse(thread);
    
    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_math_rand_commands(void)
{
    ta_register_command("drand48",drand48_cmd);
    ta_register_command("erand48",erand48_cmd);
    ta_register_command("jrand48",jrand48_cmd);
    ta_register_command("lcong48",lcong48_cmd);
    ta_register_command("lrand48",lrand48_cmd);
    ta_register_command("mrand48",mrand48_cmd);
    ta_register_command("nrand48",nrand48_cmd);
    ta_register_command("seed48",seed48_cmd);
    ta_register_command("srand48",srand48_cmd);

    ta_register_command("initstate",initstate_cmd);
    ta_register_command("random",random_cmd);
    ta_register_command("setstate",setstate_cmd);
    ta_register_command("srandom",srandom_cmd);

    ta_register_command("rand",rand_cmd);
    ta_register_command("rand_r",rand_r_cmd);
    ta_register_command("srand",srand_cmd);

    ta_register_command("get_SUT_SC_RAND_MAX",get_SUT_SC_RAND_MAX_cmd);
}

