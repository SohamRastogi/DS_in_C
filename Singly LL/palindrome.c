#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* add;
};

struct node* start = NULL;
struct node* temp ;
struct node* new1;

void display()
{
    temp = start;
    while(temp != NULL)
    {
        printf("%d ",temp -> data);
        temp = temp -> add;
    }
    return ;
}

int main()
{
    int n;
    printf("enter a number : ");
    scanf("%d",&n);

    if(start == NULL)
    {
        start = (struct node*) malloc (sizeof(struct node));
        start -> data = n;
        start -> add = NULL;
    }

    temp = start;

    printf("do you want to continue ? ");
    scanf("%d",&n);
    while(n != 0)
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));
        new1 -> data = n;
        new1 -> add = NULL;

        temp -> add = new1;
        temp = new1;

        printf("do you want to continue ?  ");
        scanf("%d",&n);
    }

    display();

    return 0 ;
}