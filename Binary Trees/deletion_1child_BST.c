#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left ;
    struct node* right ;
};

struct node* insert(struct node* root , int key)
{
    if(root == NULL)
    {
        root = (struct node* ) malloc (sizeof(struct node));
        root -> data = key;
        root -> left = NULL;
        root -> right = NULL;
    }
    else if (root -> data > key){
        root -> left = insert(root -> left , key);
    }
    else root -> right = insert(root -> right , key);

    return root ;
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
    struct node* prev = NULL;  // 15 pe hai
    struct node* parent = NULL; // 20 pe hai
    struct node* next = NULL; // 13 pe hai

    while(root != NULL)
    {
        parent = prev;
        prev = root;
        if(root -> data == key)
        {
            break;
        }
        else if(root -> data > key){
            root = root -> left;
        }
        else root = root -> right;
    }
    if(prev -> left == NULL)
    {
        next = prev -> right;
    }
    else if (prev -> right == NULL)
    {
        next = prev -> left;
    }
    free(prev);

    if(parent -> data > next -> data)
    {
        parent -> left = next;
    }
    else if ( parent -> data < next -> data)
    {
        parent -> right = next;
    }

    return ;
    
}


int main()
{
    struct node* root;
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

    // delete 15 from the above BST, it has only 1 child 
    
    int key = 15;

    delete_node(root , key);

    inorder_traversal(root);

    return 0 ;
}