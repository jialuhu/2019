/*************************************************************************
	> File Name: 火眼金睛.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  8/24 13:52:29 2019
 ************************************************************************/

#include <iostream>
#include <vector>
#include <set>
/*链接：https://www.nowcoder.com/questionTerminal/d311403b15b8495b81b622edaefd5b5a
 来源：牛客网
 
 现在我们需要查出一些作弊的问答社区中的ID，作弊有两种：1.A回答了B的问题，同时B回答了A的问题。那么A和B都是作弊。2.作弊ID用户A和作弊ID用户B同时回答了C的问题，那么C也是作弊。已知每个用户的ID是一串数字，一个问题可能有多个人回答。
 
 输入描述:
 
 每组数据第一行为总问题数N(N小于等于200000)，第二行开始每行一个问题，第一个数字为提问人ID，第二个数字为回答人数，后面则为所有回答人的ID。(ID均为0-1000000的整数)
 
 
 输出描述:
 
 第一行为作弊ID数量，第二行开始为从小到大的每行一个作弊ID。
 示例1
 输入
 
 3
 1 1 2
 2 1 1
 3 2 1 2
 输出
 
 3
 1 2 3
 * */
int main(){
    const int max = 1e3 + 5;
    int flags[max]={0};
    int question_number;
    int map[max][max]={0};
    std::cin >> question_number;
    for(int i=0; i<question_number; i++){
        std::vector<int> ai;
        int ask_id;
        std::cin >> ask_id;
        int p_number;
        std::cin >> p_number;
        int id;
        for(int j=0; j<p_number; j++){
            std::cin >> id;
            map[ask_id][id] = 1;
        }
    }
    std::set<int> an;
    for(int i=0; i<max; i++){
        for(int j=0; j<max; j++){
            if(map[i][j]){
                if(map[i][j]==1 && map[j][i]==1 && i!=j){
                    an.insert(i);
                    an.insert(j);
                }
                else{
                    auto ends = an.end();
                    int len = an.size();
                    for(auto it = an.begin(); it!=ends; it++){
                        if(*it == j){
                            flags[i]++;
                            //an.insert(i);
                        }
                    }
                }
                
            }
        }
    }
    for(int i=0; i<max; i++){
        if(flags[i]>=2){
            an.insert(i);
        }
    }
    if(an.size()==0){
        std::cout << an.size();
    }
    else{
        std::cout << an.size() << std::endl;
        auto ends = an.end();
        int len = an.size();
        for(auto it = an.begin(); it!=ends; it++){
            std::cout <<(*it) << " ";
        }
    }
    std::cout << std::endl;
}
