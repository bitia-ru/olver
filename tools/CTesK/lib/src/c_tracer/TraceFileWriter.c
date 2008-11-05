/* 
 * File: TraceFileWriter.c
 * Description: 
 *       This file contains an implementation of TraceFileWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "TraceFileWriter.h"


TraceWriter * TraceFileWriter_create(FILE *file)
{
  TraceWriter * tr = (TraceWriter *)malloc(sizeof(*tr));
  if(tr != NULL) {
    tr->state = file;
    tr->delete_state = TraceFileWriter_delete_state;
    tr->puts = TraceFileWriter_puts;
    tr->flush = TraceFileWriter_flush;
	tr->refCnt = 0;
  }
  return tr;
}

void TraceFileWriter_delete_state(void *file)
{
  if(file != NULL) {
    fflush((FILE *)file);
    fclose((FILE *)file);
  }
}

void TraceFileWriter_puts(void *file, String *str)
{
	if(file != NULL && str != NULL) {
		fputs(toCharArray_String(r(str)), (FILE *)file);
		destroy(str);
	}
}

void TraceFileWriter_flush(void *file)
{
  if(file != NULL) fflush((FILE *)file);
}

