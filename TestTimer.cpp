/*
 * TestMuduoTimer.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: lvanlv
 */

#include <stdio.h>
#include <unistd.h>

#include <CurrentThread.h>
#include <TimerQueue.h>
#include <EventLoop.h>
#include <EventLoopThread.h>

using namespace netlib::base;
using namespace netlib::net;

int cnt = 0;
EventLoop t_loop;

void printTid()
{
	printf("pid = %d, tid = %d\n", getpid(), netlib::CurrentThread::tid());
	printf("now = %s\n", TimeStamp::now().toString().c_str());
}

void print(const char* msg)
{
	printf("now = %s   msg = %s \n", TimeStamp::now().toString().c_str(), msg);

}

void cancel(TimerId timerId)
{
	t_loop.cancel(timerId);
	printf("cancel time = %s\n", TimeStamp::now().toString().c_str());
}

// test atomic
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
	loop.runAfter(1, boost::bind(print, "test1"));


}


