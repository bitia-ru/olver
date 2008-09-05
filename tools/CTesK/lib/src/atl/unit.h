/* 
 * File: unit.h
 * Description:
 *       This file declares the specification type containing the only value.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_UNIT_H__
#define __ATL_UNIT_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef void Unit;
#else
  typedef void Unit;
  extern const Type type_Unit;
#endif


/*
 * Constructs a newly allocated Unit object
 * that represents the only value of this type.
 */
Unit* create_Unit();

#endif
