/*************************************************************************
	> File Name: 1-n排列组合.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/16 14:27:04 2020
 ************************************************************************/
/*
*给定一个n，求 [1,n] 这 n 个数字的排列组合有多少个。
条件：相邻的两个数字的绝对值不能等于1.
* */

#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int> >& res, int deepth, int n, vector<int>& list, vector<bool>& visited);
int main(){
    int n;
    cin >> n;
    int deepth=0;
    vector<bool> visited;
    for(int i=0; i<=n; i++){
        visited.push_back(false);
    }
    vector<vector<int> > res;
    vector<int> list;
    dfs(res, 0, n, list, visited);
    int r = res.size();
    int c = res[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            std::cout << res[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;

}

void dfs(vector<vector<int> >& res, int deepth, int n, vector<int>& list, vector<bool>& visited){
    if(deepth == n){
        res.push_back(list);
        return;
    }
    for(int j=1; j<=n; j++){
        if( !visited[j]){
            if(list.size()==0 || abs( list[list.size()-1] - j ) != 1){
                visited[j] = true;
                list.push_back(j);
                dfs(res, deepth+1, n, list, visited);
                list.pop_back();
                visited[j] = false;
            } 
            /*visited[j] = true;
            list.push_back(j);
            dfs(res, deepth+1, n, list, visited);
            list.pop_back();
            visited[j] = false;*/
        }else{
            continue;
        }
    }
}
