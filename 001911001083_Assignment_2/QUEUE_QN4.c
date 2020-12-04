#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node **S)
{
    if (*S == NULL)
        return 1;
    return 0;
}

struct node *push(struct node **S, int k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = *S;
    *S = temp;
}

int pop(struct node **S)
{
    int k;
    if (isEmpty(S))
    {
        printf("The stack is empty\n");
        return -1;
    }
    struct node *temp = *S;
    k = temp->data;
    *S = (*S)->next;
    free(temp);
    return k;
}

void printStack(struct node **S)
{
    struct node *temp = *S;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int top(struct node **S)
{
    if (isEmpty(S))
    {
        printf("The stack is empty\n");
        return -1;
    }
    return (*S)->data;
}

struct queue
{
    struct node *S1;
    struct node *S2;
};

struct queue *createQueue()
{
    struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
    Q->S1 = NULL;
    Q->S2 = NULL;
    return Q;
}

void enqueue(struct queue *Q, int val)
{
    while (!isEmpty(&Q->S2))
    {
        int data = pop(&Q->S2);
        push(&Q->S1, data);
    }
    push(&Q->S1, val);
}

int dequeue(struct queue *Q)
{
    while (!isEmpty(&Q->S1))
    {
        int data = pop(&Q->S1);
        push(&Q->S2, data);
    }
    if (isEmpty(&Q->S2))
    {
        printf("The Queue is empty\n");
        return INT_MIN;
    }
    return pop(&Q->S2);
}

int main()
{
    struct queue *Q = createQueue();

    enqueue(Q, 5);
    enqueue(Q, 10);
    enqueue(Q, 7);
    enqueue(Q, 25);
    enqueue(Q, 40);

    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));

    enqueue(Q, 77);
    enqueue(Q, 77);

    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));

    return 0;
}
