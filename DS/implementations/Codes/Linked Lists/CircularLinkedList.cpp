#include <iostream>
using namespace std;
class CircularLinkedList
{
private:
    struct node{
    node* next;
    int data;
    };
    node* head;
    node* tail;
    int size;
public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insert_beg(int val){
        node * N = new node;            
        N->data = val;
        if (head == NULL){
            N->next = N;
            tail = head = N;
        }else{
            N->next = head;
            head = N;
            tail->next = N;
        }
    }
    void insert_end(int val){
        node * N = new node;
        N->data = val;
        if (head == NULL){
            N->next = N;
            tail = head = N;
        }else{
            tail->next = N;
            N->next = head;
            tail = N;
        }
    }
    void insert(int at, int val){
        node * N = new node;
        N->data = val;
        if (head == NULL){
            cout<<"This LinkedList is empty"<<endl;
        }else{
            node* current = head;
            while (current->data != at) {
                if (current->next == head) {
                    cout << "The given previous node not found in the linked list." << endl;
                    return;
                }
                current = current->next;
            }
            
        }
    }
    void Delete_first(){
        if (head == NULL){
            cout<<"This LinkedList is empty"<<endl;
        }else{
            node* current = head;
            head = current->next;
            delete current;
        }
    }
    void Delete_end(){
        if (head == NULL){
            cout<<"This LinkedList is empty"<<endl;
        }else{
            if (head == tail){
                delete head;
                head = tail = NULL;
                return;
            }
            node* current = head,* prev;
            while (current->data != tail->data) {
                prev = current;
                current = current->next;
            }
            prev->next = current->next;
            delete current;
        }
    }
};

CircularLinkedList::CircularLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

CircularLinkedList::~CircularLinkedList()
{
}
