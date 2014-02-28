/*
 * Copyright (c) 2003-2012 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef __ARM_MCONTEXT_H_
#define __ARM_MCONTEXT_H_

#include <sys/appleapiopts.h>
#include <mach/arm/_structs.h>

#ifndef _STRUCT_MCONTEXT
#if __DARWIN_UNIX03
#if !defined(__LP64__)
#define _STRUCT_MCONTEXT        struct __darwin_mcontext
_STRUCT_MCONTEXT
{
	_STRUCT_ARM_EXCEPTION_STATE	__es;
	_STRUCT_ARM_THREAD_STATE	__ss;
	_STRUCT_ARM_VFP_STATE		__fs;
};
#else
#define _STRUCT_MCONTEXT64	struct __darwin_mcontext64
_STRUCT_MCONTEXT64
{
	_STRUCT_ARM_EXCEPTION_STATE64	__es;
	_STRUCT_ARM_THREAD_STATE64	__ss;
	_STRUCT_ARM_NEON_STATE64	__ns;
};
#endif /* !__LP64__ */
#else /* !__DARWIN_UNIX03 */
#if !defined(__PL64__)
#define _STRUCT_MCONTEXT        struct mcontext
_STRUCT_MCONTEXT
{
	_STRUCT_ARM_EXCEPTION_STATE	es;
	_STRUCT_ARM_THREAD_STATE	ss;
	_STRUCT_ARM_VFP_STATE		fs;
};
#else
#define _STRUCT_MCONTEXT64	struct mcontext64
_STRUCT_MCONTEXT64
{
	_STRUCT_ARM_EXCEPTION_STATE64	es;
	_STRUCT_ARM_THREAD_STATE64	ss;
	_STRUCT_ARM_NEON_STATE64	ns;
};
#endif /* !__LP64__ */
#endif /* __DARWIN_UNIX03 */
#endif /* _STRUCT_MCONTEXT */


#if !defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE)
#ifndef ARM_MCONTEXT_SIZE
#define ARM_MCONTEXT_SIZE       (ARM_THREAD_STATE_COUNT + ARM_VFP_STATE_COUNT + ARM_EXCEPTION_STATE_COUNT) * sizeof(int)
#endif /* ARM_MCONTEXT_SIZE */
#endif /* (_POSIX_C_SOURCE && !_DARWIN_C_SOURCE) */

#endif /* __ARM_MCONTEXT_H_ */
