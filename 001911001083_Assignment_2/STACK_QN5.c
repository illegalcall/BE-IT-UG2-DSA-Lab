#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int *array;
    int top1, top2;
    int capacity;
};

struct stack *create(int c)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    stack->capacity = c;
    stack->top1 = -1;
    stack->top2 = c;
    stack->array = (int *)malloc(c * sizeof(int));
}

int isFull(struct stack *stack)
{
    return (stack->top1 + 1 >= stack->top2);
}
void push1(struct stack *stack, int k)
{
    if (isFull(stack))
    {
        printf("Stack overflown\n");
        return;
    }
    stack->array[++stack->top1] = k;
}

void push2(struct stack *stack, int k)
{
    if (isFull(stack))
    {
        printf("Stack overflown\n");
        return;
    }
    stack->array[--stack->top2] = k;
}

int pop1(struct stack *stack)
{
    if (stack->top1 == -1)
    {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top1--];
}

int pop2(struct stack *stack)
{
    if (stack->top2 == stack->capacity)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top2++];
}

void printStack1(struct stack *stack)
{
    if (stack->top1 == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("The 1st stack is given by :\n");
    for (int i = stack->top1; i >= 0; i--)
        printf("%d ", stack->array[i]);
    printf("\n");
}

void printStack2(struct stack *stack)
{
    if (stack->top2 == stack->capacity)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("The 1st stack is given by :\n");
    for (int i = stack->top2; i < stack->capacity; i++)
        printf("%d ", stack->array[i]);
    printf("\n");
}

int main()
{
    struct stack *stack = create(20);
    push1(stack, 5);
    push1(stack, 10);
    push1(stack, 15);
    push1(stack, 20);

    pop1(stack);

    push2(stack, 50);
    push2(stack, 60);
    push2(stack, 70);

    pop2(stack);

    printStack1(stack);

    printStack2(stack);

    return 0;
}
