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
    else if (root -> data > data)
    {
        root -> left = insert(root -> left , data);
    }
    else {
        root -> right = insert(root -> right , data);
    }

    return root;
}

void inorder(struct node* root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder(root -> left);
    printf("%d ",root -> data);
    inorder(root -> right);
}

void insert_node(struct node* root , int key)
{
    struct node* prev = NULL;
    while(root != NULL)
    {
        prev = root ;

        if(root -> data == key)
        {
            printf("already in BST, no insertion required.");
            return ;
        }
        else if(root -> data > key)
        {
            root = root -> left;
        }
        else root = root -> right;
    }
    struct node* new1;
    new1 = (struct node*) malloc (sizeof(struct node));

    new1 -> data = key;
    new1 -> left = NULL;
    new1 -> right = NULL;

    if(prev -> data > new1 -> data)
    {
        prev -> left = new1;
    }
    else prev -> right = new1;

}

int main()
{
    struct node* root;
    root = NULL;

    root = insert(root , 4);
    root = insert(root , 20);
    root = insert(root , 27);
    root = insert(root , 16);
    root = insert(root , 8);
    root = insert(root , 2);

    insert_node(root , 1);

    inorder(root);

    return 0 ;
}