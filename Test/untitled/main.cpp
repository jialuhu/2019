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
#include "Acceptor.h"
#include "EventLoop.h"
#include "InetAddr.h"
#include "SocketOpt.h"
#include "TcpServer.h"
#include <stdio.h>
#include <iostream>
/*void newConnection(int sockfd, InetAddr& peerAddr)
{
    printf("newConnection(): accepted a new connection from ");
    int ret = ::write(sockfd, "How are you?\n", 13);
    sleep(10);
    ::close(sockfd);
}

int main()
{
    printf("main(): pid = %d\n", getpid());
    InetAddr listenAddr(8888);
    EventLoop loop;
    Acceptor acceptor(&loop, listenAddr);
    acceptor.setNewConnectionCallback(newConnection);
    acceptor.listen();
    loop.loop();
}*/
int main(){
    EventLoop loop;
    InetAddr addr(8888);
    WebServer server(&loop,addr);
    server.start();
    loop.loop();
    return 0;
}
