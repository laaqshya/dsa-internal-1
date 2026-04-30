// MERGE TWO SINGLY LINKED LISTS (ALTERNATE)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
} *f1 = NULL, *f2 = NULL, *t1, *t2, *t3, *t4, *nn, *temp;

// create list
struct node *create(struct node *f)
{
    char c = 'y';

    while (c == 'y' || c == 'Y')
    {
        nn = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &nn->data);
        nn->link = NULL;

        if (f == NULL)
        {
            f = nn;
            temp = nn;
        }
        else
        {
            temp->link = nn;
            temp = nn;
        }

        printf("Continue to create (y/n): ");
        scanf(" %c", &c);   // ? safe input
    }

    return f;
}

// display list
void display(struct node *f)
{
    while (f != NULL)
    {
        printf("%d -> ", f->data);
        f = f->link;
    }
    printf("NULL\n");
}

int main()
{
    printf("Create list 1:\n");
    f1 = create(f1);

    printf("Create list 2:\n");
    f2 = create(f2);

    // if any list empty
    if (f1 == NULL)
    {
        printf("Merged list:\n");
        display(f2);
        return 0;
    }
    if (f2 == NULL)
    {
        printf("Merged list:\n");
        display(f1);
        return 0;
    }

    // alternate merge
    t1 = f1;
    t2 = f2;

    while (t1 != NULL && t2 != NULL)
    {
        t3 = t1->link;
        t4 = t2->link;

        t1->link = t2;

        if (t3 == NULL) break;

        t2->link = t3;

        t1 = t3;
        t2 = t4;
    }

    printf("After merge:\n");
    display(f1);

    return 0;
}
