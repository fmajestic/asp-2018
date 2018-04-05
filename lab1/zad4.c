#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double expo(double x, int n, int * fakt, double * xpot) {
    if (n == 0)
        return 1;

    int _fakt = *fakt / n;
    double _xpot = *xpot / x;

    return (*xpot / *fakt) + expo(x, n - 1, &_fakt, &_xpot);
}

int main (int argc, char **argv) {
    int n, fakt, i;
    double *A, x, xpot;

    printf("Unesite broj aproksimacija: ");
    scanf("%d", &n);

    A = malloc(n * sizeof(*A));

    printf("Unesite tocku aproksimacije: ");
    scanf("%lf", &x);

    xpot = 1;
    fakt = 1;

    for (i = 0; i < n; i++) {
        fakt *= (i == 0) ? 1 : i;
        xpot *= (i == 0) ? 1 : x;

        A[i] = expo(x, i, &fakt, &xpot);

        printf("%.7f\n", A[i]);
    }

    free(A);
    return 0;
}
