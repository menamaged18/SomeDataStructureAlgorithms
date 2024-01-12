#include <iostream>

class MaxHeap {
public:
    MaxHeap() {}

    // Add element to heap
    void add(int val) {
        if (size == capacity) {
            std::cout << "Heap is full, cannot add more elements.\n";
            return;
        }

        arr[size++] = val;
        int index = size - 1;
        while (index > 0 && arr[index] > arr[(index - 1) / 2]) {
            std::swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Build heap from array
    void buildHeap(int* vec, int n) {
        size = n;
        capacity = n;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = vec[i];
        }
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Sort heap
    void sort() {
        int n = size;
        while (size > 1) {
            std::swap(arr[0], arr[size - 1]);
            size--;
            heapify(0);
        }
        size = n;
    }

     // Print heap
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int* arr = NULL;
    int size = 0;
    int capacity = 0;

    // Heapify subtree with root at given index
    void heapify(int index) {
        int largest = index;
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        if (left_child < size && arr[left_child] > arr[largest]) {
            largest = left_child;
        }
        if (right_child < size && arr[right_child] > arr[largest]) {
            largest = right_child;
        }
        if (largest != index) {
            std::swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }
};

int main(){
    MaxHeap mx;
    mx.add(4);
    mx.add(3);
    mx.add(7);
    mx.add(8);
    mx.add(2);
    mx.add(1);
    mx.print();
}