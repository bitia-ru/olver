/*
 * ./SRC/common/curses_i18n_lib/socket.c
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

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "addon.h"

#define DECL_GLOBALS
#include "common.h"
#undef  DECL_GLOBALS

#undef WAIT_TIME_MAX
#define WAIT_TIME_MAX 5

FILE *err_fp;

static void
connect_error (int sig)
{
  fprintf (err_fp, "%s:Cannot communicate with terminal emulator.\n",
      result_code[UNRESOLVED]);
  exit (EXIT_FAILURE);
}

/*
 * Make a file descriptor of socket.
 * This socket is used for connecting memterm.
 */
int
sock_client (char *messege, size_t message_len)
{
  int  sockfd;
  int  len;
  int  result;
  char buf[BUFSIZ], *env_p;
  struct sockaddr_un address;

  /* Make a file to store an error message. */
  env_p = getenv(PROG_DUMPFILE_ENV);
  if (env_p != NULL)
    {
      if ((err_fp = fopen (env_p, "w")) == NULL)
    err_fp = stderr;
    }
  else
    err_fp = stderr;

  /* Get a filename of socket. */
  env_p = getenv(SOCK_FNAME_ENV);
  if (env_p == NULL)
    {
      fprintf (err_fp, "%s:The `%s' variable is not defined.\n",
      result_code[UNRESOLVED], SOCK_FNAME_ENV);
      if (err_fp != stderr)
    fclose (err_fp);
      return -1;
    }

  if (signal (SIGALRM, connect_error) == SIG_ERR)
    {
      fprintf (err_fp, "%s:Cannot use the signal `SIGALRM'.\n",
      result_code[UNRESOLVED]);
      exit (EXIT_FAILURE);
    }

  sockfd = socket (AF_UNIX, SOCK_STREAM, 0);
  address.sun_family = AF_UNIX;

  strcpy (address.sun_path, env_p);
  len = sizeof (address);

  /* Set alarm. */
  alarm (WAIT_TIME_MAX);

  while (connect (sockfd, (struct sockaddr *)&address, len) == -1);

  result = write (sockfd, messege, message_len);
  if (result == -1 || result != message_len)
    {
      fprintf (err_fp, "%s:Cannot write a message into the socket.\n",
      result_code[UNRESOLVED]);
      exit (EXIT_FAILURE);
    }

  result = read (sockfd, buf, BUFSIZ);
  if (result == -1 || buf[0] != ACK_INDICATION)
    {
      fprintf (err_fp, "%s:No reply from the memterm.\n",
      result_code[UNRESOLVED]);
      exit (EXIT_FAILURE);
    }

  /* Unset alarm. */
  alarm (0);

  close (sockfd);
  if (err_fp != stderr)
    fclose (err_fp);
  return 0;
}
