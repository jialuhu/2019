//
// Created by Jialu  Hu on 2019-08-03.
//
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <assert.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
int main()
{
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(8888);
    client.sin_addr.s_addr = htons(INADDR_ANY);
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    int i=0;

    if(fd>0){
        int ret = connect(fd, (
        struct sockaddr*)&client, sizeof(struct sockaddr_in));
        if(ret!=-1){
            char buf[300];
            strcpy(buf,"hello word");
            int n = write(fd, buf,13);
            if(n>0){
                std::cout << buf << std::endl;
            }
           /* char bufs[1000];
            if((n=read(fd,bufs,1000))){
                std::cout << "bufs: " << bufs << std::endl;
            }
            //std::cout << "bufs: " << bufs << std::endl;*/
           //sleep()
        }
    }
    close(fd);

}
