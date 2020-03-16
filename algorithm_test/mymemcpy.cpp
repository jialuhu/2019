/*************************************************************************
	> File Name: mymemcpy.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/16 14:30:35 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
void* mymemcpy(void* dst, const void* src, unsigned int count){
    assert(src!=nullptr && dst!=nullptr);
    void* res = dst;
    while(count-- && *(char*)src != '\0'){
        *static_cast<char*>(dst) = *static_cast<const char*>(src);
        dst = static_cast<char*>(dst)+1;
        src = (char*)(src)+1;
    }
    return res;
}

int main(){
    char res[10];
    const char* src = "hello";
    //mymemcpy(res,src,5);
    memcpy(res,src,5);
    std::cout << res << std::endl;
    return 0;
}
