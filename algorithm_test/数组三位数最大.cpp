/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  7/22 14:16:39 2019
 ************************************************************************/


#include <iostream>
#include <vector>
#include <poll.h>
using namespace std;
/*1. 给定一个无序数组，包含正数、负数和 0，要求从中找出 3 个数
 的乘积，使得乘积最大，要求时间复杂度:O(n)，空间复杂度:O(1) (题目来源:拼多多面试题)
 输入描述:
 无序整数数组 A[n]
 输出描述: 满足条件的最大乘积 示例:
 输入:
 3412
 输出:
 24
 */

 //如果要三个数字乘积最大，如果是正数的话，则前三位最大的数字和最大；如果其中有
 //负数的话，只有两个最小负数的乘积和一个最大正数才可以为三位数字乘积最大／综上只有两种组合
 //正数、正数、正数／最大正数、最小负数、第二小负数
int main()
{
    //存放前三位最大的数字
    int Max[3] = {0};
    //存放后两位最小的数字
    int Min[2] = {0};
    vector<int> vi;
    int number;
    cin >> number;
    for(int i=0; i<number; i++)
    {
        int n;
        cin >> n;
        vi.push_back(n);
    }
    for(int &x : vi)
    {
        //一次遍历找出前三大的数字
        if(x>0){
            if(x > Max[0]){
                Max[2] = Max[1];
                Max[1] = Max[0];
                Max[0] = x;
            } 
            else if(x > Max[1]){
                Max[2] = Max[1];
                Max[1] = x;
            }
            else if(x > Max[2]){
                Max[2] = x;
            }
        }
        else{
            if(x < Min[0]){
                Min[1] = Min[0];
                Min[0] = x;
            }
            else if(x < Min[1]){
                Min[1] = x;
            }
        }
    }
    int max1,max2;
    max1 = Max[0]*Max[1]*Max[2];
    max2 = Min[0]*Min[1];
    if(max1>max2){
        cout << max1 << endl;
    }
    else{
        cout << max2 << endl;
    }
    //cout << Min[0]<< " " << Min[1] << endl;
    //cout << Max[0] << " " << Max[1] << " " << Max[2] << endl;
    return 0;
}
