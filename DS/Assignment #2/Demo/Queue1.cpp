#include <iostream>
using namespace std;

template<typename T>
class Queue1 {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(NULL) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue1() : front(NULL), rear(NULL), size(0) {}

    void enqueue(T element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        Node* temp = front;
        T element = temp->data;
        front = front->next;
        delete temp;
        size--;
        return element;
    }

    T first() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return T();
        }
        return front->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    int queueSize() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Queue1<int> q;
    q.enqueue(5);
    // q.enqueue(8);
    // q.print();
}
