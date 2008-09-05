/* 
 * File: StringBuffer.c
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
#include "TracerStringBuffer.h"

/********************************************************************/
/**                        String Buffer                           **/
/********************************************************************/
static ElementStringBuffer * ElementStringBuffer_create(int capacity)
{
ElementStringBuffer* elem = NULL;

  elem = (ElementStringBuffer *)malloc(sizeof(*elem));
  if(NULL != elem) {
    elem->data = (char *)malloc(capacity * sizeof(char));
    if(NULL == elem->data) { free(elem); return NULL; }
    elem->len = 0;
    elem->size = capacity;
    elem->next = NULL;
  }
  return elem;
}

static void ElementStringBuffer_delete(ElementStringBuffer* elem)
{
  if(NULL != elem) {
    if(NULL != elem->data) free(elem->data);
    free(elem);
  }
}

StringBuffer * StringBuffer_create(int allocateStorBy)
{
StringBuffer* sbuf;
int alloc;

  sbuf = (StringBuffer *)malloc(sizeof(*sbuf));
  if(NULL != sbuf) { 
    alloc = (allocateStorBy > 0) ? allocateStorBy : DEFAULT_ALLOCATE_STOR_SIZE;
    sbuf->data = ElementStringBuffer_create(alloc);
    if(NULL == sbuf->data) { free(sbuf); return NULL; }
    sbuf->tail = sbuf->data;
    sbuf->allocateStorBy = alloc;
    sbuf->len = 0;
  }
  return sbuf;
}

void StringBuffer_delete(StringBuffer* sbuf)
{
  if(NULL != sbuf) {
    for(;sbuf->data!=NULL;) {
      sbuf->tail = sbuf->data->next;
      ElementStringBuffer_delete(sbuf->data);
      sbuf->data = sbuf->tail;
    }
    free(sbuf);
  }
}


int StringBuffer_append_c(StringBuffer* sbuf, char c)
{
  if ((NULL == sbuf) || 
      (NULL == sbuf->tail) || 
      (sbuf->len < 0)) 
     return 1;

  if (sbuf->tail->len >= sbuf->tail->size) {
    sbuf->tail->next = ElementStringBuffer_create(sbuf->allocateStorBy);
    if(NULL == sbuf->tail->next) return 2;
    sbuf->tail = sbuf->tail->next;
  }
  sbuf->tail->data[sbuf->tail->len] = c;
  sbuf->tail->len++;
  sbuf->len++;

  return 0;
}

int StringBuffer_append_l(StringBuffer* sbuf, long l) {
  char buf[256];
  sprintf(buf,"%lu\0",l);
  return StringBuffer_append_s(sbuf,buf);
}

int StringBuffer_append_s(StringBuffer* sbuf, const char* s) {
  return StringBuffer_append(sbuf,s,strlen(s));
}

int StringBuffer_append(StringBuffer* sbuf, const char* s, int l)
{
int rest;

  if ((NULL == sbuf) || 
      (NULL == sbuf->tail) || 
      (sbuf->len < 0)) 
     return 1;
  if ((s == NULL) || (l <= 0) || (sbuf->len + l < 0)) 
     return 2;

  rest = sbuf->tail->size - sbuf->tail->len;
  if (rest >= l) {
    memcpy(&(sbuf->tail->data[sbuf->tail->len]),s,l);
    sbuf->tail->len += l;
    sbuf->len += l;
    return 0;
  }
  if (rest > 0) {
    memcpy(&(sbuf->tail->data[sbuf->tail->len]),s,rest);
    sbuf->tail->len = sbuf->tail->size;
    sbuf->len += rest;
    l -= rest;
  }
  for(;;)
  {
    sbuf->tail->next = ElementStringBuffer_create(sbuf->allocateStorBy);
    if(NULL == sbuf->tail->next) return 3;
    sbuf->tail = sbuf->tail->next;
    if (sbuf->tail->size >= l) {
      memcpy(sbuf->tail->data,&(s[rest]),l);
      sbuf->tail->len = l;
      sbuf->len += l;
      return 0;
    }
    memcpy(sbuf->tail->data,&(s[rest]),sbuf->allocateStorBy);
    sbuf->tail->len = sbuf->allocateStorBy;
    sbuf->len += sbuf->allocateStorBy;
    l -= sbuf->allocateStorBy;
    rest += sbuf->allocateStorBy;
  } 
}

  
void StringBuffer_resize(StringBuffer* sbuf, long newLen)
{
ElementStringBuffer *tmp,*tmp2;

  if (NULL == sbuf) return;
  if (newLen >= sbuf->len) return;

  for(tmp=sbuf->data;tmp!=NULL;tmp=tmp->next)
  {
    if (newLen <= tmp->len)
      break;
    newLen = newLen - tmp->len;
  }
  if(NULL == tmp) return;

  tmp->len = newLen;
  sbuf->tail = tmp;
  tmp2 = tmp->next;
  tmp->next = NULL;
  for(;tmp2!=NULL;) {
    tmp = tmp2;
    tmp2 = tmp2->next;
    ElementStringBuffer_delete(tmp);
  }

  sbuf->len = newLen;
}

void StringBuffer_clear(StringBuffer* sbuf)
{
ElementStringBuffer* tmp;

  if(NULL != sbuf) {
    if(NULL != sbuf->data) {
      tmp = sbuf->data->next;
      for(;tmp!=NULL;) {
        sbuf->tail = tmp->next;
        ElementStringBuffer_delete(tmp);
        tmp = sbuf->tail;
      }
      sbuf->data->next = NULL;
      sbuf->data->len = 0;
    }
    sbuf->tail = sbuf->data;
    sbuf->len = 0;
  }
}

char StringBuffer_getchar(StringBuffer* sbuf, int *i)
{
ElementStringBuffer* tmp;

  if ((sbuf == NULL) || (i == NULL) || (*i < 0) || (sbuf->len <= *i))
     { *i = -1; return 0; }

  for(tmp=sbuf->data;tmp!=NULL;tmp=tmp->next) {
    if (*i < tmp->len)
      break;
    *i = *i - tmp->len;
  }

  if(tmp->data != NULL) return tmp->data[*i];
  else { *i = -1; return 0; }
}


char * StringBuffer_toString(StringBuffer* sbuf)
{
ElementStringBuffer* tmp;
char* buff;
long j;

  if(NULL == sbuf) return NULL;
  buff = (char *)malloc((sbuf->len + 1)*sizeof(char));
  if(NULL == buff) return NULL;

  j = 0;
  for(tmp=sbuf->data;tmp!=NULL;tmp=tmp->next)
  {
    if((NULL == tmp->data)&&(tmp->len != 0)) break;
    memcpy(&(buff[j]),tmp->data,tmp->len);
    j += tmp->len;
  }
  buff[j] = '\0';
  
  return buff;
}

