//
// Created by Jialu  Hu on 2019-08-01.
//
#include "Channel.h"
#include "EventLoop.h"

Channel ::Channel(EventLoop *eventLoop, int fd) :
        eloop_(eventLoop),
        fd_(fd),
        event_(0),
        revents_(0),
        indx(-1)
        {
    std::cout << "fd_:" <<fd_<<std::endl;
    std::cout << "eventloop:" << eloop_<< std::endl;
}

Channel :: ~Channel(){
    assert(!eventHanding_);
    std::cout << "Channel析构了\n";
}

//更新时间表
void Channel :: update() {
    std::cout << "Channle::channel: " <<this << std::endl;
    eloop_ -> updateChannel(this);
}

//执行回调函数
void Channel :: handleEvent() {
    //eventHanding保证在处理事件期间Channel不被析构
    eventHanding_ = true;
    //客户端关闭链接
    if(revents_ & EVFILT_VNODE ){
        std::cout << "Client is closed\n";
    }
    /*if(revents_ & EV_ERROR)
    {
        std::cout << "Handle kqueue is wrong\n";
    }*/
    if(revents_ & (EVFILT_READ))
        if(ReadCallback){
            std::cout << "有可以读的事件\n";
            std::cout << fd() << "(((((\n";
            ReadCallback();
            std::cout << "有可以读的事件\n";
        }
    if(revents_ & (EVFILT_WRITE))
        if(WriteCallback){
            WriteCallback();
        }
    eventHanding_ = false;
        std::cout << "eventHanding: " << eventHanding_ << std::endl;
}
