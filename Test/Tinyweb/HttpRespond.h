//
// Created by Jialu  Hu on 2019-08-06.
//

#ifndef UNTITLED_HTTPRESPOND_H
#define UNTITLED_HTTPRESPOND_H

#include "HttpContent.h"
class HttpRespond{
public:
    HttpRespond();
    ~HttpRespond();
    void set_url(std::string url){
        url_ = std::move(url);
        std::cout << "url: " << url_ << std::endl;
    }
    void set_method(std::string method){
        method_ = std::move(method);
        std::cout << "method: " << method_ << std::endl;
    }
    void set_version(std::string version){
        version_ = std::move(version);
        std::cout << "version: " << version_ << std::endl;
    }

private:
    std::string url_;
    std::string method_;
    std::string version_;
};

HttpRespond::HttpRespond() {

}
HttpRespond::~HttpRespond() {

}
#endif //UNTITLED_HTTPRESPOND_H
