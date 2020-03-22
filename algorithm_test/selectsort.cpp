/*************************************************************************
	> File Name: selectsort.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/22 10:13:56 2020
 ************************************************************************/

#include<iostream>
#include<vector>
void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}
void selectsort(std::vector<int>& nums){
    int len = nums.size();
    for(int i=1; i<len; i++){
        int select = i-1;
        int number = nums[i];
        while((select>=0) && number < nums[select]){
            nums[select+1] = nums[select];
            select--;
        }
        select++;
        nums[select] = number;
    }
}
int main(){
    std::vector<int> nums;
    for(int i=0; i<5; i++){
        int number;
        std::cin >> number;
        nums.push_back(number);
    }
    selectsort(nums);
    for(auto &x : nums){
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}
