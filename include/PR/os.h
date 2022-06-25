/*====================================================================
 * os.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/**************************************************************************
 *
 *  $Revision: 1.149 $
 *  $Date: 1997/12/15 04:30:52 $
 *  $Source: /disk6/Master/cvsmdev2/PR/include/os.h,v $
 *
 **************************************************************************/


#ifndef _OS_H_
#define	_OS_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)


#define OS_PIM_STACKSIZE	4096
#define OS_VIM_STACKSIZE	4096
#define OS_SIM_STACKSIZE	4096

#define	OS_MIN_STACKSIZE	72

/*
 * I/O message types
 */
#define OS_MESG_TYPE_BASE	(10)
#define OS_MESG_TYPE_LOOPBACK	(OS_MESG_TYPE_BASE+0)
#define OS_MESG_TYPE_DMAREAD	(OS_MESG_TYPE_BASE+1)
#define OS_MESG_TYPE_DMAWRITE	(OS_MESG_TYPE_BASE+2)
#define OS_MESG_TYPE_VRETRACE	(OS_MESG_TYPE_BASE+3)
#define OS_MESG_TYPE_COUNTER	(OS_MESG_TYPE_BASE+4)
#define OS_MESG_TYPE_EDMAREAD	(OS_MESG_TYPE_BASE+5)
#define OS_MESG_TYPE_EDMAWRITE	(OS_MESG_TYPE_BASE+6)

/*
 * Structure for device manager block
 */
typedef struct {
        s32             active;		/* Status flag */
	OSThread	*thread;	/* Calling thread */
        OSMesgQueue  	*cmdQueue;	/* Command queue */
        OSMesgQueue  	*evtQueue;	/* Event queue */
        OSMesgQueue  	*acsQueue;	/* Access queue */
					/* Raw DMA routine */
        s32             (*dma)(s32, u32, void *, u32);
        s32             (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;




#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_H */