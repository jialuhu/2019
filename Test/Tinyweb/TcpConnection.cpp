//
// Created by Jialu  Hu on 2019-08-04.
//
#include "TcpConnection.h"
TcpConnection::TcpConnection(EventLoop *loop,
        std::string conn_name, int connfd, InetAddr &local):
        loop_(loop),
        conn_name_(conn_name),
        connfd_(connfd),
        socket_(new Socket(connfd)),
        LocalAddr_(local),
        conn_state(CONNECTING),
        channel_(new Channel(loop,connfd)){
    channel_->setReadCallback([this]{this->HandleRead();});
    channel_->setWriteCallback([this]{this->HandleWrite();});
    channel_->setErnnoCallback([this]{this->HandleErrno();});
}
TcpConnection::~TcpConnection() {
    std::cout << "~TcpConnection\n";
}
void TcpConnection::connectEstablished() {
    assert(conn_state==CONNECTING);
    conn_state = CONNCTED;
    channel_->enableReading();
    //设置用户回调,进行事件注册
    std::cout << "The point of TcpConnection will be wrong in here\n";
    connectionCb_(shared_from_this());
}

void TcpConnection::HandleRead(){
    //此处用Buffer读取出接收到的数据，然后交给onMessageCb进行处理，
    //在Webserver中进行数据分析
    int saveErrno = 0;
    std::cout << "Handleread\n";
    int bytes = input_.ReadFd(channel_->fd(),saveErrno);
    if(bytes>0){
        std::cout << "发送数据给webserver处理 \n";
        onMessageCb_(shared_from_this(),&input_);
    }
    else if(bytes==0){
        std::cout << "关闭连接，没有数据可以读";
        HandleClose();
    }
    else{
        errno = saveErrno;
        HandleErrno();
    }

}
void TcpConnection::HandleClose() {
    std::cout << "TcpConneciton HandleClose\n";
}

void TcpConnection::HandleErrno() {
    std::cout << "TcpConneciton HandleErrno\n";

}

void TcpConnection::HandleWrite() {
    std::cout << "TcpConneciton HandleWrite\n";
}