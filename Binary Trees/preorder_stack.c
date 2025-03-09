#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* stack[10];
int top = -1;

void push(struct node* root)
{
    if(top == 9)
    {
        printf("stack_overflow");
    }
    top++;
    stack[top] = root;

    return ;
}

struct node* pop()
{
    struct node* alpha = stack[top];

    top--;
    return alpha;
}

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

    return newnode ;
}

void preorder (struct node* root)
{
    if(root == NULL) return ;

    push(root);

    while(top != -1)
    {
        root = pop();
        printf("%d ",root -> data);
        if(root -> right != NULL){
            push(root->right);
        }
        if(root -> left != NULL)
        {
            push(root -> left);
        }
    }

}

int main()
{
    struct node* root;
    root = NULL;

    root = create();

    preorder(root);

    return 0 ;
}