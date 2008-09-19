/* 
 * File: undef.h
 * Description: 
 *       This file undefines macroses that used for access from SEC code
 *       to identifiers equaled to SEC keywords.
 *
 * Copyright (c) 2002-2003 ISP RAS.
 * B.Communisticheskaya,25, Moscow, Russia.
 * All rights reserved.
 *
 */

#ifdef __SEC__
#undef call
#undef coverage
#undef invariant
#undef iterate
#undef iterator
#undef mediator
#undef pre
#undef post
#undef reaction
#undef reads
#undef scenario
#undef specification
#undef stable
#undef state
#undef updates
#undef writes
#endif
