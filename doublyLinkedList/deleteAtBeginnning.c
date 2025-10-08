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

    printf("Enter the value which you want to insert: ");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);

    if (head == NULL)
    {
        head = newNode;
        head->next = NULL;
        return head;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
struct Node *deleteAtBeginning(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List is empty!\n");
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    printf("Elemenent deleted with value %d\n", temp->data);
    free(temp);
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

    head = deleteAtBeginning(head);
    display(head);

    return 0;
}