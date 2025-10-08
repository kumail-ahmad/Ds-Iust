#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
};

struct Node *createList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;
    int Node;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for Node no %d\n", i + 1);
        scanf("%d", &Node);

        newNode = createNode(Node);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
};

struct Node *insertAtAnyPos(struct Node *head)
{

    int val, pos;
    struct Node *temp = head;

    printf("Enter the position to insert element: ");
    scanf("%d", &pos);
    printf("Enter the value which you want to insert: ");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);
    if (pos == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return head;
    }
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    return head;
}

void display(struct Node *head)
{
    printf("List : ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
};

int main()
{
    int n;
    struct Node *head = NULL;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("List Created Succesfully !! \n ");

    head = insertAtAnyPos(head);
    display(head);

    return 0;
}