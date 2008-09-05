/*
 * File: double.c
 * Description:
 *       This file defines the specification type representing double values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <atl/double.h>

#include <atl/string.h>
#include <utils/assertion.h>

#include <stdio.h>

void init_Double( Double *d, va_list *arg_list )
{
    *d = va_arg( *arg_list, double );
}

void copy_Double( Double *src, Double *dst )
{
    *dst = *src;
}

int compare_Double( Double *left, Double *right )
{
    if( *left < *right )
    {
        return -1;
    } else
    if( *left > *right )
    {
        return 1;
    } else {
        return 0;
    }
}

String *to_string_Double( Double *d )
{
    char buf[384];

    sprintf( buf, "%f", *d );

    return create_String( buf );
}

String *to_XML_Double( Double *d )
{
	return to_XML_spec("Double", to_string_Double(d));
}

const Type type_Double
    = { "Double"
      , sizeof(double)
      , &type_Object
      , (Init)init_Double
      , (Copy)copy_Double
      , (Compare)compare_Double
      , (ToString)to_string_Double
      , (ToXML)to_XML_Double
      , (CheckInvariant)check_invariant_Default
      , (Enumerate)enumerate_Default
      , (Destroy)destroy_Default
      };

Double *create_Double( double d )
{
    return create( &type_Double, d );
}

double value_Double( Double *d )
{
    double res;

    CHECK_TYPE_COMPATIBLE( value_Double, &type_Double, d );

    res = *d;
    destroy(d);
    return res;
}
