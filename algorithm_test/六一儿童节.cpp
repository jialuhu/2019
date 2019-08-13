/*************************************************************************
	> File Name: 六一儿童节.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  8/13 10:41:04 2019
 ************************************************************************/

/*
 链接：https://www.nowcoder.com/questionTerminal/9950361305164521aca1be9f879de98f
 来源：牛客网
 
 六一儿童节，老师带了很多好吃的巧克力到幼儿园。每块巧克力j的重量为w[j]，对于每个小朋友i，当他分到的巧克力大小达到h[i] (即w[j]>=h[i])，他才会上去表演节目。老师的目标是将巧克力分发给孩子们，使得最多的小孩上台表演。可以保证每个w[i]> 0且不能将多块巧克力分给一个孩子或将一块分给多个孩子。
 
 输入描述:
 
 
 第一行：n，表示h数组元素个数
 第二行：n个h数组元素
 第三行：m，表示w数组元素个数
 第四行：m个w数组元素
 
 
 输出描述:
 
 上台表演学生人数
 示例1
 输入
 
 
 3
 2 2 3
 2
 3 1
 输出
 
 1
 */
#include <vector>
#include <iostream>
#include <algorithm>
int main(){
    std::vector<int> h;
    std::vector<int> w;
    int number1,number2;
    std::cin >> number1;
    
    for(int i=0; i<number1; i++){
        int n;
        std::cin >> n;
        h.push_back(n);
    }
    std::cin >> number2;
    for(int i=0; i<number2; i++){
        int n;
        std::cin >> n;
        w.push_back(n);
    }
    sort(h.begin(),h.end());
    sort(w.begin(),w.end());
    int sum = 0;
    int len1 = h.size();
    int len2 = w.size();
    auto it1 = h.begin();
    auto it2 = w.begin();
    while (it1!=h.end() && it2!=w.end()){
        if((*it1)<=(*it2)){
            sum++;
            it1++;
            it2++;
        }
        else{
            it2++;
        }
    }
    std::cout  << sum << std::endl;
}
