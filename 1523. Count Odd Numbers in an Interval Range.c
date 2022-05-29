//
// Created by leeyu on 2022/5/29.
// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

#include <stdio.h>


int countOdds(int low, int high){
    if (low == high) {
        if (low % 2 == 0) return 0;
        else return 1;
    }

    int count = 1;
    int num = low;
    if (low % 2 == 0) {
        ++num;
    }

    num = num + 2;
    while (num <= high) {
        num = num + 2;
        ++count;
    }

    return count;
}

int main() {
    int n = countOdds(0, 7);
    printf("%d\n", n);
}