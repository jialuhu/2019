/*************************************************************************
	> File Name: 大整数相乘.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  8/13 09:43:14 2019
 ************************************************************************/
/**
 链接：https://www.nowcoder.com/questionTerminal/0f0badf5f2204a6bb968b0955a82779e
 来源：牛客网
 
 有两个用字符串表示的非常大的大整数,算出他们的乘积，也是用字符串表示。不能用系统自带的大整数类型。
 
 输入描述:
 
 空格分隔的两个字符串，代表输入的两个大整数
 
 
 输出描述:
 
 输入的乘积，用字符串表示
 示例1
 输入
 
 72106547548473106236 982161082972751393
 输出
 
 70820244829634538040848656466105986748
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
int main() {
    std::string input1;
    std::string input2;
    getline(std::cin, input1);
    getline(std::cin, input2);
    std::vector<std::vector<int>> vi;
    for(int i=input1.size()-1; i>=0; i--){
        std::vector<int> ai;
        int number1 = input1[i]-48;
        for (int j=input2.size()-1; j>=0; j--){
            int number2 = input2[j]-48;
            int sum = number1*number2;
            ai.push_back(sum);
        }
        vi.push_back(ai);
    }
    int len1 = vi.size();
    for(int i=0; i<len1; i++){
        int len2 = vi[i].size();
        int clc = 0;
        for(int j=0; j<len2; j++){
            int tmp = vi[i][j]+clc;
            vi[i][j] = (vi[i][j]+clc)%10;
            clc = tmp/10;
        }
        if(clc) vi[i].insert(vi[i].end(),clc);
        int count = i;
        while (count--){
            vi[i].insert(vi[i].begin(),0);
        }
    }
    int max_len = vi[vi.size()-1].size();
    for(int i=0; i<vi.size()-1; i++){
        int count = max_len-vi[i].size();
        while (count--){
            vi[i].push_back(0);
        }
    }
    std::vector<int> sum;
    std::vector<int> tmp;
    tmp = vi[0];
    for(int i=0; i<max_len; i++){
        int sums = 0;
        for(int j=0; j<vi.size(); j++){
            sums = vi[j][i]+sums;
        }
        sum.push_back(sums);
    }
    int c = 0;
    std::string result;
    for(int i=0; i<sum.size();i++){
        int tem = sum[i]+c;
        sum[i] = (tem)%10;
        c = tem/10;
        result.insert(result.begin(),sum[i]+48);
    }
    if(c) result.insert(result.begin(),c+48);
    std::cout << "result: " << result <<std::endl;
    std::cout << "\n";
    
    return 0;
}
