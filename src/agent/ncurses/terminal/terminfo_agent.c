/*
 * File: ncurses/terminal/terminfo_agent.c
 *
 * Author:
 * Version:  $Id: terminfo_agent.c,v 1.43 2008/10/02 16:13:35 phoenix Exp $
 *
 * Copyright (c) 2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 */

#include "ncurses/terminal/terminfo_agent.h"
#define _CURSES_HEADER "curses.h"
#include "../olverterm/addon.h"
#include <term.h>
#include <stdlib.h>
	
#define NCURSES_STACK_BUFFSIZE 1024*256
#define NCURSES_TERMDUMP ta_get_test_file_path("agent.termdump")
#define NCURSES_TERMINAL "olverct"
#define OLVERCT_TERMINFO_PATH   "./terminfo/olverct.terminfo"


TACommandVerdict create_ncurses_process_cmd(TAThread thread, TAInputStream stream)
{
    int code = 0;
    char* termname = readString(&stream);
    int sx = readInt(&stream);
    int sy = readInt(&stream);
    char sockname[256];
    char termdump[256];
    char termexp[256];
    char termdiff[256];
    char dumpfile[256];
    char termsize[30];
    char size[30];

  // Init test system descriptor
    code = fork();
    if (code == 0)
    {
        /*
            #export CT_SOCKNAME=olversock
            #export TEST_NAME="agent"
            #export TERM_DUMP="agent.termdump"
            #export TERM_EXP="agent.termexp"
            #export TERM_DIFF="agent.termdiff"
            #export CT_DUMPFILE="agent.progdump"
            #export TERM_SIZE="20x40"
            #export TEST_TERM_NAME="olverct"

            #./olverterm -g ${TERM_SIZE} -t $(TEST_TERM_NAME) -e "./${TEST_NAME}" -o ${TERM_DUMP}
        */

        /*
         * For those forms not containing an envp pointer ( execl(), execv(),
         * execlp(), and execvp()), the environment for the new process image
         * shall be taken from the external variable environ in the calling process.
         */
        sprintf(sockname, "CT_SOCKNAME=%s", ta_get_test_file_path("olversock"));
        sprintf(termdump, "TERM_DUMP=%s", NCURSES_TERMDUMP);
        sprintf(termexp, "TERM_EXP=%s", ta_get_test_file_path("agent.termexp"));
        sprintf(termdiff, "TERM_DIFF=%s", ta_get_test_file_path("agent.termdiff"));
        sprintf(dumpfile, "CT_DUMPFILE=%s", ta_get_test_file_path("agent.progdump"));
        sprintf(termsize, "TERM_SIZE=%dx%d", sx, sy);
        sprintf(size, "%dx%d", sx, sy);
        
        putenv(sockname);
        putenv("TEST_NAME=agent");
        putenv(termdump);
        putenv(termexp);
        putenv(termdiff);
        putenv(dumpfile);
        putenv("TERMINFO=./terminfo");
        putenv(termsize);
        //putenv("TERM_SIZE=20x40");
        
        code = execl("./olverterm", "./olverterm", "-g", size, "-t", termname, "-e", "./agent -silent", "-o", NCURSES_TERMDUMP, NULL);
        perror("create_ncurses_process");
        assertion( 0, "create_ncurses_process failed" );
    }

    // Response
    if (code != -1)
    {
        writeString(thread, "Ok");
    }
    else
        writeString(thread, "Failed");

    sendResponse(thread);

    return taDefaultVerdict;
}

TACommandVerdict dump_screen_contents_cmd(TAThread thread, TAInputStream stream)
{
    int success = 0;
    char resBuff[NCURSES_STACK_BUFFSIZE];
    FILE *rfile = NULL;
    resBuff[0]='\0';

    Dump_Contents(0, 0, 0, 0);

    rfile = fopen(NCURSES_TERMDUMP, "rb");
    if(rfile)
    {
        size_t rd = fread(resBuff, 1, sizeof(resBuff), rfile);
        success = ferror(rfile);

        if(rd<sizeof(resBuff)/sizeof(char))
        {
            writeByteArray(thread, resBuff, rd);
            success = 1;
        } else {
            success = 0;
        }
        fclose(rfile);
        remove(NCURSES_TERMDUMP);
    }

    // Response
    if(success)
        writeString(thread, "Ok");
    else
        writeString(thread, "Failed");

    sendResponse(thread);

    return taDefaultVerdict;
}

TACommandVerdict read_terminfo_cmd(TAThread thread, TAInputStream stream)
{
    char resBuff[NCURSES_STACK_BUFFSIZE];
    int success = sizeof(resBuff);
    FILE *rfile = NULL;
    resBuff[0]='\0';

    rfile = fopen(OLVERCT_TERMINFO_PATH, "rb");
    if(rfile)
    {
        size_t rd = fread(resBuff, 1, sizeof(resBuff), rfile);
        success = ferror(rfile);
        if(rd<sizeof(resBuff)/sizeof(char))
        {
            writeByteArray(thread, resBuff, rd);
            success = 1;
        } else {
            sendException(thread, "Error reading terminfo");
        }
        fclose(rfile);
    }

    // Response
    if(success)
        writeString(thread, "Ok");
    else
        writeString(thread, "Failed");

    sendResponse(thread);

    return taDefaultVerdict;
}

TACommandVerdict input_string_cmd(TAThread thread, TAInputStream stream)
{
    int success = 0;
    char* resBuff;
    int strLen = 0;
    size_t size;

    // Prepare
    readByteArray(&stream, &resBuff, &size);
    ta_debug_printf("%s: %d\n", resBuff, size);
    Input_String(resBuff, size);

    // Response
    writeString(thread, "Ok");
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                         Agent Commands                         **/
/********************************************************************/

static TACommandVerdict del_curterm_cmd(TAThread thread, TAInputStream stream)
{
    int      res;
    TERMINAL *nterm;

    nterm = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res =  del_curterm(nterm);
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}


static TACommandVerdict putp_cmd(TAThread thread, TAInputStream stream)
{
    int res;
    char *str;

    str = readString(&stream);

    START_TARGET_OPERATION(thread);
    res = putp(str);
    putchar('x');
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tputs_cmd(TAThread thread, TAInputStream stream)
{
    int res;
    char *str;
    int affcnt;

    str = readString(&stream);
    affcnt = readInt(&stream);

    START_TARGET_OPERATION(thread);
    res = tputs(str, affcnt, putchar);
    putchar('x');
    END_TARGET_OPERATION(thread);

    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict restartterm_cmd(TAThread thread, TAInputStream stream)
{
    char* term = NULL;
    int isZero;
    int res;
    int errret;
    char* term_val;

    isZero = readInt(&stream);
    if (!isZero)
    {
        term = readString(&stream);
    }


    START_TARGET_OPERATION(thread);
    res =  restartterm(term, stdout, &errret);
    END_TARGET_OPERATION(thread);


    writeInt(thread, res);
    writeInt(thread, errret);


    term_val = getenv("TERM");
    if (term_val==NULL || strcmp(term_val, "") == 0)
    {
        writeString(thread, "unknown");
        writeInt(thread, 1);
    }
    else
    {
        writeString(thread, term_val);
        writeInt(thread, 0);
    }

    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict set_curterm_cmd(TAThread thread, TAInputStream stream)
{
    TERMINAL* res;
    TERMINAL *nterm;

    nterm = readPointer(&stream);

    START_TARGET_OPERATION(thread);
    res =  set_curterm(nterm);
    END_TARGET_OPERATION(thread);

    writePointer(thread, res);
    writePointer(thread, stdscr);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict setupterm_cmd(TAThread thread, TAInputStream stream)
{
    char* term = NULL;
    int isZero;
    int res;
    int errret;
    char* term_val;

    isZero = readInt(&stream);
    if (!isZero)
    {
        term = readString(&stream);
    }


    START_TARGET_OPERATION(thread);
    res =  setupterm(term, stdout, &errret);
    END_TARGET_OPERATION(thread);


    writeInt(thread, res);
    writeInt(thread, errret);


    term_val = getenv("TERM");
    if (term_val==NULL || strcmp(term_val, "") == 0)
    {
        writeString(thread, "unknown");
        writeInt(thread, 1);
    }
    else
    {
        writeString(thread, term_val);
        writeInt(thread, 0);
    }

    sendResponse(thread);

    return taDefaultVerdict;

}

static TACommandVerdict termname_cmd(TAThread thread, TAInputStream stream)
{
    char* res;


    START_TARGET_OPERATION(thread);
    res =  termname();
    END_TARGET_OPERATION(thread);

    writeString(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tigetflag_cmd(TAThread thread, TAInputStream stream)
{
    char* capname;
    int res;

    // Prepare
    capname = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tigetflag(capname);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tigetnum_cmd(TAThread thread, TAInputStream stream)
{
    char* capname;
    int res;

    // Prepare
    capname = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tigetnum(capname);

    END_TARGET_OPERATION(thread);

    // Response
    writeInt(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tigetstr_cmd(TAThread thread, TAInputStream stream)
{
    char* capname;
    char* res;

    // Prepare
    capname = readString(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tigetstr(capname);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

static TACommandVerdict tparm_cmd(TAThread thread, TAInputStream stream)
{
    char* cap;
    long p1;
    long p2;
    long p3;
    long p4;
    long p5;
    long p6;
    long p7;
    long p8;
    long p9;
    char* res;

    // Prepare
    cap = readString(&stream);
    p1 = readLong(&stream);
    p2 = readLong(&stream);
    p3 = readLong(&stream);
    p4 = readLong(&stream);
    p5 = readLong(&stream);
    p6 = readLong(&stream);
    p7 = readLong(&stream);
    p8 = readLong(&stream);
    p9 = readLong(&stream);

    START_TARGET_OPERATION(thread);

    // Execute
    res = tparm(cap, p1, p2, p3, p4, p5, p6, p7, p8, p9);

    END_TARGET_OPERATION(thread);

    // Response
    writePointer(thread, res);
    sendResponse(thread);

    return taDefaultVerdict;
}

/********************************************************************/
/**                      Agent Initialization                      **/
/********************************************************************/
void register_ncurses_terminal_terminfo_commands(void)
{
    // Common commands
    ta_register_command("create_ncurses_process", create_ncurses_process_cmd);
    ta_register_command("dump_screen_contents", dump_screen_contents_cmd);
    ta_register_command("read_terminfo", read_terminfo_cmd);
    ta_register_command("input_string", input_string_cmd);
    // subsystem commands
    ta_register_command("del_curterm", del_curterm_cmd);
    ta_register_command("putp", putp_cmd);
    ta_register_command("restartterm", restartterm_cmd);
    ta_register_command("set_curterm", set_curterm_cmd);
    ta_register_command("setupterm", setupterm_cmd);
    ta_register_command("termname", termname_cmd);
    ta_register_command("tigetflag", tigetflag_cmd);
    ta_register_command("tigetnum", tigetnum_cmd);
    ta_register_command("tigetstr", tigetstr_cmd);
    ta_register_command("tparm", tparm_cmd);
    ta_register_command("tputs", tputs_cmd);
}
