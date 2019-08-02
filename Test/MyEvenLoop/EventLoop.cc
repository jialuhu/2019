#include "EvenLoop.h"
#include "Poller.h"
#include <thread>
thread_local EventLoop *_thisThreadLoop = nullptr;

EventLoop::EventLoop():
    quit_(false),looping_(false),poller_(new Poller(this)){
        if(_thisThreadLoop){
            std::cout << "Another EvenLoop exits this thread\n";
        }
        else{
            std::cout << "this thread have a new EventLoop\n";
            _thisThreadLoop = this;
        }
}

EventLoop::~EventLoop()
{
    assert(!looping_);
    _thisThreadLoop = nullptr;
}

void EventLoop :: quit()
{
    quit_ = true;
}

void EventLoop :: updateChannel(Channel *channel)
{
    assert(channel->ownerLoop() == this)
    poller_ -> updateChannel(channel);
}

void EventLoop :: loop()
{
    assert(!looping_);
    looping_ = true;
    quit_ = false;
    while(!quit_){
        _activeChannel.clear();
        poller_ -> poll(-1, &_activeChannel);
        for(auto it=_activeChannel.begin(); it!=_activeChannel.end(); it++)
        {
            (*it) -> handleEvent();
        }
    }
    looping_ = false;
}

