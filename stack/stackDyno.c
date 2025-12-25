#include <stdio.h>
#define MAX 100

typedef struct
{
    int stArr[MAX];
    int top;
} stack;

void create(stack *s)
{
    s->top = -1;
}

void push(stack *s, int value)
{
    if (s->top >= MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }
    (s->top)++;
    s->stArr[(s->top)] = value;
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    (s->top)--;
    return s->stArr[(s->top)];
}

void display(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->stArr[i]);
    }
    printf("\n");
}

int main()
{
    stack s;
    create(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped: %d\n", pop(&s));
    display(&s);

    return 0;
}
