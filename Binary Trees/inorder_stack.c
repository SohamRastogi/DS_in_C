#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* stack[10];
int top = -1;

struct node* create()
{
    struct node* newnode;
    newnode = NULL;

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

void push(struct node* root)
{
    if(top == 9) printf("stack overflow");
    
    top++;
    stack[top] = root ;
}

struct node* pop()
{
    int alpha = top;
    top--;

    return stack[alpha];
}

// void inorder_traversal(struct node* root)
// {
//     if(root == NULL) return ;
//     inorder_traversal(root -> left);
//     printf("%d ",root -> data);
//     inorder_traversal(root -> right);
// }

void inorder_traversal_iterative(struct node* root)
{
    if(root == NULL) return ;

    while(1)
    {
        if(root != NULL)
        {
            push(root);
            root = root -> left;
        }
        else 
        {
            if(top == -1) break;
            root = pop();
            printf("%d ",root -> data);
            root = root -> right;
        }
    }

    return ;

}

int main()
{
    struct node* root;
    root = NULL;

    root = create();

    // inorder_traversal(root);

    inorder_traversal_iterative(root);  // using stacks.

    return 0;
}