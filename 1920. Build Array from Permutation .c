//
// Created by leeyu on 2023/3/27.
//
int* buildArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int *ans = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; ++i) {
        ans[i] = nums[nums[i]];
    }
    return ans;
}