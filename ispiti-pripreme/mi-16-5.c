#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * stvori_matricu(int * ulaz, int n) {
    int *retarr = malloc(n * n * sizeof(*retarr));
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            retarr[i*n + j] = ulaz[j] * (i != j);

    return retarr;
}

int main (int argc, char **argv) {
    int i, j, n = 4;
    int ulaz[] = {1, 5, 3, 7};
    int *matrica = stvori_matricu(ulaz, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d", matrica[i*n + j]);
        printf("\n");
    }

    free(matrica);
    return 0;
}
