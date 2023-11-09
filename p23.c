//iterative search operation in binary search trees
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct Node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int isBST(struct Node *root)
{
    static struct Node *previous = NULL;
    if(root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(previous != NULL && root->data <= previous->data)
        {
            return 0;
        }
        previous = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *iterativeSearch(struct Node *root, int x)
{
    while(root != NULL)
    {
        if(x == root->data)
        {
            return root;
        }
        else if(x < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(5);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(3);
    /*
            4
           / \
          2   5
         / \ 
        1   3
    */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    printf("\n%d ",isBST(p));

    struct Node *n = iterativeSearch(p, 39);
    if(n != NULL)
    {
        printf("\nFound: %d",n->data);
    }
    else
    {
        printf("\nElement Not Found...");
    }
    return 0;
}