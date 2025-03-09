#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root , int value)
{
    if(root == NULL)
    {
        root = (struct node*) malloc (sizeof(struct node));
        root -> data = value;
        root -> left = NULL;
        root -> right = NULL;
    }
    else if (value < root -> data)
    {
        root -> left = insert(root -> left , value);
    }
    else 
    {
        root -> right = insert(root -> right , value);
    }

    return root ;
}

void inorder_traversal(struct node* root )
{
    if(root == NULL)
    {
        return ;
    }
    inorder_traversal(root -> left);
    printf("%d ",root -> data);
    inorder_traversal(root -> right);

    
}

int main()
{
    struct node* root ;
    root = NULL;

    root = insert(root , 10);
    root = insert(root , 5);
    root = insert(root , 8);
    root = insert(root , 20);
    root = insert(root , 18);
    root = insert(root , 6);

    inorder_traversal(root) ;

    return 0 ;
}