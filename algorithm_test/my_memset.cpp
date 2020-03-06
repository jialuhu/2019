/*************************************************************************
	> File Name: my_memset.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 09:59:21 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
void* mymemset(void* dst, const void* src, size_t count){
    std::cout << "s: " << strlen((char*)dst) << std::endl;
    //判断是否为空指针
    assert(dst!=NULL && src != NULL);
    void* ret = dst;
    //判断是否有内存重叠
    if(dst >= src || (char*)dst >= (char*)src + count){
        while(count--){
            std::cout << "count: " << count << std::endl;
           *(char*)dst = *(char*)src;
            dst = (char*)dst+1;
            src = (char*)src+1;
        }
    }else{
        dst = (char*)dst + count - 1;
        src = (char*)src + count - 1;
        while(count--){
            *(char*)dst = *(char*)src;
            dst = (char*)dst-1;
            src = (char*)src-1;
        }

    }
    return ret;
}
int main(){
    const char *src="hello";
    char dst[6];
    std::cout << "strlensrc: " << strlen(src) << std::endl;
    mymemset(dst, src, strlen(src));
    std::cout << "strlen: " << strlen(dst) << std::endl;
    dst[5] = '\0';
    std::cout << dst << std::endl;
    return 0;
}
