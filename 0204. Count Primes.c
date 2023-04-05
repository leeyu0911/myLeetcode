//
// Created by leeyu on 2023/4/4.
//
#include <stdio.h>
#include <stdlib.h>

int countPrimes(int n){
    if (n <= 2) return 0;

    int count = 0;
    char* isPrime = calloc(n, sizeof(char));
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) continue;
        ++count;
        for (long j = (long)i * i; j < n; j += i) {
            isPrime[j] = 1;
        }
    }

    return count;
}


int main() {
//    printf("%d\n", countPrimes(10));
    printf("%d\n", countPrimes(5000000));

}