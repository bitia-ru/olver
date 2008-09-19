/* 
 * File: TraceBufferWriter.h 
 * Description: 
 *       This is a header file of TraceBufferWriter.
 *
 * Copyright (c) 2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_BUFFER_WRITER_H__
#define __TRACE_BUFFER_WRITER_H__

#include "TraceWriter.h"
#include "TracerStringBuffer.h"


TraceWriter * TraceBufferWriter_create(StringBuffer *sb);
void TraceBufferWriter_delete_state(void *sb);
void TraceBufferWriter_puts(void *sb, const char *str);
void TraceBufferWriter_flush(void *sb);


#endif /* __TRACE_BUFFER_WRITER_H__ */
