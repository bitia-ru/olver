/* 
 * File: TSEnvironment.h 
 * Description: 
 *       This is a header file of TSEnvironment.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACER_TS_ENVIRONMENT_H__
#define __TRACER_TS_ENVIRONMENT_H__


/********************************************************************/
/**                     CTesK Version Info                         **/
/********************************************************************/
extern char* ts_get_ctesk_version(void);
extern char* ts_get_ctesk_build(void);


/********************************************************************/
/**                         TS Environment                         **/
/********************************************************************/
struct _TSEnvironment
{
  char * (*getOSInfo)();
  char * (*getHostInfo)();
};
typedef struct _TSEnvironment TSEnvironment;


/********************************************************************/
/**                    TS Environment Factory                      **/
/********************************************************************/
TSEnvironment* TSEnvironment_createTSEnvironment();


#endif /* __TRACER_TS_ENVIRONMENT_H__ */
