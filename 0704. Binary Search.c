//
// Created by leeyu on 2022/5/29.
// https://leetcode.com/problems/binary-search/

#include <stdio.h>


int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int mid;

    while (left <= right) {
        mid = (right + left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;

}


int main() {
    int t1[] = {-1, 0, 3, 5, 9, 12};
    int index = search(t1, sizeof(t1) / sizeof(int), 9);
    printf("%d\n", index);

    int t2[] = {-2,0,3,5,9,12};
    index = search(t2, sizeof(t2) / sizeof(int), 2);
    printf("%d\n", index);
}