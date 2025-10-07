#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

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
        printf("Enter the data for Node No %d:", i + 1);
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
}

struct Node *insertionAtBeginning(struct Node *head)
{
    int val;
    printf("Enter the value which you want to insert:");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *deleteAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty !\n");
        return head;
    }

    struct Node *temp = head;
    head = head->next;
    printf("Node deleted succesfully with value %d \n", temp->data);
    free(temp);
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

int main()
{
    int n;
    struct Node *head = NULL;

    printf("Enter the number of Nodes: ");
    scanf("%d", &n);

    head = createList(n);
    printf("List created Succesfully !!!\n");
    head = insertionAtBeginning(head);

    display(head);
    head = deleteAtBeginning(head);
    display(head);
    return 0;
}