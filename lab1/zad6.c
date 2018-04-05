#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * ostaviSlova(char * niz) {
    int i, j = 0;
    int outlen, inlen = strlen(niz) + 1;
    char * ret = calloc(inlen, sizeof(*ret));

    do
        if (isalpha(niz[i]))
            ret[j++] = *niz;
    while(*niz++);

    outlen = strlen(ret + 1);

    return realloc(ret, outlen);
}

int main (int argc, char **argv) {
    char *in = "asp123 hello_da231", *out;    

    out = ostaviSlova(in);
    printf("%s\n", out);

    free(out);
    return 0;
}
