/*************************************************************************
	> File Name: resizetest.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/26 19:24:31 2020
 ************************************************************************/

#include<iostream>
#include <memory>
#include <vector>

int main(){
    std::vector<int> test;
    for(int i=0; i<10; i++){
        test.push_back(i);
        std::cout << "test capacity: " << test.capacity()  << " test.size(): " << test.size() << std::endl;
    }
    std::cout << "test.capacity: " << test.capacity() << std::endl;
    test.reserve(8);
    test.resize(5,0);
    std::cout << "resize(): " << test.size() << std::endl;
    std::cout << "reserve capacity: " << test.capacity() << std::endl;
    return 0;
}
