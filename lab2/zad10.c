#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_LEN 41

void Zamijeni(char * a, char * b) {
    char * tmp = malloc(STR_LEN * sizeof(*tmp));
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
    free(tmp);
}

void bubbleSortPoboljsani(char ** A, int n, int smjer) {
    int i, j, did_swap = 1;

    for (i = 0; did_swap; i++) {
        did_swap = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (smjer == 1 && strcmp(A[j], A[j + 1]) > 0) {
                Zamijeni(A[j], A[j + 1]);
                did_swap = 1;
            } else if (smjer == 0 && strcmp(A[j], A[j + 1]) < 0) {
                Zamijeni(A[j], A[j + 1]);
                did_swap = 1;
            }
        }

        if (did_swap == 0)
            break;
    } 
}

int main (int argc, char **argv) {
    int i, n = 10, dir;
    char **arr = malloc(10 * sizeof(*arr));

    for (i = 0; i < n; i++)
        arr[i] = malloc(STR_LEN * sizeof(**arr));

    printf("Unesite smjer sortiranja [1 - asc, 0 - desc]: ");
    scanf("%d", &dir);

    printf("Unesite clanove polja (10):\n");
    for (i = 0; i < n; i++)
        scanf("%s", arr[i]);

    bubbleSortPoboljsani(arr, n, dir);

    printf("\nSortirano polje:\n");
    for (i = 0; i < n; i++) {
        printf("  %s\t", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}
