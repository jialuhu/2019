//
// Created by Jialu  Hu on 2019-08-04.
//
#include "TcpServer.h"
TcpServer::TcpServer(EventLoop *loop, InetAddr &listenAddr):
            loop_(loop),
            listenAddr_(listenAddr),
            acceptor_(new Acceptor(loop,listenAddr)){
    std::cout << "Tcpserver is build\n";
    std::cout << "Tcpserver eventloop: " << loop_<< std::endl;
    acceptor_->setNewConnectionCallback( std::bind(&TcpServer::newConnection,
            this, std::placeholders::_1));
}

TcpServer::~TcpServer() {
    std::cout << "~TcpServer\n";

}

void TcpServer::start() {
    acceptor_->listen();
}

void TcpServer::quit(){
    loop_ -> quit();
}

void TcpServer::newConnection(int connfd) {
    //此处建立相对应的连接事件，并且设置读写事件
     std::cout <<"建立新的connetion并且管理之\n";
     char buf[13]={"hello"};
     countId++;
     sprintf(buf,buf,"%d",countId);
     std::string s1("hujialu");
     s1+=buf;

     TcpConnectionPtr conn(new TcpConnection(loop_,"hujialu",connfd,listenAddr_));
     connections_[s1]= conn;
     conn->setConnectionCb(ConnectionCb_);
     conn->setMessageCb(OnMessageCb_);
     conn->connectEstablished();
     conn->setConnectionCb(
             std::bind(&TcpServer::removeConnection,this)
             );

     std::cout << "设置回调，执行回调\n";
}