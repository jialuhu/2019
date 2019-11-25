/*************************************************************************
	> File Name: 搜索旋转排序数组.cpp
	> Author: 
	> Mail: 
	> Created Time: 一 11/25 23:20:07 2019
 ************************************************************************/
/**
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 
 ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 
 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 
 你可以假设数组中不存在重复的元素。
 
 你的算法时间复杂度必须是 O(log n) 级别。
 
 示例 1:
 
 输入: nums = [4,5,6,7,0,1,2], target = 0
 输出: 4
 示例 2:
 
 输入: nums = [4,5,6,7,0,1,2], target = 3
 输出: -1
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(low <= high){
            mid = (low+high)>>1;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid])//有序部分
            {
                if(target>nums[mid] || target<nums[low]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else if(nums[low]>nums[mid]){//包含选择轴部分
                if(target<nums[low] && target>nums[mid]){
                    low = mid+1;
                }else{
                    high = mid -1;
                }
            }else{
                return -1;
            }
        }
        return -1;
    }
};



