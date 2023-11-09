//insert operation in binary search trees
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

void insertInBST(struct Node *root, int x)
{
    struct Node *previous = NULL;
    while(root != NULL)
    {
        previous = root;
        if(x == root->data)
        {
            return;
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
    struct Node *new = createNode(x);
    if(x < previous->data)
    {
        previous->left = new;
    }
    else
    {
        previous->right = new;
    }
    printf("Inserted: %d\n", x);
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

    insertInBST(p, 6);
    printf("%d\n", p->right->right->data);
    inOrder(p);
    return 0;
}