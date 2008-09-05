#ifndef __COMMON_H__
#define __COMMON_H__

/*
 * Synbolic Constants
 */

/* The followings are concerned with socket. */
#define SOCK_FNAME_ENV          "CT_SOCKNAME"
#define START_INDICATION    's'
#define PID_INDICATION        'p'
#define DUMP_INDICATION        'd'
#define INPUT_INDICATION    'i'
#define ACK_INDICATION        'A'

/* The following is concerned with a dump file of the test program. */
#define PROG_DUMPFILE_ENV    "CT_DUMPFILE"

/* Test result codes */
#define NULLCODE        0
#define PASS            1
#define WARNING         2
#define FIP             3
#define UNTESTED        4
#define FAIL            5
#define UNINITIATED     6
#define UNRESOLVED      7
#define UNREPORTED      8
#define LEFT            9

#ifdef DECL_GLOBALS
char *result_code[] = {
    "",
    "PASS",
    "WARNING",
    "FIP",
    "UNTESTED",
    "FAIL",
    "UNINITIATED",
    "UNRESOLVED",
    "UNREPORTED",
    "LEFT"
};
#else
extern char *result_code[];
#endif

#endif    /* __COMMON_H__ */
