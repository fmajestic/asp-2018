#include <stdio.h>
#include <stdlib.h>

int max(int * arr, int n) {
    if (n == 1) return *arr;
    int maxval = max(arr + 1, n - 1);

    return *arr > maxval ? *arr : maxval;
}

int maxind(int * arr, int n) {
    int maxval = max(arr, n);

    for (int i = 0; i < n; i++)
        if (arr[i] == maxval)
            return i;

    return -1;
}

int maxindrec(int * arr, int n, int i) {
    if (n == 1) return i;
    int maxind = maxindrec(arr + 1, n - 1, i + 1);

    return maxind > i ? maind : i;
}


int strlenrec(char * str) {
    if (*str == '\0') return 0;
    return 1 + strlenrec(str + 1);
}

int main (int argc, char **argv) {
    int A[8] = { 1, 2, 5, 6, 18, 2, 3, -16 };
    char str1[] = "Hello world!";
    char str2[] = "";

    int maxindex = maxind(A, 0);
    int str1len = strlenrec(str1);
    int str2len = strlenrec(str2);

    printf("indeks max: %d\nstring 1: %d chars\nstring 2: %d chars\n", maxval, maxindex, str1len, str2len);

    return 0;
}
