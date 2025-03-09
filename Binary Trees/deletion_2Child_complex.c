#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert(struct node* root , int data)
{
    if (root == NULL)
    {
        root = (struct node*) malloc (sizeof(struct node));
        root -> data = data;
        root -> left = NULL;
        root -> right = NULL;
    }

    else if (root -> data > data)
    {
        root -> left = insert(root -> left , data);
    }
    else 
    {
        root -> right = insert(root -> right , data);
    }

    return root ;

}

void inorder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root -> left);
    printf("%d ",root -> data);
    inorder(root -> right);
    
}

void delete_node(struct node* root , int key)
{
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* child = NULL;
    struct node* parent = NULL;

    while(root != NULL)
    {
        prev = root;
        if(root -> data == key){
            break;
        }
        else if (root -> data > key)
        {
            root = root -> left;
        }
        else root = root -> right;
    }
    // printf("%d %d",prev -> data , root ->data);

    // now prev and root both points to 10.

    next = prev -> right;
    root = next;

    // printf("%d %d",next -> data,root -> data);

    while(root != NULL)
    {
        parent = next;
        next = root;
        root = root -> left;
    }

    // printf("%d",parent -> data);
    // next points at 15 now !!
    // parent points at 20 now !!

    child = next -> right;

    // child points at 16 now !!

    int temp ;
    temp = prev -> data;
    prev -> data = next -> data;
    next -> data = temp;

    free(next);

    parent -> left = child;

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
    root = insert(root , 21);
    root = insert(root , 16);
    root = insert(root , 40);

    inorder(root);
    
    printf("\n");

    // we have to delete 10 by inorder successor compulsarily.

    int key = 10;

    delete_node(root , key);
    
    inorder(root);

    return 0 ;
}