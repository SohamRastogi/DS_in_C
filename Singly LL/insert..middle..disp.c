#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node* add;
};

struct node* start = NULL;
struct node* new1;
struct node* temp;
struct node* prev;
struct node* next;

void create();
void insert_middle();
void display();

int main()
{
    create();
    insert_middle();
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

    temp = start;

    printf("do you want to continue : ");
    scanf("%d",&n);

    while(n!=0)
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1 -> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = new1;

        printf("do you want to continue : ");
        scanf("%d",&n);
    }
    return ;
}

void display()
{
    if(start == NULL) printf("empty list");
    else 
    {
        temp = start ;
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp -> add;
        }
    }
    return ;
}

void insert_middle()
{
    if(start == NULL) printf("empty list");

    else
    {
        int pos,n;
        printf("enter the number : ");
        scanf("%d",&n);
        printf("enter the position : ");
        scanf("%d",&pos);
        
        pos--;
        temp = start;
        while(pos>1)
        {
            temp = temp -> add;
            pos--;
        }
        prev = temp;
        next = prev->add;

        new1 = (struct node*) malloc (sizeof(struct node));

        new1-> data = n;
        new1 -> add = NULL;
        prev -> add = new1;
        new1 -> add = next;
        

    }
}