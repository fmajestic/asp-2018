#define STACKMAX 16

typedef struct {
    int top, field[STACKMAX];
}

void init(Stack * stack) {
    stack->top = -1;
}

int push(Stack * stack, int elem) {
    if (stack->top >= STACKMAX - 1) return 0;
    stack->field[++stack->top] = elem;
    return 1;
}

int pop(Stack * stack, int *elem) {
    if (stack->top < 0) return 0;
    *elem = stack->field[stack->top--];
    return 1;
}

void revcopy(Stack * src, Stack * dest) {
    int elem;
    init(dest);
    while (pop(src, &elem))
        push(dest, elem);
}
