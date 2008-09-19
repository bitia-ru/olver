/* 
 * File: StringBuffer.h 
 * Description: 
 *       This is a header file of StringBuffer.
 *
 * Copyright (c) 2002-2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACER_STRING_BUFFER_H__
#define __TRACER_STRING_BUFFER_H__


#include <string.h>



/********************************************************************/
/**                        String Buffer                           **/
/********************************************************************/
#define DEFAULT_ALLOCATE_STOR_SIZE   8192

struct _ElementStringBuffer
{
  char* data;
  int len;
  int size;
  struct _ElementStringBuffer* next;
};
typedef struct _ElementStringBuffer ElementStringBuffer;

struct _StringBuffer
{
  int allocateStorBy;
  ElementStringBuffer* data;
  ElementStringBuffer* tail;
  long len;
};
typedef struct _StringBuffer StringBuffer;


StringBuffer * StringBuffer_create(int allocateStorBy);
void StringBuffer_delete(StringBuffer* sbuf);

// append methods
int StringBuffer_append_c(StringBuffer* sbuf, char c);
int StringBuffer_append_l(StringBuffer* sbuf, long l);
int StringBuffer_append_s(StringBuffer* sbuf, const char* s);
int StringBuffer_append(StringBuffer* sbuf, const char* s,int l);
  
// resize methods
void StringBuffer_resize(StringBuffer* sbuf, long newLen);
void StringBuffer_clear(StringBuffer* sbuf);

// access methods
char StringBuffer_getchar(StringBuffer* sbuf, int *i);
char * StringBuffer_toString(StringBuffer* sbuf);


#endif /* __TRACER_STRING_BUFFER_H__ */
