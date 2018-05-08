#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_LEN 41  

int cmpstr(char * a, char * b, int dir) {
    return dir == 1 ? strcmp(a, b) > 0 : strcmp(b, a) > 0;
}

void shellSort(char ** A, int N, int smjer) {
    int i, j, korak;
    char *move = malloc(STR_LEN * sizeof(*move));

    for (korak = N/2; korak > 0; korak /= 2) {
        for (i = korak; i < N; i++) {
            strcpy(move, A[i]);

            for (j = i; j >= korak && cmpstr(A[j - korak], move, smjer); j -= korak)
                strcpy(A[j], A[j - korak]);

            strcpy(A[j], move);
        }
    }
}

int main (int argc, char **argv) {
    int i, n = 10, dir;
    char **arr = malloc(10 * sizeof(*arr));

    for (i = 0; i < n; i++)
        arr[i] = malloc(STR_LEN * sizeof(**arr));

    printf("Unesite smjer sortiranja [1 - asc, 0 - desc]: ");
    scanf("%d", &dir);

    printf("Unesite clanove polja:\n");
    for (i = 0; i < n; i++)
        scanf("%s", arr[i]);

    shellSort(arr, n, dir);

    printf("\nSortirano polje:\n");
    for (i = 0; i < n; i++) {
        printf("  %s\t", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}
