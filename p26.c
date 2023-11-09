//rotation in AVL trees
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if(n==NULL)
        return 0;
    else
        return n->height;
}

int max (int a, int b){
    return (a>b)?a:b;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int getBalanceFactor(struct Node *n)
{
    if(n == NULL)
        return 0;
    else
        return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotation(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

struct Node *leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

struct Node *insertInTree(struct Node *node, int key)
{
    if(node == NULL)
    {
        return createNode(key);
    }

    if(key < node->key)
    {
        node->left = insertInTree(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insertInTree(node->right, key);
    }
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balfac = getBalanceFactor(node);

    //Left Left Case
    if(balfac > 1 && key < node->left->key)
    {
        return rightRotation(node);
    }

    //Right Right Case
    if(balfac < -1 && key > node->right->key)
    {
        return leftRotation(node);
    }

    //Left Right Case
    if(balfac > 1 && key > node->left->key)
    {
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    //Right Left Case
    if(balfac < -1 && key < node->right->key)
    {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }

    return node;
}

int main()
{
    struct Node * root = NULL;
 
    root = insertInTree(root, 1);
    root = insertInTree(root, 2);
    root = insertInTree(root, 4);
    root = insertInTree(root, 5);
    root = insertInTree(root, 6);
    root = insertInTree(root, 3);
    
    preOrder(root);

    return 0;
}