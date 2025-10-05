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
    int data;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for Node no %d:", i + 1);
        scanf("%d", &data);
        printf("\n");
        newNode = createNode(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = NULL;
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
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nLinked List Created Successfully.\n");
    printf("List: ");
    display(head);
    return 0;
}