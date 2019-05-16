/*
 * $Id: gmt_version.h.in 17858 2017-04-03 22:11:08Z jluis $
 *
 *  Copyright (c) 1991-2017 by P. Wessel, W. H. F. Smith, R. Scharroo,
 *  F. Wobbe, and J. Luis
 *
 * See LICENSE.TXT file for copying and redistribution conditions.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; version 3 or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * Contact info: gmt.soest.hawaii.edu
 */

#pragma once
#ifndef GMT_VERSION_H_
#define GMT_VERSION_H_

/* for manpages only */
#define MANDATE "15 May 2017"

#define GMT_MAJOR_VERSION 5
#define GMT_MINOR_VERSION 4
#define GMT_RELEASE_VERSION 2
#define GMT_VERSION_YEAR 2017

/* #undef GMT_SOURCE_CODE_CONTROL_VERSION_STRING */
#ifdef GMT_SOURCE_CODE_CONTROL_VERSION_STRING
#	define GMT_STRING "5.4.2_r18202 (r)"
#else /* if HAVE_SVN_VERSION or if unversioned */
#	define GMT_STRING "5.4.2_r18202"
#endif

#ifdef __x86_64__
#	define GMT_VER_64 " [64-bit]"
#else
#	if defined WIN32 && SIZEOF_VOID_P == 8
#		define GMT_VER_64 " [64-bit]"
#	else
#		define GMT_VER_64 ""
#	endif
#endif

#ifdef _OPENMP /* Open MP Parallelization is on */
#	define GMT_MP " [MP]"
#else
#	define GMT_MP ""
#endif

#ifndef GMT_MANPAGE
#	define GMT_VERSION GMT_version()
#ifdef _WIN32
	static _inline char *GMT_version () {
#else
	static inline char *GMT_version () {
#endif
		/* final string returned by GMT_version() */
		static char version[] = GMT_STRING GMT_VER_64 GMT_MP;
		return version;
	}
#endif /* !GMT_MANPAGE */

#endif /* !GMT_VERSION_H_ */

/* vim: set ft=c: */
