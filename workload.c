/*
 *  B-Queue -- An efficient and practical queueing for fast core-to-core
 *             communication
 *
 *  Copyright (C) 2011 Junchang Wang <junchang.wang@gmail.com>
 *
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sched.h>
#include <stdint.h>
#include "fifo.h"
#include "workload.h"

/* All the consumers Read it. */
static char volatile src[MEM_LEN];

/* All the consumers Write to it. */
/* FIXME: there is cache thrashing */
static char volatile dst[MEM_LEN];

/* RAND_MAX assumed to be 32767 */
int myrand(unsigned long * next) {
	*next = *next * 1103515245 + 12345;
	return((unsigned)(*next/65536) % 32768);
}

/* making myrand works fine on 64bit systems. */
#define MY_RAND_MAX (32767)
#define rand myrand

/* FIXME: function rand() is not reentrant
 *        Check "man 3 rand"
 *        We need rand_r(), however it contains a lock
*/

inline unsigned long workload(unsigned long *next)
{
	unsigned long result = 0;
	int seed;
#if (PROBAB_MEMCPY>0)
	seed = 1 + (int)( (float)PROBAB_MEMCPY * (rand(next) / (MY_RAND_MAX + 1.0)));
	if(seed == 2) {
		//printf(" PROBAB_MEMCPY \n ");
		memcpy((char *)dst, (char *)src, MEM_LEN);
	}
#endif

#if (PROBAB_MALLOC>0)
	seed = 1 + (int)( (float)PROBAB_MALLOC * (rand(next) / (MY_RAND_MAX + 1.0)));
	if(seed == 2) {
		//printf(" PROBAB_MALLOC \n ");
		temp = (char *)malloc(MEM_LEN);
		temp[MEM_LEN-1] = '1';
		free(temp);
	}
#endif

#if (PROBAB_YIELD>0)
	seed = 1 + (int)( (float)PROBAB_YIELD * (rand(next) / (MY_RAND_MAX + 1.0)));
	if(seed == 2) {
		//printf(" PROBAB_YIELD \n ");
		sched_yield();
	}
#endif

#if (PROBAB_WORKLOAD>0)
	unsigned long i;
	seed = 1 + (int)( (float)PROBAB_WORKLOAD * (rand(next) / (MY_RAND_MAX + 1.0)));
	if(seed == 2) {
		//printf(" PROBAB_LOAD \n ");
		//wait_ticks(WORKLOAD);
		for(i=0; i<WORKLOAD; i++) {
			result += i;
			result += result;
		}
	}
#endif
	return result;
}

