/*	$OpenBSD: ctype.h,v 1.19 2005/12/13 00:35:22 millert Exp $	*/
/*	$NetBSD: ctype.h,v 1.14 1994/10/26 00:55:47 cgd Exp $	*/

/*
 * Copyright (c) 1989 The Regents of the University of California.
 * All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)ctype.h	5.3 (Berkeley) 4/3/91
 */

#ifndef _CTYPE_H_
#define _CTYPE_H_

#include <cdefs.h>

#define	_CTYPE_U	0x01
#define	_CTYPE_L	0x02
#define	_CTYPE_D	0x04
#define	_CTYPE_S	0x08
#define	_CTYPE_P	0x10
#define	_CTYPE_C	0x20
#define	_CTYPE_X	0x40
#define	_CTYPE_B	0x80
#define	_CTYPE_R	(_CTYPE_P|_CTYPE_U|_CTYPE_L|_CTYPE_D|_CTYPE_B)
#define	_CTYPE_A	(_CTYPE_L|_CTYPE_U)

__BEGIN_DECLS

extern const char	*_ctype_;
extern const short	*_tolower_tab_;
extern const short	*_toupper_tab_;

#if defined(__GNUC__) || defined(_ANSI_LIBRARY) || defined(lint)
int	isalnum(int);
int	isalpha(int);
int	iscntrl(int);
int	isdigit(int);
int	isgraph(int);
int	islower(int);
int	isprint(int);
int	ispunct(int);
int	isspace(int);
int	isupper(int);
int	isxdigit(int);
int	tolower(int);
int	toupper(int);

#if __BSD_VISIBLE || __ISO_C_VISIBLE >= 1999 || __POSIX_VISIBLE > 200112 \
    || __XPG_VISIBLE > 600
int	isblank(int);
#endif

#if __BSD_VISIBLE || __XPG_VISIBLE
int	isascii(int);
int	toascii(int);
int	_tolower(int);
int	_toupper(int);
#endif /* __BSD_VISIBLE || __XPG_VISIBLE */

#endif /* __GNUC__ || _ANSI_LIBRARY || lint */

__END_DECLS

//typedef char *   va_list;

#define __builtin_next_arg(t)       ((t) ? &t : 0)
#if 0
#define __builtin_stdarg_start(a, l)    ((a) = ((l) ? 0 : 0))
#define __builtin_va_arg(a, t)      ((a) ? 0 : 0)
#define __builtin_va_end        /* nothing */
#define __builtin_va_copy(d, s)     ((d) = (s))
#endif

#undef va_arg
#undef va_start
#undef va_end
#undef __va_copy
#undef __va_size

#define __va_size(type) \
    (((sizeof(type) + sizeof(long) - 1) / sizeof(long)) * sizeof(long))

#define va_start(ap, last) \
    ((ap) = (va_list)(__builtin_next_arg(last)))

#define va_arg(ap, type) \
    ((type *)(ap += sizeof(type)))[0]

#define va_end(ap) (ap = NULL)

#define __va_copy(dest, src)    ((dest) = (src))

#endif /* !_CTYPE_H_ */
