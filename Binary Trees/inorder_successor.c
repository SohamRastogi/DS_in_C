#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int max(int a , int b)
{
    if(a>=b) return a;
    return b;
}

int height(struct node* n)
{
    if(n == NULL) return 0;
    return n -> height;
}
int getBalance(struct node* n)
{
    if(n == NULL) return 0 ;

    return (height(n -> left) - height(n -> right));
}

struct node* newnode (int data)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    n -> data = data;
    n -> left = NULL;
    n -> right = NULL;
    n -> height = 1;
    return n;
}

struct node* min_value_node(struct node* n)
{
    struct node* current = n;
    while(current -> left != NULL)
    {
        current = current -> left;
    }
    return current;
}

struct node* leftRotate (struct node* x)
{
    struct node* y = x -> right;
    struct node* t1 = y -> left;

    y -> left = x;
    x -> right = t1;

    x -> height = max(height(x -> left) , height(x -> right)) + 1;
    y -> height = max(height(y -> left) , height(y -> right)) + 1;
    
    return y;
}
struct node* rightRotate(struct node* y)
{
    struct node* x = y -> left;
    struct node* t2 = x -> right;

    x -> right = y;
    y -> left = t2;

    x -> height = max(height(x -> left) , height(x -> right)) + 1;
    y -> height = max(height(y -> left) , height(y -> right)) + 1;

    return x; 
}

struct node* insert_node (struct node* n , int data)
{
    if(n == NULL)
    {
        return newnode(data);
    }
    else if(n -> data > data)
    {
        n -> left = insert_node(n -> left , data);
    }
    else if(n -> data < data)
    {
        n -> right = insert_node(n -> right , data);
    }

    n -> height = max(height(n -> left) , height(n -> right)) + 1;
    int balance = getBalance(n);
    
    if(balance > 1 && n -> left -> data > data)
    {
        return rightRotate(n);
    }
    if(balance < -1 && n -> right -> data < data)
    {
        return leftRotate(n);
    }
    if(balance > 1 && n -> left -> data < data)
    {
        n -> left = leftRotate(n -> left);
        return rightRotate(n);
    }
    if(balance < -1 && n -> right -> data > data)
    {
        n -> right = rightRotate(n -> right);
        return leftRotate(n);
    }

    return n ;

}

void inorder(struct node* n)
{
    if(n==NULL) return ;
    inorder(n -> left);
    printf("%d ", n -> data);
    inorder(n -> right);
}

void preorder(struct node* n)
{
    if(n==NULL) return ;
    printf("%d ", n -> data);
    preorder(n -> left);
    preorder(n -> right);
}

void postorder(struct node* n)
{
    if(n==NULL) return ;
    postorder(n -> left);
    postorder(n -> right);
    printf("%d ",n -> data);
}

int main()
{
    struct node* root = NULL;

    root = insert_node(root , 1);
    root = insert_node(root , 4);
    root = insert_node(root , 2);
    root = insert_node(root , 3);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0 ;
}