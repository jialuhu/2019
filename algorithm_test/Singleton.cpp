/*************************************************************************
	> File Name: Singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 16:46:10 2020
 ************************************************************************/

#include<iostream>
#include<mutex>
using namespace std;
//饿汉模式,线程安全
class Singleton{
private:
    Singleton(){
        std::cout << "Singleton is Created\n";
    }
    //禁止生成拷贝函数
    Singleton(const Singleton& s) = delete;
    //禁止生成赋值函数
    Singleton& operator=(const Singleton& s) = delete;
    static std::shared_ptr<Singleton> mysingleton;
public:
    ~Singleton(){
        std::cout << "Singleton is destored.\n";
    }
    static std::shared_ptr<Singleton> getSingleton(){
        return mysingleton;
    }
};
//懒汉模式
class SingletonLazy{
private:
    SingletonLazy(){
        std::cout << "Singleton is Created\n";
    }
    //禁止生成拷贝函数
    SingletonLazy(const Singleton&) = delete;
    //禁止生成赋值函数
    SingletonLazy& operator=(const SingletonLazy&) = delete;
    static std::shared_ptr<SingletonLazy> mysingletonlazy;
    static std::mutex mymutex;
public:
    ~SingletonLazy(){
        std::cout << "SingletonLazy is destoied.\n";
    }
    static std::shared_ptr<SingletonLazy> getSingletonLazy(){
        if(mysingletonlazy == nullptr){
            std::lock_guard<std::mutex> lk(mymutex);
            if(mysingletonlazy == nullptr){
                mysingletonlazy = std::shared_ptr<SingletonLazy>(new SingletonLazy());
            }
        }
        return mysingletonlazy;
    }

};
/*std::shared_ptr<Singleton> Singleton::mysingleton(new Singleton());
int main(){
    shared_ptr<Singleton> c1 = Singleton::getSingleton();
    shared_ptr<Singleton> c2 = Singleton::getSingleton();
    shared_ptr<Singleton> c3 = Singleton::getSingleton();
    return 0;
}*/
std::shared_ptr<SingletonLazy> SingletonLazy::mysingletonlazy = nullptr;
std::mutex SingletonLazy::mymutex;
int main(){
    std::shared_ptr<SingletonLazy> c1 = SingletonLazy::getSingletonLazy();
    std::shared_ptr<SingletonLazy> c2 = SingletonLazy::getSingletonLazy();
    std::shared_ptr<SingletonLazy> c3 = SingletonLazy::getSingletonLazy();
    return 0;
}
