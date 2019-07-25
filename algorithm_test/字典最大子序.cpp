/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/23 08:53:00 2019
 ************************************************************************/


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
