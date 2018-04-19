#include <stdio.h>
#include <string.h>

struct el {
    struct el * next;
    int value
};
typedef struct el el;

void distinct(el * head) {
    el *curr = head;

    while (curr && curr->next) {
        while (curr->value == curr->next->value) {
            el *to_free = curr->next;
            curr->next = curr->next->next;
            free(to_free);

            if (curr->next == NULL)
                return;
        }

        curr = curr->next;
    }
}

int main (int argc, char **argv) {


    return 0;
}
