/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  7/22 14:16:39 2019
 ************************************************************************/
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string st1,st2;
    cin>>st1;
    cin>>st2;
    int n = st1.size(),m = st2.size();
    int a[n + m];
    fill(a, a + n + m, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[n + m - i - j - 2] += (st1[i] - '0') * (st2[j] - '0');
    for (int i = 0; i < n + m - 1; ++i)
    {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }

    int r = n + m - 1;
    for (; r && !a[r]; r--);
    for (;r >= 0;--r)
        cout<<a[r];
    cout<<endl;
    return 0;
}
