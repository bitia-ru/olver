/* 
 * File: map.h
 * Description:
 *       This file declares the specification type representing
 *       an abstract map container.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_MAP_H__
#define __ATL_MAP_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef struct Map Map;
#else
  typedef struct Map Map;
  extern const Type type_Map;
#endif


/*
 * Create empty map of specified type.
 */
Map *create_Map( const Type* key_type, const Type* val_type );

/*
 * Removes all mappings from this map.
 */
void clear_Map( Map *self );

/*
 * Returns true if this map contains a mapping for the specified key.
 */
bool containsKey_Map( Map *self, Object *key );

/*
 * Returns true if this map maps one or more keys to the specified value.
 */
bool containsValue_Map( Map *self, Object *value );

/*
 * Returns the value to which this map maps the specified key.
 */
Object *get_Map( Map *self, Object *key );
          
/*
 * Returns the key that this map maps to the specified value.
 */
Object *getKey_Map( Map *self, Object *value );
          
/*
 * Returns true if this map contains no key-value mappings.
 */
bool isEmpty_Map( Map *self );
 
/*
 * Associates the specified value with the specified key in this map.
 */
Object *put_Map( Map *self, Object *key, Object *value );

/*
 * Copies all of the mappings from the specified map to this map.
 */
void putAll_Map( Map *self, Map *t );

/*
 * Removes the mapping for this key from this map if present.
 */
Object *remove_Map( Map *self, Object *key );

/*
 * Returns the number of key-value mappings in this map.
 */
int size_Map( Map *self );

/*
 * Returns key for entry at specified position in the map.
 */
Object *key_Map( Map *self, int index );


/*
 * Returns the type desc of keys
 */
Type *keyType_Map (Map *self);


/*
 * Returns the type desc of values
 */
Type *valueType_Map (Map *self);


#endif
