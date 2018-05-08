#include <stdio.h>

typedef struct {
    int pbr;
    char naziv[41];
} zapis;

int cmpzapis(zapis * a, zapis * b, char dir) {
    return dir == 0 ? a->pbr > b->pbr : a->pbr < b->pbr;
}

void insertionSort(zapis * A, int n, char smjer) {
    int i, j;
    zapis move;

    for (i = 1; i < n; i++) {
        for (move = A[i], j = i; j >= 1 && cmpzapis(A + j - 1, &move, smjer); j--)
            A[j] = A[j - 1];

        A[j] = move;
    }
}

int main (int argc, char **argv) {
    int i, n, dir;
    zapis popis[10];

    printf("Unesite broj elemenata (do 10): ");
    scanf("%d", &n);
    /* Smanjimo n na 10 ako je preko */
    n = n > 10 ? 10 : n;

    printf("Unesite smjer sortiranja [0 - asc, 1 - desc]: ");
    scanf("%d", &dir);

    printf("Unesite clanove polja: [pbr naziv]\n");
    for (i = 0; i < n; i++)
        scanf("%d %[^\n]s", &(popis[i].pbr), popis[i].naziv);

    insertionSort(popis, n, dir);

    printf("\n\nSortirano polje:\n");
    for (i = 0; i < n; i++)
        printf("%8d\t", popis[i].pbr);

    printf("\n");
    for (i = 0; i < n; i++)
        printf("%8s\t", popis[i].naziv);

    return 0;
}
