//
// Created by Jialu  Hu on 2019-08-04.
//

#ifndef UNTITLED_BUFFER_H
#define UNTITLED_BUFFER_H

#include <vector>
#include <sys/uio.h>
#include <errno.h>
#include <assert.h>
#include <string>
#include <cstring>
#include <iostream>
class Buffer{
public:
    Buffer();
    ~Buffer();
    size_t ReadFd(int fd, int &saveErrno);
    //可以读取的字节数
    size_t enableRead() const{
        return (writeindex_-readindex_);
    }
    //可以写入Buffer的剩余空间
    size_t enableWrite() const{
        return (buf.size()-writeindex_);
    }
    //read指针，从哪开始读
    const char *peek(){
        return (&*buf.begin())+readindex_;
    }
    //write指针,即从哪开始写
    const char *writebegin() const{
        return (&*buf.begin()+writeindex_);
    }
    char *writebegin(){
        return (&*buf.begin()+writeindex_);
    }
    //Buffer头部挪空的字节数
    size_t prependableBytes() const{
        return readindex_;
    }
    void ensureWritableBytes(size_t len)
    {
        if (enableWrite() < len)
        {
            makeSpace(len);
        }
        assert(enableWrite() >= len);
    }
    void append(char *bufs, size_t len){
        ensureWritableBytes(len);
        std::copy(bufs,bufs+len,writebegin());
        writeindex_ = writeindex_ + len;
    }
    void prepend(const void* data, size_t len)
    {
        assert(len <= prependableBytes());
        readindex_ -= len;
        const char* d = static_cast<const char*>(data);
        std::copy(d, d+len, &*buf.begin()+readindex_);
    }

    void shrink(size_t reserve)
    {
        std::vector<char> buf(8+enableRead()+reserve);
        std::copy(peek(), peek()+enableRead(), buf.begin()+8);
        buf.swap(buf);
    }

    size_t Buffer_size(){
        return buf.size();
    }

    std::string &Buffer_str(std::string &s1){
        int len = writeindex_-readindex_;
        char *str;
        str = new char[len+1];
        s1.clear();
        std::copy(buf.begin()+readindex_,buf.begin()+writeindex_,str);
        s1 = s1+str;
        return s1;
    }

    bool Buffer_find_str(const char *str,std::string &result,size_t len_){
        std::cout << "读缓冲区的大小: " << enableRead() <<std::endl;
        std::string find_string;
        Buffer_str(find_string);
        int find = find_string.find(str)+len_;
        if(find != find_string.npos){
            result = find_string.substr(0, find);
            size_t len = result.size();
            readindex_+=len;
            if(!enableRead()){
                //此时已经将数据读完
                std::cout << "数据已经全部取出\n";
                readindex_ = 8;
                writeindex_ = 8;
                //return true;
            }
        } else{
            result = "\0";
            return false;
        }
        return true;
    }

    void Buffer_display(){
        for(auto &i : buf){
            std::cout << i;
        }
    }
private:
    void makeSpace(size_t len){
        if(enableWrite()+prependableBytes() < len+8){
            //空间不够挪腾，只能进行扩容
            shrink(len);

        } else{
            size_t readable = enableRead();
            std::copy(&*buf.begin()+readindex_,
                      &*buf.begin()+writeindex_,
                      &*buf.begin()+8);
            readindex_ = 8;
            writeindex_ = readindex_ + readable;
            assert(readable == enableRead());
        }
    }
    std::vector<char> buf;
    size_t readindex_;
    size_t writeindex_;
};
#endif //UNTITLED_BUFFER_H