
/*

Name - Soumitri Chattopadhyay
Roll - 001911001083

Q1 - implement following functions for circular linked list

– isEmpty
– getLength
– insert
– delete
– Lookup

*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node Node;

int isEmpty(Node *head)
{
    return head == NULL;
}

int getLength(Node *head)
{
    if (head == NULL)
        return 0;
    int len = 0;
    Node *temp = head;
    while (temp->next != head)
    {
        len++;
        temp = temp->next;
    }
    return len + 1;
}

Node *insert(Node *head, int value)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->value = value;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return head;
    }
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
    return head;
}

Node *deleteAt(Node *head, int index)
{
    int len = getLength(head);
    if (index >= len)
        return head;

    Node *temp = head;

    if (index == 0)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *temp1 = head;
        head = head->next;
        temp->next = head;
        free(temp1);
        return head;
    }

    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    return head;
}

int lookupValue(Node *head, int search)
{
    if (head == NULL)
        return -1;
    int index = 0;
    Node *temp = head;
    while (temp->next != head)
    {
        if (temp->value == search)
            return index;
        index++;
        temp = temp->next;
    }
    return -1;
}

void printList(Node *head)
{
    Node *itr = head;
    while (itr->next != head)
    {
        printf("%d ", itr->value);
        itr = itr->next;
    }
    printf("%d ", itr->value);
    printf("\n");
}

int main()
{
    Node *head = NULL;
    head = insert(head, 20);
    printList(head);
    head = insert(head, 12);
    printList(head);
    head = insert(head, 31);
    printList(head);
    head = insert(head, 4);
    printList(head);
    head = insert(head, 7);
    printList(head);
    printf("%d\n", getLength(head));
    head = deleteAt(head, 2);
    printf("%d\n", getLength(head));
    printList(head);
    head = insert(head, 43);
    head = insert(head, 11);
    printList(head);
    printf("%d\n", getLength(head));
    printf("%d\n", lookupValue(head, 12));
    printf("%d\n", lookupValue(head, 69));

    return 0;
}