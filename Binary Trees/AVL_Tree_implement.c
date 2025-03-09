#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int height (struct node* n){
    if(n == NULL) return 0 ;

    return n -> height;
}

int max(int a , int b)
{
    if (a>=b) return a;

    return b;
}

struct node* newnode(int key)
{
    struct node* n = (struct node*) malloc (sizeof(struct node));
    n -> key = key;
    n -> left = NULL;
    n -> right = NULL;
    n -> height = 1;

    return n ;
}

int getBalance (struct node* n)
{
    if(n == NULL) return 0 ;

    return height(n -> left) - height(n -> right);
}

struct node* min_value_node (struct node* n)
{
    struct node* current = n;
    while (current -> left != NULL)
    {
        current = current -> left;
    }
    return current ;
}

struct node* leftRotate(struct node* x) {
    struct node* y = NULL;
    struct node* t2 = NULL;

    y = x -> right;
    t2 = y -> left;

    y -> left = x ;
    x -> right = t2;

    x -> height = max(height(x -> left) , height(x -> right)) + 1;
    y -> height = max(height(y -> left) , height(y -> right)) + 1;

    return y;
}

struct node* rightRotate(struct node* y) {
    struct node* x = NULL;
    struct node* t2 = NULL;

    x = y -> left;
    t2 = x -> right;

    x -> right = y;
    y -> left = t2;

    x -> height = max(height(x -> left) , height(x -> right)) + 1;
    y -> height = max(height(y -> left) , height(y -> right)) + 1;

    return x;
}

struct node* insert_node (struct node* n , int key)
{
    if(n == NULL)
    {
        return newnode(key);
    }
    else if (n -> key > key)
    {
        n -> left = insert_node(n -> left , key);
    }
    else if ( n -> key < key) 
    {
        n -> right = insert_node(n -> right , key);
    }
    // else return n;

    n -> height = 1 + max(height(n -> left) , height(n -> right));
    int balance = getBalance(n) ;

    if (balance > 1 && key < n -> left -> key)
    {
        return rightRotate(n);
    }
    if (balance < -1 && key > n -> right -> key)
    {
        return leftRotate(n);
    }
    if (balance > 1 && key > n -> left -> key)
    {
        n -> left = leftRotate(n -> left) ;
        return rightRotate(n);
    }
    if (balance < -1 && key < n -> right -> key)
    {
        n -> right = rightRotate(n -> right);
        return leftRotate(n);
    }
    return n ;
}

struct node* delete_node(struct node* n , int key)
{
    if(n == NULL) return NULL;
    
    else if (n -> key > key)
    {
        n -> left = delete_node(n -> left , key);
    }
    else if (n -> key < key)
    {
        n -> right = delete_node(n -> right , key);
    }
    
    else 
    {
        if ((n -> left == NULL) || (n -> right == NULL))
        {
            struct node* temp = n -> left ? n -> left : n -> right;
            if(temp == NULL)
            {
                temp = n;
                n = NULL;
            }
            else 
            {
                *n = *temp;
                free(temp);
            }
        }
        else 
        {
            struct node* temp = min_value_node(n -> right);
            n -> key = temp -> key ;
            n -> right = delete_node(n -> right , temp -> key);

        }
    }
    if(n == NULL) return n;

    n -> height = max(height(n -> left) , height(n -> right))+ 1;
    int balance = getBalance(n);

    if (balance > 1 && getBalance(n -> left) >=0)
    {
        return rightRotate(n) ;
    }
    if (balance > 1 && getBalance(n -> left) < 0)
    {
        n -> left = leftRotate(n -> left);
        return rightRotate(n);
    }
    if (balance < -1 && getBalance(n -> right) <=0 )
    {
        return leftRotate(n) ;
    }
    if(balance < -1 && getBalance(n -> right) > 0) 
    {
        n -> right = rightRotate(n -> right);
        return leftRotate(n);
    }

    return n ;


}

void inorder(struct node* n)
{
    if(n == NULL)
    {
        return ;
    }
    inorder(n -> left);
    printf("%d ",n -> key);
    inorder(n -> right);
}

void preorder(struct node* n)
{
    if(n == NULL) return ;
    printf("%d ",n -> key);
    preorder(n -> left);
    preorder(n -> right);
    
}

void postorder(struct node* n)
{
    if(n == NULL) return ;
    postorder(n -> left);
    postorder(n -> right);
    printf("%d ",n -> key);
}

int main()
{
    struct node* root = NULL;
    int val , ch;

    while(1) 
    {
        printf("\n1. Insert\n2. Delete\n3. Dislpay\n4. Exit\nEnter Choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1 :
            printf("\nenter value ");
            scanf("%d",&val);
            root = insert_node(root , val);
            break;
            output :
            case 2 :
            printf("\nenter value : ");
            scanf("%d",&val);
            root = delete_node(root, val);
            break;

            case 3 :
            printf("\nPreorder is : ");
            preorder(root);

            printf("\nInorder is : ");
            inorder(root);

            printf("\nPostorder is : ");
            postorder(root);
            break;

            case 4 :
            return 0 ;
            break;
            
        }
    }

    return 0 ;
    
}