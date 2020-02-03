/*************************************************************************
	> File Name: 矩形覆盖.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  2/ 3 18:55:12 2020
 ************************************************************************/
/**
 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 **/
class Solution {
public:
    int rectCover(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;
        if(number == 3) return 3;
        int fn1 = 1;
        int fn2 = 2;
        int sum = 0;
        for(int i=3; i<=number; i++){
            sum = fn1 + fn2;
            fn1 = fn2;
            fn2 = sum;
        }
        return fn2;
    }
};

