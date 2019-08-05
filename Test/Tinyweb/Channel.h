//
// Created by Jialu  Hu on 2019-08-01.
//

#ifndef TINY_WEB_CHANNEL_H
#define TINY_WEB_CHANNEL_H

#include <boost/function.hpp>
//#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <iostream>
class EventLoop;
enum UPDATE{

};
class Channel{
public:
    typedef boost::function<void()> EventCallBack;
    Channel(EventLoop *eventLoop, int fd);
    ~Channel();

    //返回查看是否是该eventloop对象
    EventLoop *ownerloop(){
        return  eloop_;
    }

    //设置读回调
    void setReadCallback(EventCallBack cb){
        ReadCallback = std::move(cb);
    }
    //设置写回调
    void setWriteCallback(EventCallBack cb){
        WriteCallback = std::move(cb);
    }
    //设置错误回调
    void setErnnoCallback(EventCallBack cb){
        ErnnoCallback = std::move(cb);
    }
    //注册可读事件
    void enableReading(){
        std::cout << "注册可读事件\n";
        std::cout << "EVFILE_READ: " << EVFILT_READ << std::endl;
        event_ |= EVFILT_READ;
        std::cout << "update\n";
        update();
    }
    //注册可写事件
    void enableWriting(){
        std::cout << "注册可写事件\n";
        event_ |= EVFILT_WRITE;
        update();
    }
    //注册不可读写事件
    void disableAll(){
        isclose = true;
        update();
    }
    //处理半关闭状态
    void disableWriting(){
        event_ &= ~EVFILT_WRITE;
        update();
    }

    void set_index(int index){
        indx = index;
    }

    void set_isclose(bool ev){
        isclose = ev;
    }
    void set_revent(int ev){
        revents_ = ev;
    }
    bool is_close(){
        return isclose;
    }
    int fd(){
        return  fd_;
    }

    int index(){
        return  indx;
    }

    int event(){
        return  event_;
    }
    void handleEvent();
private:

    void update();
    EventCallBack ReadCallback;
    EventCallBack WriteCallback;
    EventCallBack ErnnoCallback;

    EventLoop *eloop_;
    int fd_;
    int event_;
    bool isclose;
    int revents_;
    int indx;
    bool eventHanding_;
};


#endif //TINY_WEB_CHANNEL_H
