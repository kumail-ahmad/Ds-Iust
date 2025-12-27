#include <stdio.h>
#define MAX 100

typedef struct{
    int arr[MAX];
    int top;
}Stack;

void initStack(Stack*s){
    s->top=-1;
}

int isEmpty(Stack *s){
    return s->top==-1;
}
void push(Stack *s,int val){
    s->top++;
    s->arr[s->top]=val;
}

int pop(Stack *s){
    return s->arr[ s->top--];
   

}
int peek(Stack *s){
    return s->arr[s->top];
}

//queue

typedef struct {
    Stack s1,s2;
}Queue;

void initQueue(Queue *q){
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(Queue* q, int val){
    while(!isEmpty(&q->s1)){
        push(&q->s2,  pop(&q->s1));
      
    }
    push(&q->s1,val);

    while(!isEmpty(&q->s2)){
        push(&q->s1,pop(&q->s2));
        
    }
}

int dequeue(Queue*q){

if(isEmpty(&q->s1)){
    return -1;
}

    
    
    return pop(&q->s1);
}

int front(Queue *q){
    if(isEmpty(&q->s1)){
        return -1;
    }
    return peek(&q->s1);
}


int main(){
    Queue q;
    initQueue(&q);

    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);

    printf("Front: %d\n",front(&q));
    printf("pop: %d\n",dequeue(&q));
    printf("Front: %d\n",front(&q));
}