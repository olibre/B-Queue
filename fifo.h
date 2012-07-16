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


#ifndef _FIFO_B_QUQUQ_H_
#define _FIFO_B_QUQUQ_H_

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <string.h>
#include <stdint.h>


#define ELEMENT_TYPE uint64_t

#define QUEUE_SIZE (1024 * 8) 
#define BATCH_SIZE (QUEUE_SIZE/16)
#define CONS_BATCH_SIZE BATCH_SIZE
#define PROD_BATCH_SIZE BATCH_SIZE
#define BATCH_INCREAMENT (BATCH_SIZE/2)

#define CONGESTION_PENALTY (1000) /* cycles */

#if defined(CONS_BATCH) || defined(PROD_BATCH)

struct queue_t{
	/* Mostly accessed by producer. */
	volatile	uint32_t	head;
	volatile	uint32_t	batch_head;

	/* Mostly accessed by consumer. */
	volatile	uint32_t	tail __attribute__ ((aligned(64)));
	volatile	uint32_t	batch_tail;
	unsigned long	batch_history;

	/* readonly data */
	uint64_t	start_c __attribute__ ((aligned(64)));
	uint64_t	stop_c;

	/* accessed by both producer and comsumer */
	ELEMENT_TYPE	data[QUEUE_SIZE] __attribute__ ((aligned(64)));
} __attribute__ ((aligned(64)));

#else

struct queue_t {
	/* Mostly accessed by producer. */
	volatile	uint32_t	head;

	/* Mostly accessed by consumer. */
	volatile 	uint32_t	tail __attribute__ ((aligned(64)));

	/* readonly data */
	uint64_t	start_c __attribute__ ((aligned(64)));
	uint64_t	stop_c;

	/* accessed by both producer and comsumer */
	ELEMENT_TYPE	data[QUEUE_SIZE] __attribute__ ((aligned(64)));
} __attribute__ ((aligned(64)));

#endif

#define SUCCESS 0
#define BUFFER_FULL -1
#define BUFFER_EMPTY -2

void queue_init(struct queue_t *q);
int enqueue(struct queue_t *q, ELEMENT_TYPE value);
int dequeue(struct queue_t *q, ELEMENT_TYPE *value);

inline uint64_t read_tsc();
inline void wait_ticks(uint64_t);

#endif
