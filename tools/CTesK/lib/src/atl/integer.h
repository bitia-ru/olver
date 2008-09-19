/* 
 * File: integer.h
 * Description:
 *       This file declares the specification types representing 
 *       signed and unsigned integer values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_INTEGER_H__
#define __ATL_INTEGER_H__

#include <atl/object.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __SEC__
  #pragma SEC file
  specification typedef signed int Integer;
  specification typedef unsigned int UInteger;
#else
  typedef signed int Integer;
  extern const Type type_Integer;
  typedef unsigned int UInteger;
  extern const Type type_UInteger;
#endif


/*
 * Constructs a newly allocated Integer object
 * that represents the primitive int argument.
 */
Integer *create_Integer( int i );

/*
 * Constructs a newly allocated UInteger object
 * that represents the primitive unsigned int argument.
 */
UInteger *create_UInteger( unsigned int i );

/*
 * Returns the value of this Integer as an int.
 */
int value_Integer( Integer *i );

/*
 * Returns the value of this UInteger as an unsigned int.
 */
unsigned int value_UInteger( UInteger *i );

#ifdef __cplusplus
} // extern "C"
#endif

#endif
