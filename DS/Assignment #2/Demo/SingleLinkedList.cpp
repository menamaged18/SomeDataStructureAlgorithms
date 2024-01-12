#include <iostream>
using namespace std;
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        
        Node(T d) : data(d), next(NULL) {}
    };
    
    Node* head;
    int size;

public:
    LinkedList() : head(NULL), size(0) {}

    void insertAtHead(T element) {
        Node* newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void insertAtTail(T element) {
        Node* newNode = new Node(element);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
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

        Node* newNode = new Node(element);
        Node* curr = head;
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

        Node* temp = head;
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

        Node* curr = head;
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

        Node* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }

    T retrieveAt(int index) {
        if (index >= size || index < 0) {
            cout << "Error: index out of range" << endl;
            return T();
        }

        Node* curr = head;
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

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->data = newElement;
    }

    bool isExist(T element) {
        Node* curr = head;
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

        Node* curr = head;
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
        Node* curr1 = head;
        Node* prev1 = NULL;
        for (int i = 0; i < firstItemIdx; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        Node* curr2 = head;
        Node* prev2 = NULL;
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

        Node* temp = curr2->next;
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
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList<int> myList; // create an empty list of integers
    myList.insertAtHead(5); // adds the element 5 at the head of the list
    myList.insertAtTail(7); // adds the element 7 at the tail of the list
    myList.insertAt(6, 1); // adds the element 6 at index 1 (between 5 and 7)
    myList.print(); // prints the list: 5 6 7
    myList.swap(1,2);
    myList.print(); // prints the list: 5 7 6
    myList.removeAtHead(); // removes the head element 5
    myList.removeAtTail(); // removes the tail element 7
    myList.removeAt(0); // removes the element at index 0 (which is now 6)
    myList.print(); // prints the updated list: empty
}