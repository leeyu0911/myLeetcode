//
// Created by leeyu on 2022/11/5.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20000
typedef struct hashmap Dict;

struct hashmap {
    int keys[SIZE];    // nums[i]
    int values[SIZE];  // i

    void (*init)(Dict *);
    int (*hash)(int);
    int (*search)(Dict *, int);
    void (*insert)(Dict *, int, int);
};

int hash(int key) {
    int index = key % SIZE;
    return index < 0 ? index + SIZE : index;
}

int search(Dict *dict, int key) {
    int index = hash(key);

    while (dict->values[index]) {
        if (dict->keys[index] == key)
            return dict->values[index];
        index++;
    }
    return 0;
}

void insert(Dict *dict, int key, int value) {
    int index = hash(key);

    while (dict->values[index]) {
        index++;
    }

    dict->keys[index] = key;
    dict->values[index] = value;
}

void init(Dict *dict) {
    for (int i = 0; i < SIZE; ++i) {
        dict->values[i] = 0;
    }
    dict->hash = hash;
    dict->search = search;
    dict->insert = insert;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Dict dict;
    dict.init = init;
    dict.init(&dict);

    for (int i = 0; i < numsSize; ++i) {
        int diff = target - nums[i];
        int value = search(&dict, diff);

        if (value) {
            int *ans = (int *)malloc(2 * sizeof(int));
            ans[0] = value - 1;  // recover
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }

        insert(&dict, nums[i], i + 1);  // index start from 1
    }

    return NULL;
}