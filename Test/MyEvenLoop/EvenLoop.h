/*************************************************************************
	> File Name: EvenLoop.h
	> Author: 
	> Mail: 
	> Created Time: 五  7/26 21:17:07 2019
 ************************************************************************/

#ifndef _EVENLOOP_H
#define _EVENLOOP_H

#include <iostream>
#include <atomic>
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include <boost/function.hpp>
#include <boost/noncopyable.hpp>
#include "Poller.h"

class EventLoop{
public:
    EventLoop();
    ~EventLoop();
    void loop();
    void quit();
    void updateChannel(Channel *channel);
private:
    std::vector<struct pollfd> pollfd_;
    std::map<int, std::shared_ptr<Channel> > channel_map;
    std::vector<std::shared_ptr<Channel> > _activeChannel;
    std::shared_ptr<Poller> poller_;
    Channel *channel_;
    bool quit_;
    bool looping_;
};



#endif
