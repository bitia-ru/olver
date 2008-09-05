/*
 * PROJECT:     CTesK
 * FILE:        ts.h
 * AUTHOR:      Vitaliy Omelchenko (vitaliy)
 * CREATION:    2 Aug 2001
 * DESCRIPTION: Contains data types and function
 *              declarations needed for all
 *              CTesK tests.
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

#ifndef TS_H
#define TS_H

#ifdef __SEC__
#pragma SEC force_use_start
#endif

#include <utils/sec.h>

#include <string.h>

#include <utils/boolean.h>
#include <utils/assertion.h>
#include <ts/generated.h>

#include <ts/register.h>
#include <ts/engine.h>
#include <ts/dfsm.h>
#include <ts/ndfsm.h>

#include <atl/object.h>
#include <atl/unit.h>
#include <atl/string.h>

#include <c_tracer/c_tracer.h>

#include <ts/coverage.h>

/********************************************************************/
/**                     CTesK Version Info                         **/
/********************************************************************/

// Run 'ant subst' to generate ts/version.hh
#include <ts/version.hh>

const char* ts_get_ctesk_version(void);
const char* ts_get_ctesk_build(void);


/********************************************************************/
/**                        Set Bad Verdict                         **/
/********************************************************************/
void setBadVerdict(const char *msg);
bool isBadVerdict(void);
void clearBadVerdict(void);

/********************************************************************/
/**                        Verdict Event Handling                  **/
/********************************************************************/

enum TS_Verdict
{
  TS_VERDICT_PRE = 1,
  TS_VERDICT_POST = 2,
  TS_VERDICT_MEDIATOR = 4,
  TS_VERDICT_SCENARIO = 8,
  TS_VERDICT_ALL = 15
};

typedef void (*VerdictEventHandler)( bool verdict );

void ts_set_verdict_event_handler( enum TS_Verdict ts_verdict_flags, VerdictEventHandler handler );
void ts_fire_verdict_event( enum TS_Verdict ts_verdict_flag, bool verdict );

#ifdef __SEC__
#pragma SEC force_use_end
#endif

#endif

