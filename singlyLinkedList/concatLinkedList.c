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

struct Node *concat(struct Node *head1, struct Node *head2)
{
    struct Node *temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
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
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int list1, list2;
    printf("Enter number of nodes in list 1: ");
    scanf("%d", &list1);

    printf("Enter number of nodes in list 2: ");
    scanf("%d", &list2);

    head1 = createList(list1);
    head2 = createList(list2);

    printf("\nLinked List Created Successfully.\n");
    printf("List: ");
    display(head1);
    display(head2);
    printf("after concat: ");
    concat(head1, head2);
    display(head1);
    return 0;
}