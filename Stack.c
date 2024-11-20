#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int stack[SIZE];
int top;
int a;
int your_choice;

void push();
void pop();
void print();

int main()
{
    top = -1; 
    do
    {
        printf("1. Insert an Element!\n2. Delete an Element!\n3. Display the elements of the stack!\n4. Please Exit!\n\n");
        printf("Enter your choice from the above: ");
        scanf("%d", &your_choice);
        
        switch(your_choice)
        {
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
                printf("Sorry, Please enter a valid choice!\n");
                break;
        }
    } while(your_choice != 4);
    
    return 0;
}

void push()
{
    int value;
    if(top == SIZE - 1)
    {
        printf("The Stack is full!\n");
    }
    else
    {
        printf("Enter the element to push into the stack: ");
        scanf("%d", &value);
        printf("Element added!\n");
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if(top == -1)
    {
        printf("The Stack is empty!\n");
    }
    else
    {
        printf("Deleted the element: %d\n", stack[top]);
        printf("Deleted!\n");
        top--;
    }
}

void print()
{
    if(top == -1)
    {
        printf("The Stack is empty!\n");
    }
    else
    {
        printf("Elements of the stack are: \n");
        for(a = top; a >= 0; a--)
        {
            printf("%d\n", stack[a]);
        }
    }
}
