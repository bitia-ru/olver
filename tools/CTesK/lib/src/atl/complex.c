/*
 * File: complex.c
 * Description:
 *       This file defines the specification type representing
 *       complex integer values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <atl/complex.h>


static void init_Complex( Complex *cmplx, va_list *arg_list ) {
    cmplx->re = va_arg( *arg_list, double );
    cmplx->im = va_arg( *arg_list, double );
}


static void copy_Complex( Complex *self, Complex *cmplx ) {
    cmplx->re = self->re;
    cmplx->im = self->im;
}

static int compare_Complex( Complex *left, Complex *right ) {
    return ( left->re != right->re ) || ( left->im != right->im );
}

static String *to_string_Complex( Complex *cmplx ) {
    return format_String( "( %f + %f*i )", cmplx->re, cmplx->im );
}

static String *to_XML_Complex( Complex *cmplx ) {
	return to_XML_spec("Complex", to_string_Complex(cmplx));
}

const Type type_Complex
	= { "Complex"
      , sizeof( Complex )
      , &type_Object
      , (Init)init_Complex
      , (Copy)copy_Complex
      , (Compare)compare_Complex
      , (ToString)to_string_Complex
      , (ToXML)to_XML_Complex
      , (CheckInvariant)check_invariant_Default
      , (Enumerate)enumerate_Default
      , (Destroy)destroy_Default
      };

Complex *create_Complex( double re, double im ) {
    return create( &type_Complex, re, im );
}
