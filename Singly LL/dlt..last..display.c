#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* add;
};

struct node* start = NULL;
struct node* new1 ;
struct node* temp ;
struct node* prev ;

void create();
void dlt_last();
void display();

int main()
{
    create();
    dlt_last();
    display();
    return 0 ;
}

void create()
{
    int n;
    printf("enter a number  : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> add = NULL;

    temp = start ;

    printf("type 1 if you want to continue : \n");
    printf("type 0 if you want to discontinue : \n");
    scanf("%d",&n);

    while( n!= 0){
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = new1 ;

        printf("type 1 if you want to continue : ");
        printf("\ntype 0 if you want to discontinue : ");
        scanf("%d",&n);
    }

    return ;
}

void display()
{
    if(start == NULL){
        printf("empty list");
    }
    else 
    {
        temp = start ;
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> add ;
        }


    }
    return ;
}

void dlt_last ()
{
    if (start == NULL) printf("empty list");
    else 
    {
        temp = start ;
        while(temp->add != NULL)
        {
            prev = temp;
            temp = temp ->add;
        }

        prev -> add = NULL;
        printf("deleted element is : %d",temp->data);
        printf("\n");
        free(temp);
    }
    return ;
}