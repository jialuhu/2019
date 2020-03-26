/*************************************************************************
	> File Name: shared_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/26 15:25:33 2020
 ************************************************************************/

#include<iostream>
#include <memory>
using namespace std;
int main(){
    std::shared_ptr<std::string> test = make_shared<string>("hello");
    std::cout << test.use_count() << std::endl;
    std::cout << test.get() << std::endl;
    std::shared_ptr<std::string> p2 = make_shared<string>("");
    std::shared_ptr<std::string> p3 = test;
    std::cout << test.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
    std::cout << p2.get() << std::endl;
    p2 = std::move(test);
    std::cout << test.get() << std::endl;
    std::cout << test.use_count() << std::endl;
    std::cout << p2.get() << std::endl;
    std::cout << test.use_count() << std::endl;
    return 0;
}
