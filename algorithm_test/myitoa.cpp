/*************************************************************************
	> File Name: myitoa.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 15:27:26 2020
 ************************************************************************/

#include<iostream>
#include<assert.h>
//整数转化为字符串存入str
void myitoa(int n, char* str){
    int count = 0;
    int tmp = n>=0?n:-n;
    bool sign = false;
    if(n < 0){
        sign = true;
    }
    n = tmp;
    while(tmp){
        tmp = tmp/10;
        count++;
    }
    char *buf = new char[count+2];
    for(int i=0; i<count; i++){
        buf[i] = '0';
    }
    int k = 0;
    while(n){
        buf[k] = n%10 + '0';
        std::cout << buf[k] << "*";
        n = n/10;
        k++;
    }
    int start = 0;
    if(sign){
        buf[k++] = '-';
    }else{
        start = 1;
    }
    buf[k] = '\0';
    std::cout << buf << std::endl;
    for(int i=k-1; i>=0; i--){
        *str = buf[i];
        str++;
    }
    *str = '\0';
    delete [] buf;
}
int main(){
    int n = -1234;
    char ch[6];
    myitoa(n, ch);
    std::cout << ch << std::endl;
    return 0;
}
