#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    
    Node(T element) {
        data = element;
        next = NULL;
    }
};

template<class T>
class CircularLinkedList {
private:
    Node<T>* head;
    int size;
    
public:
    CircularLinkedList() {
        head = NULL;
        size = 0;
    }

    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            newNode->next = head;
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            head = newNode;
        }
        size++;
    }

    void insertAtEnd(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    void insertAt(T element, int index) {
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtEnd(element);
        } else if (index > 0 && index < size) {
            Node<T>* newNode = new Node<T>(element);
            Node<T>* previous = head;
            for (int i = 0; i < index - 1; i++) {
                previous = previous->next;
            }
            newNode->next = previous->next;
            previous->next = newNode;
            size++;
        } else {
            cout << "Index is out of range." << endl;
        }
    }

    void removeAtHead() {
        if (head == NULL) {
            cout << "List is already empty." << endl;
        } else if (size == 1) {
            delete head;
            head = NULL;
            size--;
        } else {
            Node<T>* current = head;
            while (current->next != head) {
                current = current->next;
            }
            Node<T>* temp = head;
            head = head->next;
            current->next = head;
            delete temp;
            size--;
        }
    }

    void removeAtEnd() {
        if (head == NULL) {
            cout << "List is already empty." << endl;
        } else if (size == 1) {
            delete head;
            head = NULL;
            size--;
        } else {
            Node<T>* current = head;
            Node<T>* previous;
            while (current->next != head) {
                previous = current;
                current = current->next;
            }
            previous->next = head;
            delete current;
            size--;
        }
    }

    void removeAt(int index) {
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtEnd();
        } else if (index > 0 && index < size - 1) {
            Node<T>* previous = head;
            for (int i = 0; i < index - 1; i++) {
                previous = previous->next;
            }
            Node<T>* current = previous->next;
            previous->next = current->next;
            delete current;
            size--;
        } else {
            cout << "Index is out of range." << endl;
        }
    }

    T retrieveAt(int index) {
        if (index >= 0 && index < size) {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data;
        } else {
            cout << "Index is out of range." << endl;
            return NULL;
        }
    }

    void replaceAt(T newElement, int index) {
        if (index >= 0 && index < size) {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            current->data = newElement;
        } else {
            cout << "Index is out of range." << endl;
        }
    }

    bool isExist(T element) {
    // Searches for an element in the list and returns true if it exists, false otherwise
    Node<T>* current = head;
    do {
    if (current->data == element) {
    return true;
    }
    current = current->next;
    } while (current != head);
    return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index >= 0 && index < size) {
            Node<T>* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current->data == element;
        } else {
            cout << "Index is out of range." << endl;
            return false;
        }
    }

    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx >= 0 && firstItemIdx < size && secondItemIdx >= 0 && secondItemIdx < size) {
            if (firstItemIdx == secondItemIdx) {
                return;
            }
            int smallerIndex = min(firstItemIdx, secondItemIdx);
            int largerIndex = max(firstItemIdx, secondItemIdx);
            Node<T>* smallerNode = head;
            for (int i = 0; i < smallerIndex; i++) {
                smallerNode = smallerNode->next;
            }
            Node<T>* largerNode = head;
            for (int i = 0; i < largerIndex; i++) {
                largerNode = largerNode->next;
            }
            // Swap nodes without swapping data.
            Node<T>* smallerNodeNext = smallerNode->next;
            Node<T>* largerNodeNext = largerNode->next;
            if (smallerIndex == 0 || largerIndex == 0) {
                if (largerIndex - smallerIndex == 1) {
                    head = largerNodeNext;
                    smallerNode->next = largerNodeNext->next;
                    largerNodeNext->next = smallerNode;
                } else {
                    head = largerNode;
                    Node<T>* temp = smallerNode->next;
                    smallerNode->next = largerNodeNext->next;
                    largerNode->next = temp;
                    largerNodeNext->next = smallerNode;
                }
            } else {
                if (largerIndex - smallerIndex == 1) {
                    smallerNode->next = largerNodeNext->next;
                    largerNodeNext->next = smallerNode;
                } else {
                    Node<T>* temp = smallerNode->next;
                    smallerNode->next = largerNodeNext->next;
                    largerNode->next = temp;
                    largerNodeNext->next = smallerNode;
                }
            }
        } else {
            cout << "One or both indices are out of range." << endl;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    int circularLinkedListSize() {
        return size;
    }

    void clear() {
        while (size > 0) {
            removeAtHead();
        }
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        } else {
            Node<T>* current = head;
            do {
                cout << current->data << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }
};