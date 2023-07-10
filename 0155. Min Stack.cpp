//
// Created by leeyu on 2023/7/10.
//
#include<iostream>
//#include<utility>
using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        if (minStack.empty())
            minStack.push_back({val, val});
        else
            minStack.push_back({val, min(val, minStack.back().second)});
    }

    void pop() {
        minStack.pop_back();
    }

    int top() {
        return minStack.back().first;
    }

    int getMin() {
        return minStack.back().second;
    }
private:
    vector< pair<int, int> > minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */