#include <cstdlib>

//
// Created by leeyu on 2023/7/1.
//
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        size = k;
        queue = new int[k];
        for (int i = 0; i < k; ++i) {
            queue[i] = -1;
        }
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        queue[tail] = value;
        tail = (tail + 1) % size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        queue[front] = -1;
        front = (front + 1) % size;
        return true;
    }

    int Front() {
        return queue[front];
    }

    int Rear() {
        return queue[(tail + size - 1) % size];
    }

    bool isEmpty() {
        if (queue[tail] == -1 && queue[front] == -1) return true;
        return false;
    }

    bool isFull() {
        if (front == tail && queue[tail] != -1) return true;
        return false;
    }
private:
    int size = 0;
    int front = 0, tail = 0;
    int *queue = nullptr;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */