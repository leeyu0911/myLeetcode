//
// Created by leeyu on 2022/10/6.
//

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val){
    if (!head) return head;

    struct ListNode newHead = { -1, head };
    struct ListNode *pre = &newHead;
    struct ListNode *cur = pre->next;

    while (cur) {
        if (cur->val == val) {
            pre->next = cur->next;
            cur = cur->next;
        } else {
            pre = pre->next;
            cur = cur->next;
        }
    }
    return newHead.next;
}