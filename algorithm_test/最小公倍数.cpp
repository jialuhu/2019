/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/23 08:53:00 2019
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
/*判断是否为素数*/
bool check(int number)
{
    int i = 2;
    for(i=2; i<=number-1; i++)
    {
        if(number%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{ 
    int array[2000]={0};
    int n;
    cin >> n;
    int i=0; 
    int sum = 1;
    int res = 0;
    int mid = sqrt(n);
    for(i=2; i<=n; i++)
    {
        if(check(i))
        {
            if(i<=mid)
            {
                int k=i;
                int s=k;
                while(s<=n)
                {
                    array[i]++;
                    s = s*k;
                }
            }
            else{
                array[i] = 1;
            }
        }
        else{
            continue;
        }

    }
    for(int k=2;k<2000; k++)
    {
        if(array[k]>0)
        {
            res = pow(k,array[k]);
            sum = sum * res;
        }
        else{
            continue;
        }
    }
    cout << sum%987654321 << endl;
    return 0;
}
