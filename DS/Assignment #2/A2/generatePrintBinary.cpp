#include <iostream>
using namespace std;

template<typename T>
class Queue {
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
    Queue() : front(NULL), rear(NULL), size(0) {}

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

void generatePrintBinary(int n)
{
    // Create an empty queue of strings
    Queue<string> q;

    // Enqueue the first binary number
    q.enqueue("1");

    // This loops is like BFS of a tree with 1 as root
    // 0 as left child and 1 as right child and so on
    while (n--) {
        // print the front of queue
        string s1 = q.first();
        q.dequeue();
        cout << s1 << "\n";

        string s2 = s1; // Store s1 before changing it

        // Append "0" to s1 and enqueue it
        q.enqueue(s1.append("0"));

        // Append "1" to s2 and enqueue it. Note that s2
        // contains the previous front
        q.enqueue(s2.append("1"));
    }
}
int main()
{
    int n = 10;

    // Function call
    generatePrintBinary(n);
}
