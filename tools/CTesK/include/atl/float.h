/* 
 * File: float.h
 * Description:
 *       This file declares the specification type representing float values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_FLOAT_H__
#define __ATL_FLOAT_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef float Float;
#else
  typedef float Float;
  extern const Type type_Float;
#endif

/*
 * Constructs a newly allocated Float object
 * that represents the primitive float argument.
 */
Float *create_Float( float d );

/*
 * Returns the value of this Float as an float.
 */
float value_Float( Float *d );

#endif
