#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
typedef struct node stack;
stack *top;

void create(stack **top)
{
    *top = NULL;
}

void push(stack **top, int elem)
{
    stack *newNode;
    newNode = (stack *)malloc(sizeof(stack));
    if (newNode == NULL)
    {
        printf("\n stack is full ");
        exit(-1);
    }
    newNode->val = elem;
    newNode->next = *top;
    *top = newNode;
}

void display(stack *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    while (top != NULL)
    {
        printf("%d ", top->val);
        top = top->next;
    }
}

int main()
{
    create(&top);
    push(&top, 3);
    push(&top, 2);
    push(&top, 1);

    display(top);
    return 0;
}
