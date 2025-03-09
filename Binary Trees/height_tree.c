// tree could be a BST or any other tree.

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// user will insert values such that it is a BST.
struct node* create()
{
    struct node* newnode;
    newnode = (struct node*) malloc (sizeof(struct node));


    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    if(n==-1)
    {
        return NULL;
    }
    
    newnode -> data = n;
    
    printf("enter the left child of %d : \n",n);
    newnode -> left = create();

    printf("enter the right child of %d : \n",n);
    newnode -> right = create();

    return newnode;
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

int height_tree(struct node* root)
{
    if(root == NULL) return 0;
    else if (height_tree(root -> left) >= height_tree(root -> right)){
        return height_tree(root -> left) + 1;
    }
    else return height_tree(root ->right) + 1;
}

int main()
{
    struct node* root ;
    root = NULL;

    root = create();

    // inorder(root); // checker

    int height = height_tree(root);

    printf("%d",height);

    return 0;
}