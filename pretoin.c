#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[200];
int top=-1;

void push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

int main(){
    char pf[100], a, b;
    int i;

    printf("enter prefix expression:");
    scanf("%s",pf);

    for(i=strlen(pf)-1;i>=0;i--){
        if(isalpha(pf[i])){
            push(pf[i]);
        }
        else{
            a = pop();
            b = pop();

            switch(pf[i]){
                case '+':
                case '-':
                case '*':
                case '/':{
                    push('(');
                    push(b);
                    push(pf[i]);
                    push(a);
                    push(')');
                    break;
                }
            }
        }
    }

    for(i=0;i<=top;i++)
        printf("%c",stack[i]);

    return 0;
}
