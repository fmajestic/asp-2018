#include <stdio.h>
#include <stdlib.h>

typedef struct zps {
    int sifra;
    char naziv[51];
} zapis;

void swap(zapis * a, zapis * b) {
    zapis tmp;
    if (a == b) return;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void obicanBubbleSort(zapis * A, int n, char smjer) {
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (smjer == 0 && A[j].sifra > A[j + 1].sifra)
                swap(A + j, A + j + 1);
            else if (smjer == 1 && A[j].sifra < A[j + 1].sifra)
                swap(A + j, A + j + 1);
}

int main (int argc, char **argv) {
    int i, n, dir;
    zapis popis[10];

    printf("Unesite broj elemenata (max 10): ");
    scanf("%d", &n);
    n = n > 10 ? 10 : n;

    printf("Unesite smjer sortiranja [0 - asc, 1 - desc]: ");
    scanf("%d", &dir);

    printf("Unesite clanove polja: [sifra naziv]\n");
    for (i = 0; i < n; i++)
        scanf("%d %[^\n]s", &(popis[i].sifra), popis[i].naziv);

    obicanBubbleSort(popis, n, dir);

    printf("\n\nSortirano polje:\n");
    for (i = 0; i < n; i++)
        printf("%8d\t", popis[i].sifra);

    printf("\n");
    for (i = 0; i < n; i++)
        printf("%8s\t", popis[i].naziv);

    return 0;
}
