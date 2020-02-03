/*************************************************************************
	> File Name: 变态跳台阶.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/ 3 18:53:01 2020
 ************************************************************************/
/**
 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 f(n) = f(0) + f(1) + .... +f(n-1);
 f(n-1) = f(0) + f(1) + .... +f(n-2);
 f(n) = 2*f(n-1);
 **/

class Solution {
public:
    int jumpFloorII(int number) {
        int *dp = new int[number+1];
        if(number==1) return 1;
        if(number==2) return 2;
        if(number==3) return 4;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i=4; i<=number; i++){
            dp[i] = 0;
            for(int j=0; j<i; j++){
                dp[i] = dp[i] + dp[j];
            }
        }
        return dp[number];
    }
};

