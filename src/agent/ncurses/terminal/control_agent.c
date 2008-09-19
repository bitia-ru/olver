/*
 * File: ncurses/terminal/control_agent.c
 *
 * Author:
 * Version:  $Id: control_agent.c,v 1.3 2006/05/25 16:07:19 flint Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/terminal/control_agent.h"
#include <curses.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict clearok_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    bool bf;
    int res;

    // Prepare
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = clearok(win, bf);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict echo_cmd(TAThread thread, TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = echo();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict has_ic_cmd(TAThread thread, TAInputStream stream)
{
    bool res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = has_ic();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict has_il_cmd(TAThread thread, TAInputStream stream)
{
    bool res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = has_il();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict idcok_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    bool bf;

    // Prepare
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    idcok(win, bf);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict idlok_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    bool bf;
    int res;

    // Prepare
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = idlok(win, bf);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict immedok_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    bool bf;

    // Prepare
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    immedok(win, bf);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict leaveok_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    bool bf;
    int res;

    // Prepare
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = leaveok(win, bf);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict noecho_cmd(TAThread thread, TAInputStream stream)
{
    int res;

    START_TARGET_OPERATION(thread);

    // Execute
    res = noecho();

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict noqiflush_cmd(TAThread thread, TAInputStream stream)
{
    START_TARGET_OPERATION(thread);

    // Execute
    noqiflush();

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict qiflush_cmd(TAThread thread, TAInputStream stream)
{
    START_TARGET_OPERATION(thread);

    // Execute
    qiflush();

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict scrollok_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    bool bf;
    int res;

    // Prepare
    win = readPointer(&stream);
    bf = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = scrollok(win, bf);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setscrreg_cmd(TAThread thread, TAInputStream stream)
{
    int top;
    int bot;
    int res;

    // Prepare
    top = readInt(&stream);
    bot = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = setscrreg(top, bot);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict use_env_cmd(TAThread thread, TAInputStream stream)
{
    bool boolval;

    // Prepare
    boolval = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    use_env(boolval);

    END_TARGET_OPERATION(thread);

    // Response
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict wsetscrreg_cmd(TAThread thread, TAInputStream stream)
{
    WINDOW* win;
    int top;
    int bot;
    int res;

    // Prepare
    win = readPointer(&stream);
    top = readInt(&stream);
    bot = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = wsetscrreg(win, top, bot);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_control_commands(void)
{
    ta_register_command("clearok", clearok_cmd);
    ta_register_command("echo", echo_cmd);
    ta_register_command("has_ic", has_ic_cmd);
    ta_register_command("has_il", has_il_cmd);
    ta_register_command("idcok", idcok_cmd);
    ta_register_command("idlok", idlok_cmd);
    ta_register_command("immedok", immedok_cmd);
    ta_register_command("leaveok", leaveok_cmd);
    ta_register_command("noecho", noecho_cmd);
    ta_register_command("noqiflush", noqiflush_cmd);
    ta_register_command("qiflush", qiflush_cmd);
    ta_register_command("scrollok", scrollok_cmd);
    ta_register_command("setscrreg", setscrreg_cmd);
    ta_register_command("use_env", use_env_cmd);
    ta_register_command("wsetscrreg", wsetscrreg_cmd);
}
