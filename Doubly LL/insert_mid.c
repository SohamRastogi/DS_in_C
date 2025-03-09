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
struct node* prev;
struct node* next;

void create();
void insert_middle();
void list_display();

int main()
{
    create();

    insert_middle();

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



void insert_middle()
{
    int n;
    int pos;
    printf("enter the number : ");
    scanf("%d",&n);
    printf("enter the position : ");
    scanf("%d",&pos);

    temp = start ;
    
    pos -- ;
    while(pos >1){
        temp = temp -> radd;
        pos--;
    }
    prev = temp ;
    next = prev -> radd;

    new1 = (struct node*) malloc (sizeof(struct node));

    new1-> data = n;
    new1 -> ladd = prev;
    new1 -> radd = next;
    prev -> radd = new1 ;
    next -> ladd = new1 ;

    return ;
}