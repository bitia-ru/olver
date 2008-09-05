/* 
 * File: sec.h
 * Description: 
 *       This file defines macroses hiding compiler specific keywords.
 *
 * Copyright (c) 2002-2004 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifndef __SEC_H__
#define __SEC_H__

#ifdef __SEC__

#if defined __GNUC__

#define   asm         __asm__
#define __asm         __asm__
#define __alignof     __alignof__
#define __attribute   __attribute__
#define __complex     _Complex
#define __complex__   _Complex
#define __const       const
#define __const__     const
#define __imag        __imag__
#define __inline      inline
#define __inline__    inline
#define __real        __real__
#define __restrict    __restrict__
#define __signed      signed
#define __signed__    signed
#define __typeof      typeof
#define __typeof__    typeof
#define __volatile    volatile
#define __volatile__  volatile

/* CTesK Source Start */
#elif defined(_MSC_VER) && (_MSC_VER >= 1300)
/* Microsoft Visual Studio .Net */

#define __w64
/* CTesK Source End */

#endif

#endif

#endif
