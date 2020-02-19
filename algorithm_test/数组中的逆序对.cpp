/*************************************************************************
	> File Name: 数组中的逆序对.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  2/19 23:06:03 2020
 ************************************************************************/
/**
 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
 
  
 
 示例 1:
 
 输入: [7,5,6,4]
 输出: 5
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/
class Solution {
public:
    int InversePairCore(vector<int>& nums, vector<int>& copy, int start, int end)
    {
        if(start==end){
            return 0;
        }
        int mid = (end-start)/2;
        int left = InversePairCore(nums, copy,start, start+mid);
        int right = InversePairCore(nums,copy,start+mid+1,end);
        int i = start+mid;
        int j = end;
        int copyIndex = end;
        int count = 0;
        while(i>=start && j>=start+mid+1){
            if(nums[i] > nums[j]){
                copy[copyIndex--] = nums[i--];
                count = count+j-start-mid;
            }else{
                copy[copyIndex--] = nums[j--];
            }
        }
        for(;i>=start;--i){
            copy[copyIndex--] = nums[i];
        }
        for(;j>=start+mid+1;--j){
            copy[copyIndex--] = nums[j];
        }
        for(int k=start; k<=end; k++){
            nums[k] = copy[k];
        }
        return left+right+count;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> copy;
        int size = nums.size();
        if(size==0) return 0;
        for(int i=0; i<size; i++){
            copy.push_back(nums[i]);
        }
        return InversePairCore(nums, copy, 0, size-1);
    }
};

