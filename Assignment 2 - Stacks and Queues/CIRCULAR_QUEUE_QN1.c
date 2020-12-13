#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Soumitri Chattopadhyay
*/

struct queue
{
    int *array;
    int front;
    int rear;
    int maxsize;
    int size;
};

struct queue *createQueue(int ms)
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
    return (queue->front == (queue->rear + 1) % (queue->maxsize));
}

int isEmpty(struct queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct queue *queue, int val)
{
    if (isFull(queue))
    {
        printf("The queue is full\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear % queue->maxsize] = val;
    queue->size++;
}

int dequeue(struct queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is empty\n");
        return INT_MIN;
    }
    queue->front = (queue->front + 1) % queue->maxsize;
    queue->size--;
    return queue->array[queue->front];
}

int main()
{
    struct queue *queue = createQueue(20);

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
