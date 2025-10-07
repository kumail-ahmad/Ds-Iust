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
    int Node;
      if (n == 0)
    {
        printf("Linked List cannot be  empty!!\n");
        return ;
    }
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

      if (head == NULL)
    {
        printf("Linked List is empty!!\n");
    }
    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
    return head;
};

struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
      if (head == NULL)
    {
        printf("Linked List is empty!!\n");
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("\nLast Node deleted with value %d \n", temp->data);
    free(temp);
    return head;
}

struct Node *deletionAtAnyPos(struct Node *head)
{
    int pos;

    printf("\nEnter the Nodes position to be deleted :  ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("Linked List is empty!!\n");
    }

    if (pos == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
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
    int n, valBeg;
    struct Node *head = NULL;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("List Created Succesfully !! \n ");

    // head = insertAtbegining(head);
    display(head);
    head = deletionAtAnyPos(head);
    display(head);

    return 0;
}