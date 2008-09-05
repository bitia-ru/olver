/*
 * PROJECT:     CTesK                              
 * FILE:        ndfsm.h                            
 * AUTHOR:      Alexey V. Khoroshilov (hed)        
 * CREATION:    11 Apr 2005                        
 * DESCRIPTION: Implementation of the test engine  
 *              for testing a group of functions   
 *              by traversing a nondetermenictic   
 *              graph contained mutually connected 
 *              deterministic spanning subgraph.   
 * SCOPE:       It is an interface header.         
 * VERSION AND LIST OF CHANGES:                    
 *                                                 
 *   Copyright (c) 2005-2006 ISP RAS.                  
 *   25, B.Communisticheskaya, Moscow, Russia.    
 *   All rights reserved.                      
 *
 */

#ifndef TS_NDFSM_H
#define TS_NDFSM_H

#include "ts/dfsm.h"


/********************************************************************/
/**                      NDFSM data type                           **/
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
} ndfsm;


/********************************************************************/
/**                  Start NDFSM engine function                   **/
/********************************************************************/
bool start_ndfsm(int argc, char** argv, ndfsm* test);


#endif
