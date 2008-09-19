/* 
 * File: object_int.h
 * Description:
 *       This file defines the type of header of each specification object.
 *       It is an internal header file of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_OBJECT_INT_H__
#define __ATL_OBJECT_INT_H__

#include <atl/object.h>

typedef struct Header Header;

struct Header
{
  const Type* type;
  int   weak_ref_cnt;
  int   hard_ref_cnt;
};

Header* header(Object* ref);

#endif
