/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  6/ 4 11:24:23 2019
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int sum1={0};
    int sum2={0};
    int n;
    cin >> n;
    vector<int> vi;
    for(int i=0; i<n; i++)
    {
        int m;
        cin >> m;
        vi.push_back(m);
    }
    sort(vi.begin(),vi.end());//从小到大排序，每次每个人都拿最大，差值即为次数的偶数次数牌数和减去奇数次数牌数和
    int k = 0;
    for(auto it = vi.rbegin(); it!=vi.rend(); it++)
    {
        if(k%2==0)
        {
            sum1 = sum1+(*it);
        }
        else
        {
            sum2 = sum2 + (*it);
        }
        k++;
    }
    cout << sum1 - sum2 << endl;
    return 0;
}
