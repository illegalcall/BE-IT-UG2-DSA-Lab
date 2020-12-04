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
	printf("%d pushed to stack\n", val);
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
	struct Stack *stack = create(100);

	push(stack, 5);
	push(stack, 10);
	push(stack, 15);

	printf("%d popped from stack\n", pop(stack));

	printf("%d is at the top of the stack\n", peek(stack));

	return 0;
}
