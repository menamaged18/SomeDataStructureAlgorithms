#include <iostream>
using namespace std;
template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(T data): data(data), prev(NULL), next(NULL) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList(): head(NULL), tail(NULL), size(0) {}

    void insertAtHead(T element) {
        Node* new_node = new Node(element);
        if (head == NULL) {
            tail = new_node;
        } else {
            head->prev = new_node;
            new_node->next = head;
        }
        head = new_node;
        size++;
    }

    void insertAtTail(T element) {
        Node* new_node = new Node(element);
        if (tail == NULL) {
            head = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
        }
        tail = new_node;
        size++;
    }

    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtTail(element);
        } else {
            Node* new_node = new Node(element);
            Node* current_node = head;
            for (int i = 0; i < index - 1; i++) {
                current_node = current_node->next;
            }
            new_node->prev = current_node;
            new_node->next = current_node->next;
            current_node->next->prev = new_node;
            current_node->next = new_node;
            size++;
        }
    }

    void insertAfter(Node* prev_node, T element) {
        if (prev_node == NULL) {
            cout<<"Previous node cannot be null"<<endl;
            return;
        }
        Node* new_node = new Node(element);
        new_node->prev = prev_node;
        new_node->next = prev_node->next;
        prev_node->next->prev = new_node;
        prev_node->next = new_node;
        size++;
    }

    void removeAtHead() {
        if (head == NULL) {
            cout<<"list is empty"<<endl; 
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
        size--;
    }

    void removeAtTail() {
        if (tail == NULL) {
            cout<<"list is empty"<<endl; 
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
        size--;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtTail();
        } else {
            Node* current_node = head;
            for (int i = 0; i < index; i++) {
                current_node = current_node->next;
            }
            current_node->prev->next = current_node->next;
            current_node->next->prev = current_node->prev;
            delete current_node;
            size--;
        }
    }

    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        Node* current_node = head;
        for (int i = 0; i < index; i++) {
            current_node = current_node->next;
        }
        return current_node->data;
    }

    Node return_node(int index){
        if (index < 0 || index >= size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        Node* current_node = head;
        for (int i = 0; i < index; i++) {
            current_node = current_node->next;
        }
        return current_node;
    }

    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        Node* current_node = head;
        for (int i = 0; i < index; i++) {
            current_node = current_node->next;
        }
        current_node->data = newElement;
    }

    bool isExist(T element) {
        Node* current_node = head;
        while (current_node != NULL) {
            if (current_node->data == element) {
                return true;
        }
        current_node = current_node->next;
    }
    return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        Node* current_node = head;
        for (int i = 0; i < index; i++) {
            current_node = current_node->next;
        }
        return current_node->data == element;
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            cout<<"Index out of range"<<endl; 
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        Node* first_node = head;
        for (int i = 0; i < firstItemIdx; i++) {
            first_node = first_node->next;
        }
        Node* second_node = head;
        for (int i = 0; i < secondItemIdx; i++) {
            second_node = second_node->next;
        }
        Node* first_prev = first_node->prev;
        Node* first_next = first_node->next;
        Node* second_prev = second_node->prev;
        Node* second_next = second_node->next;
        
        if (first_node == head) {
            head = second_node;
        } else if (second_node == head) {
            head = first_node;
        }
        
        if (first_node == tail) {
            tail = second_node;
        } else if (second_node == tail) {
            tail = first_node;
        }
        
        if (first_node->next == second_node) { //neighbours nodes
            first_node->prev = second_node;
            first_node->next = second_next;
            second_node->prev = first_prev;
            second_node->next = first_node;
            if (first_prev != NULL) {
                first_prev->next = second_node;
            }
            if (second_next != NULL) {
                second_next->prev = first_node;
            }
        } else if (second_node->next == first_node) { //in other words if 2 nodes only
            second_node->prev = first_node;
            second_node->next = first_next;
            first_node->prev = second_prev;
            first_node->next = second_node;
            if (second_prev != NULL) {
                second_prev->next = first_node;
            }
            if (first_next != NULL) {
                first_next->prev = second_node;
            }
        } else {
            first_node->prev = second_prev;
            first_node->next = second_next;
            second_node->prev = first_prev;
            second_node->next = first_next;
            if (first_prev != NULL) {
                first_prev->next = second_node;
            }
            if (second_prev != NULL) {
                second_prev->next = first_node;
            }
            if (first_next != NULL) {
                first_next->prev = second_node;
            }
            if (second_next != NULL) {
                second_next->prev = first_node;
            }
        }
    }

    void reverse() {
        Node* current_node = head;
        while(current_node != NULL) {
            Node* temp = current_node->prev;
            current_node->prev = current_node->next;
            current_node->next = temp;
            current_node = current_node->prev;
        }
        Node* temp = head;
        head = tail;
        tail = temp;
    }

    bool isEmpty() {
        return size == 0;
    }

    int doubleLinkedListSize() {
        return size;
    }

    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        size = 0;
    }

    void forwardTraversal() {
        Node* current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }

    void backwardTraversal() {
        Node* current_node = tail;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->prev;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList<int> list;

    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtTail(3);
    list.insertAt(1, 4);
    // list is now: 2 <-> 1 <-> 4 <-> 3

    list.insertAfter(&(list.return_node(1)), 5);
    // list is now: 2 <-> 1 <-> 5 <-> 4 <-> 3

    list.removeAtHead();
    list.removeAtTail();
    // list is now: 1 <-> 5 <-> 4

    cout << "Size: " << list.doubleLinkedListSize() << endl;
    cout << "First element: " << list.retrieveAt(0) << endl;
    cout << "Last element: " << list.retrieveAt(list.doubleLinkedListSize()-1) << endl;

    list.replaceAt(6, 1);
    // list is now: 1 <-> 6 <-> 4

    cout << "Is 4 in the list? " << list.isExist(4) << endl;
    cout << "Is item at index 1 equal to 6? " << list.isItemAtEqual(6, 1) << endl;

    list.swap(0, 1);
    // list is now: 6 <-> 1 <-> 4

    list.reverse();
    // list is now: 4 <-> 1 <-> 6

    cout << "Forward traversal: ";
    list.forwardTraversal();

    cout << "Backward traversal: ";
    list.backwardTraversal();

    list.clear();
    // list is now empty
}
