//
// Created by Jialu  Hu on 2019-08-04.
//

#include "Buffer.h"
/*Buffer::Buffer() :buf(1023),readindex_(0),writeindex_(0)
{

}

Buffer::~Buffer() {

}

size_t Buffer::ReadFd(int fd, int &saveErrno) {
    char extrabuf[68680];
    struct iovec vec[2];
    const size_t writable = enableWrite();
    std::cout << "ablewrite is <<<< "<< writable <<std::endl;
    vec[0].iov_base = begin()+readindex_+writeindex_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof extrabuf;
    const ssize_t n = readv(fd, vec, 2);
    std::cout << "readv is <<<< "<< n <<std::endl;
    if (n < 0) {
        saveErrno = errno;
    } else if (n <= writable) {
        writeindex_ += n;
    } else {
        writeindex_ = buf.size();
        append(extrabuf, n - writable);
    }
    return n;
}*/





// 将fd中的数据读到Buffer中
int Buffer::readFd(int fd, int &save)
{
    char extrabuf[65536];
    struct iovec iov[2];
    size_t writen = writeable();
    ssize_t n;

    iov[0].iov_base = begin() + _writeindex;
    iov[0].iov_len = writen;
    iov[1].iov_base = extrabuf;
    iov[1].iov_len = sizeof(extrabuf);

    if ((n = readv(fd, iov, 2)) > 0) {
        if (n <= writen)
            _writeindex += n;
        else {
            _writeindex += writen;
            append(extrabuf, n - writen);
        }
    }
    return n;
}

