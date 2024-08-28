#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int top;
    int *arr;
} stack;


void create(stack *s) {
    s->size = 64;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
}


int isEmpty(stack *s) {
    return s->top == -1;
}


int isFull(stack *s) {
    return s->top == s->size - 1;
}


void push(stack *s, int x) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = x;
    }
}


int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}


void DECI_TO_BIN(stack *s, int deci) {
    if (deci == 0) {
        printf("Binary representation: 0\n");
        return;
    }

    int rem;
    while (deci > 0) {
        rem = deci % 2;
        push(s, rem);
        deci /= 2;
    }

    printf("Binary representation: ");
    while (!isEmpty(s)) {
        printf("%d", pop(s));
    }
    printf("\n");
}

int main() {
    int deci;
    stack *s;

    s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    create(s);

    printf("Enter decimal number:\n");
    scanf("%d", &deci);

    DECI_TO_BIN(s, deci);

    free(s->arr);
    free(s);

    return 0;
}
