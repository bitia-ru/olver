/*
 * PROJECT:     CTesK                               
 * FILE:        engine_tsi.h                        
 * AUTHOR:      Alexey V. Khoroshilov               
 * CREATION:    18 April 2005                       
 * DESCRIPTION: Common properties of test engines.  
 * SCOPE:       It is an internal header.           
 *                                                  
 *   Copyright (c) 2005-2006 ISP RAS.                   
 *   25, B.Communisticheskaya, Moscow, Russia.     
 *   All rights reserved.                       
 *
 */

#ifndef TS_ENGINE_INTERNAL_INTERFACE_H
#define TS_ENGINE_INTERNAL_INTERFACE_H

#include "ts/engine.h"
#include "ts/generated.h"
#include "utils/assertion.h"


/********************************************************************/
/**              Quick Access to Finish Mode property              **/
/********************************************************************/
extern FinishMode tsFinishMode;
extern int tsNumberOfErrorsToFinish;


/********************************************************************/
/**                       Test System Mode                         **/
/********************************************************************/
void setTSMode(TSMode mode);


/********************************************************************/
/**               Test System Assertion Exit Function              **/
/********************************************************************/
AssertionExit ts_setup_assert_function(void);
void ts_restore_assert_function(AssertionExit prev_assert);


/********************************************************************/
/**                      Calculate TT filename                     **/
/********************************************************************/
char* getTTFileName(const char* basename);


/********************************************************************/
/**                   Process Standard Parameters                  **/
/********************************************************************/
typedef struct TestSystemParameters
{
  bool   no_trace;
  bool   console;
  char** files;
  int    argc;
  char** argv;
} TestSystemParameters;

TestSystemParameters* processStandardParameters( const char* name
                                               , ScenarioFunctionID* scenario_actions
                                               , int argc
                                               , char** argv
                                               );

void disableStandardParameters(TestSystemParameters* pars);


/********************************************************************/
/**                     Current Test Scenario                      **/
/********************************************************************/
void setCurrentTestScenarioName(const char* name);


/********************************************************************/
/**                      Model State Syncronizer                   **/
/********************************************************************/
bool onFrameEnd( ModelStateManager* model_state, bool verdict );
bool syncronize_ModelState( ModelStateManager* model_state );


/********************************************************************/
/**                           Arc Symbol                           **/
/********************************************************************/
typedef struct ArcSymbol
{
  int     kind;
  Object* value;
} ArcSymbol;

void init_ArcSymbol( ArcSymbol* symbol );
void destroy_ArcSymbol( ArcSymbol* symbol );
bool isNull_ArcSymbol( ArcSymbol* symbol );


/********************************************************************/
/**                        Arc Symbol Executor                     **/
/********************************************************************/
typedef struct ArcSymbolExecutor
{
  ModelStateManager   model_state;
  ScenarioFunctionID* actions;
} ArcSymbolExecutor;

void initArcSymbol( ArcSymbolExecutor* executor, ArcSymbol* symbol );
void nextArcSymbol( ArcSymbolExecutor* executor, ArcSymbol* next_symbol, int kind, Object* value );
bool executeArcSymbol( ArcSymbolExecutor* executor, int arcid, ArcSymbol* symbol, ArcSymbol* next_symbol );


#endif
