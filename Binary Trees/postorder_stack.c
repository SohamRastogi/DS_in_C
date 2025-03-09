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

void postorder_traversal_iterative(struct node* root)
{
    struct node* current = root;
    while(current != NULL || top != -1)
    {
        if(current != NULL)
        {
            push(current);
            current = current -> left;
        }
        else 
        {
            struct node* temp = NULL;
            temp = stack[top] -> right;
            if(temp == NULL)
            {
                temp = pop();
                printf("%d ",temp -> data);
                while(top != -1 && temp == stack[top]->right)
                {
                    temp = pop();
                    printf("%d ",temp -> data);
                }
            }
            else{
                current = temp;
            }
        }
    }
}


int main()
{
    struct node* root;
    root = NULL;

    root = create();

    // inorder_traversal(root);

    postorder_traversal_iterative(root);  // using stacks.

    return 0;
}