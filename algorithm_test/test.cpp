/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/ 8 20:10:43 2020
 ************************************************************************/

#include<iostream>
#include <vector>
using namespace std;
void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void foldednumber(vector<int>& numbers, int folder){
    int len = numbers.size();
    if(folder < 0 || folder >= len){
        return;
    }/*else if(folder==0){
        int tmp = numbers[0];
        for(int i=len-1; i>=0; i++){
            numbers[i] = tmp;
            tmp = 
        }
    }*/
    int start = 0;
    int end = len-1;
    if(folder == 0){
        start = 0;
        end = len-1;
    }else if(folder*2 > len-1){
        end = len-1;
    }else{
        end = folder*2;
    }
    while(start != end){
        if(start < end){
            swap(numbers[start],numbers[end]);
            start++;
            end--;
        }else{
            break;
        }
    }
}

int main(){
    vector<int> numbers;
    int n;
    std::cin >> n;
    for(int i=0; i<n; i++){
        int nm;
        std::cin >> nm;
        numbers.push_back(nm);
    }
    int folder;
    std::cin >> folder;
    foldednumber(numbers,folder);
    for(int &i : numbers){
        std::cout << i << " "; 
    }
    std::cout << "\n";
    return 0;
}
