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
}

struct Node *createList(int n)
{
    struct Node *head = NULL, *temp = NULL;
    int NodeElem;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the value of Elem %d: ", i + 1);
        scanf("%d", &NodeElem);

        struct Node *newNode = createNode(NodeElem);

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *insertionAtBeginning(struct Node *head)
{
    int val;

    printf("Enter the value which you want to insert: ");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);

    if (head == NULL)
    {
        head = newNode;

        return head;
    }

    newNode->next = head;
    head->prev = newNode;

    head=newNode;
    return head;
}
int main()
{
    struct Node *head = NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);
    display(head);

    head = insertionAtBeginning(head);
    display(head);
    return 0;
}