/*************************************************************************
	> File Name: mystrstr.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 13:06:23 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
#include<string.h>
#include<xlocale.h>
char* mystrstr(const char* strSrc, const char *str){
    assert(strSrc!=NULL && str!=NULL);
    const char* s = strSrc;
    const char* t = str;
    for(;*strSrc!='\0';strSrc++){
        for(s=strSrc,t=str; *s==*t && *t!='\0'; s++,t++){

        }
        if(*t=='\0'){
            return (char*)strSrc;
        }
    }
    return NULL;
}
int main(){
    const char* strSrc = "hello";
    const char* str = "llo";
    //const char *ch = strstr(strSrc,str);
    char *ch = mystrstr(strSrc,str);
    std::cout << ch << std::endl;
    return 0;
}
