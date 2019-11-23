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
/*快速选择
 方法二：快速选择
 快速选择算法 的平均时间复杂度为
 O
 (
 N
 )
 O(N)。就像快速排序那样，本算法也是 Tony Hoare 发明的，因此也被称为 Hoare选择算法。
 
 本方法大致上与快速排序相同。简便起见，注意到第 k 个最大元素也就是第 N - k 个最小元素，因此可以用第 k 小算法来解决本问题。
 
 首先，我们选择一个枢轴，并在线性时间内定义其在排序数组中的位置。这可以通过 划分算法 的帮助来完成。
 
 为了实现划分，沿着数组移动，将每个元素与枢轴进行比较，并将小于枢轴的所有元素移动到枢轴的左侧。
 这样，在输出的数组中，枢轴达到其合适位置。所有小于枢轴的元素都在其左侧，所有大于或等于的元素都在其右侧。
 
 这样，数组就被分成了两部分。如果是快速排序算法，会在这里递归地对两部分进行快速排序，时间复杂度为
 O
 (
 N
 log
 ⁡
 N
 )
 O(NlogN)。
 
 而在这里，由于知道要找的第 N - k 小的元素在哪部分中，我们不需要对两部分都做处理，这样就将平均时间复杂度下降到
 O
 (
 N
 )
 O(N)。
 
 最终的算法十分直接了当 :
 
 随机选择一个枢轴。
 
 使用划分算法将枢轴放在数组中的合适位置 pos。将小于枢轴的元素移到左边，大于等于枢轴的元素移到右边。
 
 比较 pos 和 N - k 以决定在哪边继续递归处理。
 
 ! 注意，本算法也适用于有重复的数组
 
 
 作者：LeetCode
 链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
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
