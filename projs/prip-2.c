#include <stdio.h>
#include <string.h>
#include "util/putils.h"

typedef struct {
    char JMBG[14], flname[41];
    float income, rtax;
} entry_t;

entry_t* load(char *fname, int *entries) {
    entry_t *data;

    FILE *fp = fopen(fname, "rb");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return NULL;
    }
    
    fread(entries, sizeof(*entries), 1, fp);
    if (*entries < 0) fatal("Negative nr. of entries");
    
    data = malloc(*entries * sizeof(entry_t));
    if (data == NULL) fatal("Not enough memory to load entries");

    fread(data, sizeof(entry_t), *entries, fp);
    fclose(fp);

    return data;
}

entry_t *mrtax(entry_t *data, int entries) {
    float max = 0; /* because we know it's positive, otherwise FLOAT_MIN */
    int i = 0;
    entry_t *cu = NULL;

    while (i++ < entries) {
        cu = data->rtax > max ? data : cu;
        data++;
    }

    return cu;
}


int main(int argc, char **argv) {
    int entries;
    entry_t *data, *rmax;

    printf("My name is %s\n", argv[0]);

    data = load("io-files/podaci.dat", &entries);
    rmax = mrtax(data, entries);

    if (rmax != NULL)
        printf("Highest amount to pay: %s, %f\n", rmax->flname, rmax->rtax);
    else
        printf("Nobody has to pay any taxes\n");

    free(data);
    return 0;
}
