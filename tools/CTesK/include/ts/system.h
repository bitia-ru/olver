/*
 * PROJECT:     CTesK
 * FILE:        system.h
 * AUTHOR:      Alexey V. Khoroshilov
 * CREATION:    18 April 2005
 * DESCRIPTION: Unified platform-independent
 *              interface for different concepts
 *              such as semaphores
 * SCOPE:       It is an interface header.
 *                                                 
 *   Copyright (c) 2005-2006 ISP RAS.
 *   25, B.Communisticheskaya, Moscow, Russia.
 *   All rights reserved.
 *
 */

#ifndef TS_SYSTEM_H
#define TS_SYSTEM_H

#include <time.h>
#include "utils/boolean.h"


/********************************************************************/
/**                          Sleep Function                        **/
/********************************************************************/
void sleep_msec(time_t msecs);


/********************************************************************/
/**                           Semaphores                           **/
/********************************************************************/
typedef void* TSSemaphore;

TSSemaphore ts_create_semaphore(void);
bool ts_close_semaphore(TSSemaphore sema);
bool ts_open_semaphore(TSSemaphore sema);
void ts_destroy_semaphore(TSSemaphore sema);


/********************************************************************/
/**                       Exception Handling                       **/
/********************************************************************/

/* ===================================== *
 * POSIX Exception Handling
 * ===================================== */
#if defined(__GNUC__)

#include <signal.h>

typedef void (*PosixExceptionHandler)(siginfo_t* info, void* context);

void start_exception_protected_section(PosixExceptionHandler exception_handler);
void end_exception_protected_section(void);


#define START_EXCEPTION_PROTECTED_SECTION(handler)  start_exception_protected_section(handler);
#define END_EXCEPTION_PROTECTED_SECTION()           end_exception_protected_section();

void ts_default_exception_handler(siginfo_t* info, void* context);


/* CTesK Source Start */
/* ===================================== *
 * Win32 Exception Handling
 * ===================================== */
#elif defined(_MSC_VER)

#include <windows.h>

typedef int (*Win32ExceptionHandler)(LPEXCEPTION_POINTERS info);

#define START_EXCEPTION_PROTECTED_SECTION(handler)  { Win32ExceptionHandler ts_exception_handler = handler; __try { 
#define END_EXCEPTION_PROTECTED_SECTION()           } __except (ts_exception_handler(GetExceptionInformation())) {} }

int ts_default_exception_handler(LPEXCEPTION_POINTERS info);
/* CTesK Source End */


/* ===================================== *
 * Absence of Exception Handling
 * ===================================== */
#else

#define START_EXCEPTION_PROTECTED_SECTION(handler)  
#define END_EXCEPTION_PROTECTED_SECTION()          


#endif


/********************************************************************/
/**               User Callback On Exception Handler               **/
/********************************************************************/
/* User callback function is called by ts_default_exception_handler() */

typedef void (*ExceptionEventHandler)(void);

ExceptionEventHandler ts_set_exception_event_handler(ExceptionEventHandler handler);


#endif
