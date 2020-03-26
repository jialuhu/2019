/*************************************************************************
	> File Name: nullptrclass.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/26 17:04:16 2020
 ************************************************************************/
#include<iostream>
#include <memory>
class TestA{
public:
    TestA() : /*a(4)*/{
    }
    ~TestA(){
        
    }
    void printTestA(){
        //std::cout << "a: " << a << std::endl;
        std::cout << "nullptr can callable." << std::endl;
    }
    
    /*private:
     int a;*/
};

int main(){
    TestA *p = nullptr;
    p->printTestA();
    return 0;
}

