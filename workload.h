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


#define PROBAB (100)
#define PROBAB_MEMCPY 0
#define MEM_LEN (1024*4)
#define PROBAB_MALLOC 0
#define PROBAB_YIELD 0
#define PROBAB_LOCK 0
#define PROBAB_WORKLOAD 10
#define WORKLOAD (2000)
#define AVG_WORKLOAD (0) 


inline unsigned long workload(unsigned long *next);
