
/*

Name - Soumitri Chattopadhyay
Roll - 001911001083

Q3 - Concatenate 2 singly Linked lists
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

Node *concatLists(Node *head1, Node *head2)
{
    Node *conhead = NULL;
    if (head1 && head2)
    { // both lists are non-null
        Node *temp = head1;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        conhead = head1;
    }
    else if (head1)
    { // head2 is null
        conhead = head1;
    }
    else if (head2)
    { // head1 is null
        conhead = head2;
    }
    return conhead;
}

Node *insert(Node *head, int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
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
    while (con != NULL)
    {
        printf("%d ", con->data);
        con = con->next;
    }
    return 0;
}