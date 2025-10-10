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
struct Node *deletionAtAnyPos(struct Node *head)
{
    int pos;
    printf("Enter the position at which you want to delete : ");
    scanf("%d", &pos);
    if (!head)
        return NULL;
    if (pos == 1)
    {
        if (head->next == head)
        {
            free(head);
            return NULL;
        }
        struct Node *temp = head;
        struct Node *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
        return head;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    struct Node *del = temp->next;
    if (del == head)
        return head;
    temp->next = del->next;
    free(del);
    return head;
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
    head = deletionAtAnyPos(head);
    display(head);

    return 0;
}