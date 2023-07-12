//
// Created by leeyu on 2023/7/12.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode* head) {
        int count = 0;
        ListNode *ptr = head;
        while (ptr != nullptr) {
            stack.push_back(ptr);
            ptr = ptr->next;
            count++;
        }
        if (count < 3) return;

        ptr = head;
        int index = 0;
        while (index <= count/2) {
            stack.back()->next = ptr->next;
            ptr->next = stack.back();
            ptr = stack.back()->next;
            stack.pop_back();
            index++;
        }
        ptr->next = nullptr;
    }
private:
    vector<ListNode*> stack;
};

//    ListNode *creatReverseList(ListNode *head, int &count) {
//        ListNode *pt = head;
//        ListNode *reverse = nullptr;
//        while (pt) {
//            auto *node = new ListNode(pt->val, reverse);
//            reverse = node;
//            pt = pt->next;
//            count++;
//        }
//        return reverse;
//    }