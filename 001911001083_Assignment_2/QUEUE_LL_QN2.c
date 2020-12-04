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
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

int isEmpty(struct queue *queue)
{
    return queue->size == 0;
}

void enqueue(struct queue *queue, int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->rear->next = temp;
        queue->rear = temp;
    }
    queue->size++;
}

int dequeue(struct queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is empty\n");
        return INT_MIN;
    }
    struct node *temp = queue->front;
    queue->front = queue->front->next;
    queue->size--;
    int ans = temp->data;
    free(temp);
    return ans;
}

int main()
{
    struct queue *queue = newQueue();

    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    enqueue(queue, 25);
    enqueue(queue, 30);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    return 0;
}
