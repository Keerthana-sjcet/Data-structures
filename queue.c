#include<stdio.h>
int main() {
    int n, choice, value;
    int front = -1, rear = -1;
    printf("Enter size of the queue: ");
    scanf("%d", &n);
    int queue[n];
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (rear == n - 1) {
                    printf("Overflow\n");
                } else {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    if (front == -1) front = 0; 
                    queue[++rear] = value;
                    printf("%d inserted\n", value);
                }
                break;
            case 2: 
                if (front == -1) {
                    printf("Underflow\n");
                } else {
                    printf("Deleted: %d\n", queue[front]);
                    if (front == rear) {  
                        front = rear = -1;
                    } else {
                        front++;
                    }
                }
                break;
            case 3:  
                if (front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
