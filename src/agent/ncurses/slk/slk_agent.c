/* 
 * File: ncurses/slk/slk_agent.c
 * 
 * Author:
 * Version:  $Id: slk_agent.c,v 1.2 2006/06/19 07:14:09 biga Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "common/ta_stream.h"
#include "ncurses/slk/slk_agent.h"
#include <curses.h> 

chtype readChType(TAInputStream *stream);
attr_t readNcursesAttrT(TAInputStream *stream);
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict slk_attrset_cmd(TAThread thread,TAInputStream stream)
{
    chtype attrs;
    int res;
    
    attrs = readChType(&stream);

    START_TARGET_OPERATION(thread);
    
    res = slk_attrset(attrs);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict slk_attr_set_cmd(TAThread thread,TAInputStream stream)
{
    attr_t attrs;
    short color_pair_number;
    void * opt;
    int res;
    
    attrs = readNcursesAttrT(&stream);
    color_pair_number = readShort(&stream);
    opt = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    
    res = slk_attr_set(attrs, color_pair_number, opt);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict slk_attroff_cmd(TAThread thread,TAInputStream stream)
{
    chtype attrs;
    int res;
    
    attrs = readChType(&stream);

    START_TARGET_OPERATION(thread);
    
    res = slk_attroff(attrs);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict slk_attron_cmd(TAThread thread,TAInputStream stream)
{
    chtype attrs;
    int res;
    
    attrs = readChType(&stream);

    START_TARGET_OPERATION(thread);
    
    res = slk_attron(attrs);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict slk_clear_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = slk_clear();
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
    
    return taDefaultVerdict;
}

static TACommandVerdict slk_color_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    short color_pair_number;
    
    color_pair_number = readShort(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = slk_color(color_pair_number);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
    
    return taDefaultVerdict;
}

static TACommandVerdict slk_init_cmd(TAThread thread,TAInputStream stream)
{
    int fmt;
    int res;
    
    fmt = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = slk_init(fmt);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
        
    return taDefaultVerdict;
}

static TACommandVerdict slk_label_cmd(TAThread thread,TAInputStream stream)
{
    int labnum;
    char * res;
        
    labnum = readInt(&stream);
        
    START_TARGET_OPERATION(thread);
    
    res = slk_label(labnum);
    
    END_TARGET_OPERATION(thread);
    
    writeString(thread, res);
    sendResponse(thread); 
    
    return taDefaultVerdict;
}

static TACommandVerdict slk_refresh_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = slk_refresh();
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
        
    return taDefaultVerdict;
}

static TACommandVerdict slk_restore_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = slk_restore();
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
        
    return taDefaultVerdict;
}

static TACommandVerdict slk_set_cmd(TAThread thread,TAInputStream stream)
{
    int labnum;
    char * label;
    int justify;
    int res;
    
    labnum = readInt(&stream);
    label = readString(&stream);
    justify = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    
    res = slk_set(labnum, label, justify);
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
        
    return taDefaultVerdict;
}

static TACommandVerdict slk_noutrefresh_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = slk_noutrefresh();
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
        
    return taDefaultVerdict;
}

static TACommandVerdict slk_touch_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    
    res = slk_touch();
    
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread); 
        
    return taDefaultVerdict;
}



/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_slk_commands(void)
{
    ta_register_command("slk_attrset",slk_attrset_cmd);
    ta_register_command("slk_attr_set",slk_attr_set_cmd);
    ta_register_command("slk_attroff",slk_attroff_cmd);
    ta_register_command("slk_attron",slk_attron_cmd);
    ta_register_command("slk_color",slk_color_cmd);
    ta_register_command("slk_clear",slk_clear_cmd);
    ta_register_command("slk_init",slk_init_cmd);
    ta_register_command("slk_label",slk_label_cmd);
    ta_register_command("slk_refresh",slk_refresh_cmd);
    ta_register_command("slk_restore",slk_restore_cmd);
    ta_register_command("slk_set",slk_set_cmd);
    ta_register_command("slk_noutrefresh",slk_noutrefresh_cmd);    
    ta_register_command("slk_touch",slk_touch_cmd);
}

