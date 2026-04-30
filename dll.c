// implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
    int data;
    struct node *prev,*link;
}*first=NULL,*last=NULL,*nn,*t=NULL;

void create();
void insertbeg();
void insertend();
void insertpos();
void delbeg();
void delend();
void delpos();
void displayfor();
void displayback();
int count();

int main()
{
    int choice;
    char ch;

    do{
        printf("\n1.Create\n");
        printf("2.Insert at Beginning\n");
        printf("3.Insert at End\n");
        printf("4.Insert at Position\n");
        printf("5.Delete at Beginning\n");
        printf("6.Delete at End\n");
        printf("7.Delete at Position\n");
        printf("8.Display Forward\n");
        printf("9.Display Backward\n");
        printf("10.Count\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            printf("Creation:\n");
            create();
            break;

        case 2:
            printf("Insertion at Beginning:\n");
            insertbeg();
            break;

        case 3:
            printf("Insertion at End:\n");
            insertend();
            break;

        case 4:
            printf("Insert at Position:\n");
            insertpos();
            break;

        case 5:
            printf("Deletion at Beginning:\n");
            delbeg();
            break;

        case 6:
            printf("Deletion at End:\n");
            delend();
            break;

        case 7:
            printf("Deletion at Position:\n");
            delpos();
            break;

        case 8:
            displayfor();
            break;

        case 9:
            displayback();
            break;

        case 10:
            printf("No. of nodes in list: %d\n",count());
            break;

        default:
            printf("Invalid choice\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c",&ch);

    }while(ch=='y'||ch=='Y');

    return 0;
}
// create doubly linked list
void create(){
    int n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("Enter value: ");
        scanf("%d",&nn->data);
        if(first==NULL){
            first=nn;
            last=nn;
            nn->prev=NULL;
            nn->link=NULL;
        }
        else{
            last->link=nn;
            nn->prev=last;
            nn->link=NULL;
            last=nn;
        }
    }
    displayfor();
}
// insert at beginning
void insertbeg(){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&nn->data);
    if(first==NULL){
        first=last=nn;
        nn->prev=NULL;
        nn->link=NULL;
    }
    else{
        nn->link=first;
        nn->prev=NULL;
        first->prev=nn;
        first=nn;
    }
    displayfor();
}
// insert at end
void insertend(){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&nn->data);
    if(first==NULL){
        first=last=nn;
        nn->prev=NULL;
        nn->link=NULL;
    }
    else{
        last->link=nn;
        nn->prev=last;
        nn->link=NULL;
        last=nn;
    }
    displayfor();
}
// insert at given position
void insertpos(){
    int pos,i,x;
    x=count();
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>x+1)
    printf("Invalid position\n");
    if(pos==1)
    insertbeg();
    if(pos==x+1)
    insertend();
    nn=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&nn->data);
    t=first;
    for(i=1;i<pos-1;i++)
      t=t->link;
    nn->link=t->link;
    nn->prev=t;
    t->link->prev=nn;
    t->link=nn;
    displayfor();
}
// delete at beginning
void delbeg(){
    if(first==NULL)
    printf("List is empty\n");
    t=first;
    if(first==last)
    first=last=NULL;
    else{
        first=first->link;
        first->prev=NULL;
    }
    free(t);
    displayfor();
}
// delete at end
void delend(){
    if(first==NULL)
    printf("List is empty\n");
    if(first==last)
    delbeg();
    t=last;
    last=last->prev;
    last->link=NULL;
    free(t);
    displayfor();
}
// delete at position
void delpos(){
    int pos,i,c;
    c=count();
    printf("Enter position to delete: ");
    scanf("%d",&pos);
    if(pos<1 || pos>c)
    printf("Invalid position\n");
    if(pos==1)
        delbeg();
    if(pos==c)
        delend();
    t=first;
    for(i=1;i<pos-1;i++)
        t=t->link;

    nn=t->link;
    t->link=nn->link;
    nn->link->prev=t;
    free(nn);
    displayfor();
}
// display forward
void displayfor()
{
    if(first==NULL)
    printf("List is empty\n");
    t=first;
    printf("Forward list:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->link;
    }
    printf("\n");
}
// display backward
void displayback()
{
    if(last==NULL)
    printf("List is empty\n");
    t=last;
    printf("Backward list:\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->prev;
    }
    printf("\n");
}
// count nodes
int count()
{
    int c=0;
    t=first;
    while(t!=NULL){
        c++;
        t=t->link;
    }
    return c;
}
