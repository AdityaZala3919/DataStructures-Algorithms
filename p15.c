//implementation of queue using arrays
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q);
int isFull(struct Queue *q);
void enQueue(struct Queue *q, int x);
int deQueue(struct Queue *q);
void printQueue(struct Queue *q);

int main()
{
    struct Queue q;
    q.size = 100;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enQueue(&q, 12);
    enQueue(&q, 23);
    enQueue(&q, 34);
    enQueue(&q, 45);
    enQueue(&q, 56);
    printf("\n");
    printQueue(&q);

    printf("\nDeQueued: %d",deQueue(&q));
    printf("\nDeQueued: %d",deQueue(&q));

    printQueue(&q);
    return 0;
}

int isEmpty(struct Queue *q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Queue *q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(struct Queue *q, int x)
{
    if(isFull(q))
    {
        printf("\nQueue OverFlow...!!!");
    }
    else
    {
        q->r++;
        q->arr[q->r] = x;
        printf("\nEnqueued: %d",x);
    }
}

int deQueue(struct Queue *q)
{
    int a = -1;
    if(isEmpty(q))
    {
        printf("\nQueue UnderFlow...!!!");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void printQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nQueue: ");
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}