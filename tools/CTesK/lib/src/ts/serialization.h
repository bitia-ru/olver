/*
 * PROJECT:     CTesK                               
 * FILE:        serialization.h                     
 * AUTHOR:      Alexey V. Khoroshilov               
 * CREATION:    8 Jul 2003                          
 * DESCRIPTION: Declares functions needed           
 *              for serialization.                  
 * SCOPE:       It is an internal header.           
 *                                                  
 *   Copyright (c) 2003-2006 ISP RAS.                   
 *   25, B.Communisticheskaya, Moscow, Russia.      
 *   All rights reserved.
 *
 */

#ifndef TS_SERIALIZATION_H
#define TS_SERIALIZATION_H

#include "ts/register_tsi.h"
#include "ts/engine.h"

/********************************************************************/
/**                     Serialization Manager                      **/
/********************************************************************/
Serialization* createLinearSerialization(Interactions* interactions);
Serialization* createDistributedSerialization(Interactions* interactions);


/********************************************************************/
/**                           Hyper Oracle                         **/
/********************************************************************/
bool serialize_interactions(Interactions* interactions,ModelStateManager* model_state);


#endif
