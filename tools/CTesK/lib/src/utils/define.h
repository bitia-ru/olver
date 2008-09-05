/* 
 * File: define.h
 * Description: 
 *       This file defines macroses that used for access from SEC code
 *       to identifiers equaled to SEC keywords.
 *
 * Copyright (c) 2002-2005 ISP RAS.
 * 25, B.Communisticheskaya, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifdef __SEC__
#define call $call
#define coverage $coverage
#define invariant $invariant
#define iterate $iterate
#define iterator $iterator
#define mediator $mediator
#define pre $pre
#define post $post
#define reaction $reaction
#define reads $reads
#define scenario $scenario
#define specification $specification
#define stable $stable
#define state $state
#define updates $updates
#define writes $writes
#endif
