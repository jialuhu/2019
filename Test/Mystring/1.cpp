/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  7/24 09:15:51 2019
 ************************************************************************/

#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;
void sum(initializer_list<int> il)
{
    cout << il.size() << "&&&"<<endl;
    for(auto p=il.begin(); p!=il.end(); p++)
    {
        cout << *p << endl;
    }
}
void fun(void *s)
{
}
int main()
{
    string a("hujialu");
    string b(a,1);
    cout << b<< endl;
    sum({0,9,8});
    string s;
    char S[10];
    int i=0;
    int pos = 10;
    int len = 10;
    return 0;
}

