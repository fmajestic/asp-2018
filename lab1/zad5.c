#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binarnoTrazi(int *polje, int n, int x) {
    int start = 0, end = n - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (x < polje[mid])
            end = mid - 1;
        else if (x > polje[mid])
            start = mid + 1;
        else
            return mid;
    }

    return -1;
}

int recur_binarnoTrazi(int * polje, int start, int end, int x) {
    if (start <= end) {
        int mid = (start + end) / 2;

        if (x < polje[mid])
            return recur_binarnoTrazi(polje, start, mid - 1, x);
        else if (x > polje[mid])
            return recur_binarnoTrazi(polje, mid + 1, end, x);
        else 
            return mid;
    }

    return -1;
}

int main (int argc, char **argv) {
    int *A, n, x, i, index, recindex;

    printf("Unesite broj elemenata:  ");
    scanf("%u", &n);
    
    printf("Unesite broj za pronaci: ");
    scanf("%d", &x);

    A = malloc(n * sizeof(*A));

    printf("\n");

    for (i = 0; i < n; i++)
        A[i] = i + 1;

    index = binarnoTrazi(A, n, x);
    recindex = recur_binarnoTrazi(A, 0, n, x);

    if (index != -1) {
        printf("Indeks u polju: %d\n", index);
        printf("Rekurzivni indeks: %d\n", recindex);
    }
    else
        printf("Broj se ne nalazi u polju\n");

    free(A);
    return 0;
}
