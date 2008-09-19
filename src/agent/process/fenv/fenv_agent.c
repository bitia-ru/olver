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


#include "process/fenv/fenv_agent.h"

#include <fenv.h>


/********************************************************************/
/**                           Readers                             **/
/********************************************************************/
static int readFEnvExceptions(TAInputStream *stream)
{
    int res = 0;

    verifyType_TAInputStream(stream, "fexcepts");

    res = readChar(stream) != '\x00' ? res | FE_DIVBYZERO : res;
    res = readChar(stream) != '\x00' ? res | FE_INEXACT   : res;
    res = readChar(stream) != '\x00' ? res | FE_INVALID   : res;
    res = readChar(stream) != '\x00' ? res | FE_OVERFLOW  : res;
    res = readChar(stream) != '\x00' ? res | FE_UNDERFLOW : res;

    return res;
}

#define FE_INVALID_ROUNDING_DIRECTION -11;

static int readFEnvRoundingDirection(TAInputStream *stream)
{
    int res = readInt(stream);

    switch(res)
    {
    case 0: return FE_DOWNWARD;
    case 1: return FE_TONEAREST;
    case 2: return FE_TOWARDZERO;
    case 3: return FE_UPWARD;
    }

    switch(res)
    {
    case FE_DOWNWARD:
    case FE_TONEAREST:
    case FE_TOWARDZERO:
    case FE_UPWARD:
        return FE_INVALID_ROUNDING_DIRECTION;
    }

    return FE_INVALID_ROUNDING_DIRECTION;
}

/********************************************************************/
/**                           Writers                              **/
/********************************************************************/
static void writeFEnvExceptions(TAThread thread, int excepts)
{
    writeChar(thread, excepts & FE_DIVBYZERO ? '\xFF' : '\x00');
    writeChar(thread, excepts & FE_INEXACT   ? '\xFF' : '\x00');
    writeChar(thread, excepts & FE_INVALID   ? '\xFF' : '\x00');
    writeChar(thread, excepts & FE_OVERFLOW  ? '\xFF' : '\x00');
    writeChar(thread, excepts & FE_UNDERFLOW ? '\xFF' : '\x00');
}

static void writeFEnvRoundingDirection(TAThread thread, int roundVal)
{
    switch(roundVal)
    {
    case FE_DOWNWARD:
        writeInt(thread, 0);
        return;
    case FE_TONEAREST:
        writeInt(thread, 1);
        return;
    case FE_TOWARDZERO:
        writeInt(thread, 2);
        return;
    case FE_UPWARD:
        writeInt(thread, 3);
        return;
    }

    if(roundVal >= 0 && roundVal <= 3)
    {
        writeInt(thread, 4);
    }
    else
    {
        writeInt(thread, roundVal);
    }
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/
static TACommandVerdict feclearexcept_cmd(TAThread thread, TAInputStream stream)
{
    int excepts, res;

    // Prepare
    excepts = readFEnvExceptions(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = feclearexcept(excepts);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fegetenv_cmd(TAThread thread, TAInputStream stream)
{
    fenv_t *envp;
    int res;

    // Prepare
    envp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = fegetenv(envp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fegetexceptflag_cmd(TAThread thread, TAInputStream stream)
{
    fexcept_t *flagp;
    int excepts, res;

    // Prepare
    flagp = readPointer(&stream);
    excepts = readFEnvExceptions(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = fegetexceptflag(flagp, excepts);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fegetround_cmd(TAThread thread, TAInputStream stream)
{
    int res;

    // Prepare

    START_TARGET_OPERATION(thread);

    // Execute
    res = fegetround();

    END_TARGET_OPERATION(thread);

    // Response
    writeFEnvRoundingDirection(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict feholdexcept_cmd(TAThread thread, TAInputStream stream)
{
    fenv_t *envp;
    int res;

    // Prepare
    envp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = feholdexcept(envp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict feraiseexcept_cmd(TAThread thread, TAInputStream stream)
{
    int excepts, res;

    // Prepare
    excepts = readFEnvExceptions(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = feraiseexcept(excepts);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fesetenv_cmd(TAThread thread,TAInputStream stream)
{
    fenv_t *envp;
    int res;

    // Prepare
    envp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = fesetenv(envp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fesetexceptflag_cmd(TAThread thread,TAInputStream stream)
{
    fexcept_t *flagp;
    int excepts, res;

    // Prepare
    flagp = readPointer(&stream);
    excepts = readFEnvExceptions(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = fesetexceptflag(flagp, excepts);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fesetround_cmd(TAThread thread, TAInputStream stream)
{
    int roundVal, res;

    // Prepare
    roundVal = readFEnvRoundingDirection(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = fesetround(roundVal);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict fetestexcept_cmd(TAThread thread, TAInputStream stream)
{
    int excepts, res;

    // Prepare
    excepts = readFEnvExceptions(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = fetestexcept(excepts);

    END_TARGET_OPERATION(thread);

    // Response
    writeFEnvExceptions(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict feupdateenv_cmd(TAThread thread, TAInputStream stream)
{
    fenv_t *envp;
    int res;

    // Prepare
    envp = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = feupdateenv(envp);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_process_fenv_commands(void)
{
    ta_register_command("feclearexcept", feclearexcept_cmd);
    ta_register_command("fegetenv", fegetenv_cmd);
    ta_register_command("fegetexceptflag", fegetexceptflag_cmd);
    ta_register_command("fegetround", fegetround_cmd);
    ta_register_command("feholdexcept", feholdexcept_cmd);
    ta_register_command("feraiseexcept", feraiseexcept_cmd);
    ta_register_command("fesetenv", fesetenv_cmd);
    ta_register_command("fesetexceptflag", fesetexceptflag_cmd);
    ta_register_command("fesetround", fesetround_cmd);
    ta_register_command("fetestexcept", fetestexcept_cmd);
    ta_register_command("feupdateenv", feupdateenv_cmd);
}

