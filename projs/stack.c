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

typedef struct nd {
    int elem;
    struct nd * next;
} node;

typedef struct st {
    node *top;
} Stack;

void init(Stack * stack) {
    stack->top = NULL;
}

int push(Stack * stack, int elem) {
    node *newnode= malloc(sizeof(*new));
    
    if (!stack || !newnode) return 0;

    node->elem = elem;
    node->next = stack->top;
    stack->top = node;

    return 1;
}

int pop(Stack * stack, int * elem) {
    stack *toremove;
    
    if (!stack || !stack->top || !elem) return 0;

    toremove = stack->top;
    *elem = stack->top->elem;

    stack->top = stack->top->next;
    free(toremove);

    return 1;    
}
