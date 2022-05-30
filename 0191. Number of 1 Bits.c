//
// Created by leeyu on 2022/5/30.
// https://leetcode.com/problems/number-of-1-bits/


#include "stdio.h"
typedef unsigned int uint32_t;

int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}


int hammingWeight1(uint32_t n) {
    if(n==0) return 0;
    return 1 + hammingWeight(n&(n-1));
}


int main() {
    printf("%d\n", hammingWeight(10));
}