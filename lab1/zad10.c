#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double f(double z, int k) {
    if (k == 0) return z;
	return f(z, k-1) * (-1)*z*z / ((2*k + 1) * (2*k));
}

int main (int argc, char **argv) {
    int i;
    double z = 0.5;

    for (i = 0; i < 7; i++)
        printf("%+5.10f\n", f(z, i));

    printf("\n");

    return 0;
}
