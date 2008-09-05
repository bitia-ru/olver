/* 
 * File: void_ast.h
 * Description:
 *       This file declares the specification type representing pointer values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_VOID_AST_H__
#define __ATL_VOID_AST_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef void* VoidAst;
#else
  typedef void* VoidAst;
  extern const Type type_VoidAst;
#endif


/*
 * Constructs a newly allocated VoidAst object
 * that represents the primitive void* argument.
 */
VoidAst *create_VoidAst( void *d );

/*
 * Returns the value of this VoidAst as an void*.
 */
void *value_VoidAst( VoidAst *d );

#endif
