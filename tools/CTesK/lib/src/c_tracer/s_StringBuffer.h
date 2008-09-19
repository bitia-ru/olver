/* 
 * File: s_StringBuffer.h 
 * Description: 
 *       This is a header file of s_StringBuffer.
 *
 * Copyright (c) 2002-2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACER_s_STRING_BUFFER_H__
#define __TRACER_s_STRING_BUFFER_H__


#include <string.h>


/********************************************************************/
/**                        String Buffer                           **/
/********************************************************************/

#define DEFAULT_STRINGBUFFER_SIZE   1024

struct s_StringBuffer
{
  char *data;
  int len;
};

int s_StringBuffer_init(struct s_StringBuffer *);
int s_StringBuffer_resize(struct s_StringBuffer *, int);
int s_StringBuffer_addstr(struct s_StringBuffer *, char *, int);
int s_StringBuffer_addint(struct s_StringBuffer *, long);
void s_StringBuffer_freebuf(struct s_StringBuffer *);


#endif /* __TRACER_s_STRING_BUFFER_H__ */
