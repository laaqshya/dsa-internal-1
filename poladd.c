#include <stdio.h>
#include <stdlib.h>
struct node{
    int pow,coeff;
    struct node*link;
}*nn,*f1=NULL,*f2=NULL,*l=NULL,*r=NULL;
void create(struct node**f);
void add(struct node*f1,struct node*f2);
void display(struct node*f);
int main(){
     printf("Enter Polynomial 1:\n");
    create(&f1);

    printf("\nEnter Polynomial 2:\n");
    create(&f2);

    printf("\nPolynomial 1: ");
    display(f1);

    printf("\nPolynomial 2: ");
    display(f2);

    printf("\nResult after Addition:\n");
    add(f1,f2);

    display(r);

    return 0;
}
void create(struct node**f){
    int n,i;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("enter coefficient and power:");
        scanf("%d %d",&nn->coeff,&nn->pow);
        nn->link=NULL;
        if(*f==NULL)
            *f=l=nn;
        else{
            l->link=nn;
            l=nn;
        }
    }
}
void add(struct node*f1,struct node*f2){
    struct node*t1,*t2;
    t1=f1;t2=f2;
    while(t1!=NULL && t2!=NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->link=NULL;
        if(t1->pow>t2->pow){
            nn->coeff=t1->coeff;
            nn->pow=t1->pow;
            t1=t1->link;
        }
        else if(t2->pow>t1->pow){
            nn->coeff=t2->coeff;
            nn->pow=t2->pow;
            t2=t2->link;
        }
        else if(t1->pow==t2->pow){
            nn->coeff=t1->coeff+t2->coeff;
            nn->pow=t1->pow;
            t1=t1->link;
            t2=t2->link;
        }
        if(r==NULL){
            r=l=nn;
        }
        else{
            l->link=nn;
            l=nn;
        }
    }
    while(t1!=NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->link=NULL;
        nn->coeff=t1->coeff;
        nn->pow=t1->pow;
        if(r==NULL)
        r=l=nn;
        else{
            l->link=nn;
            l=nn;
        }
    }
    while(t2!=NULL){
        nn=(struct node*)malloc(sizeof(struct node));
        nn->link=NULL;
        nn->coeff=t2->coeff;
        nn->pow=t2->pow;
        if(r==NULL)
        r=l=nn;
        else{
            l->link=nn;
            l=nn;
        }
    }
}
void display(struct node*t){
    while(t!=NULL){
        printf("%dx^%d",t->coeff,t->pow);
        if(t->link!=NULL)
        printf("+");
        t=t->link;
    }
}
