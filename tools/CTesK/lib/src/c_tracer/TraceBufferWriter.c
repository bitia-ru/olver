/* 
 * File: TraceBufferWriter.c
 * Description: 
 *       This file contains an implementation of TraceBufferWriter.
 *
 * Copyright (c) 2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <malloc.h>
#include "TraceBufferWriter.h"


TraceWriter * TraceBufferWriter_create(StringBuffer *sb)
{
  TraceWriter * tr = (TraceWriter *)malloc(sizeof(*tr));
  if(tr != NULL) {
    tr->state = sb;
    tr->delete_state = TraceBufferWriter_delete_state;
    tr->puts = TraceBufferWriter_puts;
    tr->flush = TraceBufferWriter_flush;
	tr->refCnt = 0;
  }
  return tr;
}

void TraceBufferWriter_delete_state(void *sb)
{
  StringBuffer_delete((StringBuffer *)sb);
}

void TraceBufferWriter_puts(void *sb, const char *str)
{
  if((sb != NULL) && (str != NULL)) 
    StringBuffer_append_s((StringBuffer *)sb, str);
}

void TraceBufferWriter_flush(void *sb) {}





