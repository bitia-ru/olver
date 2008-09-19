/* 
 * File: intset.h
 * Description:
 *       This file declares the specification type representing
 *       sets of integers.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_INTSET_H__
#define __ATL_INTSET_H__

#include <atl/object.h>
#include <atl/list.h>
#include <atl/set.h>
#include <utils/boolean.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef struct IntSet IntSet;
#else
  typedef struct IntSet IntSet;
  extern const Type type_IntSet;
#endif


/*
 * Create empty set with specified upper bound.
 */
IntSet *create_IntSet( unsigned int upper );


/*
 * Returns upper bound of specified set
 */
unsigned int upper_IntSet (IntSet *self);

/*
 * Returns the number of elements in this set.
 */
size_t size_IntSet( IntSet *self );

/*
 * Returns true if this set contains no elements.
 */
bool isEmpty_IntSet( IntSet *self );

/*
 * Returns true if this set contains the specified element.
 */
bool contains_IntSet( IntSet *self, unsigned int i );

/*
 * Adds the specified element to this set if it is not already present
 */
bool add_IntSet( IntSet *self, unsigned int i );

/*
 * Removes the specified element from this set if it is present
 */
bool remove_IntSet( IntSet *self, unsigned int i );

/*
 * Returns true if this set contains all of the elements of the specified set
 */
bool containsAll_IntSet( IntSet *self, IntSet *set );

/*
 * Adds all of the elements in the specified set to this set if they're not already present
 */
bool addAll_IntSet( IntSet *self, IntSet *set );

/*
 * Retains only the elements in this set that are contained in the specified set
 */
bool retainAll_IntSet( IntSet *self, IntSet *set );

/*
 * Removes from this set all of its elements that are contained in the specified set
 */
bool removeAll_IntSet( IntSet *self, IntSet *set );

/*
 * Removes all of the elements from this set
 */
void clear_IntSet( IntSet *self );

/*
 * Fills this set
 */
void fill_IntSet( IntSet *self );

/*
 * Returns IntSet that is invertion of '*self' IntSet
 */
void invert_IntSet( IntSet *self );

/*
 * Returns the element at the specified position in this set treated as list
 * NOTE: Order of elements is unpredictable
 */
unsigned int get_IntSet( IntSet *self, int index );

/*
 * Returns set that contains all elements from this set
 */
Set *toSet_IntSet( IntSet *self );

/*
 * Returns list that contains all elements from this set
 */
List *toList_IntSet( IntSet *self );

#endif
