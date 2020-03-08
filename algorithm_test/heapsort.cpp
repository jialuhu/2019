/*************************************************************************
	> File Name: heapsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/ 8 21:03:06 2020
 ************************************************************************/

#include<iostream>
#include<vector>
void swap(int& a,int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
void adjustheap(std::vector<int>& numbers, int root, int len){
    int left_child = 2*root+1;
    while(left_child < len){
        if(left_child+1 < len && numbers[left_child]<numbers[left_child+1]){
            left_child++;
        }
        if(numbers[left_child]<numbers[root]){
            break;
        }
        swap(numbers[root], numbers[left_child]);
        root = left_child;
        left_child = 2*root+1;
    }
}
void makeheap(std::vector<int>& numbers,int len){
    for(int i=len/2-1; i>=0; i--){
        adjustheap(numbers, i, len);
    }
}
void heapsort(std::vector<int>& numbers){
    makeheap(numbers,numbers.size());
    int len = numbers.size();
    for(int i=len-1; i>=0; i--){
        swap(numbers[0], numbers[i]);
        adjustheap(numbers,0,i);
    }
}
int main(){
    std::vector<int> numbers;
    int n = 10;
    for(int i=0; i<n; i++){
        int number;
        std::cin >> number;
        numbers.push_back(number);
    }
    heapsort(numbers);
    for(int& a : numbers){
        std::cout << a << " ";
    }
    std::cout << "\n";
    return 0;
}
