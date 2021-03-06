//
// Created by Jialu  Hu on 2019-08-06.
//

#ifndef UNTITLED_HTTPRESPOND_H
#define UNTITLED_HTTPRESPOND_H

#include "HttpContent.h"
#include "TcpConnection.h"
#include <sys/stat.h>
#include <sys/mman.h>
class HttpRespond{
public:
    HttpRespond();
    ~HttpRespond();
    void set_url(std::string url){
        url_ = url;
        std::cout << "url: " << url_ << std::endl;
    }
    void set_method(std::string method){
        method_ = method;
        std::cout << "method: " << method_ << std::endl;
    }
    void set_version(std::string version){
        version_ = version;
        std::cout << "version: " << version_ << std::endl;
    }

    void set_postcontent(std::string st){
        std::cout << "hhhhhhhhhhhhhhhhhhhh--------------------: " << st << std::endl;
        post_content = st;
    }
    void set_Respond_Header(std::string head){
        Respond_Header_ = head;
    }

    void set_Host_(std::string host){
        Host_ = Host_;
    }

    void set_ContentLength(std::string length){
        ContentLength_ = length;
    }

    void set_ContentLanguage(std::string language){
        ContentLanguage_ = language;
    }

    void set_ContentType(std::string type){
        ContentType_ = type;
    }

    void set_Connection(std::string Connction){
        Connection_ = Connction;
    }
    void FillRespond_POST(const TcpConnectionPtr &conn){
        conn->Post_deal("/Users/jialuhu/2019/add", post_content.c_str());
    }
    void FillRespond_GET(const TcpConnectionPtr &conn){
            method_ = "/Users/jialuhu/2019"+method_;
            std::cout << "method:^^^^^^^^^^^^^ "<< method_ << std::endl;
            int fd = open(method_.c_str(),O_RDWR);
            if(fd < 0){
                std::string header("HTTP/1.1 404\r\n");
                std::string content("Content-Length: 0\r\nConnection: close\r\n\r\n");
                std::cout << header << content << std::endl;
                std::cout << "打开失败\n";
            }
            else{
                std::string header("HTTP/1.1 200 ok\r\nConnection: close\r\n");
                conn->set_Handlewrite(method_.c_str(),fd,header);
            }
            close(fd);

    }
private:
    std::string url_;
    std::string method_;
    std::string version_;

    std::string post_content;

    std::string Respond_Header_;
    std::string Host_;
    std::string ContentLanguage_;
    std::string ContentLength_;
    std::string ContentType_;
    std::string Connection_;
};

HttpRespond::HttpRespond() {

}
HttpRespond::~HttpRespond() {

}
#endif //UNTITLED_HTTPRESPOND_H
