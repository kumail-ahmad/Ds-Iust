#include <stdio.h>
#define MAX 100

int st[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack is full \n ");
    }
    else
    {
        top++;
        st[top] = val;
       
    }
}

int pop()
{
    if (top == -1)
    {
        printf("List is empty \n");
    }
    else
    {
        return st[top];
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("List is empty \n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", st[i]);
        }
        printf("\n");
    }
}



int main()
{
    push(3);
    push(2);
    push(4);
    push(1);
    int x = pop();
    printf("Popped element: %d\n", x);
    
    display();
    return 0;
}