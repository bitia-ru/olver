/* 
 * File: ncurses/window/attr_agent.c
 * 
 * Author:
 * Version:  $Id: attr_agent.c,v 1.5 2006/05/15 12:59:03 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/window/attr_agent.h"
#include <curses.h>



void writeNcursesAttr(TAThread thread, attr_t attrs)
{
   
    writeInt(thread, attrs&WA_ALTCHARSET? 1 : 0);
    writeInt(thread, attrs&WA_BLINK ? 1 : 0);
    writeInt(thread, attrs&WA_BOLD ? 1 : 0);
    writeInt(thread, attrs&WA_DIM ? 1 : 0);
    writeInt(thread, attrs&WA_HORIZONTAL ? 1 : 0);
    writeInt(thread, attrs&WA_INVIS ? 1 : 0);
    writeInt(thread, attrs&WA_LEFT ? 1 : 0);
    writeInt(thread, attrs&WA_LOW ? 1 : 0);
    writeInt(thread, attrs&WA_PROTECT ? 1 : 0);
    writeInt(thread, attrs&WA_REVERSE ? 1 : 0);
    writeInt(thread, attrs&WA_RIGHT ? 1 : 0);
    writeInt(thread, attrs&WA_STANDOUT ? 1 : 0);
    writeInt(thread, attrs&WA_TOP ? 1 : 0);
    writeInt(thread, attrs&WA_UNDERLINE ? 1 : 0);
    writeInt(thread, attrs&WA_VERTICAL ? 1 : 0);

    writeInt(thread, attrs&A_COLOR>>8);

}


/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict attr_get_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;
    short  color_pair_number;

    
    START_TARGET_OPERATION(thread);
    res = attr_get(NULL, &color_pair_number, NULL);
    res = attr_get(&attrs, NULL, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeNcursesAttr(thread, attrs);
    writeInt(thread, color_pair_number);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict attr_off_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;

    attrs = readNcursesAttrT(&stream);

    START_TARGET_OPERATION(thread);
    res = attr_off(attrs, NULL);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict attr_on_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;
    
    attrs = readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = attr_on(attrs, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict attr_set_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;
    int color_pair_number;
    
    attrs = readNcursesAttrT(&stream);
    color_pair_number = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = attr_set(attrs, color_pair_number, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict attroff_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int attrs;
    
    attrs = (int)readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = attroff(attrs);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict attron_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int attrs;
    
    attrs = (int)readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = attron(attrs);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict attrset_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int    attrs;
    
    attrs = (int)readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = attrset(attrs);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict color_set_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    short color_pair_number;
    
    color_pair_number = (short)readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = color_set(color_pair_number, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict standend_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    
    START_TARGET_OPERATION(thread);
    res = standend();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict standout_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    
    START_TARGET_OPERATION(thread);
    res = standout();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattr_get_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    WINDOW* win;
    attr_t attrs;
    short  color_pair_number;
    
    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wattr_get(win, NULL, &color_pair_number, NULL);
    res = wattr_get(win, &attrs, NULL, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    writeNcursesAttr(thread, attrs);
    writeInt(thread, color_pair_number);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattr_off_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;
    WINDOW* win;

    win=readPointer(&stream);
    attrs = readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wattr_off(win, attrs, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattr_on_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;
    WINDOW* win;

    win=readPointer(&stream);
    attrs = readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wattr_on(win, attrs, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattr_set_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    attr_t attrs;
    int color_pair_number;
    WINDOW* win;
    
    win=readPointer(&stream);
    
    attrs = readNcursesAttrT(&stream);
    color_pair_number = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = wattr_set(win, attrs, color_pair_number, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattroff_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int  attrs;
    WINDOW* win;
    
    win=readPointer(&stream);
    attrs = (int)readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wattroff(win, attrs);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattron_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int  attrs;
    WINDOW* win;
    
    win=readPointer(&stream);
    attrs = (int)readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wattron(win, attrs);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wattrset_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int  attrs;
    WINDOW* win;
    
    win=readPointer(&stream);
    attrs = (int)readNcursesAttrT(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wattrset(win, attrs);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wcolor_set_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    int color_pair_number;
    WINDOW* win;
    
    win=readPointer(&stream);
    color_pair_number = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wcolor_set(win, color_pair_number, NULL);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wstandend_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    WINDOW* win;
    
    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wstandend(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict wstandout_cmd(TAThread thread,TAInputStream stream)
{
    int    res;
    WINDOW* win;
    
    win=readPointer(&stream);
    
    START_TARGET_OPERATION(thread);
    res = wstandout(win);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_window_attr_commands(void)
{
    ta_register_command("attr_get",attr_get_cmd);
    ta_register_command("attr_off",attr_off_cmd);
    ta_register_command("attr_on",attr_on_cmd);
    ta_register_command("attr_set",attr_set_cmd);
    ta_register_command("attroff",attroff_cmd);
    ta_register_command("attron",attron_cmd);
    ta_register_command("attrset",attrset_cmd);
    ta_register_command("color_set",color_set_cmd);
    ta_register_command("standend",standend_cmd);
    ta_register_command("standout",standout_cmd);
    ta_register_command("wattr_get",wattr_get_cmd);
    ta_register_command("wattr_off",wattr_off_cmd);
    ta_register_command("wattr_on",wattr_on_cmd);
    ta_register_command("wattr_set",wattr_set_cmd);
    ta_register_command("wattroff",wattroff_cmd);
    ta_register_command("wattron",wattron_cmd);
    ta_register_command("wattrset",wattrset_cmd);
    ta_register_command("wcolor_set",wcolor_set_cmd);
    ta_register_command("wstandend",wstandend_cmd);
    ta_register_command("wstandout",wstandout_cmd);
}

