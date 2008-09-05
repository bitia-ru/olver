/*
 * PROJECT:     CTesK                               
 * FILE:        register_tsi.h                      
 * AUTHOR:      Alexey V. Khoroshilov               
 * CREATION:    13 Apr 2003                         
 * DESCRIPTION: Registrar of interactions with      
 *              system under test.                  
 * SCOPE:       It is an internal header.           
 *                                                  
 *   Copyright (c) 2003-2006 ISP RAS.              
 *   25, B.Communisticheskaya, Moscow, Russia.     
 *   All rights reserved.
 *
 */

#ifndef REGISTER_INTERNAL_INTERFACE_H
#define REGISTER_INTERNAL_INTERFACE_H

#include "ts/register.h"


/********************************************************************/
/**                          Interaction                           **/
/********************************************************************/
typedef struct Interaction Interaction;

struct Interaction
{
  InteractionId   id;
  bool            is_native;
  bool            is_stimulus;
  char*           name;
  SpecificationID specificationDesc;
  Object*         data;
  TimeInterval    interval;
  Interaction*    nextPtr;
  Interaction*    prevPtr;
};


/********************************************************************/
/**                       InteractionChannel                       **/
/********************************************************************/
typedef struct InteractionChannel InteractionChannel;

struct InteractionChannel
{
  ChannelID           chid;
  Interaction*        first;
  Interaction*        last;
  LinearTimeMark      maxMinMark;  // the maximum of { minMark(interactions) } - linear time model only
  InteractionChannel* nextPtr;
};


/********************************************************************/
/**                        InteractionList                         **/
/********************************************************************/
typedef
struct Interactions
{
  InteractionChannel* first;
  InteractionChannel* last;
  long                numInteractions;
  bool                is_correct;
  char*               defect_description;
} 
Interactions;

ChannelID getChannelIDOfInteraction(Interactions* list,Interaction* interaction);
InteractionChannel* getChannelOfInteraction(Interactions* list,Interaction* interaction);
void destroyInteractions(Interactions* list);


/********************************************************************/
/**                        Get Gathered Data                       **/
/********************************************************************/
// calls all registered catchers and returns the list of registered
// stimulus and reactions. The internal store is cleared.
Interactions* getGatheredInteractions(void);

// Clear the internal store.
void clearGatheredInteractions(void);


/********************************************************************/
/**                         Gather Reactions                       **/
/********************************************************************/
bool gatherReactions(void);


/********************************************************************/
/**                    Trace Alien Interactions                    **/
/********************************************************************/
void traceAlienInteractions(Interactions* interactions);


/********************************************************************/
/**                          Serialization                         **/
/********************************************************************/
typedef struct Serialization Serialization;

Serialization* createSerialization(Interactions* interactions);
bool fixPrefix(Serialization* serialization,Interaction* interaction,bool ignore);
bool nextSeries(Serialization* serialization);
void restartSerialization(Serialization* serialization);
Interaction* getNextInteraction(Serialization* serialization);
void destroySerialization(Serialization* serialization);


/********************************************************************/
/**                     Serialization Manager                      **/
/********************************************************************/
typedef struct SerializationManager SerializationManager;

struct SerializationManager
{
  Serialization* (*createSerialization) (Interactions* interactions);
  bool           (*fixPrefix)(Serialization* serialization,Interaction* interaction,bool ignore);
  bool           (*nextSeries)          (Serialization* serialization);
  void           (*restartSerialization)(Serialization* serialization);
  Interaction*   (*getNextInteraction)  (Serialization* serialization);
  void           (*destroySerialization)(Serialization* serialization);
};


#endif
