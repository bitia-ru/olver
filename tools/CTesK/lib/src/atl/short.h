/* 
 * File: short.h
 * Description:
 *       This file declares the specification types representing 
 *       signed and unsigned short integer values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_SHORT_H__
#define __ATL_SHORT_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef signed short Short;
  specification typedef unsigned short UShort;
#else
  typedef signed short Short;
  extern const Type type_Short;
  typedef unsigned short UShort;
  extern const Type type_UShort;
#endif


/*
 * Constructs a newly allocated Short object
 * that represents the primitive short argument.
 */
Short *create_Short( short i );

/*
 * Constructs a newly allocated UShort object
 * that represents the primitive unsigned short argument.
 */
UShort *create_UShort( unsigned short i );

/*
 * Returns the value of this Short as an short.
 */
short value_Short( Short *i );

/*
 * Returns the value of this UShort as an unsigned short.
 */
unsigned short value_UShort( UShort *i );

#endif
