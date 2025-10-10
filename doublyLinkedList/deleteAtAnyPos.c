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
    struct Node *head = NULL, *temp = NULL, *newNode;
    int val;
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        newNode = createNode(val);
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

struct Node *deleteAtPos(struct Node *head)
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty!\n");
        return head;
    }

    if (pos == 1)
    {
        struct Node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    struct Node *head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    head = createList(n);
    printf("Original List:\n");
    display(head);
    head = deleteAtPos(head);
    printf("After Deletion:\n");
    display(head);
    return 0;
}
