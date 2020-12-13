#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue
{
    int *array;
    int front;
    int rear;
    int maxsize;
    int size;
};

struct queue *create(int ms)
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->array = (int *)malloc(sizeof(int) * ms);
    queue->front = -1;
    queue->rear = -1;
    queue->maxsize = ms;
    queue->size = 0;
}

int isFull(struct queue *queue)
{
    return (queue->rear == queue->maxsize - 1);
}

int isEmpty(struct queue *queue)
{
    return (queue->front >= queue->rear);
}

void enqueue(struct queue *queue, int val)
{
    if (isFull(queue))
    {
        printf("The queue is full\n");
        return;
    }
    queue->array[++queue->rear] = val;
    queue->size++;
}

int dequeue(struct queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is empty\n");
        return INT_MIN;
    }
    queue->size--;
    return queue->array[++queue->front];
}

int main()
{
    struct queue *queue = create(20);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("%d\n", dequeue(queue));
    printf("%d\n", dequeue(queue));

    enqueue(queue, 60);
    enqueue(queue, 70);
    enqueue(queue, 80);

    printf("%d\n", dequeue(queue));

    return 0;
}
