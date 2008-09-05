/* 
 * File: char.h
 * Description:
 *       This file declares the specification type representing characters.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_CHAR_H__
#define __ATL_CHAR_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef char Char;
#else
  typedef char Char;
  extern const Type type_Char;
#endif

/*
 * Constructs a newly allocated Char object
 * that represents the primitive char argument.
 */
Char *create_Char( char d );

/*
 * Returns the value of this Char as an char.
 */
char value_Char( Char *d );

#endif
