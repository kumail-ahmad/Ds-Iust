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
}

struct Node *createList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    int nodeElem;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for Node no %d: ", i + 1);
        scanf("%d", &nodeElem);

        struct Node *newNode = createNode(nodeElem);

        if (head == NULL)
        {
            head = newNode;

            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    if (temp != NULL)
    {
        temp->next = head;
    }

    return head;
}

struct Node *deletionAtBeginning(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return NULL;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    printf("node deleted \n");
    temp->next = head->next;
    head->next = NULL;
    head = temp->next;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head)\n");
}

int main()
{
    int n;
    struct Node *head = NULL;
    printf("Enter the Number of Nodes: ");
    scanf("%d", &n);

    head = createList(n);
    head = deletionAtBeginning(head);
    display(head);

    return 0;
}