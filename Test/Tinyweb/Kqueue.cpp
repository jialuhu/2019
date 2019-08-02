//
// Created by Jialu  Hu on 2019-08-02.
//

#include "Kqueue.h"
//#include "Channel.h"
int Kqueue::kqfd = -1;

Kqueue::Kqueue(EventLoop *loop):owner_loop_(loop){
    kqfd = ::kqueue();
    assert(kqfd>0);
}

Kqueue::~Kqueue(){
    close(kqfd);
}
bool Kqueue::Register(Channel* channel,int fd) {
    std::cout << "kqfd: " << kqfd << " channel: " << channel->event() <<std::endl;
    std::cout << "fd " << fd << std::endl;
    struct kevent changes[1];
    EV_SET(&changes[0], fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    kqfds_.push_back(changes[0]);
    int idx = static_cast<int>(kqfds_.size())-1;
    channel->set_index(idx);
    channels_[fd] = channel;
    //Register 将 fd 注册到 kq 中
    // 注册的方法是通过 kevent() 将 eventlist 和 neventlist 置成 NULL 和 0 来达到的
    int ret = kevent(kqfd, changes, 1, nullptr, 0, nullptr);
    if (ret == -1){
        std::cout << ret << std::endl;
        return false;
    }
    return true;
}

bool Kqueue::Change(Channel* channel,int fd){
    struct kevent changes[1];
    if(channel->is_close()){
        if(channel->index() == (kqfds_.size()-1))
        {
            //删除vector尾元素
            kqfds_.pop_back();
        }
        else{
            int tmp_fd = kqfds_[kqfds_.size()-1].ident;
            int tmp_index = channel->index();
            iter_swap(kqfds_.begin()+channel->index(), kqfds_.end()-1);
            kqfds_.pop_back();
            channels_[tmp_fd]->set_index(tmp_index);
        }
        channels_.erase(channel->fd());
        EV_SET(&changes[0], fd, channel->event(), EV_DELETE, 0, 0, NULL);
    }
    else{
        EV_SET(&changes[0], fd, channel->event(), EV_ADD, 0, 0, NULL);
    }
    int ret = kevent(kqfd, changes, 1, nullptr, 0, nullptr);
    if (ret == -1) {
        std::cout << ret << std::endl;
        return false;
    }
    return true;

}

void Kqueue::updateChannel(Channel* channel) {
    int idx = channel->index();
    int kfd = channel -> fd();
    if(idx<0){
        assert(channels_.find(kfd) == channels_.end());
        //该事件还未出现在事件注册表中,如新建立的链接
        //对该事件进行注册
        assert(Register(channel,kfd)==true);
    }
        //更新事件表
    else{
        assert(channels_.find(kfd)!=channels_.end());
        assert(channels_[kfd]==channel);
        assert(idx>=0 && idx<kqfds_.size());
        //更新事件表
        assert(Change(channel,kfd)==true);
    }
}
const int MAX_EVENT_COUNT = 5000;
void Kqueue::kqueue(int timeout, std::vector<Channel*> *activeChannel){
    //std::vector<struct kevent> krevents[MAX_EVENT_COUNT];
    struct kevent krevents[MAX_EVENT_COUNT];
    std::cout << "测试vector的krevents\n";
    int ret = ::kevent(kqfd, nullptr, 0, krevents, MAX_EVENT_COUNT, nullptr);
    if(ret>0) {
        std::cout << "ret: " << ret << std::endl;
        for (int i=0; i<ret; i++) {
            int socketfd = krevents[i].ident;
            std::cout << "ident: " << krevents[i].ident << std::endl;
            int datacount = krevents[i].data;
            int setrv = krevents[i].filter;
            assert(channels_.find(socketfd) != channels_.end());
            auto actChannel = channels_[socketfd];
            assert(actChannel->fd() == socketfd);
            actChannel->set_revent(setrv);
            activeChannel->push_back(actChannel);
        }
    }
    else if(ret==0){
        std::cout << "Nothing happend\n";
    }
    else{
        std::cout << "Kqueue::kqueue\n";
    }

}
