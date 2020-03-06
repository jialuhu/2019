/*************************************************************************
	> File Name: mystrcat.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 11:53:35 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
char *mystrcat(char* dst, const char* src){
    char* ret = dst;
    assert(dst!=NULL && src!=NULL);
    while(*dst != '\0'){
        dst++;
    }
    while((*dst = *src) != '\0'){
        src++;
        dst++;
    }
    return ret;
}
int main(){
    char dst[10]={'a','a'};
    const char* src="hello";
    mystrcat(dst, src);
    std::cout << dst << std::endl;
    return 0;
}
