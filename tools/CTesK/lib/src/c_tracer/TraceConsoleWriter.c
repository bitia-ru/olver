/* 
 * File: TraceConsoleWriter.c
 * Description: 
 *       This file contains an implementation of TraceConsoleWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "TraceConsoleWriter.h"


TraceWriter * TraceConsoleWriter_create()
{
  TraceWriter * tr = (TraceWriter *)malloc(sizeof(*tr));
  if(tr != NULL) {
    tr->state = NULL;
    tr->delete_state = TraceConsoleWriter_delete_state;
    tr->puts = TraceConsoleWriter_puts;
    tr->flush = TraceConsoleWriter_flush;
	tr->refCnt = 0;
  }
  return tr;
}

void TraceConsoleWriter_delete_state(void *arg) {}

void TraceConsoleWriter_puts(void *arg, String *str)
{
  if(str != NULL) {
	fputs(toCharArray_String(r(str)), stdout);
	destroy(str);
  }
}

void TraceConsoleWriter_flush(void *arg)
{
  fflush(stdout);
}
