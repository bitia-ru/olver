#ifndef __MEMTERM_H__
#define __MEMTERM_H__

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include "iterm/core.h"
#include "common.h"

/*
 * Macro
 */
#define xfree(ptr)    \
do            \
  {            \
    free (ptr);        \
    ptr = NULL;        \
  }            \
while (0)

/*
 * Structures
 */

/* iterm structure */
struct _Memterm
{
  VTCore    *vtcore;    /* VTCore pointer */
  VTScreenView    *view;        /* VT screen view pointer */
  TerminalIO    *tio;        /* terminal IO data pointer */
  char        **command;    /* Command, which runs on the terminal. */
  pid_t        cmd_pid;    /* Process ID of the command. */
  char        *term_env;    /* Terminal Environment. */
  size_t    col_max;    /* The number of columns. */
  size_t    row_max;    /* The number of raws. */
  char        rendition[64];    /* Current rendition of characters. */
};

typedef struct _Memterm Memterm;


/*
 * Synbolic Constants
 */
#define DEFAULT_COL_MAX        80
#define DEFAULT_RAW_MAX        25
#define DEFALUT_TERM        "vt100"
#define DEFAULT_OUT_FP        stdout

/*
 * Global variables
 */
#ifdef DECL_GLOBALS
# define extern
#endif

extern Memterm    *pMemterm;    /* Pointer to the memterm entity. */
extern char    *out_filename;    /* Name of output file. */
extern int    listen_sockfd;    /* File descriptor of socket for listen. */

#undef extern


/*
 * Functions
 */

/* tools.c */

/* Exit the program with an error message.  */
void fatal_error (const char *format, ...);

/* Duplicate string. When error is occured, exit the program.  */
char *xstrdup(const char *str);


/*
 * itp_opts.c
 */

/* Make a string arrangement of executed command. */
int make_cmdarg (char *str);

/* Get geometry. */
int get_geometry (const char *geo_str);

/* Get the TERM environment variable. */
int get_term_env (const char *name);

/* Open a file pointer. Output data is written to it. */
int open_output_fp (const char *file);

/* Make a file descriptor of socket for listen. */
int make_listen_sockfd (void);


/*
 * vt.c
 */

/* Initialize VT machine */
int InitVt (void);


/*
 * dump.c
 */

/* Dump the displayed content to the file. */
void dump_content (size_t scol, size_t srow, size_t ecol, size_t erow);
void VTScreenView_draw_text (VTScreenView *view, int col, int row,
                char *mbstring, int length, int width);
void VTScreenView_set_rendition (VTScreenView *view, int bold, int blink,
    int inverse, int underline, int foreground, int background, char charset);

#endif    /* __MEMTERM_H__ */
