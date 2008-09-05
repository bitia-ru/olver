/* 
 * File: TraceMultiWriter.h 
 * Description: 
 *       This is a header file of TraceMultiWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_MULTIWRITER_H__
#define __TRACE_MULTIWRITER_H__

#include "TraceWriteController.h"
#include "TraceList.h"
#include "TraceBool.h"
#include <string.h>


/********************************************************************/
/**                       Trace Multi Writer                       **/
/********************************************************************/

struct _WriterCell
{
  char*        name;
  TraceWriter* writer;
  int          refCnt;
};
typedef struct _WriterCell WriterCell;


struct _TraceMultiWriter_state
{
  TraceList * writers;  // list <WriterCell *>
  TraceList * stack;    // list <list <WriterCell *>>
};
typedef struct _TraceMultiWriter_state TraceMultiWriter_state;


TraceWriteController * TraceMultiWriter_create();


#endif /* __TRACE_MULTIWRITER_H__ */
