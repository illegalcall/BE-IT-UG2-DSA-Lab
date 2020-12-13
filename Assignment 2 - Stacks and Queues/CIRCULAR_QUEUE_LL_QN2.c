#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Soumitri Chattopadhyay
*/

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

void enqueue(struct queue *Q, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = Q->front;

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
    Q->rear->next = Q->front;
    Q->size--;
    int ans = temp->data;
    free(temp);
    return ans;
}

int main()
{
    struct queue *Q = newQueue();
    enqueue(Q, 5);
    enqueue(Q, 10);
    enqueue(Q, 15);
    enqueue(Q, 20);

    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));

    enqueue(Q, 25);
    enqueue(Q, 30);

    printf("%d\n", dequeue(Q));
    printf("%d\n", dequeue(Q));

    return 0;
}
