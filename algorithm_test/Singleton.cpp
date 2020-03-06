/*************************************************************************
	> File Name: Singleton.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 16:46:10 2020
 ************************************************************************/

#include<iostream>
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
std::shared_ptr<Singleton> Singleton::mysingleton(new Singleton());
int main(){
    shared_ptr<Singleton> c1 = Singleton::getSingleton();
    shared_ptr<Singleton> c2 = Singleton::getSingleton();
    shared_ptr<Singleton> c3 = Singleton::getSingleton();
    return 0;
}
