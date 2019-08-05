//
// Created by Jialu  Hu on 2019-08-04.
//

#ifndef UNTITLED_TCPCONNECTION_H
#define UNTITLED_TCPCONNECTION_H
#include <boost/any.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "InetAddr.h"
#include "TcpServer.h"
#include "Buffer.h"
#include "CallBack.h"
class TcpConnection : boost::noncopyable,
public boost::enable_shared_from_this<TcpConnection>
{
public:
    //记录连接的状态
    enum State{
        CONNECTING,
        CONNCTED,
        CLOSED,
    };
    TcpConnection(EventLoop* loop, std::string cooname,int connfd, InetAddr &local);
    ~TcpConnection();
    void setConnectionCb(ConnectionCallback cb){
        connectionCb_ = std::move(cb);
    }
    void setMessageCb(OnMessageCallback cb){
        onMessageCb_ = std::move(cb);
    }

    //进行用户的回调
    void connectEstablished();
private:
    typedef boost::function<void (TcpConnection &)> ConnectionCallbacks;
    void HandleRead();
    void HandleWrite();
    void HandleClose();
    void HandleErrno();
    boost::scoped_ptr<Channel> channel_;
    EventLoop *loop_;
    std::string conn_name_;
    int connfd_;
    InetAddr LocalAddr_;
    boost::scoped_ptr<Socket> socket_;
    State conn_state;
    ConnectionCallback connectionCb_;
    OnMessageCallback onMessageCb_;
    Buffer input_;
    //Buffer output_;

};
#endif //UNTITLED_TCPCONNECTION_H
