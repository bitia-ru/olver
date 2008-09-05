/* 
 * File: TraceXMLFormatter.h 
 * Description: 
 *       This is a header file of TraceXMLFormatter.
 *
 * Copyright (c) 2002-2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_XML_FORMATTER__
#define __TRACE_XML_FORMATTER__

#include "TraceFormatter.h"



/*
 * indentation class
 */
struct _Indent 
{
  int  indent_size;
  int  cur_indent;
  char indent_char;
};
typedef struct _Indent Indent;

struct _TraceXMLFormatter_state 
{
  unsigned int indent_size;
  unsigned int cur_indent;
  char indent_char;

  Indent indent;
};
typedef struct _TraceXMLFormatter_state TraceXMLFormatter_state;


TraceFormatter * TraceXMLFormatter_create(int indent_size, char indent_char);
TraceFormatter * TraceXMLFormatter_default_create();



#endif /* __TRACE_XML_FORMATTER__ */
