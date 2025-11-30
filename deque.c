#include <stdio.h>
#define MAX 100

int main() {
    int deque[MAX], size;
    int front = -1, rear = -1;
    int choice, value;

    printf("Enter the size of the Deque (max %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);

                if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
                    printf("Deque is Full\n");
                } else {
                    if (front == -1)
                        front = rear = 0;
                    else if (front == 0)
                        front = size - 1;
                    else
                        front--;
                    deque[front] = value;
                    printf("%d inserted at front\n", value);
                }
                break;

            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);

                if ((front == 0 && rear == size - 1) || (front == rear + 1)) {
                    printf("Deque is Full\n");
                } else {
                    if (front == -1)
                        front = rear = 0;
                    else if (rear == size - 1)
                        rear = 0;
                    else
                        rear++;
                    deque[rear] = value;
                    printf("%d inserted at rear\n", value);
                }
                break;

            case 3:
                if (front == -1) {
                    printf("Deque is Empty\n");
                } else {
                    printf("%d deleted from front\n", deque[front]);
                    if (front == rear)
                        front = rear = -1;
                    else if (front == size - 1)
                        front = 0;
                    else
                        front++;
                }
                break;

            case 4:
                if (front == -1) {
                    printf("Deque is Empty\n");
                } else {
                    printf("%d deleted from rear\n", deque[rear]);
                    if (front == rear)
                        front = rear = -1;
                    else if (rear == 0)
                        rear = size - 1;
                    else
                        rear--;
                }
                break;

            case 5:
                if (front == -1) {
                    printf("Deque is Empty\n");
                } else {
                    printf("Deque: ");
                    int i;
                    for (i = front; ; i = (i + 1) % size) {
                        printf("%d ", deque[i]);
                        if (i == rear)
                            break;
                    }
                    printf("\n");
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
