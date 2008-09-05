/* 
 * File: s_StringBuffer.c
 * Description: 
 *       This file contains an implementation of String Buffer.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <stdio.h>
#include <malloc.h>
#include "s_StringBuffer.h"

/********************************************************************/
/**                        String Buffer                           **/
/********************************************************************/

int s_StringBuffer_init(struct s_StringBuffer *sb)
{
  if(NULL == sb) return 1;
  sb->data = (char *) malloc(DEFAULT_STRINGBUFFER_SIZE + 1);
  if(NULL == sb->data) return 2;
  memset(sb->data,0,DEFAULT_STRINGBUFFER_SIZE + 1);
  sb->len = DEFAULT_STRINGBUFFER_SIZE;
  return 0;
}

int s_StringBuffer_resize(struct s_StringBuffer *sb, int newlen)
{
  int len, flag = 0;
  char * tmp;

  if(NULL == sb) return 1;
  if(NULL == sb->data) flag = 1;
  len = DEFAULT_STRINGBUFFER_SIZE >= newlen ? DEFAULT_STRINGBUFFER_SIZE : newlen;
  if(sb->len > 0) len += sb->len;
  tmp = (char *) realloc(sb->data, len + 1);
  if(NULL == tmp) return 2;
  sb->data = tmp;
  if(flag) memset(sb->data,0,len + 1);
  else memset((char *)sb->data + sb->len, 0, len + 1 - sb->len);
  sb->len = len;
  return 0;
}

int s_StringBuffer_addstr(struct s_StringBuffer *sb, char *str, int str_len)
{
  int len;
  int addlen;

  if((NULL == sb)||(NULL == sb->data)||(NULL == str)) return 1;
  if(strlen(str) == 0) return 0;

  len = strlen(sb->data) ;
  if(sb->len < len) return 2;
  len = sb->len - len;
  addlen = ((str_len <= 0) || ((unsigned)str_len > strlen(str))) ? strlen(str) : str_len;
  if(len < addlen) {
    if( s_StringBuffer_resize(sb, (addlen - len)) ) return 3;
  }
  strncat(sb->data,str,addlen);

  return 0;
}

int s_StringBuffer_addint(struct s_StringBuffer *sb, long a)
{
  char buf[256];

  if((NULL == sb)||(NULL == sb->data)) return 1;
  sprintf(buf,"%lu\0",a);
  if(s_StringBuffer_addstr(sb,buf,-1)) return 2;

  return 0;
}

void s_StringBuffer_freebuf(struct s_StringBuffer *sb)
{
  if(NULL != sb) {
    if(NULL != sb->data) {
      free(sb->data);
      sb->data = NULL;
    }
    sb->len = 0;
  }
}




