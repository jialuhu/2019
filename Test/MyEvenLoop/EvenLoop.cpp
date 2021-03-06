/*************************************************************************
	> File Name: EvenLoop.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  7/29 10:37:31 2019
 ************************************************************************/

#include <iostream>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <mutex>
#include <memory>
#include <map>
#include <vector>
#include <assert.h>
#include <poll.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/event.h>
#include <fcntl.h>
#include <sys/stat.h>
#include  <boost/function.hpp>
class Channel;
class Poller;
class EventLoop{
public:
    EventLoop();
    ~EventLoop();
    
    void loop();
    void quit();
    void updateChannel(Channel* channel);
    
private:
    //std::__thread_id _tid;
    std::unique_ptr<Poller> _poller;
    // 事件与对应的fd表
   // std::map<int, std::shared_ptr<Channel> > _channelMaps;
    // 活跃事件触发表
    //std::vector<std::shared_ptr<Channel> > _activeChannels;
    std::vector<Channel*> _activeChannels;
    bool _quit;
    bool _looping;
};

class Channel //: boost::noncopyable
{
private:
    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;
public:
    typedef boost::function<void()> EventCallback;
    
    Channel(EventLoop* loop, int fd);
    
    void handleEvent();
    void setReadCallback(const EventCallback& cb)
    { readCallback_ = cb; }
    void setWriteCallback(const EventCallback& cb)
    { writeCallback_ = cb; }
    void setErrorCallback(const EventCallback& cb)
    { errorCallback_ = cb; }
    
    int fd() const { return fd_; }
    int events() const { return events_; }
    void set_revents(int revt) { revents_ = revt; }
    bool isNoneEvent() const { return events_ == kNoneEvent; }
    
    void enableReading() { events_ |= POLLIN|POLLPRI; /*std::cout << "hujialu\;*/update(); }
    // void enableWriting() { events_ |= kWriteEvent; update(); }
    // void disableWriting() { events_ &= ~kWriteEvent; update(); }
    // void disableAll() { events_ = kNoneEvent; update(); }
    
    // for Poller
    int index() { return index_; }
    void set_index(int idx) { index_ = idx; }
    
    EventLoop* ownerLoop() { return loop_; }
    
private:
    void update();
    
   /* static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;*/
    
    EventLoop* loop_;
    const int  fd_;
    int        events_;
    int        revents_;
    int        index_; // used by Poller.
    
    EventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback errorCallback_;
};

const int kNoneEvent = 0;
const int kReadEvent = POLLIN | POLLPRI;
const int kWriteEvent = POLLOUT;
//Channel事件构造函数
Channel::Channel(EventLoop* loop, int fd)
:loop_(loop),fd_(fd),events_(0),revents_(0),index_(-1){
    
}
//更新事件表
void Channel::update()
{
    std::cout << "jialuhu\n";
    loop_ -> updateChannel(this);
}

void Channel :: handleEvent(){
    if(revents_&(POLLERR | POLLNVAL)){
        if (errorCallback_) errorCallback_();
    }
    if(revents_&(POLLIN|POLLPRI|POLLHUP)){
        if(readCallback_) readCallback_();
    }
    if(revents_ & POLLOUT){
        if(writeCallback_) writeCallback_();
    }
}

class Poller //: boost::noncopyable
{
public:
    typedef std::vector<Channel*> ChannelList;
    
    Poller(EventLoop* loop);
    ~Poller();
    
    /// Polls the I/O events.
    /// Must be called in the loop thread.
    void poll(int timeoutMs, ChannelList* activeChannels);
    
    /// Changes the interested I/O events.
    /// Must be called in the loop thread.
    void updateChannel(Channel* channel);
    
    //void assertInLoopThread() { ownerLoop_->assertInLoopThread(); }
    
private:
    void fillActiveChannels(int numEvents,
                            ChannelList* activeChannels) const;
    
    typedef std::vector<struct pollfd> PollFdList;
    typedef std::map<int, Channel*> ChannelMap;
    
    EventLoop* ownerLoop_;
   // std::vector<struct pollfd> pollfds_;
    PollFdList pollfds_;
    ChannelMap channels_;
    std::vector<int> vi;

};

Poller :: Poller(EventLoop* loop) : ownerLoop_(loop){
   vi.push_back(1); 
}

Poller :: ~Poller(){

}

void Poller :: fillActiveChannels(int numEvents,
    ChannelList* activeChannels) const{
    for(auto pfd = pollfds_.begin(); pfd != pollfds_.end(); pfd++)
    {
        if(pfd -> revents > 0)
        {
            --numEvents;
            //通过pfd返回对应的事件类型
            ChannelMap::const_iterator ch = channels_.find(pfd->fd);
            assert(ch != channels_.end());
            Channel* now_channel = ch->second;
            assert(now_channel->fd()==pfd->fd);
            now_channel->set_revents(pfd->revents);
            activeChannels->push_back(now_channel);

        }
    }
}

void Poller::updateChannel(Channel *channel)
{
    if(channel->index() < 0){
        assert(channels_.find(channel->fd())==channels_.end());
        struct pollfd pfd;
        pfd.fd = channel->fd();
         pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        std::cout << "^^^^**\n";
        pollfds_.push_back(pfd);
        std::cout << "^^^^**\n" << pollfds_.size()<<std::endl;
        int idx = static_cast<int>(pollfds_.size()-1);
        channel->set_index(idx);
        channels_[pfd.fd] = channel;
    }
    else{
        assert(channels_.find(channel->fd())!=channels_.end());
        assert(channels_[channel->fd()]==channel);
        int idx = channel->index();
        struct pollfd pfd;
        pollfds_[idx].events = static_cast <short>(channel->events());
        pollfds_[idx].revents = 0;
        /*if(channel->isNoneEvent()){
            pollfds_[idx].fd = -1;
        }*/
    }
}

void Poller :: poll(int timeoutMs, ChannelList* activeChannels)
{
    int numEvents = ::poll(&*pollfds_.begin(), pollfds_.size(),timeoutMs);
    if(numEvents > 0){
        std::cout << "numEvents is " << numEvents << std::endl;
        fillActiveChannels(numEvents, activeChannels);
    }
    else{
        std::cout << "nothing happend\n";
    }
}


thread_local EventLoop *_thisThreadLoop = nullptr;

EventLoop :: EventLoop()
: _looping(false), _quit(false),_poller(new Poller(this)){
    std::cout << "EvenLoop Created "  << " in thread " << std::endl;
    if(_thisThreadLoop)
    {
        std::cout << "Another EvenLoop exits in this thread\n";
    }
    else{
        std::cout << "this thread is exits\n";
        _thisThreadLoop = this;
    }
   // _poller = new Poller;
}

EventLoop :: ~EventLoop()
{
    std::cout << _looping <<"\n";
    assert(!_looping);
    _thisThreadLoop = nullptr;
}

void EventLoop :: quit()
{
    _quit = true;
    //wakeup;
}



void EventLoop :: updateChannel(Channel *channel)
{
    //检查该事件的Evenloop是否是本对象
    assert(channel->ownerLoop() == this);
    std::cout << "EventLoop update\n";
    //assertInLoopThread();
    _poller -> updateChannel(channel);
}

void EventLoop :: loop()
{
    assert(!_looping);
    _looping = true;
    _quit = false;
    while(!_quit){
        _activeChannels.clear();
        _poller->poll(-1,&_activeChannels);
        for(auto it=_activeChannels.begin(); it!=_activeChannels.end(); it++)
        {
            (*it) -> handleEvent();
        }
    }
    _looping = false;
}

EventLoop* g_loop;
void fun()
{
    std::cout << "hello\n";
    g_loop->quit();
}


int main()
{
    int kqfd = kqueue();
    int fd = open("1.txt",O_RDWR);
    /*struct kevent changes[1];
    EV_SET(&changes[0], fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    int ret = kevent(kqfd, changes, 1, nullptr, 0, nullptr);
    if (ret == -1){
        std::cout << ret << std::endl;
    }*/
    if(fd < 0){
        std::cout << "&&&\n";
        return 0;
    }
    else{
        std::cout << fd << std::endl;
    }
    close(fd);
}
