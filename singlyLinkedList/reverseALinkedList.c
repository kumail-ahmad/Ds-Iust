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
    int node;

    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for Node no %d:\n", i + 1);
        scanf("%d", &node);

        newNode = createNode(node);
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
struct Node *reverse(struct Node *head)
{
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    printf("Linked list reversed Succesfully \n");
    return prev;
}
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

    head = reverse(head);
    display(head);
    return 0;
}