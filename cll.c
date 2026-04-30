#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
}*first=NULL,*last=NULL,*nn,*t=NULL;
void createcll();
void insertbegcll();
void insertendcll();
void insertposcll();
void delbegcll();
void delendcll();
void delposcll();
void displaycll();
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
                createcll();
                break;

            case 2:
                printf("insertion at beginnig:\n");
                insertbegcll();
                break;

            case 3:
                printf("insertion at end:\n");
                insertendcll();
                break;

            case 4:
                printf("insert at position:\n");
                insertposcll();
                break;

            case 5:
                delbegcll();
                break;

            case 6:
                delendcll();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delposcll();
                break;

            case 8:
                displaycll();
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

void createcll(){
    int n,i,val;
    printf("enter no. of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        nn=(struct node*)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&nn->data);
        if(first==NULL){
            first=nn;
            nn->link=first;
            last=nn;
        }
        else{
            last->link=nn;
            nn->link=first;
            last=nn;
        }
    }
    displaycll();
}

void insertbegcll(){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
    if(first==NULL){
        first=nn;
        nn->link=first;
        last=nn;
    }
    else{
        nn->link=first;
        first=nn;
        last->link=first;
    }
    displaycll();
}

void insertendcll(){
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
if(first==NULL){
    first=nn;
    nn->link=first;
    last=nn;
}
else{
    last->link=nn;
    last=nn;
    nn->link=first;
}
displaycll();
}
void insertposcll(){
    int pos,i,c=0;
    printf("enter position:");
    scanf("%d",&pos);
    nn=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&nn->data);
    if(pos==1)
    insertbegcll();
    t=first;
    while(t->link!=first){
        c++;
        t=t->link;
    }
    if(pos==c+1)
    insertendcll();
    else{
        t=first;
        for(i=1;i<pos-1;i++){
            t=t->link;
        }
        nn->link=t->link;
        t->link=nn;
   }
   displaycll();
}
void delbegcll(){
    if(first==NULL)
    printf("list is empty");
    else{
        t=first;
        first=first->link;
        last->link=first;
        t->link=NULL;
        free(t);
    }
    displaycll();
}
void delendcll(){
    if(first==NULL)
    printf("ll is empty");
    if(first==last)
    delbegcll();
    else{
        t=first;
        while(t->link!=last){
            t=t->link;
        }
        t->link=first;
        last->link=NULL;
        free(last);
        last=t;
    }
    displaycll();
}
void delposcll(){
    int pos,i,c=0;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos==1)
        delbegcll();
    t=first;
    while(t->link!=first){
        c++;
        t=t->link;
    }
    if(pos>c){
        printf("Invalid position\n");
        return;
    }
    else if(pos==c)
    delendcll();
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
    displaycll();
}
void displaycll(){
    struct node *t;
    if(first==NULL)
        printf("List is empty\n");
    else{
        t=first;
        while(t->link!=first){
            printf("%d->", t->data);
            t=t->link;
        }
        printf("%d\n",t->data);
    }
    if(last->link == first)
    printf("Circular link verified: last node points to first\n");
else
    printf("Error: list is not circular\n");
}
int count(){
    int c=0;
    struct node *t;
    t=first;
    do{
        c++;
        t=t->link;
    }while(t!=first);
    return c;
}
