#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create()
{
    int x;
    struct node* newnode;
    newnode = (struct node*) malloc (sizeof (struct node));

    printf("enter data : ");
    scanf("%d",&x);

    if ( x== -1 ){
        return NULL;
    }

    newnode -> data = x;
    printf("enter value for left child of %d\n",x);
    newnode -> left = create();

    printf("enter value for right child of %d\n",x);
    newnode -> right = create();

    return newnode ;

}



int main()
{
    struct node* root ;
    root = NULL;

    root = create();

    return 0 ;
}