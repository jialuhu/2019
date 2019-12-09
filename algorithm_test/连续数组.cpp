/*************************************************************************
	> File Name: 连续数组.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 12/ 9 22:44:47 2019
 ************************************************************************/

/**
 给定一个二进制数组, 找到含有相同数量的 0 和 1 的最长连续子数组。
 
 示例 1:
 
 输入: [0,1]
 输出: 2
 说明: [0, 1] 是具有相同数量0和1的最长连续子数组。
 示例 2:
 
 输入: [0,1,0]
 输出: 2
 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 注意: 给定的二进制数组的长度不会超过50000。
 **/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mymap{{0,-1}};
        int len = nums.size();
        int sum = 0;
        int result = 0;
        for(int i=0; i<len; i++){
            if(nums[i]==0){
                sum += (-1);
            }else{
                sum += 1;
            }
            if(mymap.count(sum)){
                result = max(result,i-mymap[sum]);
            }else{
                mymap[sum] = i;
            }
        }
        return result;
    }
};
