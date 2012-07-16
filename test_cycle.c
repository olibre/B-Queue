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


#include <sched.h>
#include <stdio.h>
#include "fifo.h"
#include "workload.h"

#define TEST_SIZE 200000000

inline uint64_t read_tsc()
{
        uint64_t        time;
        uint32_t        msw   , lsw;
        __asm__         __volatile__("rdtsc\n\t"
                        "movl %%edx, %0\n\t"
                        "movl %%eax, %1\n\t"
                        :         "=r"         (msw), "=r"(lsw)
                        :   
                        :         "%edx"      , "%eax");
        time = ((uint64_t) msw << 32) | lsw;
        return time;
}

int main()
{
	uint64_t i, start_c, stop_c;
	unsigned long seed;
	seed = read_tsc();

#if defined(RT_SCHEDULE)
        struct sched_param param;
        param.__sched_priority = sched_get_priority_min(SCHED_FIFO);
        if (sched_setscheduler(0, SCHED_FIFO, &param)) {
                printf("Error: sched_setscheduler.\n");
                return -1;
        }
        printf("Success: Real time schedule.\n");
#endif /* RT_SCHEDULE */

	start_c = read_tsc();
	for(i=0; i<TEST_SIZE; i++) {
		workload(&seed);
	}
	stop_c = read_tsc();
	printf("average: %ld cycles/op\n", ((stop_c - start_c) / TEST_SIZE));
	return 0;
}

