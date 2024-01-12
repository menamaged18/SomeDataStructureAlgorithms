#include <iostream>
#include "Queue1.cpp"
using namespace std;


class StackByQueue
{
private:
    Queue1<int> stack1;
    Queue1<int> stack2;
public:
    StackByQueue();
    void Push(int element);
    int pop();
    int top();
    void print();
    ~StackByQueue();
};

StackByQueue::StackByQueue(/* args */)
{
}

void StackByQueue::Push(int element){
    stack1.enqueue(element);
}

int StackByQueue::pop(){
    for (int i = 0; i < stack1.queueSize()-1; i++){
        stack2.enqueue(stack1.dequeue());
    }
    int ret = stack1.dequeue();
    for (int i = 0; i < stack2.queueSize(); i++){
        stack1.enqueue(stack2.dequeue());
    }
    return ret;
}

int StackByQueue::top(){
    int realsize = stack1.queueSize();
    for (int i = 0; i < realsize-1; i++){
        stack2.enqueue(stack1.dequeue());
    }
    int ret = stack1.dequeue();
    for (int i = 0; i < stack2.queueSize(); i++){
        stack1.enqueue(stack2.dequeue());
    }
    stack1.enqueue(ret);
    return ret;
}

void StackByQueue::print(){
    for (int i = 0; i < stack1.queueSize()-1; i++){
        stack2.enqueue(stack1.dequeue());
    }
}

StackByQueue::~StackByQueue()
{
}

int main(){
    StackByQueue m;
    m.Push(5);
    m.Push(3);
    cout<<m.pop();
}