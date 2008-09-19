/* 
 * File: list.h
 * Description:
 *       This file declares the specification type representing
 *       an abstract list container.
 *       It is a part of CTesK Abstract Type Library.
 *
 * Copyright (c) 2001-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __ATL_LIST_H__
#define __ATL_LIST_H__

#include <atl/object.h>


#ifdef __SEC__
  #pragma SEC file
  specification typedef struct List List;
#else
  typedef struct List List;
  extern const Type type_List;
#endif


#include <atl/set.h>


/*
 * Create empty list of specified type.
 * If elem_type == NULL element types can differ.
 */
List *create_List( const Type *elem_type );

/*
 * Inserts the specified element at the specified position in this list
 */
void add_List( List *self, int index, Object *ref );

/*
 * Appends the specified element to the end of this list
 */
void append_List( List *self, Object *ref );

/*
 * Removes all of the elements from this list
 */
void clear_List( List *self );

/*
 * Returns true if this list contains the specified element
 * PRECONDITION: type(ref) == elem_type(self)
 */
bool contains_List( List *self, Object *ref );

/*
 * Returns the element at the specified position in this list.
 */
Object *get_List( List *self, int index );

/*
 * Returns the index in this list of the first occurrence
 * of the specified element, or -1 if this list does not contain this element
 * PRECONDITION: type(ref) == elem_type(self)
 */
int indexOf_List( List *self, Object *ref );

/*
 * Returns true if this list contains no elements
 */
bool isEmpty_List( List *self );

/*
 * Returns the index in this list of the last occurrence
 * of the specified element, or -1 if this list does not contain this element
 * PRECONDITION: type(ref) == elem_type(self)
 */
int lastIndexOf_List( List *self, Object *ref );

/*
 * Removes the element at the specified position in this list
 */
void remove_List( List *self, int index );

/*
 * Replaces the element at the specified position in this list
 * with the specified element
 */
void set_List( List *self, int index, Object *ref );

/*
 * Returns the number of elements in this list.
 */
int size_List( List *self );

/*
 * Returns a view of the portion of this list between 
 * the specified fromIndex, inclusive, and toIndex, exclusive.
 */
List *subList_List( List *self, int fromIndex, int toIndex );

/*
 * Inserts the specified list at the specified position in this list
 */
void addAll_List(List *self, int index, List *other);

/*
 * Appends the specified list to the end of this list
 */
void appendAll_List(List *self, List *other);

/*
 * Returns list that contains all elements from this set
 */
Set *toSet_List(List *self);


/*
 * Returns the type desc of elements
 */
Type *elemType_List (List *self);

#endif
