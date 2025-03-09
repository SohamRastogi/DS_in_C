#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create()
{
    int x ;
    struct node* newnode;
    newnode = (struct node*) malloc (sizeof(struct node));

    printf("enter data : ");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }

    newnode -> data = x;

    printf("enter left child of %d\n",x);
    newnode -> left = create();

    printf("enter right child of %d\n",x);
    newnode -> right = create();

    return newnode ;

}

void inorder_traversal(struct node* root)
{
    if(root == NULL) return ;

    inorder_traversal (root -> left);
    printf("%d ",root -> data);
    inorder_traversal (root -> right);

}

void preorder_traversal(struct node* root)
{
    if(root == NULL) return ;
    
    printf("%d ",root -> data);
    preorder_traversal (root -> left);
    preorder_traversal (root -> right);
}

void postorder_traversal (struct node* root)
{
    if(root == NULL) return ;

    postorder_traversal (root -> left);
    postorder_traversal (root -> right);
    printf("%d ",root -> data);
}


int main()
{
    struct node* root;
    root = NULL;

    root = create();

    printf("\n");
    inorder_traversal(root);
    printf("\n");
    preorder_traversal(root);
    printf("\n");
    postorder_traversal(root);

    return 0 ;
}