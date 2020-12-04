#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node **stack)
{
    if (*stack == NULL)
        return 1;
    return 0;
}

struct node *push(struct node **stack, int k)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = k;
    temp->next = *stack;
    *stack = temp;
}

int pop(struct node **stack)
{
    int popped_val;
    if (isEmpty(stack))
    {
        printf("The stack is empty\n");
        return INT_MIN;
    }
    struct node *temp = *stack;
    popped_val = temp->data;
    *stack = (*stack)->next;
    free(temp);
    return popped_val;
}

int top(struct node **stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty!\n");
        return -1;
    }
    return (*stack)->data;
}

void printStack(struct node **stack)
{
    struct node *temp = *stack;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int findMin(struct node **stack)
{
    if (isEmpty(stack))
        return INT_MAX;

    int data = pop(stack);
    int ans = min(data, findMin(stack));
    push(stack, data);
    return ans;
}

int main()
{
    struct node *stack = NULL;

    push(&stack, 5);
    push(&stack, 8);
    push(&stack, 2);
    push(&stack, 50);
    push(&stack, 13);
    push(&stack, 5);
    push(&stack, 4);

    printf("Minimum element in the stack is: %d\n", findMin(&stack));

    return 0;
}