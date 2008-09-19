/* 
 * File: TraceWriteController.h 
 * Description: 
 *       This is a header file of TraceWriteController.
 *
 * Copyright (c) 2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_WRITE_CONTROLLER_H__
#define __TRACE_WRITE_CONTROLLER_H__


#include "TraceWriter.h"
#include "TraceBool.h"

typedef struct _TraceWriteController TraceWriteController;
struct _TraceWriteController
{
  void * state;
  void (*delete_state)(void *state);
  void (*puts)(void *state, const char* str);
  void (*flush)(void *state);

  TraceBool (*addWriter)(void *state, const char* name, TraceWriter* writer);
  TraceBool (*hasWriter)(void *state, const char* name);
  TraceBool (*removeWriter)(void *state, const char* name, const char *finalizer);
  TraceBool (*isTraceEnabled)(void *state);

  void (*pushWriters)(void *state);
  void (*popWriters)(void *state);

  TraceBool (*valid)(TraceWriteController *tc);
};


void TraceWriteController_delete(TraceWriteController *tc);


#endif /* __TRACE_WRITE_CONTROLLER_H__ */
