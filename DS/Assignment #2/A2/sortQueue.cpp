#include "Queue1.cpp"

void sortQueue(Queue1<int>& q) {
    int n = q.queueSize();
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        int min_val = q.first();
        Queue1<int> temp_q;
        for (int j = 0; j < n - i; j++) {
            int current_val = q.first();
            q.dequeue();
            if (current_val < min_val) {
                temp_q.enqueue(min_val);
                min_val = current_val;
                min_index = j + i;
            }
            else {
                temp_q.enqueue(current_val);
            }
        }
        q.enqueue(min_val);
        for (int j = 0; j < n - i - 1; j++) {
            int current_val = temp_q.first();
            temp_q.dequeue();
            if (j == min_index - i) {
                min_val = current_val;
            }
            else {
                q.enqueue(current_val);
            }
        }
        q.enqueue(min_val);
    }