#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MinPQS *MinPQ;

struct MinPQS
{
    int *q;
    int *idxq;
    int size;
    int rear;
    int end;
};

MinPQ createMinPQ(int size)
{
    if (size < 1)
        return NULL;
    MinPQ x = (MinPQ)malloc(sizeof(*x));
    if (!x)
        return NULL;
    x->size = size;
    x->end = -1;
    x->rear = -1;
    x->q = (int *)malloc(sizeof(int) * size);
    if (!(x->q))
        return NULL;
    for (int i = 0; i < size; i++)
        x->q[i] = -1;
    x->idxq = (int *)malloc(sizeof(int) * size);
    if (!(x->idxq))
        return NULL;
    for (int i = 0; i < size; i++)
        x->idxq[i] = -1;
    return x;
}

int enqueue(MinPQ x, int data)
{
    if (data == INT_MIN)
        return 0;
    if (x->rear + 1 == x->size)
        return 0;
    x->q[++(x->rear)] = data;
    // updating idxq :
    int i = 0;
    while (i <= x->end && x->q[x->idxq[i]] < data)
        i++;
    int j = x->end;
    while (j >= i)
    {
        x->idxq[j + 1] = x->idxq[j];
        j--;
    }
    x->idxq[i] = x->rear;
    x->end++;
    return 1;
}

int dequeue(MinPQ x)
{
    if (x->end == -1)
        return INT_MIN;
    int data = x->q[x->idxq[0]];
    x->q[x->idxq[0]] = -1;
    int j = 0;
    while (j < x->end)
    {
        x->idxq[j] = x->idxq[j + 1];
        j++;
    }
    x->idxq[x->end] = -1;
    x->end--;
    return data;
}

int main()
{
    printf("Enter a capacity : ");
    int cap;
    scanf("%d", &cap);
    MinPQ x = createMinPQ(cap);
    if (x == NULL)
    {
        exit(0);
    }
    int ch = 1, data;
    while (ch)
    {
        printf("0: Exit  1: enqueue  2: dequeue\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printf("Exiting\n");
            break;
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            if (enqueue(x, data) == 1)
                printf("Enqueued %d \n", data);
            else
                printf("Overflow! The PQ is full!\n");
            break;
        case 2:
            data = dequeue(x);
            if (data == INT_MIN)
                printf("Underflow! The PQ is empty!\n");
            else
                printf("Dequeued %d \n", data);
            break;
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}
