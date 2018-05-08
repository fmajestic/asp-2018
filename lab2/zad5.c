#include <stdio.h>

void spojiNizove(char * A, char * B, char * Rez) {
    while (*A || *B)
        if (*A >= *B)
            *Rez++ = *A++;
        else
            *Rez++ = *B++;

    *Rez = '\0';
}

int main (int argc, char **argv) {
    char A[] = "ecaDB",
         B[] = "dbECA",
         Rez[20];

    spojiNizove(A, B, Rez);

    printf("%s\n", Rez);

    return 0;
}
