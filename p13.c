//implementing stack using array
#include <stdio.h>
#include <stdlib.h>
 
struct Stack
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int val)
{
    if(isFull(ptr))
    {
        printf("\nStack OverFlow...!!!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct Stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("\nUnderFlow...!!!");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *s, int i)
{
    int arrIndex = (s->top)-i+1;
    if(arrIndex < 0)
    {
        printf("\nError...Invalid Position...!!!");
        return -1;
    }
    else 
    {
        return s->arr[arrIndex];
    }
}

int stackTop(struct Stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct Stack *s)
{
    return s->arr[0];
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    for(int i=1;i<=(s->top+1);i++)
    {
        printf("%d ",peek(s, i));
    }
    printf("\nPopped: %d", pop(s));
    printf("\nPopped: %d", pop(s));    
    for(int i=1;i<=(s->top+1);i++)
    {
        printf("%d ",peek(s, i));
    }
    return 0;
}
