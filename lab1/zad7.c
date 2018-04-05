#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int * randsqr(int * arr, int n) {
    int i, j, t;
    int * ret = malloc(n * sizeof(*ret));

    for (i = 0; i < n; i++) {
        ret[i] = arr[i] * arr[i];

        j = (i != 0) ? rand() % (i + 1): 0;

        t = ret[j];
        ret[j] = ret[i];
        ret[i] = t;
    }

    return ret;
}

int main (int argc, char **argv) {
    int *in, *out, n, i;

    srand(time(NULL));

    printf("Unesite broj clanova: ");
    scanf("%d", &n);

    in = malloc(n * sizeof(*in));

    for (i = 0; i < n; i++)
        in[i] = i + 1;

    out = randsqr(in, n);

    for (i = 0; i < n; i++)
        printf("%6d", out[i]);

    free(in);
    free(out);
    return 0;
}
