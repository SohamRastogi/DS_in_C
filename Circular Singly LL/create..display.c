#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* add;
};

struct node* start = NULL;
struct node* new1;
struct node* temp;

void create();
void display();

int main()
{
    create();

    display();

    return 0 ;
}

void create()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    start = (struct node*) malloc (sizeof(struct node));

    start -> data = n;
    start -> add = NULL;

    temp = start ;

    printf("do you want to continue ? ");
    scanf("%d",&n);

    while(n!=0)
    {
        printf("Enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = new1;

        printf("do you want to continue ? ");
        scanf("%d",&n);

    }
    temp = start;
    while (temp-> add != NULL)
    {
        temp = temp -> add;
    }
    temp -> add = start ;
    // temp = start ;
    return ;
}



void display()
{
    temp = start ;
    while (temp -> add != start)
    {
        printf("%d ",temp -> data);
        temp = temp -> add;
    }
    printf("%d",temp -> data);
    return ;
}