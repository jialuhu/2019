/*************************************************************************
	> File Name: mymemccpy.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/16 14:44:34 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
void* mymemccpy(void* dst, const void* src, int c, unsigned int count){
    assert(dst != nullptr && src != nullptr);
    while(count--){
        *static_cast<char*>(dst) = *static_cast<const char*>(src);
        if(*static_cast<const char*>(src) == static_cast<char>(c)){
            return ((char*)dst+1);
        }
        dst = static_cast<char*>(dst)+1;
        src = static_cast<const char*>(src)+1;
    }
    return nullptr;
}
int main(){
    char dst[10];
    const char* src = "hellobc";
    mymemccpy(dst,src,'A',7);
    std::cout << dst << std::endl;
    return 0;
}
