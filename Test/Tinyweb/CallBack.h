//
// Created by Jialu  Hu on 2019-08-04.
//

#ifndef UNTITLED_CALLBACK_H
#define UNTITLED_CALLBACK_H
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
class TcpConnection;
class Buffer;
typedef boost::shared_ptr<TcpConnection> TcpConnectionPtr;
typedef boost::function<void (const TcpConnectionPtr&)> ConnectionCallback;
typedef boost::function<void (const TcpConnectionPtr&, Buffer *buf)> OnMessageCallback;
typedef boost::function<void (int fd)> CloseCallback;
#endif //UNTITLED_CALLBACK_H
