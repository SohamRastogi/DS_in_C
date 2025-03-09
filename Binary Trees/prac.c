#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

int max (int a , int b)
{
    if(a >= b)
    {
        return a;
    }
    else return b;
}

int height(struct node* n)
{
    if (n == NULL) return 0;
    return n -> height;
}

struct node* newnode(int key){

    struct node* n = (struct node*) malloc (sizeof(struct node));
    n -> data = key;
    n -> left = NULL;
    n -> right = NULL;
    n -> height = 1;
    return n;
}

int getBalance (struct node* n)
{
    if(n == NULL) return 0;
    return height(n -> left) - height(n -> right);

}

struct node* min_value_node(struct node* n)
{
    struct node* current = n;
    while(current -> left  != NULL)
    {
        current = current -> left;

    }
    return current ;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x -> right;
    struct node* t1 = y -> left;

    y -> left = x;
    x -> right = t1;

    y -> height = max(height(y -> left) , height(y -> right)) + 1;
    x -> height = max(height(x -> left) , height(x -> right)) + 1;

    return y;
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y -> left;
    struct node* t2 = x -> right ;

    x -> right = y;
    y -> left = t2;

    y -> height = max(height(y -> left) , height(y -> right)) + 1;
    x -> height = max(height(x -> right) , height(x -> left)) + 1;

    return x ;
}

struct node* insert_node(struct node* n , int data)
{
    if(n == NULL)
    {
        return newnode(data);
    }
    else if (n -> data > data)
    {
        n -> left = insert_node(n -> left  , data);
    }
    else if (n -> data < data)
    {
        n -> right = insert_node(n -> right , data);
    }

    n -> height = max(height(n -> left) , height(n -> right));
    int balance = getBalance(n);

    if(balance > 1 &&  n -> left -> data > data)
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

    return n;
}

void searching_node(struct node* n, int target)
{
    if(n == NULL) {
        printf("tree empty");
        return ;
    }
    while(n != NULL)
    {
        if(n -> data == target)
        {
            printf("element found");
            return ;
        }
        else if (n -> data > target)
        {
            n = n -> left;
        }
        else if (n -> data < target)
        {
            n = n -> right;
        }
    }
    printf("element not found ");
    return ;
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

void preorder(struct node* root)
{
    if(root == NULL)
    {
        return ;
    }
    printf("%d ",root -> data);
    preorder(root -> left);
    preorder(root -> right);
    
}

void postorder(struct node* root)
{
    if(root == NULL)
    {
        return ;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ",root -> data);
    
}

int main()
{
    struct node* root = NULL;
    root = insert_node(root , 1);
    root = insert_node(root , 4);
    root = insert_node(root , 3);
    root = insert_node(root , 2);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0 ;
}