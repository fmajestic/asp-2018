#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct singlist {
    int value;
    struct singlist * next;
} sllnode;

sllnode * sllnode_create(int value) {
    sllnode *retval = malloc(sizeof(*retval));

    if (retval == NULL)
        exit(1); /* Out of memory. */
    
    retval->value = value;
    retval->next = NULL;

    return retval;
}

void sll_add(sllnode * head, int value) {
    sllnode *newnode = create_sllnode(value);

    while (head->next != NULL)
        head = head->next;

    head->next = newnode;
}

sllnode * sll_insert(sllnode * head, int value, int index) {
    int i;
    sllnode *newnode = create_sllnode(value);

    if (i == 0) {
        newnode->next = head;
        head->next = newnode;
    } else {
        for (i = 0; i < index && head->next; i++)
            head = head->next;

        newnode->next = head->next;
        head->next = newnode;
    }

    return head;
}

sllnode * sll_remove(sllnode * head, int toremove) {
    while (head->next && head->next->value != toremove)
        head = head->next;

    if (head->value == toremove) {      /* Last element edge case */
        sllnode *tofree = head->next;
        head->next = head->next->next;
        free(tofree);

        return head->next;
    }

    return NULL;
}

sllnode * sll_removeall(sllnode * head, int toremove) {
    sllnode *prev;

    do
        prev = head;
        head = sll_remove(head, toremove);
    while (head);

    return prev;
}

void sll_distinct(sllnode * head) {
    do
        head = sll_removeall(head->next, head->value);
    while (head);
}

void sll_destroy(sllnode ** headp) {
    sllnode *tofree;
    while (*headp) {
        tofree = *headp;
        headp = &(tofree->next);
        free(headp);        
    }
}

int main (int argc, char **argv) {

    return 0;
}
