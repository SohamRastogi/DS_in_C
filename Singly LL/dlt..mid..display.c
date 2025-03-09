#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* add;

};

struct node* start = NULL;
struct node* new1;
struct node* temp;
struct node* prev;
struct node* next;

void create();
void delete_middle();
void display();

int main()
{
    create();
    delete_middle();
    display();
    return 0;
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

    while (n != 0)
    {
        printf("enter a number : ");
        scanf("%d",&n);

        new1 = (struct node*) malloc (sizeof(struct node));

        new1-> data = n;
        new1 -> add = NULL;
        temp -> add = new1;
        temp = temp -> add;

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
        temp = start;
        while(temp != NULL)
        {
            printf("%d ",temp -> data);
            temp = temp -> add;
        }
    }
    return ;
}

void delete_middle()
{
    if( start == NULL) printf("empty list");
    
    else 
    {
        temp = start;
        int pos;
        printf("enter position of deleted node : ");
        scanf("%d",&pos);

        pos--;
        while(pos > 1)
        {
            temp = temp -> add;
            pos-- ;
        }
        prev = temp;
        new1 = prev -> add;
        next = new1 -> add;
        printf("deleted element is : %d\n",new1 -> data);

        prev -> add = next ;
        free (new1);
    }
    return ;
}
