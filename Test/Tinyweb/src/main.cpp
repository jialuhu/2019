#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/event.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include "Buffer.h"
#include "TcpConnection.h"
#include "WebServer.h"
/*EventLoop *g_loop;
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
}*/
/*#include "Acceptor.h"
#include "EventLoop.h"
#include "InetAddr.h"
#include "SocketOpt.h"
#include "TcpServer.h"
#include <stdio.h>
#include <iostream>*/

int main(){
    EventLoop loop;
    InetAddr addr(8888);
    WebServer server(&loop,addr);
    server.start();
    loop.loop();
    return 0;
}
