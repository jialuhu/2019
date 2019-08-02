/*************************************************************************
	> File Name: 1.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  7/24 09:15:51 2019
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    int num;
    cin>>num;
    while(num--)
    {
        cin>>n;
        int n4=0,n2=0,n1=0;
        while(n--)
        {
            int temp=0;
            cin>>temp;
            if(temp%4==0)
                n4++;
            else if(temp%2==0)
                n2++;
            else
                n1++;
        }
        if(n2==0)
        {
            if(n4>=n1-1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        else
        {
            if(n4>=n1)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}

