/* 
 * File: ncurses/color/color_agent.c
 * 
 * Author:
 * Version:  $Id: color_agent.c,v 1.4 2007/07/25 11:10:53 egor Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/color/color_agent.h"
#include <curses.h>

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict can_change_color_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = can_change_color();    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res ? 1 : 0);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict color_content_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    short color, red, green, blue;

    color = readShort(&stream);

    START_TARGET_OPERATION(thread);
    res = color_content(color, &red, &green, &blue);    
    END_TARGET_OPERATION(thread);

    writeShort(thread, red);
    writeShort(thread, green);
    writeShort(thread, blue);
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict has_colors_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = has_colors();    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res ? 1 : 0);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict init_color_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    short color, red, green, blue;

    color = readShort(&stream);
    red = readShort(&stream);
    green = readShort(&stream);
    blue = readShort(&stream);
    
    START_TARGET_OPERATION(thread);
    res = init_color(color, red, green, blue);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict init_pair_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    short pair, f, b;

    pair = readShort(&stream);
    f = readShort(&stream);
    b = readShort(&stream);
    
    START_TARGET_OPERATION(thread);
    res = init_pair(pair, f, b);    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict pair_content_cmd(TAThread thread,TAInputStream stream)
{
    int res, num;
    short pair, f, b;

    pair = readShort(&stream);
    
    START_TARGET_OPERATION(thread);
    res = pair_content(pair, &f, &b);    
    END_TARGET_OPERATION(thread);

    writeShort(thread, f);
    writeShort(thread, b);
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict start_color_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = start_color();    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict getCOLORS_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    writeInt(thread, COLORS);
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict getCOLOR_PAIRS_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    writeInt(thread, COLOR_PAIRS);
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict COLOR_PAIR_cmd(TAThread thread,TAInputStream stream)
{
    int n, res;

    n = readInt(&stream);
    START_TARGET_OPERATION(thread);
    res = COLOR_PAIR(n);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}
static TACommandVerdict PAIR_NUMBER_cmd(TAThread thread,TAInputStream stream)
{
    int value, res;

    value = readInt(&stream);
    START_TARGET_OPERATION(thread);
    res = PAIR_NUMBER(value);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_color_commands(void)
{
    ta_register_command("can_change_color",can_change_color_cmd);
    ta_register_command("color_content",color_content_cmd);
    ta_register_command("has_colors",has_colors_cmd);
    ta_register_command("init_color",init_color_cmd);
    ta_register_command("init_pair",init_pair_cmd);
    ta_register_command("pair_content",pair_content_cmd);
    ta_register_command("start_color",start_color_cmd);

    ta_register_command("getCOLORS",getCOLORS_cmd);
    ta_register_command("getCOLOR_PAIRS",getCOLOR_PAIRS_cmd);
    ta_register_command("COLOR_PAIR",COLOR_PAIR_cmd);
    ta_register_command("PAIR_NUMBER",PAIR_NUMBER_cmd);
}

