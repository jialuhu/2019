//
// Created by Jialu  Hu on 2019-08-04.
//
#include "TcpConnection.h"
#include <sys/stat.h>
#include <sys/mman.h>
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

void TcpConnection::Post_deal(const char* file_path, const char *argv){
    method_ = true;
    file_path_=file_path;
    argv_=argv;
    std::cout << argv_ << std::endl;
    if(fork()==0)
    {
        dup2(channel_->fd(),STDOUT_FILENO);
        int r=execl(file_path_,argv_,NULL);
    }
    wait(NULL);
   // channel_->enableWriting();


}
void TcpConnection::set_Handlewrite(const char* filepath, int fd,std::string &head) {

    method_= false;
    std::cout << "set_handlewrite\n\n";
    int saveErrno;
    int number = output_.ReadFd(fd,saveErrno);
    std::cout << "%%%%%%%%%%%%%%%\n";
    std::cout << output_.enableRead() << std::endl;
    char buf[100];
    sprintf(buf,"Content-Length: %d\r\n\r\n",output_.enableRead());
    buf[strlen(buf)]='\0';
    head = head+buf;
    respond_head = head;
    channel_->enableWriting();
    std::cout << "set_handlewrite\n\n";
}
//**************此处需要修改
void TcpConnection::HandleWrite(){
    /*std::cout << "The fd of send message: " << channel_->fd() <<std::endl;
    std::cout << "****************最后的响应头*****************\n";
    std::cout << respond_head << std::endl;*/
    /*int n = ::write(channel_->fd(),respond_head.c_str(),respond_head.size());
    fd_=::open(path_.c_str(),O_RDWR);
    struct stat tbuf;
    fstat(fd_,&tbuf);
    char *address;
    address = (char*)mmap(0,tbuf.st_size,PROT_READ,MAP_PRIVATE,fd_,0);
    struct iovec m_iv[1];
    m_iv[0].iov_base = address;
    m_iv[0].iov_len = tbuf.st_size;
    int nRecvBuf=32*1024;//设置为32K
    setsockopt(channel_->fd(),SOL_SOCKET,SO_RCVBUF,(const char*)&nRecvBuf,sizeof(int));
    int nSendBuf = 32*1024;
    setsockopt(channel_->fd(),SOL_SOCKET,SO_SNDBUF,(const char*)&nSendBuf,sizeof(int));
    int ret = writev(channel_->fd(),m_iv,1);
    std::cout << "!!!!!!!!!!!!! " << ret << std::endl;
    if(address){
        munmap(address,tbuf.st_size);
    }*/
    /*int ret=write(channel_->fd(),output_.peek(),output_.enableRead());
    std::cout << "ret is " << ret << std::endl;
    std::cout << output_.enableRead() <<std::endl;
    //close(fd_);
    channel_->disableWriting();*/
    //if(method_){
        /*if(fork()==0)
        {
            std::cout << "POST%%%%%%%%%%%%%%%%%%%%\n";
            dup2(channel_->fd(),STDOUT_FILENO);
            int r=execl(file_path_,argv_,NULL);
            std::cout << r <<std::endl;
        }
        wait(NULL);
        channel_->disableWriting();*/

   // }
    //else{
    std::cout << "The fd of send message: " << channel_->fd() <<std::endl;
    //respond_head +=respond_content;//最后的响应头
    std::cout << "****************最后的响应头*****************\n";
    std::cout << respond_head << std::endl;
    int n = ::write(channel_->fd(),respond_head.c_str(),respond_head.size());
    int ret;


    std::cout << "_______________________________\n";
    std::cout << output_.enableRead() <<std::endl;
    ret=::write(channel_->fd(),output_.peek(),output_.enableRead());
    std::cout << "The n of the write is " << n << std::endl;
    std::cout << "The ret of the write is           !!!!!  " << ret << std::endl;
    std::cout << "TcpConneciton HandleWrite\n\n";
    channel_->disableWriting();
   // }
    //channel_->disableWriting();
}
