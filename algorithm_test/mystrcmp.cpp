/*************************************************************************
	> File Name: mystrcmp.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 11:09:22 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
int mystrcmp(const char* s, const char* t){
    assert(s != NULL && t != NULL);
    while(*s && *t && *s==*t){
        s++;
        t++;
    }
    return((*s) - (*t));
}
int main(){
    const char *s = "hello";
    const char *t = "hello";
    int diff = mystrcmp(s,t);
    std::cout << diff << std::endl;
    return 0;
}
