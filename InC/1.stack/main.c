#include <stdio.h>

#include "stack.h"

int main() {
    Stack s;
    StackEntery x = 0;
    intializeStack(&s);

    if (!stackFull(&s)) {
        push(2, &s);
    }

    if (!stackEmpty(&s)) {
        x = pop(&s);
    }

    printf("x=%d\n", x);
    printf("%d\n", stackEmpty(&s));


    if (!stackFull(&s)) {
        push(4, &s);
    }

    if (!stackEmpty(&s)) {
        x = stackTop(&s);
    }

    printf("x=%d\n", x);
    printf("%d", stackEmpty(&s));

    return 0;
}

