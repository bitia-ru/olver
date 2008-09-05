/* 
 * File: TraceFileWriter.h 
 * Description: 
 *       This is a header file of TraceFileWriter.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_FILE_WRITER_H__
#define __TRACE_FILE_WRITER_H__

#include "TraceWriter.h"

TraceWriter * TraceFileWriter_create(FILE *file);
void TraceFileWriter_delete_state(void *);
void TraceFileWriter_puts(void *file, const char *str);
void TraceFileWriter_flush(void *file);


#endif /* __TRACE_FILE_WRITER_H__ */
