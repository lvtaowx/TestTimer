/*
 * Epoller.h
 *
 *  Created on: Nov 22, 2013
 *      Author: lvanlv
 */

#ifndef EPOLLER_H_
#define EPOLLER_H_
#include <vector>

#include <sys/epoll.h>

const int ADD = EPOLL_CTL_ADD;
const int MOD = EPOLL_CTL_MOD;
const int DEL = EPOLL_CTL_DEL;

const int noEvent = 0;
const int readEvent = EPOLLIN;
const int writeEvent = EPOLLOUT;

typedef struct epoll_event EpEvent;
typedef std::vector<EpEvent> EpEventList;

int createPollFd();
void upodateOpts(int epFd, int operation, int fd, EpEvent *ev);
int pollFd(int epFd, EpEventList epEventList, int timeOut);
void closeFd(int fd);

#endif /* EPOLLER_H_ */
