/*************************************************************************
	> File Name: 最长子序列.cpp
	> Author: 
	> Mail: 
	> Created Time: 四 12/19 17:07:03 2019
 ************************************************************************/

/**
 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 
 示例:
 
 输入: [10,9,2,5,3,7,101,18]
 输出: 4
 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 说明:
 
 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 你算法的时间复杂度应该为 O(n2) 。
 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 
 
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = nums.size();
        if(length<2){
            return length;
        }
        int *dp = new int[length];
        for(int i=0; i<length; i++){
            dp[i] = 1;
        }
        int Max = -1;
        for(int a=1; a<=length-1; a++){
            for(int p=0; p<a; p++){
                if(nums[p]<nums[a]){
                    dp[a] = max(dp[a],dp[p]+1);
                }
            }
            Max = max(dp[a],Max);
        }
        return Max;
    }
};
