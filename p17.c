//implementation of queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

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

int isEmpty()
{
    if(f == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *n)
{
    if(n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if(isFull(n))
    {
        printf("\nQueue OverFlow...");
    }
    else
    {
        n->data = x;
        n->next = NULL;
        if(isEmpty(f))
        {
            f = n;
            r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
        printf("\nEnqueued: %d",x);
    }
}

int deQueue()
{
    int x = -1;
    struct Node * n = f;
    if(isEmpty(f))
    {
        printf("\nQueue UnderFlow...");
    }
    else
    {
        f = f->next;
        x = n->data;
        free(n);
        printf("\nDequeued: %d",x);
    }
    return x;
}

int main()
{
    enQueue(12);
    enQueue(23);
    enQueue(34);
    linkedListTraversal(f);
    deQueue();
    deQueue();
    linkedListTraversal(f);
    return 0;
}