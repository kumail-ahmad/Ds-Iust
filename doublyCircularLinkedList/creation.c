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
 
    display(head);
    return 0;
}
