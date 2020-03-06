/*************************************************************************
	> File Name: mystrncpy.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 10:59:59 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
char* mystrncpy(char* dst, const char* src, size_t n){
    assert(dst!=NULL && src!=NULL);
    char* ret = dst;
    while((n--) && *src!='\0'){
        *dst = *src;
        dst++;
        src++;
    }
    if(n>0){
        while(n--){
            *dst++ = '\0';
        }
    }
    *dst = '\0';
    return ret;
}
int main(){
    const char *src = "hello";
    char dst[6];
    strncpy(dst, src, 20);
    //mystrncpy(dst, src, 3);
    std::cout << strlen(dst) << std::endl;
    std::cout << dst << std::endl;
    return 0;
}
