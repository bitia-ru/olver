/* 
 * File: TraceFormatter.c 
 * Description: 
 *       his file contains an implementation of TraceWriteController.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */


#include <stdlib.h>

#include "TraceFormatter.h"

void TraceFormatter_delete(TraceFormatter *tf)
{
  if(tf != NULL) {
    (*tf->delete_state)(tf->state);
    free(tf);
  }
}

