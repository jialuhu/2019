/*************************************************************************
	> File Name: 循环队列.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  3/29 21:09:44 2020
 ************************************************************************/

#include<iostream>

int max_size = 10;
class deque{
public:
    deque();
    ~deque();
    bool isempty();
    bool isfull();
    void pop();
    void put(int a);
    void showbuffer();
    int top();
private:
    size_t capacity;
    int front;
    int rear;
    int *buffer;
};

deque::deque() : front(0),rear(0),capacity(0),
buffer(new int[max_size]){
    for(int i=0; i<max_size; i++){
        buffer[i] = 0;
    }
}
deque::~deque(){
    delete[](buffer);
}
bool deque :: isempty() {
    if(capacity <= 0){
        return true;
    }
    return false;
}

bool deque :: isfull() {
    if(capacity == max_size){
        return true;
    }
    return false;
}

void deque :: put(int a){
    if(!isfull()){
        buffer[rear] = a;
        rear = (rear+1) % max_size;
        capacity++;
    }
    return;
}

int deque :: top() {
    if(isempty()){
        return -1;
    }
    return buffer[front];
}

void deque :: pop() {
    if(isempty()){
        return;
    }
    front = (front+1) % max_size;
    capacity--;
}
void deque :: showbuffer() {
    for(int i=0; i<max_size; i++){
        std::cout << buffer[i] << " ";
    }
    std::cout << std::endl;
}
int main(){
    deque A{};
    for(int i=0; i<10; i++){
        A.put(i);
    }
    A.pop();
    A.pop();
    for(int i=0; i<2; i++){
        A.put(100);
    }
    A.showbuffer();
    for(int i=0; i<10; i++){
        std::cout << A.top() << " ";
        A.pop();
    }
    
    return 0;
}




