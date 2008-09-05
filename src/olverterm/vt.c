/*
 * ./SRC/common/curses_i18n_utils/vt.c
 *
 * Copyright (c) 1991, 1992, 1997, 1998, 1999, 2001 X/Open Company Ltd.
 * (X/Open)
 * trading as The Open Group
 * Copyright (c) 2001, 2003 International Business Machines Corp.
 * All rights reserved except as granted by this License.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the "Artistic License" which comes with this
 * Kit, with the following modification:
 * a) "executable(s)" should be interpreted to include
 * "test case(s)"
 * b) if you wish to make changes as defined in clause 2 and 3, and
 * distribute a modified version of this package, then
 * clauses 3c and 4c are required
 * c) Clause 7 is rephrased as follows: "Subroutines supplied by you
 * and linked into this Package shall not be considered part of this
 * Package".
 *
 *
 * X/OPEN, TRADING AS THE OPEN GROUP, AND IBM CORP. DISCLAIM ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL X/OPEN OR IBM CORP. BE
 * LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * You should have received a copy of the Artistic License with this
 * Kit, in the file named "Artistic".  If not, we'll be glad to provide one.
 */

#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "iterm/core.h"
#include "iterm/unix/ttyio.h"

#include "memterm.h"

/* Make a VTScreenView sturcuture. */
static VTScreenView *
VTScreenView_new (void)
{
  VTScreenView *view;

  view = malloc (sizeof (VTScreenView));
  if (view == NULL)
    {
      perror ("VTScreenView_new");
      return NULL;
    }

  VTScreenView_init (view);
  view->set_rendition    = VTScreenView_set_rendition;
  view->draw_text    = VTScreenView_draw_text;

  return view;
}


/* Initialize Terminal IO */
static TerminalIO *
init_io (void)
{
  char *env;
  TerminalIO *ret;

  env = (char *) malloc (5 /* "TERM=" */ + strlen (pMemterm->term_env) + 1);
  strcpy (env, "TERM=");
  strcat (env, pMemterm->term_env);
  putenv (env);

  if (setgid (getgid ()) != 0) abort();
  if (setuid (getuid ()) != 0) abort();

  ret = (TerminalIO *) TtyTerminalIO_new (pMemterm->col_max,
      pMemterm->row_max, *(pMemterm->command), pMemterm->command);

  xfree  (env);
  return ret;
}


/* Initialize VT machine */
int
InitVt (void)
{
  /* create screen view object */
  pMemterm->view = VTScreenView_new ();
  if (pMemterm->view == NULL)
    return -1;

  /* create terminal IO object */
  pMemterm->tio = init_io ();
  if (pMemterm->tio == NULL)
    {
      fprintf (stderr, "init_io() failed.\n");
      return -1;
    }

  /* create VTCore object */
  pMemterm->vtcore = VTCore_new (pMemterm->tio,
                 pMemterm->col_max, pMemterm->row_max,
                 pMemterm->row_max);

  if (pMemterm->vtcore == NULL)
    {
      fprintf (stderr, "VTCore_new() failed.\n");
      return -1;
    }

  /* set screen view object pointer to VTCore */
  VTCore_set_screen_view (pMemterm->vtcore, pMemterm->view);

  return 0;
}
