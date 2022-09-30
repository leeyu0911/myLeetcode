//
// Created by 王立宇 on 2022/9/30.
//
#include <stdlib.h>


typedef struct {
    int numsSize;
    int *nums;
    int *nums_copy;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution *solution = malloc(sizeof(Solution));

    solution->numsSize = numsSize;
    solution->nums = nums;
    solution->nums_copy = malloc(sizeof(int) * numsSize);

    for (int i=0; i<numsSize; ++i) {
        solution->nums_copy[i] = nums[i];
    }
    return solution;
}

int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->numsSize;

    // for (int i=0; i<obj->numsSize; ++i) {
    //     obj->nums[i] = obj->nums_copy[i];
    // }

    return obj->nums_copy;
}

int* solutionShuffle(Solution* obj, int* retSize) {
    *retSize = obj->numsSize;

    for (int i=0; i<obj->numsSize; ++i) {
        int shuffle_index = rand() % obj->numsSize;

        int temp = obj->nums[shuffle_index];
        obj->nums[shuffle_index] = obj->nums[i];
        obj->nums[i] = temp;
    }

    return obj->nums;
}

void solutionFree(Solution* obj) {
    free(obj->nums);
    free(obj->nums_copy);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 * int* param_2 = solutionShuffle(obj, retSize);

 * solutionFree(obj);
*/