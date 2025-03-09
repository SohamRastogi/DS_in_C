#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* radd;
    struct node* ladd;
};

struct node* start = NULL;
struct node* temp;
struct node* new1;
struct node* prev;
struct node* next;

void create();
void delete_mid();
void display();

int main()
{
    create();

    delete_mid();

    display();

    return 0;
}

void create()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data  = n;
    start -> ladd = NULL;
    start -> radd = NULL;

    temp = start;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while (n != 0)
    {
        printf("Enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> radd = NULL;
        new1 -> ladd = temp;
        temp -> radd = new1;
        temp = new1;

        printf("do you want to continue ? ");
        scanf("%d",&n);
    }

    return ;
}



void display()
{
    temp = start;
    while(temp -> radd != NULL)
    {
        printf("%d ",temp->data);
        temp = temp -> radd;
    }
    printf("%d",temp->data);

    return ;
}



void delete_mid()
{
    int pos ;
    printf("enter the position : ");
    scanf("%d",&pos);

    temp = start;

    while(pos > 1)
    {
        temp = temp -> radd;
        pos--;
    }
    prev = temp -> ladd;
    next = temp -> radd;

    printf("the deleted element is : %d",temp -> data);
    printf("\n");
    free(temp);
    prev -> radd = next;
    next -> ladd = prev ;

    return ;
}


