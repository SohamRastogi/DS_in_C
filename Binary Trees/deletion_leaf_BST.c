#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create()
{
    struct node* newnode;
    newnode = (struct node*) malloc(sizeof(struct node));

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
    struct node* father = NULL;
    while(root != NULL)
    {
        father = prev;
        prev = root ;
        if(root == NULL){
            break;
        }
        else if(root -> data > key){
            root = root -> left;
        }
        else {
            root = root -> right;
        }
    }
    // printf("%d ",prev-> data);
    // printf("\n%d ",father -> data);
    if(father -> data > prev -> data)
    {
        father -> left = NULL;
        free(prev);
    }
    else{
        father -> right = NULL;
        free(prev);
    }
    return ;
}

int main()
{
    struct node* root;
    root = NULL;

    root = create();

    inorder_traversal(root);
    printf("\n");

    // delete the leaf node :
    // delete 13 for example

    int key = 13;

    delete_node(root , key);

    inorder_traversal(root);


    return 0 ;

}