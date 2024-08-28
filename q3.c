
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char arr[MAX_SIZE];
} Stack;


void initializeStack(Stack *s) {
    s->top = -1;
}


int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}


void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->arr[++s->top] = c;
    }
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0'; // Return null character if the stack is empty
    }
    return s->arr[s->top--];
}


int isPalindrome(char *str) {
    Stack s;
    initializeStack(&s);

    // Remove non-alphanumeric characters and convert to lowercase
    char cleaned_str[MAX_SIZE];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            cleaned_str[j++] = tolower(str[i]);
        }
    }
    cleaned_str[j] = '\0'; // Null-terminate the cleaned string

    // Push characters onto the stack
    for (int i = 0; cleaned_str[i] != '\0'; i++) {
        push(&s, cleaned_str[i]);
    }


    for (int i = 0; cleaned_str[i] != '\0'; i++) {
        if (cleaned_str[i] != pop(&s)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Is a palindrome
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);

    // Remove the trailing newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
