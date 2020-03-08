/*************************************************************************
	> File Name: 插入排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/ 8 11:31:19 2020
 ************************************************************************/

#include<iostream>
using namespace std;
void swap(int &a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    int sorts[10] = {12,43,3,65,98,0,32,12,5,1};
    int n = 10;
    for(int i=1; i<n; i++){
        int key = sorts[i];
        int j = i-1;
        while(j>=0 && sorts[j] > key){
            sorts[j+1] = sorts[j];
            j--;
        }
        sorts[j+1] = key;
    }
    for(int i=0; i<n; i++){
        std::cout << sorts[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
