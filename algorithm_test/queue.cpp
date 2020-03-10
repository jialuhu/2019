/*************************************************************************
	> File Name: queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  3/10 21:28:13 2020
 ************************************************************************/
#include <iostream>

using namespace std;
#define MAX_SIZE 5

typedef struct queue{
    int count;
    int front;
    int rear;
    int data[MAX_SIZE];
}Queue;

void Init(Queue* ptr) { //初始化队列
    ptr->count = 0;
    ptr->front = 0;
    ptr->rear = -1;
}

bool QueueFull(Queue* ptr) {  //判断队列是否满
    return ptr->count >= MAX_SIZE;
}

bool QueueEmpty(Queue* ptr) {   //判断队列是否为空
    return ptr->count <= 0;
}

void Append (Queue* ptr, int item) {    //入队
    if (QueueFull(ptr)) {
        cerr << "队列满了!" << endl;
        return;
    }else {
        ptr->count ++;
        ptr->rear = (ptr->rear + 1) % MAX_SIZE;
        ptr->data[ptr->rear] = item;
    }
}

void Pop(Queue* ptr) {  //出队
    if (QueueEmpty(ptr)) {
        cerr << "队列为空!" << endl;
        return;
    }else {
        ptr->count --;
        ptr->front = (ptr->front + 1) % MAX_SIZE;
    }
}

int QueueSize (Queue* ptr) {    //返回队列长度
    return ptr->count;
}

void Show(Queue* ptr) { //遍历队列
    if(QueueEmpty(ptr)) {
        cout << "队列为空!" << endl;
        return;
    }else {
        cout << "队列遍历: ";
        int i = ptr->front;
        while (i != ptr->rear) {
            cout << ptr->data[i] << " ";
            i ++;
            i = i % MAX_SIZE;
        }
        cout << ptr->data[ptr->rear] << " ";
    }
    cout << endl;
}


int main() {
    Queue* dummy = (Queue *)malloc(sizeof(Queue));  //申请结点空间
    Init(dummy);
    
    Append(dummy, 11);
    Append(dummy, 5);
    Append(dummy, 23);
    Append(dummy, 18);
    Pop(dummy);
    Show(dummy);
    
    
    Append(dummy, 33);
    Pop(dummy);
    Show(dummy);
    
    
    Append(dummy, 77);
    Show(dummy);
    
    
    
    return 0;
}

