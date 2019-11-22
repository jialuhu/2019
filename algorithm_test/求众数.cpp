/*************************************************************************
	> File Name: 求众数.cpp
	> Author: 
	> Mail: 
	> Created Time: 五 11/22 20:34:50 2019
 ************************************************************************/

/**
 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 
 你可以假设数组是非空的，并且给定的数组总是存在众数。
 
 示例 1:
 
 输入: [3,2,3]
 输出: 3
 示例 2:
 
 输入: [2,2,1,1,1,2,2]
 输出: 2
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/majority-element
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
/*分治法求解*/
class Solution {
public:
    int compTwoElement(vector<int>& nums, int number, int lo, int hi){
        int count = 0;
        for(int i=lo; i<=hi; i++){
            if(nums[i]==number){
                count++;
            }
        }
        return count;
    }
    int majorityMidElement(vector<int>& nums, int lo, int hi){
        if(lo==hi) return nums[lo];
        int mid = (lo+hi)>>1;
        int left = majorityMidElement(nums,lo,mid);
        int right = majorityMidElement(nums,mid+1,hi);
        if(left==right) return left;
        int count_l = compTwoElement(nums,left,lo,mid);
        int count_r = compTwoElement(nums,right,mid+1, hi);
        return count_l>count_r?left:right;
    }
    int majorityElement(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return majorityMidElement(nums,low,high);
    }
};
