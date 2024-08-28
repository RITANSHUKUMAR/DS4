#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int arr[MAX_SIZE];
} Stack;


void create(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}


void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->arr[++s->top] = value;
    }
}


int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}


void printStack(Stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


void deleteKElements(int arr[], int n, int k) {
    Stack s;
    create(&s);
    int deletions = 0;

    for (int i = 0; i < n; i++) {
        while (!isEmpty(&s) && deletions < k && s.arr[s.top] < arr[i]) {
            pop(&s);
            deletions++;
        }
        push(&s, arr[i]);
    }

    // If more deletions are needed, pop from the end
    while (deletions < k) {
        pop(&s);
        deletions++;
    }

    // Print the remaining elements in the stack
    printStack(&s);
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);


    int *arr = (int *)malloc(n * sizeof(int));



    printf("Enter %d elements:\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of elements to delete (k): ");
    scanf("%d", &k);



    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Array after deleting %d elements: ",k);
    deleteKElements(arr, n, k);

    free(arr);
    return 0;
}
