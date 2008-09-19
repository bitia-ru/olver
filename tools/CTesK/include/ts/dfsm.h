/*
 * PROJECT:     CTesK                               
 * FILE:        dfsm.h                              
 * AUTHOR:      Vitaliy Omelchenko (vitaliy)        
 * CREATION:    2 Aug 2001                          
 * DESCRIPTION: Contents data structures and        
 *              forward declarations functions      
 *              that needs for testing group of     
 *              functions by browsing determenistic 
 *              mutually connected graph.           
 * SCOPE:       It is an interface header.          
 * VERSION AND LIST OF CHANGES:                     
 *  1 Jul 2003  (hed)                               
 *   Support of deferred reactions has been added   
 *                                                  
 *   Copyright (c) 2001-2006 ISP RAS.              
 *   25, B.Communisticheskaya, Moscow, Russia.      
 *   All rights reserved.                          
 *
 */

#ifndef TS_DFSM_H
#define TS_DFSM_H

#include "utils/boolean.h"
#include "atl/object.h"
#include "ts/generated.h"
#include "ts/engine.h"


/********************************************************************/
/**                     DFSM data field types                      **/
/********************************************************************/
/*
 */
typedef bool (*PtrInit)(int, char**);


/*
 */
typedef void (*PtrFinish)(void);


/*
  getState - specific for test (and maybe realization),
             it evaluates and returns current state (node in
             traversing graph) of test, state is always the
             object type;
*/
typedef Object* (*PtrGetState)(void);


/********************************************************************/
/**                      DFSM data type                            **/
/********************************************************************/
typedef struct
{
  const char*          name;
  PtrInit              init;
  PtrGetState          getState;
  PtrSaveModelState    saveModelState;
  PtrRestoreModelState restoreModelState;
  PtrIsStationaryState isStationaryState;
  PtrObserveState      observeState;
  PtrFinish            finish;
  ScenarioFunctionID*  actions;   /* The last element of the array should be NULL */
} dfsm;


/********************************************************************/
/**                  Start DFSM engine function                    **/
/********************************************************************/
bool start_dfsm(int argc, char** argv, dfsm* td);


#endif
