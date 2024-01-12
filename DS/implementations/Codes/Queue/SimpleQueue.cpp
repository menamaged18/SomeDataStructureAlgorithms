#include <iostream>
using namespace std;

class SimpleQueue{
private:
    int maxNumber,first,last;
    int* arr;
public:
    SimpleQueue(int n);
    bool isfull(){
        return (last == maxNumber-1 && first == 0) || first == last+1;
    }
    void enqueue(int val){
        if (!isfull()){
            //now after this condition it became circular
            if (last == maxNumber-1 || last == -1){
                arr[0] = val;
                last = 0;
                if (first == -1){
                    first = 0;
                }
            }else{
                arr[++last] = val;
            }
        }else{
            cout<<"This queue is Full!"<<endl;
        }
    }
    int dequeue(){
        if (first == -1){
            cout<<"This queue is empty!"<<endl;
            return 0;
        }
        int temp;
        temp = arr[first];
        if (first == last){
            first = last = -1;
        }else if(first == maxNumber -1){
            first = 0;
        }else{
            first++;
        }
        return temp;
    }
    void Display(){
        for (size_t i = first; i <= last; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~SimpleQueue();
};

SimpleQueue::SimpleQueue(int n){
    maxNumber = n;
    first = last = -1;
    arr = new int[maxNumber];
}

SimpleQueue::~SimpleQueue(){
}

int main(){
    SimpleQueue ob(5);
    ob.enqueue(5);
    ob.enqueue(3);
    ob.enqueue(7);
    ob.enqueue(10);
    ob.dequeue();
    ob.Display();
}
