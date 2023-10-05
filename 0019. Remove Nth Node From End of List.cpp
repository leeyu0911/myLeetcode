//
// Created by leeyu on 2023/10/5.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *ptr = head;
        while (ptr != NULL) {
            size++;
            ptr = ptr->next;
        }

        ptr = head;
        ListNode *pre = NULL;
        int index = size - n;
        int i = 0;
        while (i != index) {
            pre = ptr;
            ptr = ptr->next;
            ++i;
        }

        if (pre != NULL) {
            pre->next = ptr->next;
            return head;
        } else {
            return head->next;
        }
    }
};