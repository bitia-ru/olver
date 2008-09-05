/*
 * File: TraceFormatter.h
 * Description:
 *       This is a header file of TraceFormatter.
 *
 * Copyright (c) 2002-2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __TRACE_FORMATTER_H__
#define __TRACE_FORMATTER_H__


/* CTesK Source Start */
#ifdef _MSC_VER
/* Disable warning C4786: identifier was truncated to 'x' characters in the debug information */
#pragma warning( disable : 4786 )
#endif
/* CTesK Source End */

#include <time.h>
#include "TraceBool.h"
#include "TraceList.h"

#define TRACE_VERSION "2.3"

typedef struct _TraceFormatter TraceFormatter;
struct _TraceFormatter
{
  void * state;
  void (*delete_state)(void *state);
  /*
   * Trace level methods
   */
  const char * (*startTrace)(void *state, const char *encoding);
  const char * (*endTrace)(void *state, TraceBool original);

  /*
   * Scenario level methods
   */
  const char * (*traceScenarioStart)(void *state, int traceId, const char *name, time_t now, const char *host, const char *os);
  const char * (*traceEnvironmentProperties)(void *state, int traceId, TraceList *properties);
  const char * (*traceScenarioParameters)(void *state, int traceId, int argc, const char** argv);
  const char * (*traceTestEngineProperty)(void *state, int traceId, const char *name, const char *value);
  const char * (*traceScenarioEnd)(void *state, int traceId, time_t now);

  /*
   * Transition level methods
   */
  char * (*traceScenarioValue)(void *state, int traceId, const char *kind, const char *type, const char *name, const char *value);
  const char * (*traceState)(void *state, int traceId, const char *id);
  const char * (*traceTransitionStart)(void *state, int traceId, const char *id);
  const char * (*traceTransitionEnd)(void *state, int traceId);

  /*
   * Oracle level methods
   */
  const char * (*traceModelOperationStart)(void *state, int traceId, const char *kind, const char *subsystem, const char *signature, unsigned refid);
  const char * (*traceModelOperationArgument)(void *state, int traceId, const char *type, const char *name, const char *value);
  const char * (*traceModelOperationResult)(void *state, int traceId, const char *type, const char *value);
  const char * (*traceModelOperationChannel)(void *state, int traceId, const char *channel);
  const char * (*traceModelOperationTimestamp)(void *state, int traceId, const char *timestamp);
  const char * (*traceOracleStart)(void *state, int traceId, const char *subsystem, const char *signature, unsigned ref);
  const char * (*tracePreconditionEnd)(void *state, int traceId);
  const char * (*traceOracleEnd)(void *state, int traceId);
  const char * (*traceModelOperationEnd)(void *state, int traceId);
  const char * (*traceSeriesStart)(void *state, int traceId);
  const char * (*traceSeriesEnd)(void *state, int traceId);

  /*
   * Coverage level methods
   */
  const char * (*tracePrimeFormula)(void *state, int traceId, int id, TraceBool value);
  const char * (*traceCoverageElement)(void *state, int traceId, const char *structureId, const char *coverageId, int branchId);
  const char * (*traceMark)(void *state, int traceId, const char *mark);

  const char * (*traceCoverageStructureStart)(void *state, int traceId, const char* name);
  const char * (*traceFormulaeStart)(void *state);
  const char * (*traceFormula)(void *state, int id, const char *text);
  const char * (*traceFormulaeEnd)(void *state);
  const char * (*traceCoverageStart)(void *state, const char *id);
  const char * (*traceElement)(void *state, int id, const char *name);
  const char * (*traceCoverageEnd)(void *state);
  const char * (*traceCoverageStructureEnd)(void *state);

  /*
   * Other messages
   */
  const char * (*traceException)(void *state, int traceId, const char *kind, const TraceList *values, const TraceList *infos);
  const char * (*traceInterimException)(void *state, int traceId, const char *kind, const TraceList *values, const TraceList *infos);
  const char * (*traceInternalError)(void *state, int traceId, const char *info);
  char * (*traceSystemInfo)(void *state, int traceId, const char *info);
  const char * (*traceUserInfo)(void *state, int traceId, const char *info);

  TraceBool (*valid)(TraceFormatter *tf);
};


void TraceFormatter_delete(TraceFormatter *tf);


#endif /* __TRACE_FORMATTER_H__ */
