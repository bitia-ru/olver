/*
 * ./SRC/common/curses_i18n_utils/itp_opts.c
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
#include <sys/stat.h>
#include <sys/un.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "memterm.h"

#include <errno.h>

/*
 * -e optoin:
 * Make a string arrangement of executed command.
 */
static int
dismantle (char *cmd_str, int num)
{
  char *start, *end;

  ++num;
  pMemterm->command =
    (char **) realloc (pMemterm->command, sizeof (char *) * num);
  if (pMemterm->command == NULL)
    return -1;

  /* Skip white space charcters. */
  for (start = cmd_str; isspace (*start) && *start != '\0'; ++start);

  if (*start == '\0')
    {
      pMemterm->command[num - 1] = NULL;
      return 0;
    }

  /* Skip non-white space characters. */
  for (end = start; !isspace (*end) && *end != '\0'; ++end);

  pMemterm->command[num - 1] = (char *) malloc (end - start + 1);
  memcpy (pMemterm->command[num - 1], start, end - start);
  pMemterm->command[num - 1][end - start] = '\0';

  return (dismantle (end, num));
}

int
make_cmdarg (char *str)
{
  int  ret;
  char *cmd_str;

  if (str != NULL)
    cmd_str = strdup (str);
  else
    {
      if (getenv ("SHELL") != NULL)
    cmd_str = strdup (getenv ("SHELL"));
      else
    cmd_str = strdup ("/bin/sh");
    }

  ret = dismantle (cmd_str, 0);
  xfree (cmd_str);

  if (pMemterm->command != NULL && pMemterm->command[0] == NULL)
    ret = -1;

  return (ret);
}


/*
 * -g option:
 * Get the geometry.
 */
int
get_geometry (const char *geo_str)
{
  int ret;
  int col_max, row_max;

  if (geo_str == NULL)
    {
      col_max = DEFAULT_COL_MAX;
      row_max = DEFAULT_RAW_MAX;
    }
  else
    {
      ret = sscanf (geo_str, "%dx%d", &col_max, &row_max);
      if (ret != 2 || col_max < 1 || row_max < 1)
    return -1;
    }

  pMemterm->col_max = col_max;
  pMemterm->row_max = row_max;

  return 0;
}


/*
 * -t option:
 * Get the TERM environment variable.
 */
int
get_term_env (const char *name)
{
  if (name == NULL)
    pMemterm->term_env = strdup (DEFALUT_TERM);
  else
    pMemterm->term_env = strdup (name);

  return 0;
}


/*
 * -o option:
 * Define the output stream.
 */
int
open_output_fp (const char *file)
{
  if (file == NULL)
    {
      out_filename = NULL;
      return 0;
    }

  if ((out_filename = (char *) calloc (strlen (file) + 1, sizeof(char))) == NULL)
    {
      fprintf (stderr, "There is not enough memeory to run.\n");
      return -1;
    }

  strcpy (out_filename, file);

  return 0;
}


/*
 * Make a file descriptor of socket for listen.
 */
int
make_listen_sockfd (void)
{
  struct sockaddr_un listen_sockaddr;
  size_t listen_sockaddr_len;
  // Tanur: This is for debugging purposes
  int bindres;
  int binderr;

  if (getenv (SOCK_FNAME_ENV) == NULL)
    {
      fprintf (stderr, "Environment Variable %s is not defined.\n",
      SOCK_FNAME_ENV);
      return -1;
    }

  unlink (getenv (SOCK_FNAME_ENV));

  if ((listen_sockfd = socket (AF_UNIX, SOCK_STREAM, 0)) == -1)
    {
      fprintf (stderr, "Cannot create a socket.\n");
      return -1;
    }

  listen_sockaddr.sun_family = AF_UNIX;
  strcpy (listen_sockaddr.sun_path, getenv (SOCK_FNAME_ENV));
  listen_sockaddr_len = sizeof (struct sockaddr_un);

  unlink(listen_sockaddr.sun_path);

  bindres = bind (listen_sockfd,
      (struct sockaddr *)&listen_sockaddr, listen_sockaddr_len);
  binderr = errno;

  if ( bindres == -1 )
    {
      fprintf (stderr, "Cannot name to a socket (0x%X).\n", binderr);
      return -1;
    }

  return 0;
}
