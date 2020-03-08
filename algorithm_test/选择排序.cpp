/*************************************************************************
	> File Name: 选择排序.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/ 8 11:21:04 2020
 ************************************************************************/
#include<iostream>
using namespace std;
void swap(int &a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
int main(){
    int sorts[10]={34,354,23,2,4,6,45,98,67,0};
    int min = sorts[0];
    int n = 10;
    for(int i=0; i<n; i++){
        min = sorts[i];
        for(int j = i+1; j<n; j++){
            if(sorts[i] > sorts[j]){
                min = sorts[j];
            }
        }
        if(min != i){
            swap(sorts[i], sorts[min]);
        }
    }
    for(int i=0; i<n; i++){
        std::cout << sorts[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
