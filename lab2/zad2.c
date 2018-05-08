#include <stdio.h>

void swap(int * a, int * b) {
    int tmp;
    if (a == b) return;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void minmax(int * arr, int * end, int ** min, int ** max) {
    *min = arr;
    *max = arr;

    for (; arr <= end; arr++) {
        *min = *arr < *(*min) ? arr : *min;
        *max = *arr > *(*max) ? arr : *max;
    }
}

void selection2Sort(int * A, int n, char smjer) {
    int *start, *end, *min, *max;

    start = A;
    end   = A + n - 1;

    for (; start < end; start++, end--) {
        minmax(start, end, &min, &max);

        /* Turn elements to swap around if descending,
         * this way we can still use the same pointers. */
        if (smjer == 1)
            swap(min, max);

        swap(start, min);

        /* If we're at the last 2 elements,
         * this swap would cancel out the previous one.
         */
        if (end - start > 2)
            swap(end, max);
    }
}

int main (int argc, char **argv) {
    int i, n, dir, nums[10];

    printf("Unesite broj elemenata (max 10): ");
    scanf("%d", &n);
    n = n > 10 ? 10 : n;

    printf("Unesite smjer sortiranja [0 - asc, 1 - desc]: ");
    scanf("%d", &dir);

    printf("Unesite clanove polja:\n");
    for (i = 0; i < n; i++)
        scanf("%d", nums + i);

    selection2Sort(nums, n, dir);

    printf("Sortirano polje: \n");
    for (i = 0; i < n; i++)
        printf("%4d", nums[i]);
    
    return 0;
}
