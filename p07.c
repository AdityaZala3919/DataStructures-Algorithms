//insertion in a linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr);
struct Node * insertAtFirst(struct Node * head, int data);
struct Node * insertAtIndex(struct Node * head, int data, int index);
struct Node * insertAtEnd(struct Node * head, int data);
struct Node * insertAfterNode(struct Node * head, struct Node * prevNode, int data);

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

    //Link 3rd & 4th Nodes
    third->data = 3;
    third->next = fourth;

    //Terminate List At 4th Node
    fourth->data = 4;
    fourth->next = NULL;

    linkedListTraversal(head);
    //head = insertAtFirst(head, 1234);
    head = insertAtIndex(head, 1234, 2);
    //head = insertAtEnd(head, 1234);
    //head = insertAfterNode(head, second, 1234);
    linkedListTraversal(head);
    
    return 0;
}

void linkedListTraversal(struct Node *ptr)
{
    int c=0;
    while(ptr!=NULL)
    {
        printf("\nElement %d: %d",c,ptr->data);
        ptr = ptr->next;
        c++;
    }
}

struct Node * insertAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=head;
    return ptr;
}

struct Node * insertAtIndex(struct Node * head, int data, int index)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;

    while(i!=(index-1))
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * prevNode, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr; 
    return head;  
}
