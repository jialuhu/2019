/*************************************************************************
	> File Name: 全排列.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 12/21 19:20:59 2019
 ************************************************************************/

/**
 给定一个没有重复数字的序列，返回其所有可能的全排列。
 
 示例:
 
 输入: [1,2,3]
 输出:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/permutations
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> res;
        int len = nums.size();
        vector<bool> flag(len, false);
        return HDFS(result,res,flag,nums,0,len);
    }
    
    vector<vector<int>> HDFS(vector<vector<int>> &result, vector<int> &res, vector<bool> &flag, vector<int>&nums, int deepth, int len){
        if(deepth == len){
            result.push_back(res);
        }
        for(int i=0; i<len; i++){
            if(!flag[i])//没有被访问到
            {
                flag[i] = true;
                res.push_back(nums[i]);//加入节点
                HDFS(result,res,flag,nums,deepth+1,len);//对改节点进行遍历
                res.pop_back();//然后回退到上一层
                flag[i] = false;
            }
        }
        return result;
    }
};
