/* 
 * File: TraceWriter.c 
 * Description: 
 *       his file contains an implementation of TraceWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */


#include <stdlib.h>

#include "TraceWriter.h"

void TraceWriter_delete(TraceWriter *tr)
{
  if(tr != NULL) {
    (*tr->delete_state)(tr->state);
    free(tr);
  }
}

