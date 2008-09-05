/*
 * PROJECT:     CTesK                               
 * FILE:        register.h                          
 * AUTHOR:      Alexey V. Khoroshilov               
 * CREATION:    13 Apr 2003                         
 * DESCRIPTION: Contains functions needed           
 *              for work with reactions.            
 * SCOPE:       It is an interface header.          
 *                                                  
 *   Copyright (c) 2003-2006 ISP RAS.              
 *   25, B.Communisticheskaya, Moscow, Russia.     
 *   All rights reserved.
 *
 */

#ifndef TS_REGISTER_H
#define TS_REGISTER_H

#include "atl/object.h"
#include "ts/timemark.h"
#include "ts/generated.h"
#include "utils/boolean.h"


/********************************************************************/
/**                        Register Reaction                       **/
/********************************************************************/
void registerReaction(
         ChannelID       chid,
         const char*     name,
         SpecificationID reactionID,
         Object*         data
                     );

void registerReactionWithTimeMark(
         ChannelID       chid,
         const char*     name,
         SpecificationID reactionID,
         Object*         data,
         TimeMark        mark
                                 );

void registerReactionWithTimeInterval(
         ChannelID       chid,
         const char*     name,
         SpecificationID reactionID,
         Object*         data,
         TimeInterval    interval
                                     );


/********************************************************************/
/**                     Register Wrong Reaction                    **/
/********************************************************************/
void registerWrongReaction(const char* info);


/********************************************************************/
/**                            Catchers                            **/
/********************************************************************/
typedef bool (*ReactionCatcherFuncType)(void*);

void registerReactionCatcher(ReactionCatcherFuncType catcher,void* par);
bool unregisterReactionCatcher(ReactionCatcherFuncType catcher,void* par);
bool unregisterReactionCatchers(ReactionCatcherFuncType catcher);


/********************************************************************/
/**                       Register Stimulus                        **/
/********************************************************************/
ChannelID setStimulusChannel(ChannelID chid);
ChannelID getStimulusChannel(void);

void registerStimulus(
         const char*     name,
         SpecificationID stimulusID,
         Object*         data,
         TimeInterval    interval
                     );

/* The variable argument list should be the following: inpars, outpars, returned_value          */
/*   where:                                                                                     */
/*     inpars         - a list of input values of the specification function arguments          */
/*     outpars        - a list of output values of the specification function arguments         */
/*     returned_value - a value returned by specification function if returned type is not void */
void registerStimulusWithTimeInterval(
         ChannelID       chid,
         const char*     name,
         SpecificationID stimulusID,
         TimeInterval    interval,
         ...
                                     );


#endif
