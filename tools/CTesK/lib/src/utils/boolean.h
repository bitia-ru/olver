/* 
 * File: boolean.h
 * Description: 
 *       This file contains boolean type definition.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef BOOLEAN_H
#define BOOLEAN_H

#ifndef __cplusplus

typedef int bool;

#ifdef true
#undef true
#endif
#define true  1

#ifdef false
#undef false
#endif
#define false 0

#endif /* __cplusplus */

#endif /* BOOLEAN_H */
