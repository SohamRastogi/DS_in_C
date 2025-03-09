#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root , int key)
{
    if(root == NULL)
    {
        root = (struct node*) malloc (sizeof(struct node));
        root -> data = key;
        root -> left = NULL;
        root -> right = NULL;
    }
    else if (root -> data > key)
    {
        root -> left = insert(root -> left , key);
    }
    else {
        root -> right = insert(root -> right , key);
    }

    return root;
}

void inorder_traversal(struct node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder_traversal(root -> left);
    printf("%d ",root -> data);
    inorder_traversal(root -> right);
}

void delete_node(struct node* root , int key)
{
    struct node* prev = NULL;
    struct node* child = NULL;
    struct node* parent = NULL;
    struct node* next = NULL;

    while(root != NULL)
    {
        prev = root;
        if(root -> data == key)
        {
            break;
        }
        else if ( root -> data > key)
        {
            root = root -> left;
        }
        else root = root -> right;
    }

    // printf("%d %d",root -> data , prev -> data);
    // both prev and root points to 10.

    next = prev -> right;
    root = next;
    while(root != NULL)
    {
        parent = next;
        next = root;
        root = root -> left;
    }

    // printf("%d ",parent -> data);

    // next points to inorder successor
    int temp;
    temp = next -> data;
    next -> data = prev -> data;
    prev -> data = temp;

    free(next);
    parent -> left = NULL;

    return ;
}



int main()
{
    struct node* root ;
    root = NULL;
    
    root = insert(root , 25);
    root = insert(root , 10);
    root = insert(root , 5);
    root = insert(root , 3);
    root = insert(root , 6);
    root = insert(root , 20);
    root = insert(root , 15);
    root = insert(root , 13);
    root = insert(root , 21);
    root = insert(root , 40);
    root = insert(root , 35);

    inorder_traversal(root);
    printf("\n");

    int key = 10;

    // i have to delete the node 10 by inorder successor.

    delete_node(root,10);

    inorder_traversal(root);

    return 0 ;
}