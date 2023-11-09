//breadth first search in graphs
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

int main()
{
    struct Queue q;
    q.size = 400;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //BFS implementation
    int node;
    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7] = {
    //   0 1 2 3 4 5 6
        {0,1,1,1,0,0,0},// 0
        {1,0,1,0,0,0,0},// 1
        {1,1,0,1,1,0,0},// 2
        {1,0,1,0,1,0,0},// 3
        {0,0,1,1,0,1,1},// 4
        {0,0,0,0,1,0,0},// 5
        {0,0,0,0,1,0,0} // 6
    };
    printf("%d ", i);
    visited[i] = 1;
    enQueue(&q, i);
    while(!isEmpty(&q))
    {
        node = deQueue(&q);
        for(int j=0;j<7;j++)
        {
            if(a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enQueue(&q, j);
            }
        }
    }
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