/*************************************************************************
	> File Name: 最长回文字符串.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/15 19:08:38 2019
 ************************************************************************/
/**
 面试题31. 栈的压入、弹出序列
 难度
 中等
 
 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。
 

 **/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> stacks;
        int i = 0;
        int p = 0;
        if(pushed.size() == 0 && popped.size()==0 ){
            return true;
        }
        if(pushed.size() == 0 || popped.size()==0 ){
            return false;
        }
        int len = pushed.size();
        int n = popped.size();
        for(int i=0; i<len; i++){
            stacks.push(pushed[i]);
            while(!stacks.empty() && p < n && stacks.top()==popped[p]){
                p++;
                stacks.pop();
            }
        }
        return stacks.empty();
    }
};
