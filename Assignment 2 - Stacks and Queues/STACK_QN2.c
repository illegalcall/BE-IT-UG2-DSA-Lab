#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
	int data;
	struct StackNode *next;
};

struct StackNode *newNode(int val)
{
	struct StackNode *stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
	stackNode->data = val;
	stackNode->next = NULL;
	return stackNode;
}

int isEmpty(struct StackNode *head)
{
	return !head;
}

void push(struct StackNode **head, int val)
{
	struct StackNode *stackNode = newNode(val);
	stackNode->next = *head;
	*head = stackNode;
	printf("%d pushed to stack\n", val);
}

int pop(struct StackNode **head)
{
	if (isEmpty(*head))
		return INT_MIN;
	struct StackNode *temp = *head;
	*head = (*head)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(struct StackNode *head)
{
	if (isEmpty(head))
		return INT_MIN;
	return head->data;
}

int main()
{
	struct StackNode *head = NULL;

	push(&head, 5);
	push(&head, 10);
	push(&head, 15);

	printf("%d popped from stack\n", pop(&head));

	printf("Top element is %d\n", peek(head));

	return 0;
}
