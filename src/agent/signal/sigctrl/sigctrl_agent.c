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

#include <errno.h>
#include "signal/sigaction/sigaction_agent.h"
#include "signal/sigctrl/sigctrl_agent.h"
#include "signal/sigstr/sigstr_agent.h"

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict sighold_cmd(TAThread thread,TAInputStream stream)
{
    int sig;
    int res;
    // Prepare
    sig = readInt(&stream);
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = sighold(sig);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sigignore_cmd(TAThread thread,TAInputStream stream)
{
    int sig;
    int res;
    // Prepare
    sig = readInt(&stream);
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = sigignore(sig);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sigpause_cmd(TAThread thread,TAInputStream stream)
{
    int sig;
    int res;
    // Prepare
    sig = readInt(&stream);
    errno = 0;

    BEFORE_BLOCKED_TARGET_OPERATION(thread);
    writeString(thread,"Ok");
    sendResponse(thread);

    // Execute
    START_TARGET_OPERATION(thread);
    ta_debug_printf("sigpause start\n");
    res = sigpause(sig);
    ta_debug_printf("sigpause end\n");
    END_TARGET_OPERATION(thread);

    // Response
    ta_debug_printf("asdfkfml\n");
    writeDeferredReaction(thread, "sigpause_react");
    writeInt(thread, res);
    writeInt(thread, sig);
    writeInt(thread, errno);
    sendResponse(thread);
    ta_debug_printf("asdfkfml2\n");

    return taDefaultVerdict;
}

static TACommandVerdict sigrelse_cmd(TAThread thread,TAInputStream stream)
{
    int sig;
    int res;
    // Prepare
    sig = readInt(&stream);
    errno = 0;

    // Execute
    START_TARGET_OPERATION(thread);
    res = sigrelse(sig);
    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict sigset_cmd(TAThread thread,TAInputStream stream)
{
    int sig, handl;
    p_handl new_handler;
    p_handl old_handler;
    // Prepare
    sig = readInt(&stream);
    handl = readInt(&stream);
    errno = 0;

    new_handler = get_catcher_handler(handl);

    // Execute
    START_TARGET_OPERATION(thread);
    old_handler = sigset(sig, new_handler);
    END_TARGET_OPERATION(thread);

    // Response
    handl = handler_number(old_handler);
    writeInt(thread, handl);
    writeInt(thread, errno);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_signal_sigctrl_commands(void)
{
    ta_register_command( "a_signalAsCString", a_signalAsCString_cmd );

    ta_register_command( "sighold"  , sighold_cmd   );
    ta_register_command( "sigignore", sigignore_cmd );
    ta_register_command( "sigpause" , sigpause_cmd  );
    ta_register_command( "sigrelse" , sigrelse_cmd  );
    ta_register_command( "sigset"   , sigset_cmd    );
}
