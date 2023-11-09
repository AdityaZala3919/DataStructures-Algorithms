//implementation of circular queue using array
#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

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
    if(((q->r)+1)%q->size == q->f)
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
        printf("\nQueue OverFlow...");
    }
    else
    {
        q->r = ((q->r)+1) % q->size;
        q->arr[q->r] = x;
        printf("\nEnQueued: %d",x);
    }
}

int deQueue(struct Queue *q)
{
    int x=-1;
    if(isEmpty(q))
    {
        printf("\nQueue UnderFlow...");
    }
    else
    {
        q->f = ((q->f)+1) % q->size;
        x = q->arr[q->f];
        printf("\nDeQueued: %d",x);
    }
    return x;
}

int main()
{
    struct Queue q;
    q.size = 4;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);

    deQueue(&q);
    deQueue(&q);
    deQueue(&q);

    enQueue(&q, 4);
    enQueue(&q, 5);
    enQueue(&q, 6);

    return 0;
}