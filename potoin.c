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

    for(i=0;pf[i]!='\0';i++){
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
                    push(a);
                    push(pf[i]);
                    push(b);
                    break;
                }
            }
        }
    }

    for(i=top;i>=0;i--)
        printf("%c",stack[i]);

    return 0;
}
