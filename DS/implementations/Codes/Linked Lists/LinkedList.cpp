#include <iostream>
using namespace std;
struct node{
    node* next;
    int data;
};
class LinkedList{
    private:
        node * head;
        int size;
    public:
    LinkedList(){
        head = NULL;
        size = 0;
    }
    void insert(int _data){
        node *n_node = new node , *last;
        n_node->data = _data;
        if (head == NULL){
            head = n_node;
            n_node->next = NULL;
            size++;
        }else{
            last = head;
            while (last->next != NULL){
                last = last->next;
            }
            last->next = n_node;
            n_node->next = NULL;
            size++;
        }
    }    
    void insertAT(int at,int v){
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }else{ 
            node *n_node = new node , *current =head ,*N_next ;
            n_node->data = v;
            // if (current->data == at){
            //     N_next = current->next;
            //     current->next = n_node;
            //     n_node->next = N_next;
            // }
            while (current->data != at){
                current = current->next;
            }
            N_next = current->next;
            current->next = n_node;
            n_node->next = N_next ;
            size++;
        }
    }
    void insert_at_beg(int val){
        node *n_node = new node;
        n_node->data = val;
        n_node->next = head;
        head = n_node;
    }
    void Delete_beg(){
        node * current = head ;
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        head = head->next;
        delete current;
    }
    void Delete(int v){
        node * current = head , *previous = head;
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        if (current->data == v){
            head = head->next;
            delete current;
            return;
        }
        while (current->data != v){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
    void Delete_end(){
        node * current = head , *previous = head;
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return;
        }
        while (current->next != NULL){
            previous = current;
            current = current->next;
        }
        previous->next = NULL;
        delete current;
    }
    bool search(int val){
        node * forloop = head;
        if (head == NULL){
            cout<<"This linked list is Empty"<<endl;
            return 0;
        }
        while (forloop != NULL){
            if (forloop->data == val){
                return 1;
            }
            forloop = forloop->next;
        }
        return 0;
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

int main(){
    LinkedList ob;
    ob.insert(5);
    ob.insert(3);
    ob.Print();
    ob.insert_at_beg(3);
    ob.Print();
    ob.Delete_beg();
    ob.Print();
    ob.insertAT(3,7);
    ob.Print();
    ob.Delete_end();
    ob.Print();
    cout<<ob.search(8);
}