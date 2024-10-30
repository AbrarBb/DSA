#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 5

int ourQueue[CAPACITY];
int front = 0, rear = -1, totalItem = 0;

bool isFull() {
    return totalItem == CAPACITY;
}

bool isEmpty() {
    return totalItem == 0;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Sorry, the Queue is full.\n");
        return;
    }
    rear = (rear + 1) % CAPACITY;
    ourQueue[rear] = item;
    totalItem++;
}

int dequeue() {
    if (isEmpty()) {
        printf("Sorry, the Queue is empty.\n");
        return -1;
    }
    int frontItem = ourQueue[front];
    front = (front + 1) % CAPACITY;
    totalItem--;
    return frontItem;
}

void printQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i < totalItem; i++) {
        int index = (front + i) % CAPACITY;
        printf("%d ", ourQueue[index]);
    }
    printf("\n");
}

int main() {
    printf("\n***********\nLet's implement our Queue.\n\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printQueue();
    enqueue(50);
    printQueue();
    enqueue(60);
    printf("Deque: %d\n", dequeue());
    printQueue();
    enqueue(60);
    printQueue();
    return 0;
}
