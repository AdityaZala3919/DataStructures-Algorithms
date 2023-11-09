//implementing stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

int isEmpty(struct Node *top);
int isFull();
void stackTraversal(struct Node *x);
struct Node * push(struct Node *top, int x);
int pop(struct Node *top);
int peek(int pos);
int stackTop();

int main()
{
    top = push(top, 12);
    top = push(top, 23);
    top = push(top, 34);
    top = push(top, 45);
    
    stackTraversal(top);

    printf("\nPopped element is %d\n", pop(top));
    printf("%d ", peek(3));
    return 0;
}

void stackTraversal(struct Node *x)
{
    while(x != NULL)
    {
        printf("%d ", x->data);
        x = x->next;
    }
}

int isEmpty(struct Node *top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()//(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node * push(struct Node *top, int x)
{
    if(!isFull(/*top*/))
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
    else
    {
        printf("\nStack OverFlow...");
        return 0;
    }
}

int pop(struct Node *top)
{
    if(!isEmpty(top))
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
    else
    {
        printf("\nStack UnderFlow...");
        return 0;
    }
}

int peek(int pos)
{
    int i=0;
    struct Node *x = top;
    while(x != NULL)
    {
        if(i == pos)
        {
            return x->data;
        }
        x = x->next;
        i++;
    }
    return -1;
}

int stackTop()
{
    return top->data;
}