#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define true 1
#define false 0
typedef char bool;

char * trimwhite(char * str) {
    bool skipping = false;
    int i, j = 0, len = strlen(str) + 1;
    char *ret = calloc(len, sizeof(*ret));

   do {
        if (!skipping)
            ret[j++] = *str;
        
        if (isspace(*str) && isspace(*(str + 1)))
            skipping = true;
        else
            skipping = false;
    } while (*str++);

    return ret;
}

int main (int argc, char **argv) {
    char *in, *out;

    in = malloc(1024 * sizeof(*in));

    printf("Unesite string: ");
    scanf("%[^\n]s", in);

    out = trimwhite(in);
    printf("Sazeti string: %s\n", out);

    free(in);
    free(out);
    return 0;
}
