//
// Created by leeyu on 2022/5/29.
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <stdio.h>


int countOdds(int low, int high){
    if (low % 2 == 0 && high % 2 ==0)
        return (high - low) / 2;
    else
        return (high - low) / 2 + 1;
}

int countOdds1(int low, int high){
    int ret = (high - low) / 2;
    if ((low % 2) || (high % 2))
        ret += 1;
    return ret;
}

int main() {
    int n = countOdds(0, 7);
    printf("%d\n", n);
}