#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpstr(char * a, char * b, char dir) {
    return dir == 1 ? strcmp(a, b) > 0 : strcmp(b, a) > 0;
}

void insertionSort(char ** A, int N, int smjer) {
    int i, j;
    char *move;

    for (i = 1; i < N; i++) {
        for (move = A[i], j = i; j >= 1 && cmpstr(A[j - 1], move, smjer); j--)
            A[j] = A[j - 1];
        
        A[j] = move;
    }
}

int main (int argc, char **argv) {
    int i, n = 10, dir;
    char **arr = malloc(10 * sizeof(*arr));

    for (i = 0; i < n; i++)
        arr[i] = malloc(41 * sizeof(**arr));

    printf("Unesite smjer sortiranja [1 - asc, 0 - desc]: ");
    scanf("%d", &dir);

    printf("Unesite clanove polja (10):\n");
    for (i = 0; i < n; i++)
        scanf("%s", arr[i]);

    insertionSort(arr, n, dir);

    printf("\nSortirano polje:\n");
    for (i = 0; i < n; i++) {
        printf("  %s\t", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}
