/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/23 08:53:00 2019
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
/*1. 牛牛对整除非常感兴趣。牛牛的老师给他布置了一道题:牛牛的 老师给出一个 n,然后牛牛需要回答出能被 1 到 n 之间(包括 1 和 n) 所有整数整除的最小的数。牛牛犯了难，希望你能编程帮他解决这个 问题。(题目来源:京东面试题)
输入描述:
    输入包括一个整数 n(1<=n<=100000)
    输出描述: 输出一个整数，即满足要求的最小整数。答案可能很大，请输出这个 整数对于 987654321 取模的结果
    示例:
    输入:
         3
     输出:
         6
         */


/*判断是否为素数*/
bool check(int number)
{
    int i = 2;
    for(i=2; i<=number-1; i++)
    {
        if(number%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{ 
    int array[2000]={0};
    int n;
    cin >> n;
    int i=0; 
    int sum = 1;
    int res = 0;
    int mid = sqrt(n);
    for(i=2; i<=n; i++)
    {
        if(check(i))
        {
            if(i<=mid)
            {
                int k=i;
                int s=k;
                while(s<=n)
                {
                    array[i]++;
                    s = s*k;
                }
            }
            else{
                array[i] = 1;
            }
        }
        else{
            continue;
        }

    }
    for(int k=2;k<2000; k++)
    {
        if(array[k]>0)
        {
            res = pow(k,array[k]);
            sum = sum * res;
        }
        else{
            continue;
        }
    }
    cout << sum%987654321 << endl;
    return 0;
}
