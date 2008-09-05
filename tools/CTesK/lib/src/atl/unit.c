/*
 * File: unit.c
 * Description:
 *       This file defines the specification type containing the only value.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <atl/unit.h>

#include <utils/boolean.h>

static int compare_Unit( Unit *left, Unit *right ) {
    return 0;
}

static String *to_string_Unit( Unit *unit ) {
    return create_String( "<unit>" );
}

static String *to_XML_Unit( Unit *unit ) {
	return to_XML_spec("Unit", to_string_Unit(unit));
}

const Type type_Unit
    = { "Unit"
      , 0
      , &type_Object
      , (Init)init_Default
      , (Copy)copy_Default
      , (Compare)compare_Unit
      , (ToString)to_string_Unit
      , (ToXML)to_XML_Unit
      , (CheckInvariant)check_invariant_Default
      , (Enumerate)enumerate_Default
      , (Destroy)destroy_Default
      };

Unit *create_Unit() {
    return create(&type_Unit);
}
