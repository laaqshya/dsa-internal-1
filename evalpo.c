#include <stdio.h>
#include<ctype.h>
#include<math.h>
int stack[100],top=-1;

void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}

int main(){
    char pf[100];
    int i,op1,op2,x;
    printf("enter postfix expression:");
    scanf("%s",pf);
    for(i=0;pf[i]!='\0';i++){
        if(isalpha(pf[i])){
            scanf("%d",&x);
            push(x);
        }//end of if
        else{
            op2=pop();
        op1=pop();
        switch(pf[i]){
            case '+':push(op1+op2);
                     break;
            case '-':push(op1-op2);
                    break;
            case '*':push(op1*op2);
                    break;
            case '/':push(op1/op2);
                    break;
        }
      }
    }
    printf("result:%d",stack[top]);
    return 0;
}
