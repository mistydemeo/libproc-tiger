/*
 * Copyright (c) 2005 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
#ifndef _LIBPROC_H_
#define _LIBPROC_H_

#include <sys/buf.h>
#include <sys/proc.h>
#include <mach/mach_types.h>

int proc_info_internal(int callnum, int pid, int flavor, uint64_t arg, user_addr_t buffer, uint32_t buffersize, register_t * retval);

/* protos for proc_info calls */
int proc_listpids(uint32_t type, uint32_t tyoneinfo, user_addr_t buffer, uint32_t buffersize, register_t * retval);
int proc_pidinfo(int pid, int flavor, uint64_t arg, user_addr_t buffer, uint32_t buffersize, register_t * retval);
int proc_pidfdinfo(int pid, int flavor,int fd, user_addr_t buffer, uint32_t buffersize, register_t * retval);
int proc_kernmsgbuf(user_addr_t buffer, uint32_t buffersize, register_t * retval);

/* protos for procpidinfo calls */
int proc_pidfdlist(proc_t p, user_addr_t buffer, uint32_t buffersize, register_t *retval);
int proc_pidbsdinfo(proc_t p, struct proc_bsdinfo *pbsd);
int proc_pidtaskinfo(proc_t p, struct proc_taskinfo *ptinfo);
int proc_pidallinfo(proc_t p, int flavor, uint64_t arg, user_addr_t buffer, uint32_t buffersize, register_t *retval);
int proc_pidthreadinfo(proc_t p, uint64_t arg,  struct proc_threadinfo *pthinfo);
int proc_pidlistthreads(proc_t p,  user_addr_t buffer, uint32_t buffersize, register_t *retval);
int proc_pidregioninfo(proc_t p, uint64_t arg, user_addr_t buffer, uint32_t buffersize, register_t *retval);
int proc_pidregionpathinfo(proc_t p,  uint64_t arg, user_addr_t buffer, uint32_t buffersize, register_t *retval);
int proc_pidvnodepathinfo(proc_t p,  uint64_t arg, user_addr_t buffer, uint32_t buffersize, register_t *retval);

/* protos for proc_pidfdinfo calls */
int pid_vnodeinfo(vnode_t vp, uint32_t vid, struct fileproc * fp, user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_vnodeinfopath(vnode_t vp, uint32_t vid, struct fileproc * fp, user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_socketinfo(socket_t  so, struct fileproc *fp, user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_pseminfo(struct psemnode * psem, struct fileproc * fp,  user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_pshminfo(struct pshmnode * pshm, struct fileproc * fp,  user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_pipeinfo(struct pipe * p, struct fileproc * fp,  user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_kqueueinfo(struct kqueue * kq, struct fileproc * fp,  user_addr_t  buffer, uint32_t buffersize, register_t * retval);
int pid_atalkinfo(struct atalk  * at, struct fileproc * fp,  user_addr_t  buffer, uint32_t buffersize, register_t * retval);

#endif /*_LIBPROC_H_ */
