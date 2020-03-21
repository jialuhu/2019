/*************************************************************************
	> File Name: Shared_ptr.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  3/21 13:55:39 2020
 ************************************************************************/

#include<iostream>
template<class T>
class Shared_ptr{
public:
    Shared_ptr() : _ptr(nullptr), _count(nullptr){

    }
    Shared_ptr(T* p) : _ptr(p),_count(new int(1)){
        
    }
    Shared_ptr(const Shared_ptr<T>& org){
        _ptr = org._ptr;
        _count = org._count;
        ++(*_count);
    }
    Shared_ptr<T>& operator=(const Shared_ptr<T>& rhs){
        ++(*rhs._count);
        if(--(*_count)==0){
            delete _ptr;
            _ptr = nullptr;
            delete _count;
            _count = nullptr;
        }
        _ptr = rhs._ptr;
        _count = rhs._count;
        return *this;
    }
    ~Shared_ptr(){
        std::cout << "析构函数\n";
        if(--(*_count)==0){
            delete _ptr;
            _ptr = nullptr;
            delete _count;
            _count = nullptr;
        }
    }
    T& operator*(){
        return *_ptr;
    }
    T* operator->(){
        return _ptr;
    }
    int getcount(){
        return *_count;
    }
    T* get() const{
        return _ptr;
    }
private:
    T* _ptr;
    int* _count;
};

int main(int argc, const char * argv[])
{
    Shared_ptr<std::string> pstr(new std::string("abc"));
    std::cout << pstr.getcount() << std::endl;
    Shared_ptr<std::string> pstr2(pstr);
    std::cout << pstr.getcount() << std::endl;
    std::cout << pstr2.getcount() << std::endl;
    Shared_ptr<std::string> pstr3(new std::string("hao"));
    pstr3 = pstr2;    
    return 0;

}
