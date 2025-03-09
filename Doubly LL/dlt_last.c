#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* ladd;
    struct node* radd;
};

struct node* start ;
struct node* new1 ;
struct node* temp;

void create();
void dlt_last();
void list_display();

int main()
{
    create();

    dlt_last();

    list_display();

    return 0 ;
}



void create()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> ladd = NULL;
    start -> radd = NULL;

    temp = start ;
    

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while (n != 0)
    {
        printf("Enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> ladd = temp;
        new1 -> radd = NULL;
        temp -> radd = new1;
        temp = new1;

        printf("do you want to conitnue ? ");
        scanf("%d",&n);


    }
    return ;
}



void list_display()
{
    temp = start ;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp -> radd;
    }
    return ;
}

void dlt_last()
{
    temp = start ;
    while (temp -> radd != NULL)
    {
        temp = temp -> radd;
    }
    new1 = temp -> ladd;
    new1 -> radd = NULL;
    printf("deleted element is : %d\n",temp -> data);
    free(temp);

    return ;
}