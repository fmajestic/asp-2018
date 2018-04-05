#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double iter_pi(int n) {
    double retval = 0;
    int denom = 1, sign = 1, i;

    for (i = 0; i < n; i++) {
        retval += sign * 1.0 / denom;
        denom += 2;
        sign *= -1;
    }

    return retval * 4;
}

double pi(int n) {
    printf("Fuck this recursive shit lmao\n");
}

int main (int argc, char **argv) {
    int i, n;
    double *pivals;

    printf("Unesite broj broj aproksimacija: ");
    scanf("%d", &n);

    pivals = malloc(n * sizeof(*pivals));

    for (i = 0; i < n; i++) {
        pivals[i] = iter_pi(i + 1);
        printf("%.8f\n", pivals[i]);
    }

    free(pivals);
    return 0;
}
