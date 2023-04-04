//
// Created by leeyu on 2023/4/4.
//
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* initNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build(int* nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;

    struct TreeNode* node = initNode(nums[mid]);
    node->left = build(nums, start, mid - 1);
    node->right = build(nums, mid + 1, end);
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return build(nums, 0, numsSize - 1);
}

