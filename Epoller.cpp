/*
 * Epoller.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: lvanlv
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include <Epoller.h>

#define MAXSIZE 1000

int createPollFd()
{
	int fd = ::epoll_create(MAXSIZE);
	if(fd <= 0)
	{
		printf("create epoll fd failed %s %s\n", __FUNCTION__, __FILE__);
	}

	return fd;
}

void upodateOpts(int epFd, int operation, int fd, EpEvent *ev)
{
	int res = ::epoll_ctl(epFd, operation, fd, ev);
	if(res != 0)
	{
		printf("epoll ctl failed %s %s\n", __FUNCTION__, __FILE__);
		printf("epoll ctl failed  the error info %d  %s\n", errno, strerror(errno));
	    perror(strerror(errno));
	}
}

int pollFd(int epFd, EpEventList epEventList, int timeOut)
{
	int size =  epEventList.size();
	int eventNums = ::epoll_wait(epFd, &*epEventList.begin(), epEventList.size(), timeOut);
	if(eventNums <= 0)
	{
		printf("nothing happened %s %s\n", __FUNCTION__, __FILE__);
	}
	return eventNums;
}

void closeFd(int fd)
{
	::close(fd);
}


