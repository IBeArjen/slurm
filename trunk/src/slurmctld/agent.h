/*****************************************************************************\
 *  agent.h - data structures and function definitions for parallel 
 *	background communications
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Moe Jette <jette@llnl.gov>, et. al.
 *  Derived from dsh written by Jim Garlick <garlick1@llnl.gov>
 *  UCRL-CODE-2002-040.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#ifndef _AGENT_H
#define _AGENT_H

#include <src/slurmctld/agent.h>
#include <src/slurmctld/slurmctld.h>

#define AGENT_IS_THREAD  	1	/* set if agent itself a thread of slurmctld */
#define AGENT_THREAD_COUNT	20	/* maximum active agent threads */
#define COMMAND_TIMEOUT 	5	/* seconds */

typedef struct agent_arg {
	uint32_t	addr_count;		/* number of network addresses to communicate with */
	struct sockaddr_in *slurm_addr;		/* array of network addresses */
	slurm_msg_type_t msg_type;		/* RPC to be issued */
	void		*msg_args;		/* RPC data to be transmitted */
} agent_arg_t;

void *agent (void *args);

#endif /* !_AGENT_H */
