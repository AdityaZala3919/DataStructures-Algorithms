//delete operation in binary search trees
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

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int x)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL && root->data == x)
    {
        free(root);
        return 0;
    }

    if(x < root->data)
    {
        root->left = deleteNode(root->left, x);
    }
    else if(x > root->data)
    {
        root->right = deleteNode(root->right, x);
    }
    else
    {
        struct Node *iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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
    deleteNode(p, 4);
    printf("\n");
    inOrder(p);
    return 0;
}