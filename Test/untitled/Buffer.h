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
#include <algorithm>
/*class Buffer{
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
    char *peek(){
        std::cout << "$$$$$$$$$$$$$readindex_\n";
        std::cout << readindex_ << std::endl;
        return (begin()+readindex_);
    }
    void update(int ret){
        if(ret < enableRead()){
            readindex_+=ret;
        }
        else{
            readindex_ = writeindex_ = 8;
        }
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
            std::cout << "make space\n";
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
        std::vector<char> bufs(8+enableRead()+reserve);
        std::copy(peek(), peek()+enableRead(), bufs.begin()+8);
        bufs.swap(buf);
        std::cout << "###!!!!!!!!!!!!!!!\n";
    }

    size_t Buffer_size(){
        return buf.size();
    }
    std::string& read_string(std::string &s1)
    {
        Buffer_str(s1);
        readindex_=8;
        writeindex_ = 8;
        return s1;
    }

    std::string &Buffer_str(std::string &s1){
        int len = writeindex_-readindex_;
        s1.clear();
        for(int i=readindex_; i<=writeindex_; i++)
        {
            s1.push_back(buf[i]);
        }
        //readindex_ = writeindex_ = 8;
        return s1;
    }
    char *begin()
    {
        std::cout << "Rrrrrrrrread: " << readindex_ << std::endl;
        return (&*buf.begin());
    }
    bool Buffer_find_str(const char *str,std::string &result,size_t len_){
        //std::cout << "读缓冲区的大小: " << enableRead() <<std::endl;
        std::string find_string;
        Buffer_str(find_string);
        int find = find_string.find(str)+len_;
        if(find-len_==0){
            return false;
        }
        if(find != find_string.npos){
            result = find_string.substr(0, find);
            std::cout << "string: " << result << std::endl;
            size_t len = result.size();
            readindex_+=len;
            if(!enableRead()){
                //此时已经将数据读完
                //std::cout << "数据已经全部取出\n";
                readindex_ = 8;
                writeindex_ = 8;
                //return true;
            }
        } else{
            //result = "\0";
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
            std::cout << "扩容\n";
            //shrink(len);
            buf.resize(len+writeindex_);

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
};*/



class Buffer {
public:
    Buffer() : _buf(INIT_SIZE) {  }
    ~Buffer() {  }
    static const size_t INIT_SIZE = 1024;
    char *begin() { return &*_buf.begin(); }
    char *peek() { return begin() + _readindex; }
    size_t prependable() const { return _readindex; }
    size_t readable() const { return _writeindex - _readindex; }
    size_t writeable() const { return _buf.size() - _writeindex; }
    void append(const char *data, size_t len)
    {
        makeSpace(len);
        std::copy(data, data + len, _buf.begin() + _writeindex);
        _writeindex += len;
    }
    // 内部腾挪
    void makeSpace(size_t len)
    {
        if (len > writeable()) {
            if (len <= writeable() + prependable()) {
                size_t readBytes = readable();
                std::copy(peek(), peek() + readBytes, begin());
                _readindex = 0;
                _writeindex = _readindex + readBytes;
            } else
                _buf.resize(_writeindex + len);
        }
    }

    std::string &Buffer_str(std::string &s1){
        int len = readable();
        s1.clear();
        for(int i=_readindex; i<=_writeindex; i++)
        {
            s1.push_back(_buf[i]);
        }
        //readindex_ = writeindex_ = 8;
        return s1;
    }
    // 返回C风格字符串
    const char *c_str()
    {
        makeSpace(1);
        _buf[_writeindex] = '\0';
        return peek();
    }
    int findStr(char *s, const char *p, size_t plen)
    {
        const char *pattern = std::search(s, begin() + _writeindex, p, p + plen);
        return pattern == begin() + _writeindex ? -1 : pattern - s;
    }
    int findStr(const char *s, size_t len)
    {
        return findStr(peek(), s, len);
    }
    // 返回\r\n在Buffer中第一次出现的位置，没出现返回-1
    int findCrlf() { return findStr("\r\n", 2); }
    int findLf() { return findStr("\n", 1); }
    // 跳过已读的数据
    void update(size_t len)
    {
        if (len < readable())
            _readindex += len;
        else
            _readindex = _writeindex = 0;
    }
    void retrieveAll() { update(readable()); }
    int readFd(int fd,int &save);
    void swap(Buffer& _buffer)
    {
        _buf.swap(_buffer._buf);
        std::swap(_readindex, _buffer._readindex);
        std::swap(_writeindex, _buffer._writeindex);
    }
    bool Buffer_find_str(const char *str,std::string &result,size_t len_){
        //std::cout << "读缓冲区的大小: " << enableRead() <<std::endl;
        std::string find_string;
        Buffer_str(find_string);
        int find = find_string.find(str)+len_;
        if(find-len_==0){
            return false;
        }
        if(find != find_string.npos){
            result = find_string.substr(0, find);
            std::cout << "string: " << result << std::endl;
            size_t len = result.size();
            _readindex+=len;
            if(readable()==0){
                _readindex = 0;
                _writeindex = 0;
            }
        } else{
            //result = "\0";
            return false;
        }
        return true;
    }
    char& operator[](size_t idx) { return _buf[idx]; }
private:
    std::vector<char> _buf;
    size_t _readindex = 0;
    size_t _writeindex = 0;
};

#endif //UNTITLED_BUFFER_H
