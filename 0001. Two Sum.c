//
// Created by leeyu on 2022/11/5.
//
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#pragma GCC optimize ("O3")
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[j] == target - nums[i]) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return NULL;
}

