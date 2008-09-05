/*
 * ./SRC/common/curses_i18n_lib/communicate.c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "addon.h"
#include "common.h"

/* Dump a message. */
void
Message (int type, char *format, ...)
{
  FILE *message_fp = NULL;
  char message[BUFSIZ];
  char *env_p;
  va_list arg_p;

  va_start (arg_p, format);
  vsprintf (message, format, arg_p);
  va_end   (arg_p);

  if (message_fp == NULL)
    {
      if ((env_p = getenv (PROG_DUMPFILE_ENV)) == NULL)
    message_fp = stderr;
      else
    {
      if ((message_fp = fopen (env_p, "w")) == NULL)
        message_fp = stderr;
    }
    }

  fprintf (message_fp, "%s:%s\n", result_code[type], message);

  if (message_fp != stderr)
    fclose (message_fp);
}


/* Start a session with terminal emulator */
int
Make_Session (void)
{
  char message[] = { START_INDICATION, '\0' };
  return (sock_client (message, 1));
}

/* Request terminal emulator to dump the displayed contents. */
void
Dump_Contents (int y, int x, int y_width, int x_width)
{
  int ret;
  char message[256];

  sleep (1);

  sprintf (message, "%c%d,%d,%d,%d", DUMP_INDICATION, x, y, x + x_width, y + y_width);
  ret = sock_client (message, strlen (message));

  if (ret == -1)
    sleep (5);
  else
    Message (LEFT, "");
}

/* Request terminal emulator to input string via pty. */
void
Input_String (char *request, size_t request_len)
{
  char   *message;
  size_t message_len;

  message_len = request_len + 1;

  message = malloc ((message_len + 1) * sizeof(char));
  message[0] = INPUT_INDICATION;
  memcpy (message + 1, request, request_len);
  message[message_len] = '\0';

  if (Make_Session ())
    return;

  sock_client (message, message_len);

  free (message);
}
