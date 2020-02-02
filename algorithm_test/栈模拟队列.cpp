/*************************************************************************
	> File Name: 栈模拟队列.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  2/ 2 15:50:30 2020
 ************************************************************************/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
    
    int pop() {
        if(stack2.size()<=0){
            while(!stack1.empty()){
                int t = stack1.top();
                stack2.push(t);
                stack1.pop();
            }
        }
        int a = stack2.top();
        stack2.pop();
        return a;
    }
    
private:
    stack<int> stack1;
    stack<int> stack2;
};

