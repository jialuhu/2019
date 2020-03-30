/*************************************************************************
	> File Name: Cqueue.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  3/30 15:07:38 2020
 ************************************************************************/

#include<iostream>
#include<stack>
class Cqueue{
public:
    Cqueue();
    ~Cqueue();
    void push(int a);
    int front();
    bool isempty();
    size_t size();
    void pop_front();
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

Cqueue :: Cqueue() : stack1(), stack2(){
    
}

Cqueue :: ~Cqueue(){
    
}

bool Cqueue :: isempty(){
    if(stack1.empty() && stack2.empty()){
        return true;
    }
    return false;
}

size_t Cqueue :: size(){
    return stack1.size() + stack2.size();
}

void Cqueue :: push(int a){
    stack1.push(a);
}

int Cqueue :: front(){
    int res;
    if(stack1.empty() && stack2.empty()){
        return -1;
    }else if(!stack1.empty() && stack2.empty()){
        while( !stack1.empty() ){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    res = stack2.top();
    return res;
}

void Cqueue :: pop_front(){
    if(stack1.empty() && stack2.empty()){
        std::cout << "Cqueue is empty\n";
        return;
    }else if(!stack1.empty() && stack2.empty()){
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    stack2.pop();
}

int main(){
    Cqueue Aqueue;
    for(int i=0; i<10; i++){
        Aqueue.push(i);
    }
    for(int i=0; i<10; i++){
        std::cout << Aqueue.front() << " ";
        Aqueue.pop_front();
    }
    return 0;
}
