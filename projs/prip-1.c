#include <stdio.h>
#include <string.h>
#include "util/putils.h"

/**
  * Things to note:
  *   - only opening files once needed, closing right away when no longer using
  *   - only allocating mem once needed, freeing right away
  *   - NULL checks
  *   - EOF IS -1, NOT 0
  */

int main (int argc, char **argv) {
    int *input, *output,
        i, j, t, n = 0;
    FILE *in  = fopen("io-files/in.txt", "r"), *out;

    while(n++, fscanf(in, "%d", &t) != EOF);
    rewind(in); n--;

    input = malloc(n * sizeof(int));
    if (input == NULL) fatal("Input file too large");

    for (i = 0; fscanf(in, "%d", input+i) != EOF; i++);
    fclose(in);

    output = malloc(n * n * sizeof(int));
    if (output == NULL) fatal("Not enough memory for output");

    for (i = 0; *(output+i) = *(input+i), i < n; i++);
    free(input);

    for (i = 1; i < n; i++)
        for (j = 0; j < n; j++)
            *(output + i*n + j) = *(output + (i-1)*n + j) * *(output + j);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%6d", *(output + i*n + j));
        printf("\n");
    }

    out = fopen("io-files/npolje.bin", "wb");
    fwrite(&n, sizeof(int), 1, out);
    fwrite(output, sizeof(int), n * n, out);

    fclose(out);
    free(output);

    return 0;
}
