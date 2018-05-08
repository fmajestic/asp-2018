#include <stdio.h>
#include <string.h>

void spojiPolja(int * A, int * B, int * Rez, int n1, int n2) {
    int in1 = 0, in2 = 0, i;

    for (i = 0; i < n1 + n2; i++) {
        if (A[in1] >= B[in2])
            Rez[i] = A[in1++];
        else
            Rez[i] = B[in2++];
    }
}

int main (int argc, char **argv) {
    int A[] = {9, 7, 5, 3, 1},
        B[] = {8, 6, 4, 2, 0},
        Rez[10], i;

    spojiPolja(A, B, Rez, 5, 5);

    for (i = 0; i < 10; i++)
        printf("%3d", Rez[i]);
    printf("\n");

    return 0;
}
