/*
 * PROJECT:     CTesK
 * FILE:        timemark.h
 * AUTHOR:      Alexey V. Khoroshilov
 * CREATION:    1 Jul 2003
 * DESCRIPTION: Contents functions that needs
 *              for work with timemarks.
 * SCOPE:       It is an interface header.
 *                                                  
 *   Copyright (c) 2003-2006 ISP RAS.
 *   25, B.Communisticheskaya, Moscow, Russia.
 *   All rights reserved.
 *
 */

#ifndef TS_TIMEMARK_H
#define TS_TIMEMARK_H

#include "utils/boolean.h"
#include "utils/stdint.h"


/********************************************************************/
/**                           ChannelID                            **/
/********************************************************************/
typedef long ChannelID;

extern const ChannelID WrongChannel;
extern const ChannelID UniqueChannel;

ChannelID getChannelID(void);
void releaseChannelID(ChannelID chid);


/********************************************************************/
/**                      Linear Time Model                         **/
/********************************************************************/
typedef uint64_t LinearTimeMark;


/********************************************************************/
/**                     Time Frame of Reference                    **/
/********************************************************************/
typedef int TimeFrameOfReferenceID;

extern const TimeFrameOfReferenceID infiniteTimeFrameOfReferenceID;
extern const TimeFrameOfReferenceID systemTimeFrameOfReferenceID;

TimeFrameOfReferenceID getTimeFrameOfReferenceID(const char* name);
bool setSystemTimeFrameOfReferenceName(const char* name);


/********************************************************************/
/**                            Time Mark                           **/
/********************************************************************/
typedef struct TimeMark TimeMark;

struct TimeMark
{
  TimeFrameOfReferenceID frame;
  LinearTimeMark         timemark;
};

extern const TimeMark minTimeMark;
extern const TimeMark maxTimeMark;

TimeMark createTimeMark(LinearTimeMark timemark);
TimeMark createDistributedTimeMark(TimeFrameOfReferenceID frame,LinearTimeMark timemark);


/********************************************************************/
/**                     Set Time Dependencies                      **/
/********************************************************************/
void setTimeMarkDependence(TimeMark former,TimeMark latter);


/********************************************************************/
/**                       Compare Time Marks                       **/
/********************************************************************/
typedef
enum CompareResult
{
  EqualCR,
  LessCR,
  GreaterCR,
  NonComparableCR
}
CompareResult;

CompareResult compareTimeMarks(TimeMark tm1,TimeMark tm2);

bool equalTimeMarks(TimeMark tm1,TimeMark tm2);
bool lessTimeMarks(TimeMark tm1,TimeMark tm2);
bool lessOrEqualTimeMarks(TimeMark tm1,TimeMark tm2);
bool greaterTimeMarks(TimeMark tm1,TimeMark tm2);
bool greaterOrEqualTimeMarks(TimeMark tm1,TimeMark tm2);
bool noncomparableTimeMarks(TimeMark tm1,TimeMark tm2);


/********************************************************************/
/**                     Time Mark Arithmetic                       **/
/********************************************************************/
typedef int64_t TimeUnit;

TimeUnit diffTimeMarks(TimeMark tm1,TimeMark tm2);
TimeMark addTimeMarks(TimeMark tm,TimeUnit delta);
TimeMark subtractTimeMarks(TimeMark tm,TimeUnit delta);


/********************************************************************/
/**                         Time Interval                          **/
/********************************************************************/
typedef struct TimeInterval TimeInterval;

struct TimeInterval
{
  TimeMark minMark;
  TimeMark maxMark;
};

extern const TimeInterval overallTimeInterval;

TimeInterval createTimeInterval(TimeMark minMark,TimeMark maxMark);

bool areIntersectedTimeIntervals(TimeInterval ti1,TimeInterval ti2);
TimeInterval addTimeIntervals(TimeInterval ti,TimeUnit delta);
TimeInterval subtractTimeIntervals(TimeInterval ti,TimeUnit delta);


/********************************************************************/
/**                Auxiliary Time Interval Functions               **/
/********************************************************************/

/*
 * Puts string representation of the interval into the buffer and
 * returns number of the bytes written.
 */
int printLinearTimeInterval(char* buffer,TimeInterval interval);

/*
 * Puts string representation of the interval into the buffer and
 * returns number of the bytes written.
 */
int printDistributedTimeInterval(char* buffer,TimeInterval interval);


/********************************************************************/
/**                         Current Time                           **/
/********************************************************************/
bool setAutomaticTimeMarksMode(bool enable);
bool areAutomaticTimeMarksEnabled(void);

TimeMark getCurrentTimeMark(void);

typedef TimeMark (*GetCurrentTimeMarkFuncType)(void);
GetCurrentTimeMarkFuncType setDefaultCurrentTimeMarkFunction(GetCurrentTimeMarkFuncType new_func);

void setAutomaticTimeMark(TimeMark* timemark);


/********************************************************************/
/**                      Time Model property                       **/
/********************************************************************/
typedef
enum TSTimeModel
{
  NotUseTSTime,
  LinearTSTime,
  DistributedTSTime  
} TSTimeModel;

TSTimeModel setTSTimeModel(TSTimeModel time_model);
TSTimeModel getTSTimeModel(void);


#endif
