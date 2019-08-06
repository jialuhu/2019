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
    channel_->setCloseCallback([this]{this->HandleClose();});
}
TcpConnection::~TcpConnection() {
    std::cout << "~TcpConnection\n";
}
void TcpConnection::connectEstablished() {
    std::cout << "TcpConnection::connectEstablished\n\n";
    assert(conn_state==CONNECTING);
    conn_state = CONNCTED;
    channel_->enableReading();
    //设置用户回调,进行事件注册
    connectionCb_(shared_from_this());
    std::cout << "TcpConnection::connectEstablished\n\n";
}

void TcpConnection::HandleRead(){
    //此处用Buffer读取出接收到的数据，然后交给onMessageCb进行处理，
    //在Webserver中进行数据分析
    int saveErrno = 0;
    std::cout << "TcpConnection::Handleread\n\n";
    int bytes = input_.ReadFd(channel_->fd(),saveErrno);
    if(bytes>0){
        std::cout << "发送数据给webserver处理 \n";
        onMessageCb_(shared_from_this(),input_);
    }
    else if(bytes==0){
        std::cout << "关闭连接，没有数据可以读\n";
        HandleClose();
    }
    else{
        std::cout << "Handlernno 关闭连接\n";
        errno = saveErrno;
        HandleErrno();
    }
    std::cout << "TcpConnection::Handleread\n\n";

}
void TcpConnection::HandleClose() {
    std::cout << "TcpConneciton HandleClose\n\n";
    conn_state = CONNCTED;
    channel_->disableAll();
    CloseCb_(shared_from_this());
    std::cout << "TcpConneciton HandleClose\n\n";

}

void TcpConnection::HandleErrno() {
    std::cout << "TcpConneciton HandleErrno\n\n";
    HandleClose();
    std::cout << "TcpConneciton HandleErrno\n\n";
}
void TcpConnection::set_Handlewrite() {
    std::cout << "set_handlewrite\n\n";
    channel_->enableWriting();
    std::cout << "set_handlewrite\n\n";
}
//**************此处需要修改
void TcpConnection::HandleWrite() {
    std::cout << "TcpConneciton HandleWrite\n\n";
    std::string buf("HTTP/1.1 200 ok\r\nconnection: close\r\nContent-Type: text/html\r\n"
                    "Content-Length: 24\r\n\r\n");
    std::cout << "The content of bufs is: \n";
    std::cout << buf << std::endl;
    std::cout << "The fd of send message: " << channel_->fd() <<std::endl;
    int n = ::write(channel_->fd(),buf.c_str(),buf.size());
    std::cout << "The n of the write is " << n << std::endl;
    char buff[250]={"<html>hello word!</html>"};
    int ret = ::write(channel_->fd(),buff,strlen(buff));
    std::cout << "The ret of the write is " << ret << std::endl;
    std::cout << "TcpConneciton HandleWrite\n\n";
    channel_->disableWriting();
}