/*************************************************************************
	> File Name: mystrcpy.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 10:40:16 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
char* mystrcpy(char* dst, const char* src){
    assert(dst != NULL && src != NULL);
    char* ret = dst;
    while(((*dst++) = (*src++)) != '\0');
    return ret;
}
int main(){
    const char* src = "hello";
    char dst[5];
    mystrcpy(dst, src);
    std::cout << dst <<std::endl;
    return 0;
}
