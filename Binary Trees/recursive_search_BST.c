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
        root -> data  = key;
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

    return root ;

}

// void inorder(struct node* root)
// {
//     if(root == NULL) return ;
//     inorder(root -> left);
//     printf("%d ",root -> data);
//     inorder(root -> right);


// }

struct node* search(struct node* root , int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root -> data == key)
    {
        return root;
    }
    else if (root -> data > key)
    {
        return search(root -> left , key);
    }
    else 
    {
        return search (root -> right , key);
    }
}

int main()
{
    struct node* root ;
    root = NULL;
    
    root = insert(root , 10);
    root = insert(root , 15);
    root = insert(root , 4);
    root = insert(root , 2);
    root = insert(root , 26);
    root = insert(root , 6);
    root = insert(root , 8);

    // inorder(root);
    
    int key;
    printf("element to be searched : ");
    scanf("%d",&key);

    struct node* temp = NULL;

    temp = search(root , key);

    if(temp != NULL) {
        printf("element found ");
    }
    else{
        printf("element not found");
    }

    return 0;
}