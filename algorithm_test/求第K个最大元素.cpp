/*************************************************************************
	> File Name: 求第K个最大元素.cpp
	> Author: 
	> Mail: 
	> Created Time: 六 11/23 16:21:14 2019
 ************************************************************************/
/**
 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 
 示例 1:
 
 输入: [3,2,1,5,6,4] 和 k = 2
 输出: 5
 示例 2:
 
 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 输出: 4
 说明:
 
 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 
 
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
/*快速选择*/
class Solution
{
public:
    void Swap(int &a, int& b){
        int temp=a;
        a = b;
        b = temp;
    }
    int partition(vector<int>& nums, int lo, int hi){
        int base_number = nums[lo];
        Swap(nums[lo],nums[hi]);
        int base_index = lo;
        for(int i=lo; i<hi; i++){
            if(nums[i]<base_number){
                Swap(nums[i],nums[base_index]);
                base_index++;
            }
        }
        Swap(nums[base_index],nums[hi]);
        return base_index;
    }
    int quickselect(vector<int>& nums, int lo, int hi, int target){
        if(lo==hi){
            return nums[lo];
        }
        int pivot_index = lo;
        pivot_index = partition(nums,lo,hi);
        if(pivot_index==target){
            return nums[target];
        }else if(pivot_index > target){
            return quickselect(nums, lo, pivot_index-1, target);
        }else{
            return quickselect(nums, pivot_index+1, hi, target);
        }
        return 0;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int lo = 0;
        int hi = nums.size()-1;
        int target = (hi+1)-k;
        return quickselect(nums,lo,hi,target);
    }
};
