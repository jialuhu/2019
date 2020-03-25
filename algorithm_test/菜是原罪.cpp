/*************************************************************************
	> File Name: 菜是原罪.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  3/25 23:36:30 2020
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
void findMin(std::vector<std::vector<int>>& numbers,
             int row, int deepth, int last, int &minsum, int &currsum,int n){
    if(deepth > n-1){
        minsum = std::min(minsum, currsum);
        return;
    }
    for(int i=0; i<3; i++){
        currsum = currsum+abs(numbers[i][deepth]-last);
        findMin(numbers,i,deepth+1,numbers[i][deepth],minsum,currsum,n);
        currsum = currsum - abs(numbers[i][deepth]-last);
    }
}
int main(){
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> numbers(3,std::vector<int>(n,0));
    int minsum = 0;
    int currsum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            int number;
            std::cin >> number;
            minsum += number;
            numbers[i][j] = number;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<n; j++){
            std::cout << numbers[i][j] << " ";
        }
        std::cout << "\n";
    }
    int deepth = -1;
    for(int i=0; i<3; i++){
        findMin(numbers, i, deepth+1, numbers[i][0], minsum, currsum, n);
    }
    std::cout << minsum << std::endl;
    return 0;
}
