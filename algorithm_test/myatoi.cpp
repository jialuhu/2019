/*************************************************************************
	> File Name: myatoi.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 14:42:45 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
int isspace(char ch){
    if(ch == ' ' || ch=='\t' || ch=='\n' || ch=='\r'){
        return 1;
    }
    return 0;
}

int isdigital(char ch){
    if(ch >= '0' && ch <= '9'){
        return 1;
    }
    return 0;
}

int myaoti(const char* str){
    assert(str!=NULL);
    int sum = 0;
    char sign;
    while(isspace((unsigned char)*str)){
        str++;
    }
    int c = (int)(unsigned char)*str;
    sign = (unsigned char)*str;
    if(c=='-' || c=='+'){
        str++;
    }
    while(isdigital((unsigned char)*str)){
        sum = 10*sum+(unsigned char)*str-'0';
        str++;
    }
    if(sign=='-'){
        return -sum;
    }
    return sum;
}
int main(){
    const char* number = "1234";
    int sum = myaoti(number);
    std::cout << sum << std::endl;
    return 0;
}
