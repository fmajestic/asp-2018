#include <stdio.h>
#include <stdlib.h>

typedef struct cvr {
    int elem;
    struct cvr * next;
} cvor;

void printLinked(cvor * glava) {
    printf("HEAD  -->");
    for (; glava; glava = glava->next) {
        printf("%3d  -->", glava->elem);
    }
    printf("  END\n");
}

int upis(cvor ** glava, int element) {
    cvor *prev, *head,
         *node = malloc(sizeof(*node));

    /* We can't insert if we get NULL pointers */
    if (!glava || !node)
        return 0;

    node->elem = element;

    /* Special case when we have an empty list,
     * or have to move the original head */
    if (*glava == NULL || (*glava)->elem > element) {
        node->next = *glava;
        *glava = node;
        return 1;
    }

    head = *glava;

    /* Move `prev` to the element after which we insert */
    while (head && head->elem <= element) {
        prev = head;
        head = head->next;
    }

    node->next = prev->next;
    prev->next = node;

    return 1;
}

int main (int argc, char ** argv) {
    int n, i, input;
    cvor *glava = NULL;

    printf("Unesite broj elemenata (max 10): ");
    scanf("%d", &n);
    n = n > 10 ? 10 : n;

    printf("Unesite clanove liste: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &input);
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
