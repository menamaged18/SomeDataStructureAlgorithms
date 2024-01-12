#include <iostream>
using namespace std;

class StackLinkedList{
private:
struct node{
    node* next;
    int data;
};
node* top;
public:
    StackLinkedList();
    void insert(int val){
        node *n_node = new node;
        n_node->data = val;
        n_node->next = top;
        top = n_node;
    }
    int pop(){
        if (top == NULL){
            cout<<"This linked is Empty!"<<endl;
            return;
        }
        node* to_delete = top;
        top = top->next;
        delete to_delete;
    }
    void Print(){
        node * forloop = top;
        if (top == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        while (forloop != NULL){
            cout<<forloop->data<<" ";
            forloop = forloop->next;
        }
        cout<<endl;
    }
    ~StackLinkedList();
};

StackLinkedList::StackLinkedList(){
    top = NULL;
}

StackLinkedList::~StackLinkedList(){}
