//
// Created by Jialu  Hu on 2019-08-06.
//

#ifndef UNTITLED_HTTPCONTENT_H
#define UNTITLED_HTTPCONTENT_H

#include "TcpConnection.h"
//#include "Buffer.h"
#include "HttpRespond.h"
class HttpContent{
public:
    /*NO_REQUESTION是代表请求不完整，需要客户继续输入；
     * BAD_REQUESTION是HTTP请求语法不正确；
     * GET_REQUESTION代表获得并且解析了一个正确的HTTP请求；
     * FORBIDDEN_REQUESTION是代表访问资源的权限有问题；
     * FILE_REQUESTION代表GET方法资源请求；INTERNAL_ERROR代表服务器自身问题；
     * NOT_FOUND代表请求的资源文件不存在；
     * DYNAMIC_FILE表示是一个动态请求；
     * POST_FILE表示获得一个以POST方式请求的HTTP请求*/

    enum HTTP_CODE{NO_REQUESTION, GET_REQUESTION,
            BAD_REQUESTION, FORBIDDEN_REQUESTION,
            FILE_REQUESTION,INTERNAL_ERROR,NOT_FOUND,
            DYNAMIC_FILE,POST_FILE};

    /*HTTP请求解析的状态转移。HEAD表示解析头部信息，REQUESTION表示解析请求行*/
    enum CHECK_STATUS{HEAD,REQUESTION};

    HttpContent();
    ~HttpContent();
    void doit(const TcpConnectionPtr &conn, Buffer &buf);
private:
    HttpRespond httprespond_;
    HTTP_CODE analyse(const TcpConnectionPtr& conn, Buffer &buffer);
    void set_status(CHECK_STATUS statu){
        status_ = statu;
    }
    HTTP_CODE ParseHeader();//解析请求头
    HTTP_CODE ParseRequestion();//解析请求
    CHECK_STATUS Analyse_Status(){
        return status_;
    }
    std::string content;//需要解析的每一行
    HTTP_CODE RESULT_;//解析的结果
    CHECK_STATUS status_;
};

HttpContent::HttpContent(){

}

HttpContent::~HttpContent(){

}

void HttpContent::doit(const TcpConnectionPtr &conn, Buffer &buffer){
    RESULT_ = analyse(conn,buffer);
    switch (RESULT_){
        case BAD_REQUESTION:{
            std::cout << "请求头格式有问题\n";
            break;
        }
        case FILE_REQUESTION:{
            std::cout << "GET请求方法\n";
            break;
        }
        case POST_FILE:{
            std::cout << "POST请求方法\n";
        }
    }
     conn->set_Handlewrite();

}
HttpContent::HTTP_CODE HttpContent::ParseRequestion() {

    return FILE_REQUESTION;
}


HttpContent::HTTP_CODE HttpContent::ParseHeader() {
    int find_url = content.find(" ");
    std::string url;
    url = content.substr(0,find_url);
    std::cout << "url: " << url << std::endl;
    httprespond_.set_url(url);

    std::string method;
    int find_method = content.find(" ",find_url+1);
    method = content.substr(find_url+1,find_method-find_url-1);
    httprespond_.set_method(method);

    std::string version;
    version = content.substr(find_method+1,content.size()-find_method-3);
    httprespond_.set_version(version);

    return url=="GET"?FILE_REQUESTION:POST_FILE;

}
HttpContent::HTTP_CODE HttpContent::analyse(const TcpConnectionPtr &conn, Buffer &buffer) {
    std::cout << "address of buffer: " << &buffer << std::endl;
    //buffer.Buffer_find_str("\r\n",content);
    std::cout<<"查看转化过来的字符串: " << content << std::endl;
    status_ = HEAD;
    bool flags = true;
    while (buffer.enableRead() && flags && buffer.Buffer_find_str("\r\n",content,2)){
        std::cout<<"查看转化过来的字符串: " << content << std::endl;
        switch(status_){
            case HEAD:{
                std::cout << "解析请求行的头部\n";
                ParseHeader();
                set_status(REQUESTION);
                break;
            }
            case REQUESTION:{
                std::cout << "解析请求头字段信息\n";
                ParseRequestion();
                break;
            }
            default:{
                std::cout <<"错误输出\n";
                flags = false;
            }
        }
        content.clear();
    }
    //conn->set_Handlewrite();
    return RESULT_;

}

#endif //UNTITLED_HTTPCONTENT_H
