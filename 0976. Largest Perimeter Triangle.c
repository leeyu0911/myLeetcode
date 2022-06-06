//
// Created by leeyu on 2022/6/6.
//
#include <stdio.h>
#define MAX_NUMS_LEN 1000000

void bucky_sort(char* bucket, int* nums, int numsSize) {
    for (int i = 0; i < numsSize; ++i) {
        bucket[nums[i]] += 1;
    }

    int i = 0, n = 0;
    while (i < MAX_NUMS_LEN) {
        while (bucket[i] > 0) {
            nums[n] = i;
            ++n;
            --bucket[i];
        }
        ++i;
    }
}

int largestPerimeter(int* nums, int numsSize){
    char bucket[MAX_NUMS_LEN] = { 0 };

    bucky_sort(bucket, nums, numsSize);
    for (int i = numsSize - 1; i >= 2; --i) {
        if (nums[i] < (nums[i-1] + nums[i-2])) {
            return nums[i] + nums[i-1] + nums[i-2];
        }
    }
    return 0;
}

int main() {
    int t1[] = {2, 1, 2};
    int n = sizeof(t1) / sizeof(int);
    int r1 = largestPerimeter(t1, n);
    printf("%d\n", r1);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", t1[i]);
    }
}