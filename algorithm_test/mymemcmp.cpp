/*************************************************************************
	> File Name: mymemcmp.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/16 15:49:47 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
using namespace std;
int mymemcmp(const void* s, const void* t, unsigned int count){
    assert(s != nullptr && t != nullptr);
    while(*static_cast<const char*>(s) && *static_cast<const char*>(t) && 
          *static_cast<const char*>(s)==*static_cast<const char*>(t) && count--){
        s = static_cast<const char*>(s) + 1;
        t = static_cast<const char*>(t) + 1;
    }
    return (*static_cast<const char*>(s)-(*static_cast<const char*>(t)));
}
int main(){

}
