#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

struct Node *createList(int n) {
    if (n == 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node *node = createNode(val);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    head->prev = tail;
    tail->next = head;
    return head;
}

struct Node *insertAtBeginning(struct Node *head) {
    int val;
    scanf("%d", &val);
    struct Node *node = createNode(val);
    if (!head) { node->next = node->prev = node; return node; }
    struct Node *tail = head->prev;
    node->next = head;
    node->prev = tail;
    tail->next = head->prev = node;
    return node;
}

struct Node *insertAtEnd(struct Node *head) {
    int val;
    scanf("%d", &val);
    struct Node *node = createNode(val);
    if (!head) { node->next = node->prev = node; return node; }
    struct Node *tail = head->prev;
    tail->next = node;
    node->prev = tail;
    node->next = head;
    head->prev = node;
    return head;
}

struct Node *insertAtAnyPos(struct Node *head) {
    int val, pos;
    scanf("%d %d", &pos, &val);
    struct Node *node = createNode(val);
    if (!head || pos == 1) return insertAtBeginning(head);
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;
    return head;
}


void display(struct Node *head) {
    if (!head) { printf("NULL\n"); return; }
    struct Node *temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head)\n");
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node *head = createList(n);
    head = insertAtBeginning(head);
    head = insertAtEnd(head);
    head = insertAtAnyPos(head);
 
    display(head);
    return 0;
}
