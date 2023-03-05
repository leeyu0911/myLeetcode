//
// Created by leeyu on 2023/3/5.
//
#include <stdio.h>
//#define bool int
//#define true 1
//#define false 0

typedef enum {
    true = 1, false = 0
}bool;


struct ListNode {
    int val;
    struct ListNode *next;
};


bool hasCycle(struct ListNode *head) {
    if (head == NULL)
        return false;

    struct ListNode *f = head;
    struct ListNode *s = head;
    while (f != NULL && f->next != NULL) {
        f = f->next->next;
        s = s->next;
        if (f == s) return true;
    }
    return false;
}