#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *create(int cap)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
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

void push(struct Stack *stack, int val)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = val;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int main()
{
    struct Stack *stack = create(100); /*considering maximum length of the Fibonacci Series to be 100*/

    int n, a, b, c;
    int fib[100] = {0};

    scanf("%d", &n);

    push(stack, 0);
    push(stack, 1);

    for (int i = 1; i <= (n - 2); i++)
    {
        b = pop(stack);
        a = pop(stack);

        c = a + b;

        push(stack, a);
        push(stack, b);
        push(stack, c);
    }

    for (int i = 1; i <= n; i++)
    {
        fib[n - i] = pop(stack);
    }

    printf("The series is given as :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
    }

    return 0;
}
