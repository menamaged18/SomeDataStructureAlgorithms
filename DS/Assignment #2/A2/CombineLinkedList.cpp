#include <bits/stdc++.h>
using namespace std;
template <class T>
struct  Node {
    T data;
    Node* next;
    Node(T el):data(el){}
};
template <class T>
class LinkedList {
public:

    Node<T>* head;
    int size;

    LinkedList() : head(NULL), size(0) {}

    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtTail(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
        } else {
            Node<T>* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        size++;
    }

    void insertAt(T element, int index) {
        if (index >= size || index < 0) {
            cout << "Error: index out of range" << endl;
            return;
        }

        if (index == 0) {
            insertAtHead(element);
            return;
        }

        Node<T>* newNode = new Node<T>(element);
        Node<T>* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    void removeAtHead() {
        if (head == NULL) {
            cout << "Error: list is empty" << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void removeAtTail() {
        if (head == NULL) {
            cout << "Error: list is empty" << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            size--;
            return;
        }

        Node<T>* curr = head;
        //curr->next->next this to make us in the node that it's before the last node
        while (curr->next->next != NULL) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = NULL;
        size--;
    }

    void removeAt(int index) {
        if (index >= size || index < 0) {
            cout << "Error: index out of range" << endl;
            return;
        }

        if (index == 0) {
            removeAtHead();
            return;
        }

        Node<T>* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node<T>* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }

    T retrieveAt(int index) {
        if (index >= size || index < 0) {
            cout << "Error: index out of range" << endl;
            return T();
        }

        Node<T>* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data;
    }

    void replaceAt(T newElement, int index) {
        if (index >= size || index < 0) {
            cout << "Error: index out of range" << endl;
            return;
        }

        Node<T>* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->data = newElement;
    }

    bool isExist(T element) {
        Node<T>* curr = head;
        while (curr != NULL) {
            if (curr->data == element) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index >= size || index < 0) {
            cout << "Error: index out of range" << endl;
            return false;
        }

        Node<T>* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx == secondItemIdx) {
            return; // no need to swap
        }

        if (firstItemIdx >= size || firstItemIdx < 0 ||
            secondItemIdx >= size || secondItemIdx < 0) {
            cout << "Error: index out of range" << endl;
            return;
        }
        Node<T>* curr1 = head;
        Node<T>* prev1 = NULL;
        for (int i = 0; i < firstItemIdx; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        Node<T>* curr2 = head;
        Node<T>* prev2 = NULL;
        for (int i = 0; i < secondItemIdx; i++) {
            prev2 = curr2;
            curr2 = curr2->next;
        }

        if (prev1 != NULL) {
            prev1->next = curr2;
        } else {
            head = curr2;
        }

        if (prev2 != NULL) {
            prev2->next = curr1;
        } else {
            head = curr1;
        }

        Node<T>* temp = curr2->next;
        curr2->next = curr1->next;
        curr1->next = temp;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int linkedListSize() {
        return size;
    }

    void clear() {
        while (head != NULL) {
            removeAtHead();
        }
    }

    void print() {
        Node<T>* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    friend void printwithnode(Node<T>* n);

// Merges two given lists in-place.
// This function mainly compares head
// nodes and calls mergeUtil()
    friend Node<T>* mergee(Node<T>* h1, Node<T>* h2);
};
template <class T>
Node<T>* mergee(Node<T>* h1, Node<T>* h2)
{
if (!h1)
return h2;
if (!h2)
return h1;

// start with the linked list
// whose head data is the least
if (h1->data < h2->data)
{
h1->next = mergee(h1->next, h2);
return h1;
}
else
{
h2->next = mergee(h1, h2->next);
return h2;
}
}
template <class T>
void printwithnode(Node<T>* n) {
    Node<T>* curr = n;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    LinkedList<int> myList ;// create an empty list of integers
    LinkedList<int>  mylist2;
    myList.insertAtHead(100);
    myList.insertAtHead(90);
    myList.insertAtHead(60);
    mylist2.insertAtHead(95);
    mylist2.insertAtHead(80);
    mylist2.insertAtHead(70);
    printwithnode(mergee(myList.head,mylist2.head));
    //mylist2.print(); // prints the updated list: empty
}
