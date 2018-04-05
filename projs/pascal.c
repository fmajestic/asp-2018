#include <stdio.h>

int pascal(int row, int col) {
    if (col > row) return 0;
    if (col == 0 || row == col) return 1;
    return pascal(row - 1, col) + pascal(row - 1, col - 1);
}

int main (void) {
    int i, j;

    for (i = 0; i <= 10; i++) {
        for (j = 0; j <= i; j++)
           printf("Pascal (%2d,%2d): %5d\n", i, j, pascal(i, j));
        printf("\n");
    }

    return 0;
}
