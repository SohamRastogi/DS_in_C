#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* ladd;
    struct node* radd;
};

struct node* start = NULL;
struct node* temp;
struct node* new1;

void create();
void insert_end();
void display();



int main ()
{
    create();

    insert_end();

    display();

    return 0;
}



void create()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> ladd = NULL;
    start -> radd = NULL;

    temp = start;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while ( n != 0 )
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> radd = NULL;
        new1 -> ladd = temp;
        temp -> radd = new1 ;
        temp = new1;

        printf("do you want to continue ? ");
        scanf("%d",&n);

    }
    // printf("%d",temp -> data);
    // printf("\n");
    temp -> radd = start ;
    start -> ladd = temp ;
     
    return ;
}



void display()
{
    if(start == NULL) printf("empty linked list");

    else 
    {
        temp = start ;
        while ( temp -> radd != start )
        {
            printf("%d ",temp -> data);
            temp = temp -> radd;
        }
        printf("%d" , temp -> data );
    }

    return ;

    
}




void insert_end()
{
    temp = start ;
    while( temp -> radd != start)
    {
        temp = temp -> radd;
    }
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    new1 = (struct node*) malloc (sizeof(struct node));

    new1 -> data = n;
    new1 -> ladd = temp ;
    new1 -> radd = start;
    temp -> radd = new1;
    start -> ladd = new1;

    return ;
}