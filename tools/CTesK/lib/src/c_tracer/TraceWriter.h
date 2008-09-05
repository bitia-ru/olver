/* 
 * File: TraceWriter.h 
 * Description: 
 *       This is a header file of TraceWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_WRITER_H__
#define __TRACE_WRITER_H__

#include <string.h>

struct _TraceWriter 
{
  void * state;
  void (*delete_state)(void *state);
  void (*puts)(void *state, const char* str);
  void (*flush)(void *state);
  int refCnt;
};
typedef struct _TraceWriter TraceWriter;


void TraceWriter_delete(TraceWriter *tr);



#endif /* __TRACE_WRITER_H__ */
