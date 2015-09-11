# B-Queue
An efficient and practical queueing for fast core-to-core communication 

## History

During summer 2012, Junchang Wang, Kai Zhang and Bei Hua 
from University of Science and Technology of China (USTC), 
and Xinan Tang from Intel Compiler Lab (Santa Clara, USA)
published the B-Queue algorithm.

The original source code is available in Sourceforge:
http://sourceforge.net/projects/bqueue/

## Target

B-Queue aims to be faster than FastForward and MCRingBuffer, 
two other *single-producer-single-consumer concurrent lock-free FIFOs* (abbreviated as
CLF).

## See also

* [Draft publication](http://staff.ustc.edu.cn/~bhua/publications/IJPP_draft.pdf) is available 
  ([final version](http://link.springer.com/article/10.1007/s10766-012-0213-x) costs about $40 / 35€ / £30)
* http://psy-lob-saw.blogspot.com/2013/11/spsc-iv-look-at-bqueue.html
* [Liberty Queue](http://liberty.princeton.edu/Publications/epic8_queues.pdf), 
  another interresting *single-producer/single-consumer (SP/SC) concurrent lock-free (CLF) queue*
* The SP/SC CLF queue of [FastFlow framework](http://sourceforge.net/projects/mc-fastflow/) 
  ([overview](http://www.1024cores.net/home/technologies/fastflow))
* [boost::lockfree](http://www.boost.org/doc/libs/release/doc/html/lockfree.html)
* [LMAX Disruptor](https://github.com/LMAX-Exchange/disruptor)
