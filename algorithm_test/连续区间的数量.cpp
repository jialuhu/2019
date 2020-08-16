/*************************************************************************
	> File Name: 连续区间的数量.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/16 17:28:20 2020
 ************************************************************************/

/**
* 长度为 n 的数组，数组中每个元素 a 满足：1<=a<=n
* 求连续区间的数量，要求区间中相同元素的数量 >=m
* 例如：
* 5 2
* 1 2 1 5 2
* 4
* 可以有4种可能：[1,3]，[1,5]，[2,5]，[1,4]`*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int n = 0;
    int m = 0;
    cin >> n;
    cin >> m;
    vector<int> nums;
    vector<vector<int> > result;
    map<int, vector<int> > nums_map;
    for(int i=0; i<n; i++){
        int number;
        std::cin >> number;
        nums.push_back(number);
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(nums_map.count(nums[i])){
            if(nums_map[nums[i]].size()+1 >= m){
                for(int j=i; j<n; j++){
                    vector<int> res;
                    res.push_back(nums_map[nums[i]][0]);
                    res.push_back(j);
                    result.push_back(res);
                    std::cout << res[0] << " " << res[1] << std::endl;
                }
                nums_map[nums[i]].push_back(i);
            }
        }
        else{
            vector<int> res;
            res.push_back(i);
            nums_map[nums[i]] = res;
        }
    }
    /*int r = result.size();
    int c = result[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    A
    }*/
    std::cout << result.size() << std::endl; 
    return 0;
}
