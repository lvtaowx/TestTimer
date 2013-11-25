/*
 * TestMuduoTimer.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: lvanlv
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include <CurrentThread.h>
#include <TimerQueue.h>
//#include <Epoller.h>
#include <EventLoop.h>
#include <EventLoopThread.h>

using namespace netlib::base;
using namespace netlib::net;

int cnt = 0;
//EventLoop t_loop;

void printTid()
{
	printf("pid = %d, tid = %d\n", getpid(), netlib::CurrentThread::tid());
	printf("now = %s\n", TimeStamp::now().toString().c_str());
}

void print(const char* msg)
{
	printf("%s %s now = %s   msg = %s \n", __FUNCTION__, __FILE__, TimeStamp::now().toString().c_str(), msg);
}

//void cancel(TimerId timerId)
//{
//	t_loop.cancel(timerId);
//	printf("cancel time = %s\n", TimeStamp::now().toString().c_str());
//}

// test atomic

const int kInitEventListSize = 16;

int main()
{
//	AtomicInt64 atomic;
//	assert(atomic.get() == 0);
//	assert(atomic.getAndAdd(1) == 0);
//	assert(atomic.getAndAdd(1) == 1);
//	assert(atomic.addAndGet(2) == 4);
//	assert(atomic.get() == 4);
//	assert(atomic.incrementAndGet() == 5);
//	atomic.decrement();
//	assert(atomic.get() == 4);
	printTid();

	EventLoop loop;
//	t_loop = &loop;

	printf("main\n");
	loop.runAfter(3, boost::bind(print, "test1"));
	loop.loop();

	sleep(5);

/*
 *  this timerfd has been tested
 *  first test
 *
	EpEvent epEvent;
	EpEventList epEventList(kInitEventListSize);

	int timerFd = createTimerFd();
	int epFd = createPollFd();

	epEvent.events = EPOLLIN | EPOLLPRI;
	epEvent.data.fd = timerFd;
	upodateOpts(epFd, ADD, timerFd, &epEvent);
	resetTimerFd(timerFd, addTime(TimeStamp::now(), 10));
	while(1)
	{
		int nums = pollFd(epFd, epEventList, 500);
		sleep(1);
		if(nums > 0)
		{
			printf("%s %s now = %s   num = %d \n", \
				__FUNCTION__, __FILE__, TimeStamp::now().toString().c_str(), nums);
			break;
		}
	}

*/
	return 0;
}


