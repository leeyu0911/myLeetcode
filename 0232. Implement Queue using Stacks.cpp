//
// Created by leeyu on 2023/7/31.
//
#include <iostream>
using namespace std;


class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        queue.push_back(x);
    }

    int pop() {
        int temp = queue.front();
        queue.erase(queue.begin());
        return temp;
    }

    int peek() {
        return queue[0];
    }

    bool empty() {
        return queue.empty();
    }

private:
    vector <int> queue;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */