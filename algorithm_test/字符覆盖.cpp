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
