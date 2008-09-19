/*
 * PROJECT:     CTesK                               
 * FILE:        engine.h                            
 * AUTHOR:      Alexey V. Khoroshilov               
 * CREATION:    18 April 2005                       
 * DESCRIPTION: Common properties of test engines.  
 * SCOPE:       It is an interface header.          
 *                                                  
 *   Copyright (c) 2005-2006 ISP RAS.                   
 *   25, B.Communisticheskaya, Moscow, Russia.     
 *   All rights reserved.                       
 *
 */

#ifndef TS_ENGINE_H
#define TS_ENGINE_H

#include <time.h>
#include <atl/object.h>
#include <utils/boolean.h>


/********************************************************************/
/**                         Test Verdict                           **/
/********************************************************************/
/*==============================================================*/
/*  Global variable defining test mode:                         */
/*  TD_ok - test succesfull finished;                           */
/*  TD_bad_parameters - bad parameters are got to the test,     */
/*                      they may be standart parameters or      */
/*                      defined by test developer;              */
/*  TD_not_enough_resourses - not enough resources for the test */
/*                            (malloc or calloc returned NULL); */
/*  TD_bad_verdict - after stimulus call and waiting for the    */
/*                   specified time stationary state was not    */
/*                   achieved;                                  */
/*  TD_faulted - empty arc was got in stimulus call, or         */
/*               non-deterministic behaviour was found when     */
/*               calling back arc (i.e. calling back arc was    */
/*               result in the test state different from one    */
/*               after calling the same arc from the same test  */
/*               state), or                                     */
/*               when trying go along back arcs to path there   */
/*               is not back arc in tested node;                */
/*  ORACLE_bad_verdict - oracle of some stimulus returned bad   */
/*                       verdict or serialization of reactions  */
/*                       not found;                             */
/*==============================================================*/
typedef
enum
{
    TD_ok,
    TD_bad_parameters,
    TD_not_enough_resources,
    TD_bad_verdict,
    TD_faulted,
    ORACLE_bad_verdict
}
TestVerdict;

extern TestVerdict testVerdict;


/********************************************************************/
/**                     Finish Mode property                       **/
/********************************************************************/
typedef
enum
{
  UNTIL_ERROR, /* run test scenario until error (default) */
  UNTIL_END    /* run test scenario until end */
} FinishMode;

FinishMode setFinishMode(FinishMode finish_mode);
FinishMode getFinishMode(void);
int setNumberOfErrorsToFinish(int error_number); 


/********************************************************************/
/**                       Test System Mode                         **/
/********************************************************************/
typedef
enum TSMode
{
  SequentialTSMode,
  ParallelTSMode
}
TSMode;

TSMode getTSMode(void);


/********************************************************************/
/**                   Deferred Reactions property                  **/
/********************************************************************/
bool setDeferredReactionsMode(bool enable);
bool areDeferredReactionsEnabled(void);


/********************************************************************/
/**                         WTime property                         **/
/********************************************************************/
time_t setWTime(time_t secs);
time_t setWTimeMSec(time_t millisecs);
time_t getWTime(void);
time_t getWTimeMSec(void);


/********************************************************************/
/**                 Find First Series Only property                **/
/********************************************************************/
bool setFindFirstSeriesOnly(bool new_value);
bool isFindFirstSeriesOnly(void);
int setFindFirstSeriesOnlyBound(int bound);
int getFindFirstSeriesOnlyBound(void);

/********************************************************************/
/**               Test System Assertion Exit Function              **/
/********************************************************************/
void ts_assert_function(const char* format, va_list arg_list);


/********************************************************************/
/**                   Start and Stop Test System                   **/
/********************************************************************/
bool startTestSystem(int argc, char** argv);
void stopTestSystem(void);


/********************************************************************/
/**                     Current Test Scenario                      **/
/********************************************************************/
const char* getCurrentTestScenarioName(void);

/********************************************************************/
/**                      Model State Manager                       **/
/********************************************************************/

/*
  isStationaryState - returns is current model state stationary or not
*/
typedef bool (*PtrIsStationaryState)(void);


/*
  saveModelState - returns model state of the system under test
*/
typedef Object* (*PtrSaveModelState)(void);


/*
  restoreModelState - restores model state of the system under test
*/
typedef void (*PtrRestoreModelState)(Object*);


/*
  observeState - observes state of the system under test by means of oracle calls in stationary states
*/
typedef void (*PtrObserveState)(void);


/*
  doneEvent - updates model state of the system under test as the last event in any serialization
*/
typedef void (*PtrDoneEvent)(void);


typedef struct ModelStateManager
{
  PtrSaveModelState    saveModelState;
  PtrRestoreModelState restoreModelState;
  PtrIsStationaryState isStationaryState;
  PtrObserveState      observeState;  
} ModelStateManager;


#endif
