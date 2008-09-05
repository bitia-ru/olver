/* 
 * File: assertion.c
 * Description: 
 *       This file contains an implementation of assertion functions.
 *
 * Copyright (c) 2002-2006 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 *
 */

#include <stdarg.h>

#include "utils/assertion.h"


/********************************************************************/
/**                    Assertion Trap Handlers                     **/
/********************************************************************/
static void defaultAssertionExit(const char * format, va_list arg_list);

static AssertionExit assertion_handler = defaultAssertionExit;
static AssertionExit fault_handler = defaultAssertionExit;

AssertionExit atAssertion(AssertionExit func)
{
AssertionExit tmp;

  tmp = assertion_handler;
  assertion_handler = func;
  return tmp;
}

AssertionExit atFault(AssertionExit func)
{
AssertionExit tmp;

  tmp = fault_handler;
  fault_handler = func;
  return tmp;
}

bool isCustomAssertionExit(void)
{
  return (assertion_handler != defaultAssertionExit);
}

static void defaultAssertionExit(const char * format, va_list arg_list)
{
  vfprintf( stderr, format, arg_list );
  exit(1);
}



/********************************************************************/
/**                            Assertions                          **/
/********************************************************************/
void assertion( int expr, const char* format, ... )
{
    static int assert_depth;
    
    if( !expr )
    {
        va_list arg_list;

        va_start(arg_list, format);
        if (assertion_handler && !assert_depth ) {
          assert_depth++;
          assertion_handler(format, arg_list);
        }
        va_end(arg_list);
        exit(1);
    }
}

void fault( int expr, const char* format, ... )
{
    static int assert_depth;
    
    if( !expr )
    {
        va_list arg_list;

        va_start(arg_list, format);
        if (fault_handler && !assert_depth ) {
          assert_depth++;
          fault_handler(format, arg_list);
        }
        va_end(arg_list);
        exit(1);
    }
}
