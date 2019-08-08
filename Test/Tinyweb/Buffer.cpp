//
// Created by Jialu  Hu on 2019-08-04.
//

#include "Buffer.h"
Buffer::Buffer() :buf(1023),readindex_(8),writeindex_(8)
{

}

Buffer::~Buffer() {

}

size_t Buffer::ReadFd(int fd, int &saveErrno) {
    char extrabuf[108680];
    struct iovec vec[2];
    const size_t writable = enableWrite();
    std::cout << "ablewrite is <<<< "<< writable <<std::endl;
    vec[0].iov_base = &*buf.begin()+writeindex_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof extrabuf;
    const ssize_t n = readv(fd, vec, 2);
    std::cout << "readv is <<<< "<< n <<std::endl;

    if (n < 0) {
        saveErrno = errno;
    } else if (n <= writable) {
        std::cout << "readv is <<<< "<< writable <<std::endl;
        writeindex_ += n;
    } else {
        writeindex_ = buf.size();
        append(extrabuf, n - writable);
    }
    return n;
}
