/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  6/ 4 11:24:23 2019
 ************************************************************************/

/*
链接：https://www.nowcoder.com/questionTerminal/ebec6fac8a834bf7aed2d5da7c8aa432
来源：牛客网

牛牛和羊羊正在玩一个纸牌游戏。这个游戏一共有n张纸牌, 第i张纸牌上写着数字ai。
牛牛和羊羊轮流抽牌, 牛牛先抽, 每次抽牌他们可以从纸牌堆中任意选择一张抽出, 直到纸牌被抽完。
他们的得分等于他们抽到的纸牌数字总和。
现在假设牛牛和羊羊都采用最优策略, 请你计算出游戏结束后牛牛得分减去羊羊得分等于多少。

输入描述:

输入包括两行。
第一行包括一个正整数n(1 <= n <= 105),表示纸牌的数量。
第二行包括n个正整数ai(1 <= ai <= 109),表示每张纸牌上的数字。


输出描述:

输出一个整数, 表示游戏结束后牛牛得分减去羊羊得分等于多少。
示例1
输入

3
2 7 4
输出

5
*/

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
