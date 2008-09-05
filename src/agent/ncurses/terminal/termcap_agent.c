/*
 * File: ncurses/terminal/termcap_agent.c
 *
 * Author:
 * Version:  $Id: termcap_agent.c,v 1.3 2006/06/02 14:57:53 flint Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/terminal/termcap_agent.h"
#include <term.h>


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict tgetent_cmd(TAThread thread, TAInputStream stream)
{
    char* name;
    int res;

    // Prepare
    name = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tgetent(NULL, name);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgetflag_cmd(TAThread thread, TAInputStream stream)
{
    char* id;
    int res;

    // Prepare
    id = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tgetflag(id);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgetnum_cmd(TAThread thread, TAInputStream stream)
{
    char* id;
    int res;

    // Prepare
    id = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tgetnum(id);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgetstr_cmd(TAThread thread, TAInputStream stream)
{
    char* id;
    char* area;
    char* res;

    // Prepare
    id = readString(&stream);
    area = readPointer(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tgetstr(id, &area);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    writePointer(thread, area);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgetstr_nullarea_cmd(TAThread thread, TAInputStream stream)
{
    char* id;
    char* res;

    // Prepare
    id = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tgetstr(id, NULL);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tgoto_cmd(TAThread thread, TAInputStream stream)
{
    char* cap;
    int col;
    int row;
    char* res;

    // Prepare
    cap = readString(&stream);
    col = readInt(&stream);
    row = readInt(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tgoto(cap, col, row);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_termcap_commands(void)
{
    ta_register_command("tgetent", tgetent_cmd);
    ta_register_command("tgetflag", tgetflag_cmd);
    ta_register_command("tgetnum", tgetnum_cmd);
    ta_register_command("tgetstr", tgetstr_cmd);
    ta_register_command("tgetstr_nullarea", tgetstr_nullarea_cmd);
    ta_register_command("tgoto", tgoto_cmd);
}
