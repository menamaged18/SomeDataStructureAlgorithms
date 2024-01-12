#include <iostream>
using namespace std;

class DoubleLinledList
{
private:
    struct node{
    node* next;
    node* previous;
    int data;
    };    
    node* head;
    node* tail;
    int elements;
public:
    DoubleLinledList();
    ~DoubleLinledList();
    int size() { return elements; }
    int TailData() { return tail->data; }
    int HeadData() { return head->data; }
    void insert(int val){
        node * NewNode = new node;
        NewNode->data = val;
        if (head == NULL){
            head = NewNode;
            tail = NewNode;
            NewNode->next = NULL;
            NewNode->previous = NULL;
        }else{
            //add at the end
            NewNode->previous = tail;
            NewNode->next = NULL;
            tail->next = NewNode;
            tail = NewNode;
        }
        elements++;
    }
    void insertAfter(int prev_data, int new_data) {
        if (head == NULL) {
            cout << "The given previous node must be in the linked list." << endl;
            return;
        }
        node* current = head;
        while (current != NULL) {
            if (current->data == prev_data) {
                break;
            }
            current = current->next;
        }
        if (current == NULL) {
            cout << "The given previous node not found in the linked list." << endl;
            return;
        }
        node* new_node = new node();
        new_node->data = new_data;
        new_node->next = current->next;
        new_node->previous = current;
        if (current->next != NULL) {
            current->next->previous = new_node;
        }
        current->next = new_node;
        elements++;
    }
    void insert_beg(int val){
        node * newNode = new node;
        newNode->data = val;
        if (head == NULL){
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
            newNode->previous = NULL;
        }else{
            newNode->next = head;
            newNode->previous = NULL;
            head->previous = newNode;
            head = newNode;
        }
        elements++;
    }
    void Delete_beg(){
        node * _Head = head;
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        head = head->next;
        head->previous = NULL;
        delete _Head;
        elements--;
    }
    void Delete_end(){
        node * _Tail = tail;
        if (tail == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        tail = tail->previous;
        tail->next = NULL;
        delete _Tail;
        elements--;
    }
    void Delete(int val){
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
        }else if (head == tail){
            delete tail;
            head = NULL;
        }else if (tail->next == NULL && tail->data == val){
            Delete_end();
        }else{
            node* current = head;
            while (current != NULL) {
                if (current->data == val) {
                    break;
                }
                current = current->next;
            }
            if (current == NULL) {
                cout << "The given previous node not found in the linked list." << endl;
                return;
            }
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current;
        }
        elements--;
    }
    void Print(){
        node * forloop = head;
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        while (forloop != NULL){
            cout<<forloop->data<<" ";
            forloop = forloop->next;
        }
        cout<<endl;
    }
};

DoubleLinledList::DoubleLinledList()
{
    head = NULL;
    tail = NULL;
    elements = 0;
}

DoubleLinledList::~DoubleLinledList()
{
}


int main(){
    DoubleLinledList ob;
    ob.insert(3);
    ob.Print();
    ob.Delete(3);
    ob.Print();
    // ob.insert(7);
    // ob.insert(8);
    // ob.Print();
    // cout<<ob.TailData()<<endl;
    // ob.insertAfter(7,10);
    // ob.Print();
    // ob.insert_beg(1);
    // ob.Print();
    // ob.Delete_beg();
    // ob.Print();
    // ob.Delete_end();
    // ob.Print();
    // ob.Delete(10);
    // ob.Delete(7);
    // ob.Delete(3);
    // ob.Print();
}