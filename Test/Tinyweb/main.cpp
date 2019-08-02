#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include "EventLoop.h"
#include "Channel.h"
EventLoop *g_loop;
void fun(){
    std::cout << "hujialu\n";
    g_loop->quit();
}
int main() {
    EventLoop loop;
    g_loop = &loop;
    int fd = open("/Users/jialuhu/2019/Test/MyEvenLoop/1.txt",O_RDWR);
    if(fd<0)
    {
        std::cout << "打开失败\n";
        exit(0);
    }
    else{
        std::cout << "fd: " << fd <<std::endl;
    }
    Channel channel(&loop, fd);
    channel.setReadCallback(fun);
    channel.enableReading();
    loop.loop();
    close(fd);
    return 0;
}