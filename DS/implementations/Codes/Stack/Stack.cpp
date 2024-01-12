//stack using array
// #include <iostream>
// using namespace std;
// template <typename T>
// class Stack
// {
// private:
//     T* stack;
//     int top;
//     int MaxSize;
// public:
//     Stack(int val);

//     void Push(T val){
//         if (top == MaxSize-1){
//             cout<<"This Stack is full"<<endl;
//             return;
//         }
//         top++;
//         stack[top] = val; 
//     }

//     T pop(){
//         if (top == -1){
//             cout<<"This Stack is empty"<<endl;
//             return T();
//         }
//         return stack[top--];
//     }

//     T Top(){
//         if (isEmpty){
//             cout<<"Error: this list is empty"<<endl;
//             return T();
//         }
//         return stack[top];
//     }

//     bool isEmpty(){
//         return top == -1;
//     }

//     int stackSize(){
//         return top+1;
//     }

//     void clear(){
//         delete[] stack;
//     }

//     void print(){
//         if (top == -1){
//             cout<<"This Stack is empty"<<endl;
//             return;
//         }
//         for (int i = top; i >= 0; i--){
//             cout<<stack[i]<<" ";
//         }
//         cout<<endl;
//     }

//     ~Stack();
// };

// template <typename T>
// Stack<T>::Stack(int val){
//     top = -1;
//     MaxSize = val;
//     stack = new T[MaxSize];
// }

// template <typename T>
// Stack<T>::~Stack(){
//     delete[] stack;
// }

// singly linked list Stack
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T element) : data(element), next(NULL) {}
    };
    Node* top_node;

public:
    Stack() : top_node(NULL) {}

    void push(T element) {
        Node* new_node = new Node(element);
        new_node->next = top_node;
        top_node = new_node;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Error: This Stack is empty\n";
            return T();
        }
        Node* temp = top_node;
        T result = temp->data;
        top_node = top_node->next;
        delete temp;
        return result;
    }

    T top() const {
        if (isEmpty()) {
            cout << "Error: Stack is empty\n";
            return T();
        }
        return top_node->data;
    }

    bool isEmpty() const {
        return top_node == NULL;
    }

    int stackSize() const {
        int count = 0;
        Node* temp = top_node;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        Node* temp;
        while (top_node != NULL) {
            temp = top_node;
            top_node = top_node->next;
            delete temp;
        }
    }

    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top_node;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
