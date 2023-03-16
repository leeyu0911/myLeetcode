//
// Created by leeyu on 2023/3/16.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int char_to_dec(char *c) {
    int sum = 0;
    unsigned long len = strlen(c);

    while (*c != '\0') {
        sum += ((int)*c-48) * (int)pow(2, --len);
        c++;
    }
    return sum;
}


char * addBinary(char * a, char * b){
    unsigned long len_a = strlen(a);
    unsigned long len_b = strlen(b);
    unsigned long len_output = (len_a > len_b ? len_a : len_b) + 1;
    char *ans = malloc(len_output + 1);
    int sum = 0;

    ans[len_output] = '\0';

    while (len_a > 0 || len_b > 0 || sum > 0) {
        if (len_a > 0) {
            sum += a[--len_a] - '0';
        }
        if (len_b > 0) {
            sum += b[--len_b] - '0';
        }
        ans[--len_output] = sum % 2 + '0';
        sum /= 2;
    }

    return ans + len_output;
}

int main() {
    char *c = "1111";
    printf("%d\n", char_to_dec(c));
}