/*************************************************************************
	> File Name: 爬楼梯.cpp
	> Author: 
	> Mail: 
	> Created Time: 二 12/ 3 20:07:33 2019
 ************************************************************************/

/**
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 
 注意：给定 n 是一个正整数。
 
 示例 1：
 
 输入： 2
 输出： 2
 解释： 有两种方法可以爬到楼顶。
 1.  1 阶 + 1 阶
 2.  2 阶
 示例 2：
 
 输入： 3
 输出： 3
 解释： 有三种方法可以爬到楼顶。
 1.  1 阶 + 1 阶 + 1 阶
 2.  1 阶 + 2 阶
 3.  2 阶 + 1 阶
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/climbing-stairs
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **/

class Solution {
public:
    //直接递归会超时哟
    /*int climbSum(int n){
     if(n>2){
     return climbSum(n-1)+climbSum(n-2);
     }else{
     switch(n){
     case 1:
     return 1;
     case 2:
     return 2;
     }
     }
     return 0;
     }
     int climbStairs(int n) {
     return climbSum(n);
     }*/
    //动态规划走一波
    int climbStairs(int n){
        int* a = new int[n + 1];
        for(int i=1; i<=n; i++){
            if(i==1){
                a[i] = 1;
            }else if(i==2){
                a[i] = 2;
            }else{
                a[i] = a[i-1] + a[i-2];
            }
        }
        return a[n];
    }
    //改进一下
    int climbStairs(int n){
        if(n<=2){
            return n;
        }
        int left = 1;//左边保持-2的数值，就是较小的数值
        int right = 2;//右边保持-1的数值，就是较大的数值
        for(int i=3; i<=n; i++){
            /*交换计算当前的左右数值*/
            int temp = left + right;
            left = right;
            right = temp;
        }
        return right;
    }
};
