/*
 * File: float.c
 * Description:
 *       This file defines the specification type representing float values.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <atl/float.h>

#include <atl/string.h>
#include <utils/assertion.h>

#include <stdio.h>

void init_Float( Float *f, va_list *arg_list )
{
    *f = (float)va_arg( *arg_list, double );
}

void copy_Float( Float *src, Float *dst )
{
    *dst = *src;
}

int compare_Float( Float *left, Float *right )
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

String *to_string_Float( Float *f )
{
    char buf[256];

    sprintf( buf, "%f", *f );

    return create_String( buf );
}

String *to_XML_Float( Float *f )
{
	return to_XML_spec("Float", to_string_Float(f));
}

const Type type_Float
    = { "Float"
      , sizeof(float)
      , &type_Object
      , (Init)init_Float
      , (Copy)copy_Float
      , (Compare)compare_Float
      , (ToString)to_string_Float
      , (ToXML)to_XML_Float
      , (CheckInvariant)check_invariant_Default
      , (Enumerate)enumerate_Default
      , (Destroy)destroy_Default
      };

Float *create_Float( float f )
{
    return create( &type_Float, f );
}

float value_Float( Float *f )
{
    float res;

    CHECK_TYPE_COMPATIBLE( value_Float, &type_Float, f );

    res = *f;
    destroy(f);
    return res;
}
