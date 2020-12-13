#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/*
Soumitri Chattopadhyay
*/

struct node
{
    double data;
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

void insertRear(struct queue *Q, double k)
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

void insertFront(struct queue *Q, double k)
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
        temp->next = Q->front;
        Q->front = temp;
    }
    Q->size++;
}

double deleteFront(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The queue is empty!\n");
        return INT_MIN;
    }
    struct node *temp = Q->front;
    Q->front = Q->front->next;
    Q->size--;
    double ans = temp->data;
    free(temp);
    return ans;
}

double deleteRear(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The Queue is empty\n");
        return INT_MIN;
    }
    struct node *temp = Q->front;
    if (Q->size != 1)
    {
        while (temp->next != Q->rear)
            temp = temp->next;
    }
    struct node *temp2 = Q->rear;
    double ans = temp2->data;
    Q->rear = temp;
    free(temp2);
    Q->size--;
    return ans;
}

double front(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The Queue is empty\n");
        return INT_MIN;
    }
    return Q->front->data;
}

double rear(struct queue *Q)
{
    if (isEmpty(Q))
    {
        printf("The Queue is empty\n");
        return INT_MIN;
    }
    return Q->rear->data;
}

void clear(struct queue *Q)
{
    struct node *temp;
    while (Q->front != NULL)
    {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
        Q->size--;
    }
}
int main()
{
    struct queue *Q = newQueue();

    insertFront(Q, 5);
    insertFront(Q, 10);
    insertFront(Q, 15);

    insertRear(Q, 20);
    insertRear(Q, 25);

    printf("%f\n", deleteFront(Q));
    printf("%f\n", deleteFront(Q));

    printf("%f\n", deleteRear(Q));
    printf("%f\n", deleteRear(Q));

    printf("Front: %f\n", front(Q));
    printf("Rear: %f\n", rear(Q));

    clear(Q);

    return 0;
}
