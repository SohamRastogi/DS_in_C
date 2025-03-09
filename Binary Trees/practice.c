#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root , int data)
{
    if(root == NULL)
    {
        root = (struct node*) malloc (sizeof(struct node));
        root -> data = data;
        root -> left = NULL;
        root -> right = NULL;
    }

    else if(root -> data > data)
    {
        root -> left = insert(root -> left , data);
    }
    else if(root -> data < data)
    {
        root -> right = insert(root -> right , data);
    }

    return root; 
}

void inorder_traversal(struct node* root)
{
    if(root == NULL) return ;
    inorder_traversal(root -> left);
    printf("%d ",root -> data);
    inorder_traversal(root -> right) ;
}

int main()
{
    struct node* root = NULL;
    
    root = insert(root , 3);
    root = insert(root , 2);
    root = insert(root , 4);
    root = insert(root , 6);
    root = insert(root , 5);
    root = insert(root , 1);

    inorder_traversal(root);

    return 0 ;
}