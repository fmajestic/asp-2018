#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 41

void Zamijeni(char * a, char * b) {
    char *tmp;
    if (a == b) return;
    tmp = malloc(STR_LEN * sizeof(*tmp));
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
    free(tmp);
}

void minmax(char ** arr, char ** end, char ** min, char ** max) {
    *min = *arr;
    *max = *arr;

    for (; arr <= end; arr++) {
        *min = strcmp(*arr, *min) < 0 ? *arr : *min;
        *max = strcmp(*arr, *max) > 0 ? *arr : *max;
    }
}

void selectionSort(char ** A, int N, char smjer) {
    char **start, **end, *min, *max;

    start = A;
    end   = A + N - 1;

   for (; start < end; start++, end--) {
        minmax(start, end, &min, &max);

        if (smjer == 0)
            Zamijeni(min, max);

        Zamijeni(*start, min);
        
        if (end - start > 2)
            Zamijeni(*end, max);
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

    selectionSort(arr, n, dir);

    printf("\nSortirano polje:\n");
    for (i = 0; i < n; i++) {
        printf("  %s\t", arr[i]);
        free(arr[i]);
    }

    free(arr);
    return 0;
}
