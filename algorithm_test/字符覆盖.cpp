/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/23 08:53:00 2019
 ************************************************************************/

/*小度有一个小写字母组成的字符串s.字符串s已经被写在墙上了.
小度还有很多卡片,每个卡片上有一个小写字母,组成一个字符串t。小度可以选择字符串t中任意一个字符,然后覆盖在字符串s的一个字符之上。小度想知道在选取一些卡片覆盖s的一些字符之后,可以得到的字典序最大的字符串是什么。 

输入描述:

输入包括两行,第一行一个字符串s,字符串s长度length(1 ≤ length ≤ 50),s中每个字符都是小写字母
第二行一个字符串t,字符串t长度length(1 ≤ length ≤ 50),t中每个字符都是小写字母
输出描述:

输出一个字符串,即可以得到的字典序最大字符串
输入例子1:

fedcba
ee
输出例子1:

feeeba
*/


#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);
    sort(t.begin(),t.end(),greater<char>());
    int pos = 0;
    for(auto it=s.begin(); it!=s.end(); it++)
    {
        if(*it < t[pos])
        {
            *it = t[pos++];
        }
    }
    cout << s << endl;
    return 0;
}
