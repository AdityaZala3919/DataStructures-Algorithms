//traversal in a doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void linkedListTraversal(struct Node *ptr)
{
    int c=0;
    while(ptr->next!=NULL)
    {
        printf("\nElement %d: %d",c,ptr->data);
        ptr = ptr->next;
        c++;
    }
    printf("\nElement %d: %d\n",c,ptr->data);
    while(ptr!=NULL)
    {
        printf("\nElement %d: %d",c,ptr->data);
        ptr = ptr->prev;
        c--;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    //Allocate memory for nodes in the Linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    //Link 1st & 2nd Nodes
    head->data = 1;
    head->next = second;
    head->prev = NULL;

    //Link 2nd & 3rd Nodes
    second->data = 2;
    second->next = third;
    second->prev = head;

    //Terminate the List at 3rd Node
    third->data = 3;
    third->next = fourth;
    third->prev = second;

    //Terminate the List at 4rd Node
    fourth->data = 4;
    fourth->next = NULL;
    fourth->prev = third;

    linkedListTraversal(head);
    
    return 0;
}