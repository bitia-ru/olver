/*
 * ./SRC/common/curses_i18n_utils/memterm.c
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
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/un.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>

// Tanur
#include <string.h>
#include <sys/select.h>
    
#include "iterm/core.h"
#include "iterm/unix/ttyio.h"

#define DECL_GLOBALS
# include "memterm.h"
#undef  DECL_GLOBALS

/* A pointer to runtime memterm name. */
static char *memterm_progname;

/*
 * Display usage.
 * If `exit_status' is EXIT_SUCCESS, write to stdout. Otherwise to stderr.
 */
static void
usage (int exit_status)
{
  FILE *msg_fp = stderr;

  if (exit_status == EXIT_SUCCESS)
    msg_fp = stdout;

  fprintf (msg_fp, "Usage: %s -i input_socket_filename\n"
           " [-e <command>]\n"
           " [-g <max_column>x<max_raw>]\n "
           " [-t TERM]\n"
           " [-o output filename]\n"
            , memterm_progname);
  exit (exit_status);
}


static void
exit_memterm ()
{
  if (out_filename != NULL)
    free (out_filename);

  close (listen_sockfd);
  unlink (getenv (SOCK_FNAME_ENV));

  exit (0);
}


/*
 * Protocol `?:....'
 *
 * When first character `?' is ...
 *
 *  s: Just return ACK.
 *  p: Recieve the process id of executed program.
 *  d: Dump the displayed content to the file.
 *  w: Write characters to the executed program via pty.
 */
static int
parse_sequence (void)
{
  char ack;
  char buf[BUFSIZ];
  int  read_bytes;
  int  accepted_sockfd;
  struct sockaddr_un accepted_addr;
  socklen_t accepted_addr_len;

  accepted_sockfd = accept (listen_sockfd,
    (struct sockaddr *)&accepted_addr, &accepted_addr_len);

  if (accepted_sockfd == -1)
    fatal_error ("Cannot accept a socket.\n");

  read_bytes = read (accepted_sockfd, buf, BUFSIZ);
  buf[read_bytes] = '\0';

  if (read_bytes == 0)
    return 0;
  else if (read_bytes < 0)
    return -1;

  switch (buf[0])
    {
    case START_INDICATION:
      break;

    case DUMP_INDICATION:
    {
      int scol, srow, ecol, erow;
      sscanf (buf + 1, "%d,%d,%d,%d", &scol, &srow, &ecol, &erow);
      dump_content (scol, srow, ecol, erow);
      break;
    }

    case INPUT_INDICATION:
      if (read_bytes <= 1)
    break;
      else
    VTCore_write (pMemterm->vtcore, buf + 1, read_bytes - 1);
      break;

    default:
      return -1;
    }

  ack = ACK_INDICATION;
  if (write (accepted_sockfd, &ack, 1) == -1)
    return -1;

  return 0;
}


/*
 * Main
 */
int
main (int argc, char *argv[])
{
  char *cmd_str  = NULL;
  char *geo_str  = NULL;
  char *term_str = NULL;
  char *out_file = NULL;
  int  optc;

  for(optc=0;optc<argc;optc++) printf("opt:%d val:%s\n",optc,argv[optc]);

  setlocale (LC_ALL, "");

  memterm_progname = xstrdup (argv[0]);

  /* Allocate the memory for Memterm structure. */
  pMemterm = (Memterm *) malloc (sizeof (Memterm));
  if (pMemterm == NULL)
    fatal_error ("There is not enough memory available now.\n");
  pMemterm->command = NULL;

  /* Interpret options. */
  while ((optc = getopt (argc, argv, "e:g:t:o:h")) != -1)
    {
      switch (optc)
    {
    case 'e':
      if (optarg == NULL)
        usage (EXIT_FAILURE);
      cmd_str = xstrdup (optarg);
      break;

    case 'g':
      if (optarg == NULL)
        usage (EXIT_FAILURE);
      geo_str = xstrdup (optarg);
      break;

    case 't':
      if (optarg == NULL)
        usage (EXIT_FAILURE);
      term_str = xstrdup (optarg);
      break;

    case 'o':
      if (optarg == NULL)
        usage (EXIT_FAILURE);
      out_file = xstrdup (optarg);
      break;

    case 'h':
      usage (EXIT_SUCCESS);
      break;

    default:
      usage (EXIT_FAILURE);
    }
    }
  if (optind < argc)
    usage (EXIT_FAILURE);

  if (make_cmdarg (cmd_str) == -1)
    fatal_error ("Cannot execute `%s'\n", cmd_str);
  xfree (cmd_str);

  if (get_geometry (geo_str) == -1)
    fatal_error ("Wrong geometry.\n");
  xfree (geo_str);

  if (get_term_env (term_str) == -1)
    fatal_error ("Wrong TERM environment variable.\n");
  xfree (term_str);

  if (open_output_fp (out_file) == -1)
    exit (EXIT_FAILURE);
  xfree (out_file);

  if (make_listen_sockfd() == -1)
    exit (EXIT_FAILURE);

  /* Initialize VT. */
  if ((InitVt ()) < 0)
    exit (EXIT_FAILURE);

  listen (listen_sockfd, 5);

  /* Main loop. */
    {
      int  ret;
      int  fd, max;
      fd_set rfds;
      struct timeval timeout;

      fd = TtyTerminalIO_get_associated_fd (pMemterm->tio);
      max = 0;

      while (1)
    {
      /* Check the chile process is alive or not. */
      if (waitpid (-1, (int *)0, WNOHANG) != 0)
        exit_memterm ();

      FD_ZERO (&rfds);
      FD_SET (fd, &rfds);
      FD_SET (listen_sockfd, &rfds);
      timeout.tv_sec = 0;
      timeout.tv_usec = 100000;
      if (fd > max)
        max = fd;

      ret = select (max + 1, &rfds, NULL, NULL, &timeout);
      if (ret == 0 || (ret < 0 && errno == EINTR))
        continue;

      if (ret < 0)
        perror ("select");

      if (FD_ISSET (fd, &rfds))
        {
          if (ret > 0)
        VTCore_dispatch(pMemterm->vtcore);
        }
      else if (FD_ISSET (listen_sockfd, &rfds))
        {
          if (parse_sequence () == -1)
        fatal_error ("Cannot Communicate with the executed program.\n");
        }
    }
    }

  exit_memterm (0);
}
