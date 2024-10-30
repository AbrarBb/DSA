#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5 

int queue[CAPACITY];
int front = 0, rear = -1, size = 0;


bool isFull() 
{
    return size == CAPACITY;
}

bool isEmpty() 
{
    return size == 0;
}


void enqueue(int item) 
{
    if (isFull()) 
    {
        printf("Queue is full! Cannot enqueue %d\n", item);
        return;
    }
    rear = (rear + 1) % CAPACITY; 
    queue[rear] = item;
    size++;
    printf("Enqueued: %d\n", item);
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; 
    }
    int item = queue[front];
    front = (front + 1) % CAPACITY; 
    size--;
    printf("Dequeued: %d\n", item);
    return item;
}


void displayQueue() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", queue[(front + i) % CAPACITY]);
    }
    printf("\n");
}

int main() 
{
    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
