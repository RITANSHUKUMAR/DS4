#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack to hold intermediate postfix expressions
char stack[MAX][MAX];
int top = -1;

// Function to push an element onto the stack
void push(char *item) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
    } else {
        strcpy(stack[++top], item);
    }
}

// Function to pop an element from the stack
char* pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return NULL;
    } else {
        return stack[top--];
    }
}

// Function to reverse a string
void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to convert prefix to postfix
void prefixToPostfix(char prefix[], char postfix[]) {
    int length = strlen(prefix);
    reverseString(prefix);

    for (int i = 0; i < length; i++) {
        char c = prefix[i];

        if (isalnum(c)) {
            char operand[2] = {c, '\0'};
            push(operand);
        } else {
            char operand1[MAX], operand2[MAX], temp[MAX];
            strcpy(operand1, pop());
            strcpy(operand2, pop());

            sprintf(temp, "%s%s%c", operand1, operand2, c);
            push(temp);
        }
    }

    strcpy(postfix, pop());
}

int main() {
    char prefix[MAX], postfix[MAX];
    
    while (1) {
        printf("Enter a prefix expression: ");
        fgets(prefix, sizeof(prefix), stdin);

        prefix[strcspn(prefix, "\n")] = '\0';

        prefixToPostfix(prefix, postfix);

        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}
