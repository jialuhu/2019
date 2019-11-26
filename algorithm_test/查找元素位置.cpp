/*************************************************************************
	> File Name: 查找元素位置.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 11/26 21:33:32 2019
 ************************************************************************/

/**
 *给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 
 你的算法时间复杂度必须是 O(log n) 级别。
 
 如果数组中不存在目标值，返回 [-1, -1]。
 
 示例 1:
 
 输入: nums = [5,7,7,8,8,10], target = 8
 输出: [3,4]
 示例 2:
 
 输入: nums = [5,7,7,8,8,10], target = 6
 输出: [-1,-1]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*线性查找*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        int end=0;
        int start=0;
        int len = nums.size();
        for(int i=0; i<len; i++){
            if(target!=nums[i] && end==0){
                ++start;
            }else if(target==nums[i]){
                ++end;
            }else{
                break;
            }
        }
        if(end != 0){
            result[0]=start;
            result[1]=start+end-1;
            return result;
        }
        result[0]=-1;
        result[1]=-1;
        return result;
    }
};
