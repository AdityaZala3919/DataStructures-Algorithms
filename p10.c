//insertion in circular linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    int c=0;
    do
    {
        printf("\nElement %d: %d",c,ptr->data);
        ptr = ptr->next;
        c++;
    }while(ptr != head);
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;

    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr; 
    return head;
}

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

    //Link 1st & 2nd Nodes
    head->data = 1;
    head->next = second;

    //Link 2nd & 3rd Nodes
    second->data = 2;
    second->next = third;

    //Terminate the List at 3rd Node
    third->data = 3;
    third->next = fourth;

    //Terminate the List at 4rd Node
    fourth->data = 4;
    fourth->next = head;

    linkedListTraversal(head);
    head = insertAtFirst(head, 69);
    linkedListTraversal(head);
    
    return 0;
}