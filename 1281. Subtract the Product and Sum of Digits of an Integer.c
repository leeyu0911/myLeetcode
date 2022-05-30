//
// Created by leeyu on 2022/5/30.
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/



int subtractProductAndSum(int n){
    int sum1 = 1;
    int sum2 = 0;

    while (n > 0) {
        int r = n % 10;
        sum1 *= r;
        sum2 += r;
        n /= 10;
    }
    return sum1 - sum2;
}