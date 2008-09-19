/* 
 * File: TraceConsoleWriter.h 
 * Description: 
 *       This is a header file of TraceConsoleWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_CONSOLE_WRITER_H__
#define __TRACE_CONSOLE_WRITER_H__

#include "TraceWriter.h"


TraceWriter * TraceConsoleWriter_create();
void TraceConsoleWriter_delete_state(void *);
void TraceConsoleWriter_puts(void *, const char *str);
void TraceConsoleWriter_flush(void *);



#endif /* __TRACE_CONSOLE_WRITER_H__ */
