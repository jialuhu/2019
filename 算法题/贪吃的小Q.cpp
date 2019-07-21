/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  7/20 11:43:39 2019
 ************************************************************************/
/*
小Q的父母要出差N天，走之前给小Q留下了M块巧克力。小Q决定每天吃的巧克力数量不少于前一天吃的一半，但是他又不想在父母回来之前的某一天没有巧克力吃，请问他第一天最多能吃多少块巧克力

输入描述:

每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，表示父母出差的天数N(N<=50000)和巧克力的数量M(N<=M<=100000)。


输出描述:

输出一个数表示小Q第一天最多能吃多少块巧克力。

例如：
输入
3 7
输出
4

*/

#include<iostream>
using namespace std;
int check(int mid, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum = sum + mid;
        mid = (mid+1) / 2;//检查第一天吃mid块，之后是否符合巧克力总数
    }
    return sum;
}

int find(int n, int m)
{
    if(n==1) return m;
    int low = 1;
    int high = m;
    while(low < high)
    {
        int mid = (low+high+1)/2;
        int res = check(mid,n);
        if(res == m)
        {
            return mid;
        }
        else if(res < m)//说明查找到的数字太小了，应该往后查找
        {
            low = mid;
        }
        else{//说明查找到的数字太大了，应该往前查找
            high = mid-1;
        }
    }
    return high;
}

int main()
{
    int n,m;
    cin >> n >> m;
    cout << find(n,m) << endl;
    return 0;
}
