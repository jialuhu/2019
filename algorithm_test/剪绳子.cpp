/*************************************************************************
	> File Name: 剪绳子.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/ 3 21:15:19 2020
 ************************************************************************/
/**
 给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
 **/
class Solution {
public:
    int cutRope(int number) {
        if(number==1) return 0;
        if(number==2) return 1;
        if(number==3) return 2;
        int *dp = new int[number+1];
        for(int i=0; i<=number; i++){
            dp[i] = 0;
        }
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        int length = 4;
        for(length=4; length<=number; length++){
            int m = 0;
            for(int l=1; l<=length/2; l++){
                dp[length] = dp[l]*dp[length-l];
                dp[length] = max(dp[length],m);
            }
        }
        int max_ = dp[number];
        delete[] dp;
        return max_;
        
    }
};
