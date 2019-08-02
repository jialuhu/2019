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
        indx(-1){
}

Channel :: ~Channel(){

}

//更新时间表
void Channel :: update() {
    eloop_ -> updateChannel(this);
}

//执行回调函数
void Channel :: handleEvent() {
    if(revents_ & (EVFILT_READ))
        if(ReadCallback){
            ReadCallback();
        }
    if(revents_ & (EVFILT_WRITE))
        if(WriteCallback){
            WriteCallback();
        }
}
