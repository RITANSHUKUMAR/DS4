#include <stdio.h>
#include <string.h>

int evaluate_prefix(char *expression) {
    int stack[100];
    int top = -1;
    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        char c = expression[i];

        if (c >= '0' && c <= '9') {
            stack[++top] = c - '0';
        } else {
            int a = stack[top--];
            int b = stack[top--];

            switch (c) {
                case '+':
                    stack[++top] = a + b;
                    break;
                case '-':
                    stack[++top] = a - b;
                    break;
                case '*':
                    stack[++top] = a * b;
                    break;
                case '/':
                    stack[++top] = a / b;
                    break;
            }
        }
    }

    return stack[top];
}

int main() {
    char expression[100];

    while (1) {
        printf("Enter a prefix expression: ");
        fgets(expression, 100, stdin);

        expression[strcspn(expression, "\n")] = 0;

        int result = evaluate_prefix(expression);
        printf("Result: %d\n", result);
    }
    return 0;
}
