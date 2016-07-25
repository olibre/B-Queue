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
* [LMAX Disruptor](http://lmax-exchange.github.io/disruptor/) and [Disruptor--](https://github.com/fsaintjacques/disruptor--)
* https://github.com/cameron314/concurrentqueue [Reddit](https://www.reddit.com/r/programming/comments/2ll7bf) [Hacker news](https://news.ycombinator.com/item?id=8575152)
* [Read-Log-Update](http://sigops.org/sosp/sosp15/current/2015-Monterey/printable/077-matveev.pdf) [GitHub](https://github.com/rlu-sync/rlu) [YouTube](https://www.youtube.com/watch?v=at9cxc3JTkY)
* https://github.com/concurrencykit/ck
* [stackoverflow.com - What is the reason why high level abstractions that use lock free programming deep down aren't popular?](http://stackoverflow.com/questions/8400114)
* [A Wait-free Queue as Fast as Fetch-and-Add](http://chaoran.me/assets/pdf/wfq-ppopp16.pdf) (2016)
* [Fast Concurrent Queues for x86 Processors](http://www.cs.tau.ac.il/~adamx/publications/ppopp2013-x86queues.pdf) (2013)
* [Lock-free MPMC Queue](cppnow2015.sched.org/event/ae11e93c8692544c41310615b544abd0) at C++Now mai 2015 (Aspen, USA)
* [Folly MPMC Queue](https://github.com/facebook/folly/blob/master/folly/MPMCQueue.h)
