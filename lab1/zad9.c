#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(int * polje, int n, int m) {
    if (n == 0) return;
    
    for (int i = 1; i < n; i++)
        polje[i] *= m;

    f(polje + 1, n - 1, m);
}

int main (int argc, char **argv) {
    int *arr, n, m, i;

    printf("Unesite broj elemenata i bazu: ");
    scanf("%d %d", &n, &m);
    arr = malloc(n * sizeof(*arr));

    for (i = 0; i < n; i++)
        arr[i] = 1;

    f(arr, n, m);

    for (i = 0; i < n; i++)
        printf("%6d", arr[i]);

    free(arr);
    return 0;
}
