#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cvr {
    char elem[41];
    struct cvr * next;
} cvor;

void printLinked(cvor * glava) {
    printf("HEAD  -->");
    for (; glava; glava = glava->next) {
        printf("  %s  -->", glava->elem);
    }
    printf("  END\n");
}

int upis(cvor ** glava, char * niz) {
    cvor *node = malloc(sizeof(*node));

    if (!glava || !node)
        return 0;

    strcpy(node->elem, niz);
    node->next = *glava;
    *glava = node;

    return 1;
}

int main (int argc, char ** argv) {
    int i, n;
    char input[41];
    cvor *glava = NULL;

    printf("Unesite broj elemenata (max 10): ");
    scanf("%d", &n);
    n = n > 10 ? 10 : n;

    printf("Unesite clanove liste: \n");
    for (i = 0; i < n; i++) {
        scanf("%s", input);
        if (upis(&glava, input) == 0)
            printf("Neuspjesan upis!\n");
    }

    printLinked(glava);

    while(glava) {
        glava = glava;
        glava = glava->next;
        free(glava);
    }

    return 0;
}
