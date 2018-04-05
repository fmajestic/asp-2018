#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100

int bins(int * arr, int len, int token) {
    int start = 0, end = len - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (token < arr[mid])
            end = mid - 1;
        else if (token > arr[mid])
            start = mid + 1;
        else
            return mid;
    }

    return -1;
}

int zbrojiKvadrate(int * A, int n) {
    int i, sum = 0;

    int *kvad = malloc(n * sizeof(*kvad));

    for (i = 0; i < MAX; i++)
        kvad[i] = (i + 1) * (i + 1);

    for (i = 0; i < n; i++)
        if (bins(kvad, MAX, A[i]) != -1)
            sum += A[i];

    return sum;
}

int main (int argc, char **argv) {
    int *A, n, sum, i;
    
    srand(time(NULL));

    printf("Unesite broj elemenata: ");
    scanf("%d", &n);

    A = malloc(n * sizeof(*A));

    for (i = 0; i < n; i++) {
        A[i] = rand() % MAX + 1;    /* the absolute worst way but eh */
        printf("%4d", A[i]);
    }

    sum = zbrojiKvadrate(A, n);

    printf("\nZbroj kvadrata je: %d\n", sum);

    free(A);
    return 0;
}
