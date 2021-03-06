/* 
 * Mach Operating System
 * Copyright (c) 1991 Carnegie Mellon University
 * All Rights Reserved.
 * 
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
 * 
 * Carnegie Mellon requests users of this software to return to
 * 
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 * 
 * any improvements or extensions that they make and grant Carnegie Mellon 
 * the rights to redistribute these changes.
 */

#ifndef	_I386_USER_LDT_H_
#define	_I386_USER_LDT_H_

/*
 * User LDT management.
 *
 * Each thread in a task may have its own LDT.
 */

#include <i386/seg.h>

struct user_ldt {
#ifdef	MACH_PV_DESCRIPTORS
	vm_offset_t		alloc;	/* allocation before alignment */
#endif	/* MACH_PV_DESCRIPTORS */
	struct real_descriptor	desc;	/* descriptor for self */
	struct real_descriptor	ldt[1];	/* descriptor table (variable) */
};
typedef struct user_ldt *	user_ldt_t;

extern void
user_ldt_free(user_ldt_t user_ldt);

#endif	/* _I386_USER_LDT_H_ */
