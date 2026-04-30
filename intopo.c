#include <stdio.h>
#include <ctype.h>

char s[100];
int top = -1;

void push(char x) {
    s[++top] = x;
}

char pop() {
    return s[top--];
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 3;
}

int main() {
    char exp[100];
    int i = 0;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {
        if (isalnum(exp[i])) {
            // Operand → print directly
            printf("%c", exp[i]);
        }
        else if (exp[i] == '(') {
            push(exp[i]);
        }
        else if (exp[i] == ')') {
            // Pop until '('
            while (top != -1 && s[top] != '(')
                printf("%c", pop());
            if (top != -1) pop(); // remove '('
        }
        else {
            // Operator → pop while higher/equal precedence
            while (top != -1 && priority(s[top]) >= priority(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}
