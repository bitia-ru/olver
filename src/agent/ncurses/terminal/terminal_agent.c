/* 
 * File: ncurses/terminal/terminal_agent.c
 * 
 * Author:
 * Version:  $Id: terminal_agent.c,v 1.46 2007/10/11 15:11:42 lex Exp $
 * 
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/terminal/terminal_agent.h"
#include <curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
	
#define    NCURSES_SIZE_T short 



struct my_ldat

{
    chtype    *text;        // text of the line 
    NCURSES_SIZE_T    firstchar;    //* first changed character in the line /
    NCURSES_SIZE_T    lastchar;    //* last changed character in the line /
    NCURSES_SIZE_T    oldindex;    //* index of the line at last update /
}; 


struct my_pdat {
    short _pad_y;
    short _pad_x;
    short _pad_top;
    short _pad_left;
    short _pad_bottom;
    short _pad_right;
};

chtype readChType(TAInputStream *stream);
void writeChType(TAThread thread, chtype val); 

void writeAttr(TAThread thread, attr_t val)
{
    writeInt(thread, val & A_ALTCHARSET ? 1 : 0);
    writeInt(thread, val & A_BLINK ? 1 : 0);
    writeInt(thread, val & A_BOLD ? 1 : 0);
    writeInt(thread, val & A_DIM ? 1 : 0);
    writeInt(thread, val & A_HORIZONTAL ? 1 : 0);
    writeInt(thread, val & A_INVIS ? 1 : 0);
    writeInt(thread, val & A_LEFT ? 1 : 0);
    writeInt(thread, val & A_LOW ? 1 : 0);
    writeInt(thread, val & A_PROTECT ? 1 : 0);
    writeInt(thread, val & A_REVERSE ? 1 : 0);
    writeInt(thread, val & A_RIGHT ? 1 : 0);
    writeInt(thread, val & A_STANDOUT ? 1 : 0);
    writeInt(thread, val & A_TOP ? 1 : 0);
    writeInt(thread, val & A_UNDERLINE ? 1 : 0);
    writeInt(thread, val & A_VERTICAL ? 1 : 0);

    writeInt(thread, (val & A_COLOR) >> 8);
}

void writeLdat(TAThread thread, struct my_ldat* dat, int size)
{
    int i;
    chtype    *ptr = dat->text;
    
    writeInt(thread, size);

    for(i=0;i<size;i++)
        writeChType(thread, *ptr++);

    writeUInt(thread, (unsigned int)dat->firstchar);
    writeUInt(thread, (unsigned int)dat->lastchar);
    writeUInt(thread, (unsigned int)dat->oldindex);
}

void writePdat(TAThread thread, struct my_pdat* dat)
{
    writeShort(thread, dat->_pad_y);
    writeShort(thread, dat->_pad_x);
    writeShort(thread, dat->_pad_top);
    writeShort(thread, dat->_pad_left);
    writeShort(thread, dat->_pad_bottom);
    writeShort(thread, dat->_pad_right);
}
/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict delay_output_cmd(TAThread thread,TAInputStream stream)
{
    int ms, res;
    
    ms = readInt(&stream);
    
    START_TARGET_OPERATION(thread);
    res = delay_output(ms);
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict delscreen_cmd(TAThread thread,TAInputStream stream)

{
    SCREEN * scr;

    scr = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    delscreen(scr);
    END_TARGET_OPERATION(thread);
    
    writeString(thread, "Ok");
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict endwin_cmd(TAThread thread,TAInputStream stream)
{
    int res;
    
    START_TARGET_OPERATION(thread);
    res = endwin();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict filter_cmd(TAThread thread,TAInputStream stream)
{
    START_TARGET_OPERATION(thread);
    filter();
    END_TARGET_OPERATION(thread);
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict initscr_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* res;
    int cols;
    int lines;
    
    START_TARGET_OPERATION(thread);
    res = initscr();
    END_TARGET_OPERATION(thread);
 

    atexit((void(*)())(endwin));
    writePointer(thread, res);

    getmaxyx(res, lines, cols);


    writeInt(thread, cols);
    writeInt(thread, lines);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict longname_cmd(TAThread thread,TAInputStream stream)
{
    char* res;
    
    START_TARGET_OPERATION(thread);
    res = longname();
    END_TARGET_OPERATION(thread);
 
    if (res!=NULL)
    {
        writeInt(thread, 1);
        writeString(thread, res);
    }
    else
    {
        writeInt(thread, 0);
    }
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict newterm_cmd(TAThread thread,TAInputStream stream)
{
    SCREEN* res;
    int cols;
    int lines;
    
    int     typeZero;
    char*   type = NULL;
    char*   outfile;
    char*   infile;
    FILE*   outf = NULL;
    FILE*   inf = NULL;

    typeZero=readInt(&stream);
    if (!typeZero)
    {
        type = readString(&stream);
    }
    outfile = readString(&stream);
    infile = readString(&stream);
    
    if (strcmp(outfile, "stdout") == 0)
    {
        outf = stdout;
    }
    
    if (strcmp(infile, "stdin") == 0)
    {
        inf = stdin;
    }
    
    START_TARGET_OPERATION(thread);
    res = newterm(type, outf, inf);
    END_TARGET_OPERATION(thread);


    atexit((void(*)())(endwin));
    writePointer(thread, stdscr);
    getmaxyx(stdscr, lines, cols);
    writeInt(thread, cols);
    writeInt(thread, lines);
    writePointer(thread, res);
    if (!typeZero)
    {
        writeString(thread, type);
    }
    else
    {
        writeString(thread, getenv("TERM"));
    }
    
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict set_term_cmd(TAThread thread,TAInputStream stream)
{
    SCREEN * res;
    SCREEN * newscr;

    newscr = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res = set_term(newscr);
    END_TARGET_OPERATION(thread);
    
    writePointer(thread, res);
    writePointer(thread, stdscr);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict termattrs_cmd(TAThread thread,TAInputStream stream)
{
    chtype res;
    
    START_TARGET_OPERATION(thread);
    res = termattrs();
    END_TARGET_OPERATION(thread);
    
    writeChType(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict vidattr_cmd(TAThread thread,TAInputStream stream)
{
    int    res = 0;
    chtype ch =readChType(&stream);
    char letter = (char)(ch & A_CHARTEXT);
    
    START_TARGET_OPERATION(thread);
    res = vidattr(ch);
    putchar(letter);
    fflush(stdout);
    refresh();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}

static TACommandVerdict vidputs_cmd(TAThread thread,TAInputStream stream)
{
    int    res = 0;
    chtype ch =readChType(&stream);
    char letter = (char)(ch & A_CHARTEXT);
    
    START_TARGET_OPERATION(thread);
    res = vidputs(ch, putchar);
    putchar(letter);
    fflush(stdout);
    refresh();
    END_TARGET_OPERATION(thread);
    
    writeInt(thread, res);
    sendResponse(thread);
    
    return taDefaultVerdict;
}


static TACommandVerdict get_cur_term_cmd(TAThread thread,TAInputStream stream)
{
   
    START_TARGET_OPERATION(thread);
    END_TARGET_OPERATION(thread);

    writePointer(thread, cur_term);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ungetch_char_cmd(TAThread thread,TAInputStream stream)
{
    int res, letter;

    letter = readInt(&stream);
   
    START_TARGET_OPERATION(thread);
    res = ungetch(letter);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict ungetch_array_cmd(TAThread thread,TAInputStream stream)
{
    int res = OK;
    char* ptr, *tmp;

    ptr = readPointer(&stream);
    tmp = ptr;

    while(*ptr)
        ptr++;

    START_TARGET_OPERATION(thread);
    
    res = ungetch('\n');
    
    while(res == OK && ptr != tmp)
    {
        res = ungetch(*--ptr);
    }
    
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);


    return taDefaultVerdict;
}


static TACommandVerdict window_state_cmd(TAThread thread,TAInputStream stream)
{
    WINDOW* win;
    struct my_ldat* l_dat;
    int i, size;

    win = readPointer(&stream);
    
    l_dat = (struct my_ldat*)win->_line;    
    
    START_TARGET_OPERATION(thread);    
    END_TARGET_OPERATION(thread);

    writeShort(thread, win->_cury);
    writeShort(thread, win->_curx);
    writeShort(thread, win->_maxy);
    writeShort(thread, win->_maxx);
    writeShort(thread, win->_begy);
    writeShort(thread, win->_begx);
    writeShort(thread, win->_flags);
    writeAttr(thread, win->_attrs);    
    writeChType(thread, win->_bkgd);
    writeInt(thread, win->_notimeout ? 1 : 0);
    writeInt(thread, win->_clear ? 1 : 0);
    writeInt(thread, win->_leaveok ? 1 : 0);
    writeInt(thread, win->_scroll ? 1 : 0);
    writeInt(thread, win->_idlok ? 1 : 0);
    writeInt(thread, win->_idcok ? 1 : 0);
    writeInt(thread, win->_immed ? 1 : 0);
    writeInt(thread, win->_sync ? 1 : 0);
    writeInt(thread, win->_use_keypad ? 1 : 0);
    writeInt(thread, win->_delay ? 1 : 0);

    for(i=0;i<win->_maxy+1;i++)
        writeLdat(thread, l_dat++, win->_maxx+1);
    
    writeShort(thread, win->_regtop);
    writeShort(thread, win->_regbottom);
    writeInt(thread, win->_parx);
    writeInt(thread, win->_pary);
    writePointer(thread, win->_parent);
    writePdat(thread, (struct my_pdat*)&win->_pad);
    writeShort(thread, win->_yoffset);

    sendResponse(thread);

    return taDefaultVerdict;
}

int isComment(char* arr)
{
    int i=0;

    while(arr[i] && arr[i]==' ')
        ++i;

    if(arr[i]=='#')
        return 1;

    return 0;
}

static TACommandVerdict readTerminfo_cmd(TAThread thread,TAInputStream stream)
{
    char* path = readString(&stream);
    FILE* in = fopen(path, "r+");
    char* arr = ta_alloc_memory(10000);
    memset(arr, 0, 10000);

    START_TARGET_OPERATION(thread);    
    END_TARGET_OPERATION(thread);
    
    while(fgets(arr, 10000, in))
    {
        if(!isComment(arr))   
        {
            writeString(thread, arr);            
            writeInt(thread, 1);
        }
    };    

    writeString(thread, "End of file");
    writeInt(thread, 0);
   
    sendResponse(thread);

    return taDefaultVerdict;
}
/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_terminal_commands(void)
{
    ta_register_command("delay_output",delay_output_cmd);

    ta_register_command("delscreen",delscreen_cmd);
    ta_register_command("endwin",endwin_cmd);
    ta_register_command("filter",filter_cmd);
    ta_register_command("initscr",initscr_cmd);
    ta_register_command("longname",longname_cmd);
    ta_register_command("newterm",newterm_cmd);

    ta_register_command("set_term",set_term_cmd);
    ta_register_command("termattrs",termattrs_cmd);
    ta_register_command("vidattr",vidattr_cmd);
    ta_register_command("vidputs",vidputs_cmd);


    ta_register_command("get_cur_term", get_cur_term_cmd);
    
    ta_register_command("ungetch_char", ungetch_char_cmd);
    ta_register_command("ungetch_array", ungetch_array_cmd);

    ta_register_command("window_state", window_state_cmd);

    ta_register_command("readTerminfo", readTerminfo_cmd);
}







