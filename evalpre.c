#include <stdio.h>
#include <ctype.h>
#include <string.h>

int stack[100], top = -1;

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int main(){
    char pf[100];
    int i, op1, op2, x;

    printf("enter prefix expression: ");
    scanf("%s", pf);

    // traverse from RIGHT to LEFT
    for(i = strlen(pf) - 1; i >= 0; i--){

        if(isalpha(pf[i])){
            scanf("%d", &x);
            push(x);
        }
        else{
            op1 = pop();
            op2 = pop();

            switch(pf[i]){
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }

    printf("Result = %d", pop());
    return 0;
}
