//
// Created by leeyu on 2023/4/12.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if (list1 == NULL) return list2;
    else if (list2 == NULL) return list1;

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main() {
    node* n = malloc(sizeof(node));
    n->val = 3;
    n->next = malloc(sizeof(node));
    n->next->val = 4;
    printf("%d\n", n->val);
    printf("%d\n", n->next->val);

    node* ni = NULL;
    if (ni) printf("!\n");

}