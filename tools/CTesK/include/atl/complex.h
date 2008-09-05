/* 
 * File: complex.h
 * Description:
 *       This file declares the specification type representing
 *       complex integer values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_COMPLEX_H__
#define __ATL_COMPLEX_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef struct Complex Complex;
#else
  typedef struct Complex Complex;
  extern const Type type_Complex;
#endif


struct Complex {
    double re;
    double im;
};

/*
 * Constructs a newly allocated Complex object
 * that represents the complex value 
 * corresponding to real and image arguments.
 */
Complex *create_Complex( double re, double im );

#endif
