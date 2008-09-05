/*
 * ./SRC/common/curses_i18n_utils/dump.c
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
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "iterm/core.h"

#include "memterm.h"

FILE *out_fp;        /* Output Stream.*/

/* Text drawing function. This is used by VTScreen. */
void
VTScreenView_draw_text (VTScreenView *view, int col, int row,
    char *mbstring, int length, int width)
{
  if (out_fp == NULL)
    return;

  fprintf (out_fp, "pos(%2d,%2d) bl(%3d) wd(%2d) rd(%s) : ",
        col, row, length, width, pMemterm->rendition);
  fwrite (mbstring, sizeof (char), length, out_fp);
  fprintf (out_fp, "\n");
}


/* Rendition setting function. This is used by VTScreen. */
void
VTScreenView_set_rendition (VTScreenView *view, int bold, int blink,
    int inverse, int underline, int foreground,
    int background, char charset)
{
  char str[32], *p;

  memset (pMemterm->rendition, '\0', sizeof (pMemterm->rendition));

  if (bold)
    strcat (pMemterm->rendition, "bd|");
  else
    strcat (pMemterm->rendition, "  |");

  if (blink)
    strcat (pMemterm->rendition, "bk|");
  else
    strcat (pMemterm->rendition, "  |");

  if (inverse)
    strcat (pMemterm->rendition, "iv|");
  else
    strcat (pMemterm->rendition, "  |");

  if (underline)
    strcat (pMemterm->rendition, "ul|");
  else
    strcat (pMemterm->rendition, "  |");

  sprintf (str, "fg(%d)|", foreground);
  strcat  (pMemterm->rendition, str);

  sprintf (str, "bk(%d)|", background);
  strcat  (pMemterm->rendition, str);

  sprintf (str, "cs(%c)|", charset);
  strcat (pMemterm->rendition, str);

  p  = strrchr (pMemterm->rendition, '|');
  *p = '\0';

  return;
}


/* Dump the displayed content to the file. */
void dump_content (size_t scol, size_t srow, size_t ecol, size_t erow)
{
  int temp;

  if (scol == ecol || srow == erow)
    {
      scol = 0;
      srow = 0;
      ecol = pMemterm->col_max;
      erow = pMemterm->row_max;
    }

  scol = (scol < 0) ? 0 : (scol > pMemterm->col_max) ? pMemterm->col_max : scol;
  srow = (srow < 0) ? 0 : (srow > pMemterm->row_max) ? pMemterm->row_max : srow;
  ecol = (ecol < 0) ? 0 : (ecol > pMemterm->col_max) ? pMemterm->col_max : ecol;
  erow = (erow < 0) ? 0 : (erow > pMemterm->row_max) ? pMemterm->row_max : erow;

  if (scol > ecol)
    {
      temp = ecol;
      ecol = scol;
      scol = temp;
    }
      
  if (srow > erow)
    {
      temp = erow;
      erow = srow;
      srow = temp;
    }

    if (out_filename == NULL)
      out_fp = DEFAULT_OUT_FP;
    else
      {
    if ((out_fp = fopen (out_filename, "w")) == NULL)
      {
        fprintf (stderr, "Cannot open %s.\n", out_filename);
        return;
      }
      }

  VTCore_redraw (pMemterm->vtcore, scol, srow, ecol, erow);
  fflush (out_fp);

  if (out_filename != NULL)
    {
      fclose (out_fp);
      out_fp = NULL;
    }

  return;
}
