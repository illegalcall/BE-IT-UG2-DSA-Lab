#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int from, to, aux, num;
};

struct Stack
{
    int top;
    int capacity;
    struct Node *array;
};

struct Stack *create(int cap)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (struct Node *)malloc(stack->capacity * sizeof(struct Node));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, struct Node curr)
{
    if (isFull(stack))
        return;
    struct Node p = curr;

    stack->array[++stack->top] = p;
}

struct Node *pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;

    struct Node *p = &(stack->array[stack->top--]);

    return p;
}

struct Node *peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return NULL;

    struct Node *p = &(stack->array[stack->top]);

    return p;
}

void TOH(int from, int to, int aux, int num)
{

    struct Stack *stack = create(num);

    struct Node curr = {from, to, aux, num};

    while (!isEmpty(stack) || curr.num != 0)
    {
        if (curr.num > 0)
        {
            push(stack, curr);
            curr.num--;
            int tmp = curr.aux;
            curr.aux = curr.to;
            curr.to = tmp;
        }
        else
        {
            struct Node *ret = peek(stack);
            curr = (*ret);
            pop(stack);

            printf("Disc is moved from %d pole to %d pole\n", curr.from, curr.to);

            curr.num--;
            int tmp = curr.from;
            curr.from = curr.aux;
            curr.aux = tmp;
        }
    }
}

int main()
{
    int n;

    printf("Number of discs in Tower of Hanoi is :");

    scanf("%d", &n);

    TOH(1, 3, 2, n); /*TOH(from_rod,to_rod,aux_rod,no_of_discs)*/
    /*HERE SOURCE IS 1ST ROD DESTINATION IS 3RD ROD AND THE OTHER AUXILIARY ROD IS 2ND ROD AND NO. OF DISCS IS TAKEN TO BE 3*/

    return 0;
}