/* 
 * File: TraceWriteController.c 
 * Description: 
 *       his file contains an implementation of TraceWriteController.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */


#include <malloc.h>
#include "TraceWriteController.h"

void TraceWriteController_delete(TraceWriteController *tc)
{
  if(tc != NULL) {
    (*tc->delete_state)(tc->state);
    free(tc);
  }
}

