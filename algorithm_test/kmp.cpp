/*************************************************************************
	> File Name: kmp.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 21:48:21 2020
 ************************************************************************/

#include<iostream>
using namespace std;
void cal_nex(char *str, int *next, int len){
    int k = -1;
    next[0] = -1;
    for(int q = 1; q<=len-1; q++){
        while(k>-1 && str[k+1] != str[q]){
            k = next[k];
        }
        if(str[k+1] == str[q]){
            k = k+1;
        }
        next[q] = k;
    }
}
int KMP(char* str, int slen, char *ptr, int plen){
    int *next = new int[plen];
    cal_nex(ptr, next, plen);
    int k = -1;
    for(int i=0; i<slen; i++){
        while(k>-1 && ptr[k+1]!=str[i]){
            k = next[k];
        }
        if(ptr[k+1] == str[i]){
            k = k+1;
        }
        if(k == plen-1){
            return i-plen+1;
        }
    }
    return -1;
}
int main(){
    char *str = "hellotext";
    char *sstr = "tex";
    int index = KMP(str,9,sstr,3);
    std::cout << index << std::endl;   
    return 0;
}
