//
// Created by leeyu on 2023/3/27.
//
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    *returnSize = 2 * numsSize;
    int *ans = malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize; ++i) {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }

    return ans;
}