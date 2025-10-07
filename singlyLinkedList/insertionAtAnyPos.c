#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
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
struct Node *insertAtbegining(struct Node *head)
{
    int val;
    printf("Enter the value to be inserted in beginning: \n");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
};
struct Node *insertAtEnd(struct Node *head)
{
    struct Node *temp = head;
    int val;
    printf("Enter the value To be inserted at the end : ");
    scanf("%d", &val);
    struct Node *newNode = createNode(val);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    temp = newNode;
    newNode->next = NULL;
    return head;
}
struct Node *insertAtAnyPos(struct Node *head)
{
    int pos, val;
    printf("Enter the position at which you want to insert: ");
    scanf("%d", &pos);
    printf("Enter the value which you want to insert: ");
    scanf("%d", &val);
    struct Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
};
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
    int n, valBeg;
    struct Node *head = NULL;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("List Created Succesfully !! \n ");
    insertAtAnyPos(head);
    display(head);

    return 0;
}