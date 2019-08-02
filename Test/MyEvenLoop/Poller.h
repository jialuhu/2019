/*************************************************************************
	> File Name: Poller.h
	> Author: 
	> Mail: 
	> Created Time: 一  7/29 21:48:50 2019
 ************************************************************************/

#ifndef _POLLER_H
#define _POLLER_H
#include "EvenLoop.h"
class Poller{
public:
    Poller(EventLoop *ev):loop_(ev){}
    ~Poller(){};
private:
    EventLoop *loop_;

};

class Channel{
public:
    Channel();
    ~Channel();

};

#endif
