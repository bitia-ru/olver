/*
 * File: char.c
 * Description:
 *       This file defines the specification type representing characters.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <atl/char.h>
#include <atl/string.h>
#include <utils/assertion.h>
#include <ts/convex.h>

#include <stdio.h>

void init_Char( Char *ch, va_list *arg_list )
{
    *ch = (char)va_arg( *arg_list, int );
}

void copy_Char( Char *src, Char *dst )
{
    *dst = *src;
}

int compare_Char( Char *left, Char *right )
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

String *to_string_Char( Char *ch )
{
    char buf[256];

    sprintf( buf, "%c", *ch );

    return create_String( buf );
}

String *to_XML_Char( Char *ch )
{
    return to_XML_spec("Char", to_string_Char(ch));
}

const Type type_Char
    = { "Char"
      , sizeof(char)
      , &type_Object
      , (Init)init_Char
      , (Copy)copy_Char
      , (Compare)compare_Char
      , (ToString)to_string_Char
      , (ToXML)to_XML_Char
      , (CheckInvariant)check_invariant_Default
      , (Enumerate)enumerate_Default
      , (Destroy)destroy_Default
      };

Char *create_Char( char ch )
{
    return create( &type_Char, ch );
}

char value_Char( Char *ch )
{
    char res;

    CHECK_TYPE_COMPATIBLE(value_Char, &type_Char, ch );

    res = *ch;
    destroy(ch);
    return res;
}

