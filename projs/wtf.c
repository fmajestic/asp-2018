#include <stdio.h>
#include <string.h>

#ifdef _WIN32
    #include "C:/Users/Filip/STATIC/util/putils.h"
#elif defined()

typedef struct {
    char JMBG[14], flname[41];
    float income, returntax;
} entry_t;

entry_t* load(char *fname, int *entries) {
    entry_t *data;

    FILE *fp = fopen(fname, "rb");
    if (fp == NULL)
        fatal("Cannot open file.\n");
    
    fread(entries, sizeof(*entries), 1, fp);
    if (*entries < 0)
        fatal("Negative nr. of entries");
    
    data = malloc(*entries * sizeof(entry_t));
    if (data == NULL)
        fatal("Not enough memory to load entries");

    fread(data, sizeof(entry_t), *entries, fp);
    fclose(fp);

    return data;
}

/* This, SOMEHOW, prints most of the environment PATH variable...
 * Fuck me if I know how tho.
 * Did i Spectre myself on accident?
 * I mean not this exactly but the %s in main
 */
entry_t *max_return_tax(entry_t *data, int entries) {
    float max = 0; /* because we know it's positive, otherwise FLOAT_MIN */
    int i = 0;
    entry_t *cu = NULL;

    do {
        cu = data->returntax > max ? data : cu;
        data++;
    } while (data++ && i++ < entries);

    return cu;
}


int main(int argc, char **argv) {
    int entries;
    entry_t *data, *rmax;

    data = load("io-files/podaci.dat", &entries);
    rmax = max_return_tax(data, entries);

    if (rmax != NULL)
        printf("Highest amount to pay: %s, %f\n", rmax->flname, rmax->returntax);
    else
        printf("Nobody has to pay any taxes\n");

    free(data);
    return 0;
}
