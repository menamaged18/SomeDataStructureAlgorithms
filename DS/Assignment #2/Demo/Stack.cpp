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
            cout << "Error: Stack underflow\n";
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
