//
// Created by leeyu on 2023/3/13.
//
#include <stdio.h>
int char_len(char *c) {
    int count = 0;
    while (*c != '\0') {
        count++;
        c++;
    }
    return count;
}

int strStr(char *haystack, char *needle){
    if (*haystack == '\0' || char_len(haystack) < char_len(needle)) {
        return -1;
    }
    int index = 0;
    char *h = haystack;
    char *n = needle;
    while (*h != '\0') {
        char *hh = h;
        printf("%c\n", *h);
        while (*n != '\0') {
            printf("    %c\n", *n);
            if (*hh == *n) {
                hh++; n++;
            } else {
                n = needle;
                break;
            }
            if (*n == '\0') {
                return index;
            }
        }
        h++;
        index++;
    }
    return -1;
}

int main() {
    char *haystack = "mississippi";
    char *needle = "issip";
    int a = strStr(haystack, needle);
    printf("%d\n", a);
}
