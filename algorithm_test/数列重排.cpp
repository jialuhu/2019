/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  7/23 08:53:00 2019
 ************************************************************************/

#include<iostream>
#include<functional>
int main()
{
    int array[4] = {0};
    int number;
    cin >> number;
    for(int i=0; i<number; i++){
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int t=0;
            cin >> t;
            if(t%4==0){
                array[2]++;
            } 
            else if(t%2==0){
                array[1]++;
            }
            else{
                array[0]++;
            }
        }
        if( (array[1]==0) && (array[2]>=(array[0]-1)) ){
            cout << "Yes\n";
        }
        else if(array[1]!=0 && array[2]>=array[0]){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
            
    }
}
