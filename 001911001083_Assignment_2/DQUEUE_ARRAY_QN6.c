#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
Soumitri Chattopadhyay
*/

struct queue
{
    double *array;
    int front;
    int rear;
    int maxsize;
    int size;
};

struct queue *newQueue(int ms)
{
    struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
    Q->array = (double *)malloc(sizeof(double) * ms);
    Q->front = -1;
    Q->rear = 0;
    Q->maxsize = ms;
    Q->size = 0;
}

int isFull(struct queue *Q)
{
    return ((Q->front == 0 && Q->rear == Q->maxsize - 1) || Q->front == Q->rear + 1);
}

int isEmpty(struct queue *Q)
{
    return (Q->front == -1) || (Q->size == 0);
}

void insertRear(struct queue *Q, double val)
{
    if (isFull(Q))
    {

        printf("The queue is full\n");
        return;
    }

    if (Q->front == -1)
    {
        Q->front = 0;
        Q->rear = 0;
    }

    else if (Q->rear == Q->maxsize - 1)
        Q->rear = 0;

    else
        Q->rear = Q->rear + 1;

    Q->array[Q->rear] = val;
    Q->size++;
}

void insertFront(struct queue *Q, double val)
{
    if (isFull(Q))
    {
        printf("The Queue is full\n");
        return;
    }
    if (Q->front == -1)
    {
        Q->front = 0;
        Q->rear = 0;
    }

    else if (Q->front == 0)
        Q->front = Q->maxsize - 1;

    else
        Q->front = Q->front - 1;

    Q->array[Q->front] = val;
    Q->size++;
}

double deleteFront(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The queue is empty!\n");
        return INT_MIN;
    }
    if (Q->front == Q->rear)
    {
        double ret = Q->array[Q->front];
        Q->front = -1;
        Q->rear = -1;
        Q->size--;
        return ret;
    }
    else if (Q->front == Q->maxsize - 1)
    {
        double ret = Q->array[Q->front];
        Q->front = 0;
        Q->size--;
        return ret;
    }
    else
    {
        double ret = Q->array[Q->front];
        Q->front = Q->front + 1;
        Q->size--;
        return ret;
    }
}

double deleteRear(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The Queue is empty!\n");
        return INT_MIN;
    }
    if (Q->front == Q->rear)
    {
        double ret = Q->array[Q->rear];
        Q->front = -1;
        Q->rear = -1;
        Q->size--;
        return ret;
    }
    else if (Q->rear == 0)
    {
        double ret = Q->array[Q->rear];
        Q->rear = Q->maxsize - 1;
        Q->size--;
        return ret;
    }
    else
    {
        double ret = Q->array[Q->rear];
        Q->rear = Q->rear - 1;
        Q->size--;
        return ret;
    }
}

double front(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The Queue is empty!\n");
        return INT_MIN;
    }
    return Q->array[Q->front];
}

double rear(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The queue is empty!\n");
        return INT_MIN;
    }
    return Q->array[Q->rear];
}

void clear(struct queue *Q)
{
    free(Q->array);
    Q->front = 20;
    Q->rear = 20;
}
int main()
{
    struct queue *Q = newQueue(100);
    insertFront(Q, 10);
    insertFront(Q, 20);
    insertFront(Q, 30);
    insertFront(Q, 40);
    insertFront(Q, 50);

    insertRear(Q, 60);
    insertRear(Q, 70);
    insertRear(Q, 80);
    insertRear(Q, 90);
    insertRear(Q, 100);

    printf("%f \n", deleteFront(Q));
    printf("%f \n", deleteRear(Q));
    printf("%f \n", deleteFront(Q));
    printf("%f \n", deleteRear(Q));

    printf("Front: %f \n", front(Q));
    printf("Rear: %f \n", rear(Q));

    clear(Q);

    return 0;
}
