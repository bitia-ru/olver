/*
 * Copyright (c) 2005-2006 Institute for System Programming
 * Russian Academy of Sciences
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TA_PROCESS_COMMON_H
#define TA_PROCESS_COMMON_H

#include <sys/time.h>
#include "common/agent.h"

/********************************************************************/
/**                        read text file                          **/
/********************************************************************/

TACommandVerdict getFileContents_cmd( TAThread thread, TAInputStream stream );

TACommandVerdict freadFile_cmd( TAThread thread, TAInputStream stream );

TACommandVerdict readFile_cmd( TAThread thread, TAInputStream stream );

TACommandVerdict fwreadFile_cmd( TAThread thread, TAInputStream stream );

/********************************************************************/
/**                     trace function call                        **/
/********************************************************************/

TACommandVerdict appendIfFileExists_cmd( TAThread thread, TAInputStream stream );

/********************************************************************/
/**                  execute function with ...                     **/
/********************************************************************/

TACommandVerdict executeFunctionWithDots_cmd( TAThread thread, TAInputStream stream );

TACommandVerdict functionWithDotsCall_cmd( TAThread thread, TAInputStream stream );

/********************************************************************/
/**                     byte chain with id                         **/
/********************************************************************/

/* $(markedbytechain) */
void readMarkedByteChain( TAInputStream * stream, int * id, void * value, size_t valueSize );

void writeMarkedByteChain( TAThread thread, int id, const void * value, size_t valueSize );

/********************************************************************/
/**                  write-read for int array                      **/
/********************************************************************/

/*
 * any data may be sended or received as int array
 * DANGER : byte and int order
 */
void readIntArray( TAInputStream * stream, int * array, int size );

void writeIntArray( TAThread thread, const int * array, int size );

/********************************************************************/
/**                  write-read for user types                     **/
/********************************************************************/

/* $(strnullterminatedlist) */
int readStringNullTerminatedList( TAInputStream * stream, char *** list_ptr );

void writeStringNullTerminatedList( TAThread thread, int size, char ** list );

/* $(uintlist) */
int readUintList( TAInputStream * stream, unsigned int ** list_ptr );

void writeUintList( TAThread thread, int size, unsigned int * list );

/* $(charlist) */
int readCharList( TAInputStream * stream, char ** list_ptr );

void writeCharList( TAThread thread, int size, char * list, int needDealloc );

/* $(bytelist) */
int readByteList( TAInputStream * stream, unsigned char ** list_ptr );

void writeByteList( TAThread thread, int size, unsigned char * list, int needDealloc );

/* $(timeval) */
int readTimeVal( TAInputStream * stream, struct timeval * value );

void writeTimeVal( TAThread thread, const struct timeval * value );

/* $(itimerval) */
void readITimerVal( TAInputStream * stream, struct itimerval * value );

void writeITimerVal( TAThread thread, const struct itimerval * value );

/* $(itimerspec) */
void readITimerSpec( TAInputStream * stream, struct itimerspec * value );

void writeITimerSpec( TAThread thread, const struct itimerspec * value );

/* $(errorcode) - write only */
//use writeInt

/* $(argumentdescriptor) - read only */
typedef struct ArgumentDescriptor { char * declaration; char * initialization; char * parameter; } ArgumentDescriptor;

void readArgumentDescriptor( TAInputStream * stream, ArgumentDescriptor * value );

/* $(argumentdescriptorlist) - read only */
typedef ArgumentDescriptor * ArgumentDescriptorList;

int readArgumentDescriptorList( TAInputStream * stream, ArgumentDescriptorList * listPtr );

/* $(dotsarguments) - read only */
int readDotsArguments( TAInputStream * stream, long ** listPtr );

/* $(typedlistelement) */
typedef enum TypeElementCode { IntTObjCode, CharTObjCode, ShortTObjCode, LongTObjCode, LLongTObjCode,
                               IntMaxTObjCode, SizeTObjCode, PtrDiffTObjCode, WIntTObjCode,
                               FloatTObjCode, DoubleTObjCode, LongDoubleTObjCode,
                               CStringCode, WStringCode, VoidTPtrObjCode
                             } TypeElementCode;

typedef union TypeElementData { int IntTObj; char CharTObj; short ShortTObj; long LongTObj; long long LLongTObj;
                                intmax_t IntMaxTObj; size_t SizeTObj; ptrdiff_t PtrDiffTObj; wchar_t WIntTObj;
                                float FloatTObj; double DoubleTObj; long double LongDoubleTObj;
                                char * CString; wchar_t * WString; void * VoidTPtrObj;
                              } TypeElementData;

typedef struct TypedListElement { TypeElementCode type; TypeElementData data; } TypedListElement;

void readTypedListElement( TAInputStream * stream, TypedListElement * value );

void writeTypedListElement( TAThread thread, const TypedListElement * value );

/* $(typedlist) */
typedef struct TypedList { TypedListElement * elements; int size; } TypedList;

void readTypedList( TAInputStream * stream, TypedList * list );

void writeTypedList( TAThread thread, const TypedList * list );

void printTypedList( const TypedList * list );

/* $(tm) */
void readTm( TAInputStream * stream, struct tm * value );

void writeTm( TAThread thread, const struct tm * value );

#endif // TA_PROCESS_COMMON_H
