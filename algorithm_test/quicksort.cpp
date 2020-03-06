/*************************************************************************
	> File Name: quicksort.cpp
	> Author: 
	> Mail: 
	> Created Time: 五  3/ 6 22:30:14 2020
 ************************************************************************/

#include<iostream>
#include<vector>
void quicksort(std::vector<int>& nums, int left, int right){
    if(left > right){
        return;
    }
    int index_number = nums[left];
    int low = left;
    int high = right;
    while(low != high){
        while(low<high && nums[high]>=index_number){
            high--;
        }
        while(low<high && nums[low] <= index_number){
            low++;
        }
        if(low < high){
            int t = nums[low];
            nums[low] = nums[high];
            nums[high] = t;
        }
    }
    nums[left] = nums[low];
    nums[low] = index_number;
    quicksort(nums, left, low-1);
    quicksort(nums, low+1, right);
}
int main(){
    std::vector<int> nums;
    for(int i=0; i<5; i++){
        int number;
        std::cin >> number;
        nums.push_back(number);
    }
    for(auto &c : nums){
        std::cout << c << " ";
    }
    std::cout << "\n";
    quicksort(nums,0,4);
    for(auto &c : nums){
        std::cout << c << " ";
    }
    return 0;
}
