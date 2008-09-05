/* 
 * File: set.h
 * Description:
 *       This file declares the specification type representing
 *       an abstract set container.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_SET_H__
#define __ATL_SET_H__


#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef struct Set Set;
#else
  typedef struct Set Set;
  extern const Type type_Set;
#endif


#include <atl/list.h>


/*
 * Create empty set of specified type.
 */
Set *create_Set( const Type* elem_type );

/*
 * Returns the number of elements in this set.
 */
int size_Set( Set *self );

/*
 * Returns true if this set contains no elements.
 */
bool isEmpty_Set( Set *self );

/*
 * Returns true if this set contains the specified element.
 */
bool contains_Set( Set *self, Object *ref );

/*
 * Adds the specified element to this set if it is not already present
 */
bool add_Set( Set *self, Object *ref );

/*
 * Removes the specified element from this set if it is present
 */
bool remove_Set( Set *self, Object *ref );

/*
 * Returns true if this set contains all of the elements of the specified set
 */
bool containsAll_Set( Set *self, Set *set );

/*
 * Adds all of the elements in the specified set to this set if they're not already present
 */
bool addAll_Set( Set *self, Set *set );

/*
 * Retains only the elements in this set that are contained in the specified set
 */
bool retainAll_Set( Set *self, Set *set );

/*
 * Removes from this set all of its elements that are contained in the specified set
 */
bool removeAll_Set( Set *self, Set *set );

/*
 * Removes all of the elements from this set
 */
void clear_Set( Set *self );

/*
 * Returns the element at the specified position in this set treated as list
 * NOTE: Order of elements is unpredictable
 */
Object *get_Set( Set *self, int index );

/*
 * Returns list that contains all elements from this set
 */
List *toList_Set( Set *self );

/*
 * Returns the type desc of elements
 */
Type *elemType_Set (Set *self);

#endif
