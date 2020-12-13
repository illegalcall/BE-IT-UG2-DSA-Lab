#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
    int size;
};

struct queue *newQueue()
{
    struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;
}

int isEmpty(struct queue *Q)
{
    return Q->size == 0;
}

void enqueue(struct queue *Q, int k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = NULL;

    if (isEmpty(Q))
    {
        Q->front = temp;
        Q->rear = temp;
    }
    else
    {
        Q->rear->next = temp;
        Q->rear = temp;
    }
    Q->size++;
}

int dequeue(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The queue is empty!\n");
        return -INT_MAX;
    }
    struct node *temp = Q->front;
    Q->front = Q->front->next;
    Q->size--;
    int ans = temp->data;
    free(temp);
    return ans;
}

struct stack
{
    struct queue *Q1;
    struct queue *Q2;
};

struct stack *newStack()
{
    struct stack *S = (struct stack *)malloc(sizeof(struct stack));
    S->Q1 = newQueue();
    S->Q2 = newQueue();
    return S;
}

void push(struct stack *S, int val)
{
    enqueue(S->Q1, val);
}

int pop(struct stack *S)
{
    if (isEmpty(S->Q1))
    {
        printf("The stack is empty\n");
        return INT_MIN;
    }
    int last = dequeue(S->Q1);
    while (!isEmpty(S->Q1))
    {
        enqueue(S->Q2, last);
        last = dequeue(S->Q1);
    }
    while (!isEmpty(S->Q2))
      enqueue(S->Q1, dequeue(S->Q2));

    return last;
}

int main()
{
    struct stack *S = newStack();

    push(S, 10);
    push(S, 20);
    push(S, 35);
    push(S, 3);
    push(S, 11);

    printf("%d\n", pop(S));
    printf("%d\n", pop(S));
    printf("%d\n", pop(S));

    return 0;
}
