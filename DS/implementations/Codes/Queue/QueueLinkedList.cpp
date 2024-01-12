#include <iostream>
using namespace std;
class QueueLinkedList{
private:
    struct node{
        int data;
        node* next;
    };
    node* first;
    node* last;
    int size = 0;
public:
    QueueLinkedList();
    void insert(int _data){
        node *n_node = new node; 
        n_node->data = _data;
        if (first == NULL){
            first = n_node;
        }
        last->next = n_node;
        n_node->next = NULL;
        last = n_node;
        size++;
    }
    void Delete(){
        node *temp = first;
        if (first == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        first = first->next;
        delete temp;
    }
    ~QueueLinkedList();
};

QueueLinkedList::QueueLinkedList(){
    first = NULL;
    last = NULL;
}

QueueLinkedList::~QueueLinkedList()
{
}
