
/*

Name - Soumitri Chattopadhyay
Roll - 001911001083

Q2 - Insert a node at appropriate position in a sorted singly LL

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node Node;

Node *insertSortedList(Node *head, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->value = value;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    Node *itr1 = head;
    Node *itr2 = itr1->next;

    if (itr2->value > value)
    {
        // node to be inserted at the front
        head = newnode;
        newnode->next = itr1;
        return head;
    }

    while (itr2 != NULL)
    {
        if (itr1->value <= value && itr2->value >= value)
        {
            // node to be inserted between itr1 and itr2
            itr1->next = newnode;
            newnode->next = itr2;
            return head;
        }
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    // the node needs to be inserted at the end
    itr1->next = newnode;
    newnode->next = NULL;
    return head;
}

void printList(Node *head)
{
    Node *itr = head;
    while (itr != NULL)
    {
        printf("%d ", itr->value);
        itr = itr->next;
    }
    printf("\n");
}

Node *insert(Node *head, int value)
{
    Node *newnode = (Node *)malloc(sizeof(struct Node));
    newnode->value = value;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

int main()
{
    Node *head = NULL;
    for (int i = 2; i <= 10; i += 2)
    {
        head = insert(head, i);
    }
    printList(head);
    head = insertSortedList(head, 9);
    head = insertSortedList(head, 1);
    head = insertSortedList(head, 2);
    printList(head);
    head = insertSortedList(head, 0);
    head = insertSortedList(head, 19);
    head = insertSortedList(head, 5);
    head = insert(head, 20);
    head = insertSortedList(head, 14);
    printList(head);
    return 0;
}