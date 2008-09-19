/* 
 * File: long.h
 * Description:
 *       This file declares the specification types representing 
 *       signed and unsigned long integer values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_LONG_H__
#define __ATL_LONG_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef signed long Long;
  specification typedef unsigned long ULong;
#else
  typedef signed long Long;
  extern const Type type_Long;
  typedef unsigned long ULong;
  extern const Type type_ULong;
#endif


/*
 * Constructs a newly allocated Long object
 * that represents the primitive long argument.
 */
Long *create_Long( long i );

/*
 * Constructs a newly allocated ULong object
 * that represents the primitive unsigned long argument.
 */
ULong *create_ULong( unsigned long i );

/*
 * Returns the value of this Long as an long.
 */
long value_Long( Long *i );

/*
 * Returns the value of this ULong as an unsigned long.
 */
unsigned long value_ULong( ULong *i );

#endif
