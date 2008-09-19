/* 
 * File: double.h
 * Description:
 *       This file declares the specification type representing double values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_DOUBLE_H__
#define __ATL_DOUBLE_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef double Double;
#else
  typedef double Double;
  extern const Type type_Double;
#endif

/*
 * Constructs a newly allocated Double object
 * that represents the primitive double argument.
 */
Double *create_Double( double d );

/*
 * Returns the value of this Double as an double.
 */
double value_Double( Double *d );

#endif
