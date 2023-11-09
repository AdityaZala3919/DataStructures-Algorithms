//deletion in circular linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void circularLinkedListTraversal(struct Node *head);
struct Node *deleteFirst(struct Node *head);
struct Node *deleteAtIndex(struct Node *head, int index);
struct Node *deleteLast(struct Node *head);
struct Node *deleteAtValue(struct Node *head, int value);

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st & 2nd Nodes
    head->data = 1;
    head->next = second;

    // Link 2nd & 3rd Nodes
    second->data = 2;
    second->next = third;

    // Link 3rd & 4th Nodes
    third->data = 3;
    third->next = fourth;

    // Link 4th & 1st Nodes to make it circular
    fourth->data = 4;
    fourth->next = head;

    circularLinkedListTraversal(head);

    // head = deleteFirst(head); // deleting 1st Element of the circular linked list
    // head = deleteAtIndex(head, 2); // deleting element at a given index of the circular linked list
    // head = deleteLast(head); // delete last element of the circular linked list
    head = deleteAtValue(head, 3); // deleting element with a given value of the circular linked list
    printf("\n");
    circularLinkedListTraversal(head);

    return 0;
}

void circularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    int c = 0;
    do
    {
        printf("\nElement %d: %d", c, ptr->data);
        ptr = ptr->next;
        c++;
    } while (ptr != head);
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    head = head->next;
    p->next = head;

    free(ptr);
    return head;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return (head);
}

struct Node *deleteLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    p->next = head;
    free(q);
    return (head);
}

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != head)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return (head);
}
