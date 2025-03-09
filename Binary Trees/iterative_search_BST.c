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
    else if (data < root -> data)
    {
        root -> left = insert(root -> left , data);
    }
    else 
        root -> right = insert(root -> right , data);

    return root ;
}

struct node* search_iterative(struct node* root , int key)
{
    while(root != NULL)
    {
    if(root -> data == key)
    {
        return root ;
    }
    else if (root -> data > key)
    {
        root = root -> left;
    }
    else root = root -> right;
    }
    return NULL;
}
// void inorder(struct node* root)
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     inorder(root -> left);
//     printf("%d ",root -> data);
//     inorder(root -> right);
// }

int main()
{
    struct node* root ;
    root = NULL;
    root = insert(root , 5);
    root = insert(root , 3);
    root = insert(root , 6);
    root = insert(root , 1);
    root = insert(root , 4);

    int key;
    printf("enter value to be searched : ");
    scanf("%d",&key);

    // inorder(root);


    struct node* temp = NULL;

    temp = search_iterative(root , key);

    if(temp != NULL)
    {
        printf("element found");
    }
    else {
        printf("element not found");
    }

    return 0 ;

}