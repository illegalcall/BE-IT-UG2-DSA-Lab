
/*

Name - Soumitri Chattopadhyay
Roll - 001911001083

Q5 - Concatenate 2 Circular Linked lists
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};

typedef struct Node Node;

Node *concatLists(Node *head1, Node *head2)
{
    Node *conhead = NULL;
    if (head1 && head2)
    {
        // both lists non-null
        Node *temp1 = head1;
        Node *temp2 = head2;
        while (temp1->next != head1)
        {
            temp1 = temp1->next;
        }
        while (temp2->next != head2)
        {
            temp2 = temp2->next;
        }
        temp1->next = head2;
        temp2->next = head1;
        conhead = head1;
    }
    else if (head1)
    {
        // head2 is null
        conhead = head1;
    }
    else if (head2)
    {
        // head1 is null
        conhead = head2;
    }
    return conhead;
}

Node *insert(Node *head, int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
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

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int data;

    // insert into first list
    printf("enter numbers into list 1, enter -999 to terminate\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == -999)
            break;
        head1 = insert(head1, data);
    }

    // insert into second list
    printf("enter numbers into list 2, enter -999 to terminate\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == -999)
            break;
        head2 = insert(head2, data);
    }

    // concatenate the two lists
    Node *con = concatLists(head1, head2);

    // display the concatenated list
    printf("Final list\n");

    Node *temp = con;
    while (temp->next != con)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
    return 0;
}