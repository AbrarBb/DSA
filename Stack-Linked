#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void print();

struct node {
    int value;
    struct node *NEXT;
};

struct node *tmp = NULL;

int main() {
    int your_choice;
    do {
        printf("1. Insert an element!\n2. Delete an element!\n3. Display the elements of the stack!\n4. Please Exit!\n\n");
        printf("Please enter your choice from the above: ");
        scanf("%d", &your_choice);

        switch (your_choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Sorry, please choose a valid choice!\n");
                break;
        }
    } while (your_choice != 4);
    return 0;
}

void push() {
    int value;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("The Stack is full!\n");
    } else {
        printf("Enter the element which you want to push into the stack: ");
        scanf("%d", &value);
        printf("Element added!\n");
        
        ptr->value = value;
        ptr->NEXT = tmp; // Fix: point to the previous top element
        tmp = ptr;       // Update top of stack to the new element
    }
}

void pop() {
    int element;
    struct node *ptr;
    if (tmp == NULL) {
        printf("The Stack is empty!\n");
    } else {
        element = tmp->value;
        ptr = tmp;
        tmp = tmp->NEXT;
        free(ptr);
        printf("Deleted the element: %d\n", element);
        printf("Deleted!\n");
    }
}

void print() {
    struct node *ptr = tmp;
    if (ptr == NULL) {
        printf("The Stack is empty!\n");
    } else {
        printf("Elements of the stack are: \n");
        while (ptr != NULL) {
            printf("%d\n", ptr->value);
            ptr = ptr->NEXT;
        }
    }
}
