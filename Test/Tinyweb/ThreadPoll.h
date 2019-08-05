//
// Created by Jialu  Hu on 2019-08-04.
//

#ifndef UNTITLED_THREADPOLL_H
#define UNTITLED_THREADPOLL_H
#include<pthread.h>
#include <list>
template<typename T>
/*线程池的封装*/
class threadpool
{
private:
    int max_thread;//线程池中的最大线程总数
    int max_job;//工作队列的最大总数
    pthread_t *pthread_poll;//线程池数组
    std::list<T*> m_myworkqueue;//请求队列
    mylocker m_queuelocker;//保护请求队列的互斥锁
    sem m_queuestat;//由信号量来判断是否有任务需要处理
    bool m_stop;;//是否结束线程
public:
    threadpool();
    ~threadpool();
    bool addjob(T* request);
private:
    static void* worker(void *arg);
    void run();
};
#endif //UNTITLED_THREADPOLL_H
