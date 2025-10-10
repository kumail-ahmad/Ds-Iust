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
        free(temp);
        return head;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }

    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
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

    printf("\nOriginal List:\n");
    display(head);

    head = deleteAtPos(head);

    printf("\nAfter Deletion:\n");
    display(head);

    return 0;
}
