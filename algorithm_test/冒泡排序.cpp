/*************************************************************************
	> File Name: 冒泡排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/ 8 11:07:31 2020
 ************************************************************************/

#include<iostream>
void swap(int &a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    int sorts[10] = {234,43,2,1,43,65,87,1,34,5};
    int n = 10;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1-i; j++){
            if(sorts[j] > sorts[j+1]){
                swap(sorts[j], sorts[j+1]);
            }
        }
    } 
    for(int i=0; i<10; i++){
        std::cout << sorts[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
