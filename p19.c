//preorder traversal in linked representation of binary trees
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

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    //      root --> left --> right
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(5);
    /*
            1
           / \
          2   3
         / \ 
        4   5
    */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    return 0;
}