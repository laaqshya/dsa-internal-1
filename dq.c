#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return (front == 0 && rear == MAX - 1);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        printf("No space at front\n");
        return;
    } else {
        front--;
    }

    deque[front] = x;
}

// Insert at rear
void insertRear(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        printf("No space at rear\n");
        return;
    } else {
        rear++;
    }

    deque[rear] = x;
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

// Display
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}