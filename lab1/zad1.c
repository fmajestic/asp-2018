#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ispis(float * A, int n) {
    if (*A < 0)
        printf("%f\n", *A);

    if (n > 0)
        ispis(A + 1, n - 1);
}

int main (int argc, char **argv) {
    int n, i;
    float *A;

    printf("Unesite broj elemenata: ");
    scanf("%d", &n);
        
    A = malloc(n * sizeof(*A));

    if (A == NULL) {
        fprintf(stderr, "Nema dovoljno memorije.\n");
        exit(1);
    }

    printf("\nUnesite elemente:\n");
    for (i = 0; i < n; i++)
        scanf("%f", A + i);

    printf("\nNegativni elementi:\n");
    ispis(A, n);

    free(A);
    return 0;
}
