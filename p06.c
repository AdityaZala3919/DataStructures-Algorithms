//traversal in linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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

int searchElement(struct Node *ptr, int target) {
    int c = 0;
    while (ptr != NULL) {
        if (ptr->data == target) {
            return c;
        }
        ptr = ptr->next;
        c++;
    }
    return -1;
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

    //Link 2nd & 3rd Nodes
    second->data = 2;
    second->next = third;

    //Terminate the List at 3rd Node
    third->data = 3;
    third->next = fourth;

    //Terminate the List at 4rd Node
    fourth->data = 4;
    fourth->next = NULL;

    linkedListTraversal(head);
    
    return 0;
}
