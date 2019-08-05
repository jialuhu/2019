//
// Created by Jialu  Hu on 2019-08-04.
//

#include "Buffer.h"
Buffer::Buffer() :buf(1032),readindex_(8),writeindex_(8)
{

}

Buffer::~Buffer() {

}

size_t Buffer::ReadFd(int fd, int &saveErrno) {
    char extrabuf[6868];
    struct iovec vec[2];
    const size_t writable = enableWrite();
    vec[0].iov_base = &*buf.begin()+writeindex_;
    vec[0].iov_len = writable;
    vec[1].iov_base = extrabuf;
    vec[1].iov_len = sizeof extrabuf;
    const ssize_t n = readv(fd, vec, 2);
    if (n < 0) {
        saveErrno = errno;
    } else if (n <= writable) {
        writeindex_ += n;
    } else {
        writeindex_ = buf.size();
        append(extrabuf, n - writable);
    }
    return n;

}