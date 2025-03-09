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
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* parent = NULL;

    while(root != NULL)
    {
        prev = root;
        if(root -> data == 10)
        {
            break;
        }
        else if (root -> data > 10)
        {
            root = root -> left;
        }
        else root = root -> right;
    }

    // printf("%d ",prev -> data);
    // printf("%d ",root -> data);

    // root and prev both at 10.

    next = prev -> left;
    root = next ;

    while(root != NULL)
    {
        parent = next;
        next = root;
        root = root -> right;
    }
    // printf("%d ",next -> data);

    // next pointing to inorder predecessor.

    int temp;
    temp = prev -> data;
    prev -> data = next -> data;
    next -> data = temp;

    free(next);
    parent -> right = NULL;

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

    // lets say we have to delete 10 according to inorder predecessor rule.

    int key = 10;

    delete_node(root , key);

    inorder_traversal(root);

    return 0 ;
}
