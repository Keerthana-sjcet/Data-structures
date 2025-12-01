#include <stdio.h>
int main() {
    int n;
    printf("Enter size of queue: ");
    scanf("%d", &n);
    int queue[n];
    int front = -1, rear = -1;
    int choice, value;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if ((front == 0 && rear == size - 1) ||(rear + 1) % n == front) {
                    printf("Overflow\n");
                } else {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (front == -1)
                        front = 0;
                    rear = (rear + 1) % n;
                    queue[rear] = value;
                }
                break;
            case 2: 
                if (front == -1) {
                    printf("Underflow\n");
                } else {
                    if (front == rear) {
                        front = rear = -1;
                    } else {
                        front = (front + 1) % n;
                    }
                }
                break;
            case 3:
                if (front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue: ");
                    for (int i = front; ; i = (i + 1) % n) {
                        printf("%d ", queue[i]);
                        if (i == rear) break;
                    }
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
