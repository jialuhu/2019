/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  7/20 11:43:39 2019
 ************************************************************************/

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
