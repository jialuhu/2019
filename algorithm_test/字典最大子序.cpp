/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/23 08:53:00 2019
 ************************************************************************/
/*4. 对于字符串 x 和 y, 如果擦除 x 中的某些字母(有可能全擦掉或者 都不擦)能够得到 y,我们就称 y 是 x 的子序列。例如."ncd"是 "nowcoder"的子序列,而"xt"不是。
现在对于给定的一个字符串 s,请计算出字典序最大的 s 的子序列。 (题目来源:百度面试题)
输入描述:
输入包括一行,一个字符串 s,字符串 s 长度 length(1 ≤ length ≤ 50). s 中每个字符都是小写字母
输出描述:
输出一个字符串,即字典序最大的 s 的子序列。
示例:
输入:
test
输出:
tt
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int c = 0;
    while(s.size>c)
    {
        auto index = max_element(s.begin()+c,s.end());
        s.erase(s.begin+c, index);
    }
    cout << s << "\n";
    return 0;
}
