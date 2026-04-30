#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
}*first=NULL,*last=NULL,*nn,*t=NULL;
void create();
void insertbeg();
void insertend();
void insertpos();
void delbeg();
void delend();
void delpos();
void display();
int count();
void main(){
    int choice, value, pos;
    char ch;
    do {
        printf("1.create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete at Position\n");
        printf("8. Display\n");
        printf("9.count\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("creation:\n");
                create();
                break;

            case 2:
                printf("insertion at beginnig:\n");
                insertbeg();
                break;

            case 3:
                printf("insertion at end:\n");
                insertend(value);
                break;

            case 4:
                printf("insert at position:\n");
                insertpos();
                break;

            case 5:
                delbeg();
                break;

            case 6:
                delend();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delpos(pos);
                break;

            case 8:
                display();
                break;
            
            case 9:
                printf("no. of nodes in the list:%d",count());
                break;

            default:
                printf("Invalid choice.\n");
        }

        printf("\nDo you want to continue? (y/n): ");
        fflush(stdin);
        ch=getchar();
    } while (toupper(ch) == 'Y');

}
//to create a linked list
void create(){
    int n,i,val;
    printf("enter no. of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&nn->data);
        if(first==NULL){
            first=nn;
            nn->link=NULL;
            last=nn;
        }
        else{
            last->link=nn;
            nn->link=NULL;
            last=nn;
        }
    }
    display();//check how it is created
}
//insert a node at the beginnin
void insertbeg(){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
    if(first==NULL){
        first=nn;
        nn->link=NULL;
        last=nn;
    }
    else{
        nn->link=first;
        first=nn;
    }
    display();
}
//insert a node at the end
void insertend(){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
if(first==NULL){
    first=nn;
    nn->link=NULL;
    last=nn;
}
else{
    last->link=nn;
    last=nn;
    nn->link=NULL;
}
display();
}
//insert a node at a given position
void insertpos(){
    int pos,i,c=0;
    printf("enter position:");
    scanf("%d",&pos);
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
    if(pos==1)
    insertbeg();
    t=first;
    while(t!=NULL){
        c++;
        t=t->link;
    }
    if(pos==c+1)
    insertend();
    else{
        t=first;
        for(i=1;i<pos-1;i++){
            t=t->link;
        }
        nn->link=t->link;
        t->link=nn;
   }
   display();
}
void delbeg(){
    if(first==NULL)
    printf("list is empty");
    else{
        t=first;
        first=first->link;
        t->link=NULL;
        free(t);
    }
    display();
}
void delend(){
    if(first==NULL)
    printf("ll is empty");
    if(first->link==first)
    delbeg();
    else{
        t=first;
        while(t->link!=last){
            t=t->link;
        }
        t->link=NULL;
        free(last);
        last=t;
    }
    display();
}
//to delete a bode at a specified position
void delpos(){
    int pos,i,c=0;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos==1)
        delbeg();
    t=first;
    while(t!=NULL){
        c++;
        t=t->link;
    }
    if(pos>c){
        printf("Invalid position\n");
        return;
    }
    else if(pos==c)
    delend();
    else{
    t=first;
    for(i=1;i<pos-1;i++){
        t=t->link;
    }
    nn=t->link;
    t->link=nn->link;
    nn->link=NULL;
    free(nn);
}
    display();
}
//to display a linked list
void display(){
    struct node *t;
    if(first==NULL)
        printf("List is empty\n");
    else{
        t=first;
        while(t!=NULL){
            printf("%d ", t->data);
            t=t->link;
        }
        printf("\n");
    }
}
//to count the nodes of a linked list
int count(){
    int c=0;
    struct node *t;
    t=first;
    while(t!=NULL){
        c++;
        t=t->link;
    }
    return c;
}
//to reverse a linked list
void reverse(){
    struct node *t, *t1, *t2;
    t = first;
    t1 = NULL;
    while(t!= NULL){
        t2 = t->link;   // points to the second  node
        t->link = t1;   // reverse link
        t1 = t;         // move t1 forward
        t = t2;         // move t forward
    }
    first = t1;        // update first to new head
}
